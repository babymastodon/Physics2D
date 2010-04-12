/*
 *  WorldTreeNode.cpp
 *  worldtree
 *
 *  Created by Nicholas Lima on 4/5/10.
 *  Copyright 2010 Phillips Exeter Academy. All rights reserved.
 *
 */

#include "WorldTreeNode.h"

WorldTreeNode::WorldTreeNode(int cx, int cy, int hi, int wi)
{
	cornerx = cx;
	cornery = cy;
	height = hi;
	width = wi;
	numElements = 0;
	haschildren = false;
}
WorldTreeNode* WorldTreeNode::getChild(int x)
{
	return children[x - 1];
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
	}
        else
	{
		for (int i = 0; i < numElements; i++)
		{
			if (elements[i] == removethis)
			{
                                for (i; i < numElements; i++)
                                {
                                    elements[i] = elements[i + 1];
                                }
                                numElements--;
			}
		}
	}
}
