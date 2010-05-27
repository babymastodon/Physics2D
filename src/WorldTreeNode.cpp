/*
 *  WorldTreeNode.cpp
 *  worldtree
 *
 *  Created by Nicholas Lima on 4/5/10.
 *  Copyright 2010 Phillips Exeter Academy. All rights reserved.
 *
 */

#include "WorldTreeNode.h"

#include <iostream>
using namespace std;

WorldTreeNode::WorldTreeNode(float cx, float cy, float wi, float hi)
{
	cornerx = cx;
	cornery = cy;
	height = hi;
	width = wi;
	numElements = 0;
	parent = NULL;
	haschildren = false;
}

WorldTreeNode::~WorldTreeNode()
{
	//delete child nodes
	if (haschildren){
		for (int j=0; j<4; j++)
		{
			delete children[j];
		}
	}
}

/*
 * Changed: if it's recursive, getNumElements() will return a greater
 * value than the true number of elements. (what if a element is in
 * more than one of the child nodes)
 */
int WorldTreeNode::getNumElements()
{
	return numElements;
}

WorldTreeNode* WorldTreeNode::getChild(int x)
{
	return children[x];
}
bool WorldTreeNode::hasChildren()
{
	return haschildren;
}

void WorldTreeNode::add(PObject* addthis)
{
	bool successfully_added = addToDeque(addthis);
	if (successfully_added){
		numElements++;
		if (!haschildren && numElements > MAX_ELEMENTS && width>MIN_NODE_DIMENSION && height>MIN_NODE_DIMENSION){
			//cout << "split node into children, width " << width << " height " << height << endl;
			haschildren = true;
			//Precalculate for efficiency
			float halfwidth = width/2;
			float halfheight = height/2;
			float midx = cornerx + halfwidth;
			float midy = cornery + halfheight;
			
			addToDeque(addthis);
			children[0] = new WorldTreeNode(midx, midy, halfwidth, halfheight);
			children[1] = new WorldTreeNode(cornerx, midy, halfwidth, halfheight);
			children[2] = new WorldTreeNode(cornerx, cornery, halfwidth, halfheight);
			children[3] = new WorldTreeNode(midx, cornery, halfwidth, halfheight);
			for (int i = 0; i < 4; i++){
				children[i]->setParent(this);
			}
			
			for (deque<PObject*>::iterator it = element_deque.begin(); it != element_deque.end(); it++){
				addToChildren(*it);
			}
		}
		else if (haschildren){
			addToChildren(addthis);
		}
	}
}

void WorldTreeNode::addToChildren(PObject* addThis)
{
	for (int j=0; j<4; j++)
	{
		WorldTreeNode* child = children[j];
		if (addThis->intersect(child->cornerx, child->cornery, child->width, child->height))
			child->add(addThis);
	}
}

void WorldTreeNode::remove(PObject* removethis){
	bool successfully_removed = removeFromDeque(removethis);
	if (successfully_removed){
		numElements--;
		if (haschildren){
			for (int j=0; j<4; j++)
			{
				WorldTreeNode* child = children[j];
				child->remove(removethis);
			}
			if (numElements<MIN_ELEMENTS)
			{
				deleteChildren();
			}
		}
	}
}

void WorldTreeNode::setParent(WorldTreeNode* thisisp)
{
	parent = thisisp;
}

WorldTreeNode* WorldTreeNode::getParent()
{
	return parent;
}

float WorldTreeNode::getcornerx()
{
	return cornerx;
}

float WorldTreeNode::getcornery()
{
	return cornery;
}

float WorldTreeNode::getheight()
{
	return height;
}

float WorldTreeNode::getwidth()
{
	return width;
}

void WorldTreeNode::update(int cycle)
{
	deque<PObject*>::iterator it = element_deque.begin();
	while (it != element_deque.end()){
		//cout << "update tree" << endl;
		if(!(*it)->completelyInside(cornerx, cornery, width, height))
		{
			//how will we prevent redundant "move ups"? originally, it would attempt to move up anything that intersected with the border of any child, even if of of the sibling nodes "moved it up" in the same cycle of updates.
			//have pobject keep track of cycle numbers and only move up if cycle number is outdated
			if (parent!=NULL){
				WorldTreeNode* moveup = parent;
				if (cycle!=(*it)->getLastCycle())
				{
					while ((moveup->getParent() != 0) && (!(*it)->completelyInside(moveup->cornerx, moveup->cornery, moveup->width, moveup->height)))
					{
						moveup = moveup->getParent();
					}
					moveup->addToChildren(*it);
					(*it)->setLastCycle(cycle);
				}
			}
			//remove elements that are no longer in box
			//beware, PObjects that exist completely outside the root node will get deleted
			if (!(*it)->intersect(cornerx, cornery, width, height))
			{
				it = element_deque.erase(it);
				numElements--;
				//delete from all the children also???
				/*if(haschildren){
					for (int i = 0; i < 4; i++){
						cout << "remove from children" << endl;
						children[i]->remove((*it));
					}
				}*/
			}
			else
			{
				it++;
			}
		}
		else
		{
			it++;
		}
	}
	if (haschildren)
	{
		if (numElements<MIN_ELEMENTS)
		{
			deleteChildren();
		}
		else{
			for (int i = 0; i < 4; i++)
			{
				children[i]->update(cycle);
			}
		}
	}
}

bool WorldTreeNode::addToDeque(PObject* addthis)
{
	deque<PObject*>::iterator insert_location;
	insert_location = lower_bound(element_deque.begin(),element_deque.end(),addthis);
	if (addthis != *insert_location)
	{
		element_deque.insert(insert_location, addthis);
		return true;
	}
	return false;
}
bool WorldTreeNode::removeFromDeque(PObject* removethis)
{
	deque<PObject*>::iterator remove_location;
	remove_location = lower_bound(element_deque.begin(), element_deque.end(), removethis);
	if (removethis == *remove_location)
	{
		element_deque.erase(remove_location);
		return true;
	}
	return false;
}

const deque<PObject*>& WorldTreeNode::getElements() const
{
	return element_deque;
}

void WorldTreeNode::draw()
{
	if(haschildren)
	{
		for (int i=0; i<4; i++)
		{
			children[i]->draw();
		}
	}
	else
	{
		glBegin(GL_QUADS);
			glVertex2f(cornerx, cornery);
			glVertex2f(cornerx+width, cornery);
			glVertex2f(cornerx+width, cornery+height);
			glVertex2f(cornerx, cornery+height);
		glEnd();
	}
}

void WorldTreeNode::deleteChildren()
{
	haschildren = false;
	for (int i = 0; i < 4; i++)
	{
		delete children[i]; //remember that c++ doesn't have automatic garbage collection
		children[i] = NULL;
	}
}

void WorldTreeNode::addPossibleCollisions(list<Collision*> & addToThis)
{
	if (haschildren)
	{
		for (int i=0; i<4; i++)
		{
			children[i]->addPossibleCollisions(addToThis);
		}
	}
	else
	{
		for (deque<PObject*>::iterator it = element_deque.begin(); it!=element_deque.end(); it++)
		{
			deque<PObject*>::iterator it2 = it;
			it2++;
			for (; it2!=element_deque.end(); it2++)
			{
				if ((*it)->intersect(*it2))
				{
					addToThis.push_back(new Collision((*it),(*it2)));
				}
			}
		}
	}
}
