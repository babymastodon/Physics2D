#ifndef COLLISION_H
#define COLLISION_H

#include "Point.h"
#include "PObject.h"
#include "Vect2D.h"

/*!
 * The purpose of this class is to calculate the point of collison between
 * two PObjects and find the directional vector of the force (the normal
 * vector)
 */

class Collision{
public:
	
	/*!
	 *	The Collision constructor takes two PObjects whose bounding
	 *	boxes collide and calculates whether or not they have 
	 *	collided, if they have, it stores the average point of 
	 *	collision and calculates the impulse acting on the two 
	 *	PObjects as a result of the collision
	 */
	Collision(PObject* obj1, PObject* obj2);
	~Collision();
	

	/*!
	 *	The get_pointOf method returns the average point of collision
	 */
	const Point& get_pointOf() const;
	
	/*!
	 *	The get_object1 and get_object2 methods return pointers to the
	 *	PObjects contained in the collision, allowing for easy translation
	 *	and/or rotation using the values calculated by the collision
	 */
	PObject* get_object1() const;
	PObject* get_object2() const;
	
	/*!
	 *	Returns true if the two PObjects contained in the collision 
	 *	actually do collide, returns false if only the bounding
	 *	boxes of the PObjects collided, the boolean trueCollision
	 *	is set in the constructor after the collision's calculations
	 *	have been completed
	 */
	bool isTrueCollision() const;
	
	const Vect2D& getimpulse() const;
	
private:
	
	/*!
	 *	Holds the average point of intersection of the two PObjects
	 *	stored in the collision (calculated in the constructor)
	 */
	Point intersection;
	
	/*!
	 *	Holds an array containing the two PObjects passed to the 
	 *  collision object in the constructor
	 */
	PObject** objects;
	
	/*!
	 *	Stores true if the two PObjects do collide, false if 
	 *	only their bounding boxes collide (set in constructor)
	 */
	bool trueCollision;
	
	/*!
	 *	Stores the x and y impulse acting on the first object as
	 *	a result of the collision (the impulse on the second object
	 *	is simply equal and opposite)	
	 */
	Vect2D impulse;
};

#endif
