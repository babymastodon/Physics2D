#ifndef COLLISION_H
#define COLLISION_H

#include "Point.h"
#include "PObject.h"

/*!
 * The purpose of this class is to calculate the point of collison between
 * two PObjects and find the directional vector of the force (the normal
 * vector).
 */

class Collision
{
	
	public:
		
		/*!
		 *	The Collision constructor takes two PObjects whose bounding
		 *	boxes collide and calculates whether or not they have 
		 *	collided.  If they have, it stores the average point of 
		 *	collision and calculates the impulse acting on the two 
		 *	PObjects as a result of the collision.
		 */
		Collision(PObject* obj1, PObject* obj2);
		~Collision();
	
		/*!
		 *	The get_pointOf method returns the average point of collision.
		 */
		Point get_pointOf();
	
		/*!
		 *	The get_object1 and get_object2 methods return pointers to the
		 *	PObjects contained in the collision, allowing for easy translation
		 *	and/or rotation using the values calculated by the collision.
		 */
		PObject* get_object1();
		PObject* get_object2();
	
		/*!
		 *	The isTrueCollision method returns true if the two PObjects
		 *	contained in the collision actually do collide, it returns 
		 *	false if only the bounding boxes of the PObjects collided. 
		 *	The boolean trueCollision is set in the constructor after
		 *	the collision's calculations have been completed.
		 */
		bool isTrueCollision();
	
	
		float getnormx();//not necessary
		float getnormy();
	
	private:
	
		/*!
		 *	The variable intersection holds the average point of 
		 *	intersection of the two PObjects stored in the collision. 
		 *	It is calculated in the constructor.
		 */
		Point intersection;
	
		/*!
		 *	objects holds an array containing the two PObjects passed to the 
		 *  collision object in the constructor.
		 */
		PObject** objects;
	
		/*!
		 *	trueCollision stores true if the two PObjects do collide, false if 
		 *	only their bounding boxes collide (set in constructor)
		 */
		bool trueCollision;
	
		/*!
		 *	The float variables impulsex and impulsey store the x and y 
		 *	impulse acting on the first object as a result of the collision. 
		 *	The impulse on the second object is simply equal and opposite.
		 */
		float impulsex;
		float impulsey;
	
		//maybe remove this
		float normx;
		float normy;
	
};

#endif
