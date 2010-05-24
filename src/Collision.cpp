#include "Collision.h"

Collision::Collision(PObject* obj1, PObject* obj2)
{
	objects = new PObject*[2];
	objects[0] = obj1;
	objects[1] = obj2;
	
	// this needs to calculate the point of intersection between the two objects, this is where the serious collision 
	// detection can take place 
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

