#ifndef COLLISION_H
#define COLLISION_H

#include "Point.h"
#include "PObject.h"

class Collision{
public:
	Collision(PObject* obj1, PObject* obj2);
	~Collision();
	
	Point get_pointOf();
	PObject* get_object1();
	PObject* get_object2();
	bool isTrueCollision();
	
private:
	Point intersection;
	PObject** objects;
	bool trueCollision;
	//impulse vector?
};

#endif
