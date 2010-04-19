/*
 *  WorldTreeNode.h
 *  worldtree
 *
 *  Created by Nicholas Lima on 4/5/10.
 */
#ifndef WORLDTREENODE_H
#define WORLDTREENODE_H

#include "PObject.h"

/*
 * Represents a section of the world and stores the objects within that section
 * Objects can be added or removed, if a node contains too many elements
 * it creates 4 children each containing a smaller section of the world and adds
 * its elements to the appropriate child
 *
 * currently the node will devide when a 10th element is added to it, it is fairly simple
 * to increase or decrease this number
 */
class WorldTreeNode
{
private:
	
/*
 *	stores the dimensions of the node
 */
	float cornerx;
	float cornery;
	float height;
	float width;
/*
 * stores the number of elements contained in the node, and whether or not the node has childrew
 */
	int numElements;
	bool haschildren;
/*
 * stores an array of the node's children (if it has any), if it does not, 
 * then the elements array stores the node's elements
 */
	WorldTreeNode* children[4];
	PObject* elements[10];
	WorldTreeNode* parent;

	
public:
	WorldTreeNode(float cx, float cy, float hi, float wi);
	WorldTreeNode* getChild(int x);
	bool hasChildren();
	
	void add(PObject* addthis);
	void remove(PObject* removethis);
	
	int getNumElements();
	PObject* getElement(int thisone);
	
	void setParent(WorldTreeNode* thisisp);
	WorldTreeNode* getParent();
	
	void update();
};

#endif

