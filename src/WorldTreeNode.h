/*
 *  WorldTreeNode.h
 *  worldtree
 *
 *  Created by Nicholas Lima on 4/5/10.
 */

#include "PObject.h"

/*
 * Represents a section of the world and stores the objects within that section
 * Objects can be added or removed, if a node contains too many elements
 * it creates 4 children each containing a smaller section of the world and adds
 * its elements to the appropriate child
 */
class WorldTreeNode
{
private:
	
/*
 *	stores the dimensions of the node
 */
	int cornerx;
	int cornery;
	int height;
	int width;
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
	
public:
	WorldTreeNode(int cx, int cy, int hi, int wi);
	WorldTreeNode* getChild(int x);
	void add(PObject* addthis);
	void remove(PObject* removethis);
};

