
#ifndef PMOVINGOBJECT_H
#define PMOVINGOBJECT_H

#include "PObject.h"

/*!
 * PMovingObject keeps track of a PObject using simple Cartesian 
 *	motion with velocity and acceleration.
 */
class PMovingObject: public PObject
{
	public:
		
		/*!
		 *	The PMovingObject constructor takes the bottom left corner
		 *	of the object, and the width and height of the object.
		 *	The constructor also initial acceleration of the object.
		 */
		PMovingObject(float x, float y, float width, float height, float th=0, float dx=0, float dy=0, float dth=0, float ddx=0, float ddy=0);
	
		/*!
		 *	The move method moves the object for the given time
		 *	(the time is measured in milliseconds).
		 */
		virtual void move(GLuint time); 
	
		/*!
		 *	The contains method returns true if the given x and 
		 *	y values are within the PObject.
		 */
		virtual bool contains(float x, float y) const;
	
		/*!
		 *	The getVertices method returns an array containing 
		 *	the vertices of the PObject.  This method is implemented
		 *	in the classes that inherit from PMovingObject which 
		 *	can have different numbers of vertices.
		 */
		virtual const Point* getVertices() const;

		
		/*!
		 *	The set_ax and set_ay methods set the PMovingObject's 
		 *	acceleration along the x and y axis.
		 */
		void set_ax(float n);
		void set_ay(float n);
		
		/*!
		 *	The get_ax and get_ay methods return the PMovingObject's
		 *	acceleration along the x and y axis.
		 */
		float get_ax() const;
		float get_ay() const;
			
	protected:
	
		/*!
		 *	The floats ax and ay store the PMovingObject's 
		 *	acceleration along the x and y axis. Acceleration
		 *	is measured in pixels per second.
		 */
		float ax;
		float ay;
	
		/*!
		 *	returnVertices stores an array of the PObject's vertices.
		 */
		Point *returnVertices;
	
	private:
	
		/*!
		 *	recalculateVertices stores true if the location of
		 *	the objects vertices have changed and need to be 
		 *	recalculated for the PMovingObject's new location.
		 *	It is used by the getVertices method.
		 */
		mutable bool recalculateVertices;
};

#endif