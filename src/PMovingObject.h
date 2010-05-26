
#ifndef PMOVINGOBJECT_H
#define PMOVINGOBJECT_H

#include "PObject.h"

/**
 * PMovingObject keeps track of simple Cartesian motion with velocity 
 * and acceleration. No rotation.
 */

class PMovingObject: public PObject
{
	public:
		PMovingObject(float x, float y, float width, float height, float th=0, float dx=0, float dy=0, float dth=0, float ddx=0, float ddy=0);
		virtual void move(GLuint time); ///< Time in milliseconds
		virtual bool contains(float x, float y) const;
		virtual const Point* getVertices() const;

		
		// Acceleration and velocity getter and setter functions
		void set_ax(float n);
		void set_ay(float n);
		
		float get_ax() const;
		float get_ay() const;
			
	protected:
		float ax;///< x acceleration given in pixels per second^2
		float ay;///< y acceleration given in pixels per second^2
		Point *returnVertices;
	private:
		mutable bool recalculateVertices;
};

#endif /* PMOVINGOBJECT_H */ 
