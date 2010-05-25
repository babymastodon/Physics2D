#ifndef COLLISION_H
#define COLLISION_H

#include "Point.h"
#include "PObject.h"

/*!
 * The purpose of this class is to calculat the point of collison between
 * two PObjects and find the directional vector of the force (the normal
 * vector). Another constructor can find the collision between a PObject
 * and a plane.
 */

class Collision{
public:
	Collision(PObject* obj1, PObject* obj2);
	~Collision();
	
	Point get_pointOf();
	PObject* get_object1();
	PObject* get_object2();
	bool isTrueCollision();
	float getnormx();//not necessary
	float getnormy();
	
private:
	Point intersection;
	PObject** objects;
	bool trueCollision;
	//maybe remove this
	float normx;
	float normy;
	//impulse vector
	float impulsex;
	float impulsey;
};

#endif
