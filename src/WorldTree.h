/*
 *  WorldTree.h
 *  worldtree
 *
 *  Created by Nicholas Lima on 4/5/10.
 *  Stores and allows for manipulation/traversal of a WorldTree storing SceneGraphNodes as elements
 */
#include "WorldTreeNode.h"
#include "SceneGraphNode.h"

class WorldTree
{
	
private:
	
	/* 
	 * Stores the dimentions of the world represented by the WorldTree, stores the coordinates of the bottom 
	 * left corner of the world, and the hight and width of the world
	 */
	int cornerx;
	int cornery;
	int height;
	int width;
	
	/*
	 *  Stores the root of the WorldTree, which encompasses the whole world
	 */
	WorldTreeNode* root;

public:
	
	/*
	 *  constructor takes the dimensions of the world as its parameters 
	 */
	WorldTree(int cx, int cy, int hi, int wi);
	
	/*
	 *	returns a pointer to the root of the WorldTree
	 */
	WorldTreeNode* getRoot();
	
	/*
	 *  adds a pointer to a SceneGraphNode to its proper WorldTreeNode
	 */
	void add(PObject*);
	
	/*
	 *  removes a SceneGraphNode from its WorldTreeNode, colapses the WorldTreeNode and its siblings
	 *  back into its parent if the removal of this node drops the number of elements contained in that
	 *  subtree under a certain number
	 */
	void remove(PObject*);
	
	
};

