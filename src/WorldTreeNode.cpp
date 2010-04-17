/*
 *  WorldTreeNode.cpp
 *  worldtree
 *
 *  Created by Nicholas Lima on 4/5/10.
 *  Copyright 2010 Phillips Exeter Academy. All rights reserved.
 *
 */

#include "WorldTreeNode.h"

WorldTreeNode::WorldTreeNode(float cx, float cy, float wi, float hi){
	cornerx = cx;
	cornery = cy;
	height = hi;
	width = wi;
	numElements = 0;
	haschildren = false;
}

WorldTreeNode::~WorldTreeNode(){
	//possibly delete child nodes
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

void WorldTreeNode::add(PObject* addthis){
	if (!haschildren && numElements == MAX_ELEMENTS){
		haschildren = true;
		//Precalculate for efficiency
		float halfwidth = width/2;
		float halfheight = height/2;
		float midx = cornerx + halfwidth;
		float midy = cornery + halfheight;
		
		elements[numElements] = addthis;
		children[0] = new WorldTreeNode(midx, midy, halfwidth, halfheight);
		children[1] = new WorldTreeNode(cornerx, midy, halfwidth, halfheight);
		children[2] = new WorldTreeNode(cornerx, cornery, halfwidth, halfheight);
		children[3] = new WorldTreeNode(midx, cornery, halfwidth, halfheight);
		for (int i = 0; i < 4; i++){
			children[i]->setParent(this);
		}
		
		for (int i = 0; i < MAX_ELEMENTS+1; i++){
			addToChildren(elements[i]);
		}
	}
	if (haschildren){
		addToChildren(addthis);
	}
	else{
		elements[numElements] = addthis;
	}
	numElements++;
}

void WorldTreeNode::addToChildren(PObject* addThis){
	for (int j=0; j<4; j++){
		WorldTreeNode* child = children[j];
		if (addThis->intersect(child->cornerx, child->cornery, child->width, child->height))
			child->add(addThis);
	}
}


void WorldTreeNode::remove(PObject* removethis){
	if (haschildren){
		for (int j=0; j<4; j++){
			WorldTreeNode* child = children[j];
			if (removethis->intersect(child->cornerx, child->cornery, child->width, child->height))
				child->remove(removethis);
		}
		/*
		 * Original implementation ignored the fact that
		 * elements could be in more than one child node.
		 */
		if (numElements<=MAX_ELEMENTS){
			//collect the PObjects in the children
			int counter = 0;
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
			}

			haschildren = false;
			for (int i = 0; i < 4; i++){
				delete children[i]; //remember that c++ doesn't have automatic garbage collection
				children[i] = NULL;
			}
		}
	}
	else{
		for (int i = 0; i < numElements; i++){
			if (elements[i] == removethis){
				for (int j = i; j < numElements-1; j++){
					elements[j] = elements[i + 1];
				}
			}
		}
	}
	numElements--;
}

void WorldTreeNode::setParent(WorldTreeNode* thisisp){
	parent = thisisp;
}

WorldTreeNode* WorldTreeNode::getParent(){
	return parent;
}
