
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
		PMovingObject(float x, float y, float width, float height, float dx=0, float dy=0, float ddx=0, float ddy=0);
		//why are these function virtual when implementation is provided? Subclasses can override normal functions too.
		virtual void move(GLuint time); ///< Time in milliseconds
		virtual bool intersect(float x, float y, float w, float h); 
		virtual bool contains(float x, float y);
		virtual bool collides(PObject& other);
		virtual bool completelyInside(float x, float y, float w, float h);
		
		// Acceleration and velocity getter and setter functions
		void set_ax(float n);
		void set_ay(float n);
		void set_vx(float n);
		void set_vy(float n);
		
		float get_ax() const;
		float get_ay() const;
		float get_vx() const;
		float get_vy() const;
			
	protected:
		float vx;///< x velocity given in pixels per second
		float vy;///< y velocity given in pixels per second
		float ax;///< x acceleration given in pixels per second^2
		float ay;///< y acceleration given in pixels per second^2
		float cornerx; ///< x coordinate of bottom left corner
		float cornery; ///< y coordinate of bottom left corner
		float width; ///< width of bounding rectangle
		float height; ///< height of bounding rectangle
};

#endif /* PMOVINGOBJECT_H */ 
