#ifndef COLLISION_H
#define COLLISION_H

#include "Point.h"
#include "PObject.h"

class Collision{
public:
	Collision(PObject* obj1, PObject* obj2);
	~Collision();
	
	Point get_pointOf();
	PObject** get_objects();
	bool isTrueCollision();
	
private:
	Point intersection;
	PObject** objects;
	bool trueCollision;
};

#endif
