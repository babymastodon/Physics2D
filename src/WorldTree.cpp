#include "WorldTree.h"


//CONTENTS MOVED TO SCENEGRAPH


WorldTree::WorldTree(int cx, int cy, int hi, int wi)
{
	cornerx = cx;
	cornery = cy;
	height = hi;
	width = wi;
	root = new WorldTreeNode::WorldTreeNode(cornerx, cornery, height, width);
}

void WorldTree::add(PObject* addthis)
{
	root->WorldTreeNode::add(addthis);
}

void WorldTree::remove(PObject* removethis)
{
	root->WorldTreeNode::remove(removethis);
}

WorldTreeNode* WorldTree::getRoot()
{
	return root;	
}
	
