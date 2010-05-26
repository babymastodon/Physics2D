#ifndef COLLISION_H
#define COLLISION_H

#include "Point.h"
#include "PObject.h"
#include "Vect2D.h"

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
	
	const Point& get_pointOf() const;
	PObject* get_object1() const;
	PObject* get_object2() const;
	bool isTrueCollision() const;
	const Vect2D& getimpulse() const;
	
private:
	Point intersection;
	PObject** objects;
	bool trueCollision;
	//impulse vector
	Vect2D impulse;
};

#endif
