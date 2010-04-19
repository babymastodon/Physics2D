/*
 *  WorldTreeNode.cpp
 *  worldtree
 *
 *  Created by Nicholas Lima on 4/5/10.
 *  Copyright 2010 Phillips Exeter Academy. All rights reserved.
 *
 */

#include "WorldTreeNode.h"

WorldTreeNode::WorldTreeNode(float cx, float cy, float hi, float wi)
{
	cornerx = cx;
	cornery = cy;
	height = hi;
	width = wi;
	numElements = 0;
	haschildren = false;
}

int WorldTreeNode::getNumElements()
{
	if (!haschildren)
	{
		return numElements;
	}
	else
	{
		return children[0]->getNumElements() + children[1]->getNumElements() + children[2]->getNumElements() + children[3]->getNumElements();
	}
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
	if (numElements == 9 and !haschildren)
	{
		elements[numElements] = addthis;
		children[0] = new WorldTreeNode(cornerx + (width / 2), cornery + (height / 2), height / 2, width / 2);
		children[1] = new WorldTreeNode(cornerx, cornery + (height / 2), height / 2, width / 2);
		children[2] = new WorldTreeNode(cornerx, cornery, height / 2, width / 2);
		children[3] = new WorldTreeNode(cornerx + (width / 2), cornery, height / 2, width / 2);
		for (int i = 0; i < 4; i++)
		{
			children[i]->setParent(this);
		}
		haschildren = true;
		for (int i = 0; i < 11; i++)
		{
				if (elements[i]->intersect(cornerx + (width / 2), cornery + (height / 2), height / 2, width / 2))
				{
					children[0]->add(elements[i]);
				}
				if(elements[i]->intersect(cornerx, cornery + (height / 2), height / 2, width / 2))
				{
					children[1]->add(elements[i]);
				}
				if(elements[i]->intersect(cornerx, cornery, height / 2, width / 2))
				{
					children[2]->add(elements[i]);
				}
				if(elements[i]->intersect(cornerx + (width / 2), cornery, height / 2, width / 2))
				{
					children[3]->add(elements[i]);
				}
		}
	}
	if (haschildren)
	{
		if (addthis->intersect(cornerx + (width / 2), cornery + (height / 2), height / 2, width / 2))
		{
			children[0]->add(addthis);
		}
		if(addthis->intersect(cornerx, cornery + (height / 2), height / 2, width / 2))
		{
			children[1]->add(addthis);
		}
		if(addthis->intersect(cornerx, cornery, height / 2, width / 2))
		{
			children[2]->add(addthis);
		}
		if(addthis->intersect(cornerx + (width / 2), cornery, height / 2, width / 2))
		{
			children[3]->add(addthis);
		}
	}
	else
	{
		elements[numElements] = addthis;
		numElements++;
	}
}

void WorldTreeNode::remove(PObject* removethis)
{
	if (haschildren)
	{
            if(removethis->intersect(cornerx + (width / 2), cornery + (height / 2), height / 2, width / 2))
            {
                children[0]->remove(removethis);
            }
            if(removethis->intersect(cornerx, cornery + (height / 2), height / 2, width / 2))
            {
                children[1]->remove(removethis);
            }
            if(removethis->intersect(cornerx, cornery, height / 2, width / 2))
            {
                children[2]->remove(removethis);
            }
            if(removethis->intersect(cornerx + (width / 2), cornery, height / 2, width / 2))
            {
                children[3]->remove(removethis);
            }
		
			if ((children[0]->getNumElements() + children[1]->getNumElements() + children[2]->getNumElements() + children[3]->getNumElements()) < 10)
				{
					int counter = 0;
					for (int i = 0; i < children[0]->getNumElements(); i++)
					{
						elements[i] = children[0]->getElement(i);
						numElements++;
						counter++;
					}
					for (int i = 0; i < children[1]->getNumElements(); i++)
					{
						elements[counter] = children[1]->getElement(i);
						numElements++;
						counter++;
					}
					for (int i = 0; i < children[2]->getNumElements(); i++)
					{
						elements[counter] = children[2]->getElement(i);
						numElements++;
						counter++;
					}
					for (int i = 0; i < children[3]->getNumElements(); i++)
					{
						elements[counter] = children[3]->getElement(i);
						numElements++;
						counter++;
					}

					haschildren = false;
					for (int i = 0; i < 4; i++)
					{
						children[i] = NULL;
					}
				}
		
	}
	else
	{
		for (int i = 0; i < numElements; i++)
		{
			if (elements[i] == removethis)
			{
				for (int j = i; j < numElements; j++)
				{
					elements[j] = elements[i + 1];
				}
				numElements--;
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

PObject* WorldTreeNode::getElement(int thisone)
{
	return elements[thisone];
}

void WorldTreeNode::update()
{
	if (haschildren)
	{
		for (int i = 0; i < numElements; i++)
		{
			//this is where it needs to kick the element up to its parent if it is no longer in the node
			//but what if it intersects with two squares?
			//we need a border method in pobject to check it its on the boundary
		}
	}
	else 
	{
		for (int i = 0; i < 4; i++)
		{
			children[i]->update();
		}
	}
}