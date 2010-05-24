#include "Collision.h"

Collision::Collision(PObject* obj1, PObject* obj2)
{
	objects = new PObject*[2];
	objects[0] = obj1;
	objects[1] = obj2;
	
	const Point* obj1vertices = objects[0]->getVertices();
	const Point* obj2vertices = objects[1]->getVertices();
	
	float x;
	float y;
	
	for (int i = 0; i < objects[0]->getNumVertices(); i++)
	{
		for (int j = 0; j < objects[1]->getNumVertices(); i++)
		{
			if ((obj1vertices[i].x < obj2vertices[j].x && obj1vertices[(i + 1) % (objects[0]->getNumVertices())].x > obj2vertices[j].x) || (obj1vertices[i].x > obj2vertices[j].x && obj1vertices[(i + 1) % (objects[0]->getNumVertices())].x < obj2vertices[j].x))
			{
				
			}
			if ((obj1vertices[i].y < obj2vertices[j].y && obj1vertices[(i + 1) % (objects[0]->getNumVertices())].y > obj2vertices[j].y) || (obj1vertices[i].y > obj2vertices[j].y && obj1vertices[(i + 1) % (objects[0]->getNumVertices())].y < obj2vertices[j].y))
			{
			
			}
		}
	}

	intersection.x = x;
	intersection.y = y;
}

Collision::~Collision(){}

PObject** Collision::get_objects()
{
	return objects;
}

Point Collision::get_pointOf()
{
	return intersection;
}

