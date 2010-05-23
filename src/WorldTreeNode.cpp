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

WorldTreeNode::WorldTreeNode(float cx, float cy, float wi, float hi){
	cornerx = cx;
	cornery = cy;
	height = hi;
	width = wi;
	numElements = 0;
	parent = NULL;
	haschildren = false;
}

WorldTreeNode::~WorldTreeNode(){
	//delete child nodes
	if (haschildren){
		for (int j=0; j<4; j++){
			delete children[j];
		}
	}
}

/*
 * Changed: if it's recursive, getNumElements() will return a greater
 * value than the true number of elements. (what if a element is in
 * more than one of the child nodes)
 */
int WorldTreeNode::getNumElements(){
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

void WorldTreeNode::add(PObject* addthis){
	bool successfully_added = addToDeque(addthis);
	if (successfully_added){
		numElements++;
		if (!haschildren && numElements >= MAX_ELEMENTS && width>MIN_NODE_DIMENSION && height>MIN_NODE_DIMENSION){
			cout << "split node into children, width " << width << " height " << height << endl;
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
			cout << "added to children" << endl;
			addToChildren(addthis);
		}
	}
}

void WorldTreeNode::addToChildren(PObject* addThis){
	for (int j=0; j<4; j++){
		WorldTreeNode* child = children[j];
		if (addThis->intersect(child->cornerx, child->cornery, child->width, child->height))
			child->add(addThis);
	}
}


void WorldTreeNode::remove(PObject* removethis){
	cout << "removing" << endl;
	bool successfully_removed = removeFromDeque(removethis);
	if (successfully_removed){
		cout << "successfully removed object" << endl;
		numElements--;
		if (haschildren){
			cout << "removing children" << endl;
			for (int j=0; j<4; j++){
				WorldTreeNode* child = children[j];
				if (removethis->intersect(child->cornerx, child->cornery, child->width, child->height))
					child->remove(removethis);
			}
			if (numElements<MAX_ELEMENTS){
				deleteChildren();
				//no longer needed if deques are used
				//collect the PObjects in the children
				/*int counter = 0;
				for (int j=0; j<4; j++){
					//child nodes are guarenteed to not have any more child nodes
					WorldTreeNode* child = children[j];
					for (int i = 0; i < child->numElements; i++){
						//check for duplicates before collecting
						bool noDup = true;
						for (int k=0; k<counter; k++){
							if (child->elements[i]==elements[j]) noDup = false;
						}
						if (noDup){
							elements[counter] = child->elements[i];
							counter++;
						}
					}
				}*/
			}
		}
		/*else{//no children
			for (int i = 0; i < numElements; i++){
				if (elements[i] == removethis){
					for (int j = i; j < numElements-1; j++){
						elements[j] = elements[i + 1];
					}
				}
			}
		}*/
	}
}

void WorldTreeNode::setParent(WorldTreeNode* thisisp){
	parent = thisisp;
}

WorldTreeNode* WorldTreeNode::getParent(){
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

void WorldTreeNode::update()
{
	deque<PObject*>::iterator it = element_deque.begin();
	while (it != element_deque.end()){
		//cout << "update tree" << endl;
		if(!(*it)->completelyInside(cornerx, cornery, width, height) && parent!=NULL){
			//how will we prevent redundant "move ups"? currently, it will attempt to move up anything that intersects with the border of any child, even if of of the sibling nodes "moved it up" in the same cycle of updates.
			//have pobject keep track of cycle numbers and only move up if cycle number is outdated
			cout << "moving up" << endl;
			WorldTreeNode* moveup = parent;
			while ((moveup->getParent() != 0) && (!(*it)->completelyInside(moveup->cornerx, moveup->cornery, moveup->width, moveup->height))){
				cout << "move up loop, box: " << moveup->cornerx << " " << moveup->cornery << " " << moveup->width << " " << moveup->height << endl;
				moveup = moveup->getParent();
			}
			cout << "adding to children" << endl;
			moveup->addToChildren(*it);
			cout << "added to children" << endl;
			//remove elements that are no longer in box
			if (!(*it)->intersect(cornerx, cornery, width, height)){
				cout << "no longer in box" << endl;
				it = element_deque.erase(it);
				numElements--;
			} 
			else{
				cout << "still in box" << endl;
				it++;
			}
		}
		else{
			it++;
		}
	}
	if (haschildren){
		if (numElements<MAX_ELEMENTS){
			cout << "deleting children" << endl;
			deleteChildren();
		}
		else{
			cout << "updating children" << endl;
			for (int i = 0; i < 4; i++){
				children[i]->update();
			}
		}
	}
}

bool WorldTreeNode::addToDeque(PObject* addthis){
	deque<PObject*>::iterator insert_location;
	insert_location = lower_bound(element_deque.begin(),element_deque.end(),addthis);
	if (addthis != *insert_location){
		element_deque.insert(insert_location, addthis);
		return true;
	}
	return false;
}
bool WorldTreeNode::removeFromDeque(PObject* removethis){
	deque<PObject*>::iterator remove_location;
	remove_location = lower_bound(element_deque.begin(), element_deque.end(), removethis);
	if (removethis == *remove_location){
		element_deque.erase(remove_location);
		return true;
	}
	return false;
}

const deque<PObject*>& WorldTreeNode::getElements() const{
	return element_deque;
}

void WorldTreeNode::draw(){
	if(haschildren){
		for (int i=0; i<4; i++){
			children[i]->draw();
		}
	}
	else{
		glBegin(GL_QUADS);
			glVertex2f(cornerx, cornery);
			glVertex2f(cornerx+width, cornery);
			glVertex2f(cornerx+width, cornery+height);
			glVertex2f(cornerx, cornery+height);
		glEnd();
	}
}

void WorldTreeNode::deleteChildren(){
	haschildren = false;
	for (int i = 0; i < 4; i++){
		delete children[i]; //remember that c++ doesn't have automatic garbage collection
		children[i] = NULL;
	}
}
