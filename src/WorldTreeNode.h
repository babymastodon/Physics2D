/*
 *  WorldTreeNode.h
 *  worldtree
 *
 *  Created by Nicholas Lima on 4/5/10.
 */
#ifndef WORLDTREENODE_H
#define WORLDTREENODE_H

#include "PObject.h"
#include <deque>
#include <algorithm>

using namespace std;

#define MAX_ELEMENTS 9
#define MIN_ELEMENTS 3
#define MIN_NODE_DIMENSION 10.0

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
	WorldTreeNode* parent;
	
	//PObjects stored in sorted deque for faster searching
	deque<PObject*> element_deque;

	
public:
	//Changed order for to be consistant
	WorldTreeNode(float cx, float cy, float wi, float hi);
	~WorldTreeNode();
	WorldTreeNode* getChild(int x);
	bool hasChildren();
	/*!
	 * adds the PObject. if the node has more than (n) elements in it,
	 * this node will create 4 child nodes and put elements in them
	 */
	void add(PObject* addthis);
	/*
	 * Precondition: removeThis intersects with this node's bounding rect
	 */
	void remove(PObject* removethis);
	
	int getNumElements();
	
	float getcornerx();
	float getcornery();
	float getheight();
	float getwidth();
	
	//what if it's the top level tree node. Parent could == NULL
	WorldTreeNode* getParent();
	
	void update();
	
	const deque<PObject*>& getElements() const;
	
	void draw();
	
private:
	void setParent(WorldTreeNode* thisisp);
	void addToChildren(PObject* addthis);
	//true if successfully added
	bool addToDeque(PObject* addthis);
	//true if successfully removed
	bool removeFromDeque(PObject* removethis);
};

#endif

