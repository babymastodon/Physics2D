/*
 *  WorldTreeNode.h
 *  worldtree
 *
 *  Created by Nicholas Lima on 4/5/10.
 */
#ifndef WORLDTREENODE_H
#define WORLDTREENODE_H

#include "PObject.h"

#define MAX_ELEMENTS 9
#define MIN_ELEMENTS 3

/*
 * Represents a section of the world and stores the objects within that section
 * Objects can be added or removed, if a node contains too many elements
 * it creates 4 children each containing a smaller section of the world and adds
 * its elements to the appropriate child
 *
 * currently the node will devide when a 10th element is added to it, it is fairly simple
 * to increase or decrease this number
 */

/*
 * new implementation could contain a sorted deque in each node to keep track of
 * all PObjects in its children. Although is is much more memory intensive, it will
 * allow efficient traversal of the objects as well as a more
 * efficient remove() method.
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
	PObject* elements[MAX_ELEMENTS+1];
	WorldTreeNode* parent;

	
public:
	//Changed order for to be consistant
	WorldTreeNode(float cx, float cy, float wi, float hi);
	~WorldTreeNode();
	WorldTreeNode* getChild(int x);
	bool hasChildren();
	
	void add(PObject* addthis);
	/*
	 * Precondition: removeThis intersects with this node's bounding rect
	 */
	void remove(PObject* removethis);
	
	int getNumElements();
	
	//what if it's the top level tree node. Parent could == NULL
	WorldTreeNode* getParent();
	
	void update();
	
private:
	void setParent(WorldTreeNode* thisisp);
	void addToChildren(PObject* addthis);
};

#endif

