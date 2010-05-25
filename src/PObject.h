#ifndef POBJECT_H
#define POBJECT_H

#include <SDL/SDL_opengl.h>
#include <cmath>
#include "Point.h"
#include <cstring>


#include <iostream>
using namespace std;


/*
 * Forget about separation of domain and representation. I'm putting
 * the functions for physics and drawing into the same class.
 */

/**
 * A generic class that is responsible for both the Physical and Graphical aspects
 * of the object. A PObject knows its own coordinates relative to the window, the orientation,
 * and other physical constants or variables.
 */

class PObject{
	public:
		PObject(float x=0, float y=0, float width=0, float heght=0);
		~PObject();
		
		/**
		 * Function responsible for the graphical display of the PObject onto the screen.
		 * Assumes that the center of the current perspective is at the origin of the window.
		 * PObject knows its own position in the window.
		 */
		virtual void draw() =0;  
		virtual void move(GLuint time) =0;
		
		/*!
		 * This function is called when the openGL context is initialized
		 * or re-initialized. All subclass that use openGL resources
		 * (such as display lists or texture objects) should reset these
		 * resources when this function is called
		 */
		virtual void resetGraphics(){}
		
		/*!
		 *  Determines if point (x,y) lies within the current object.
		 *  @param x The x coordinate of the point in question
		 *  @param y The y coordinate of the point in question
		 *  @return True if (x,y) lies inside the current object, False otherwise
		 */
		virtual bool contains(float x, float y)=0;
		
		/**
		 * Checks for a collision between the bounding rectangle of
		 * this PObject and the rectangle defined by the parameters.
		 * (x,y) represents the BOTTOM left corner of the rectangle.
		 *	@return True if the two rectangles intersect; false otherwise
		 */
		bool intersect(float x, float y, float width, float height);
		
		/**
		 * Checks for a collision between the bounding rectangle of
		 * this PObject and the other PObject
		 *	@return True if the two objects intersect; false otherwise
		 */
		bool intersect(PObject* other);
		
		/*!
		 *  Slow check for collisions between this PObject and the one passed
		 *  as a parameter. Uses the contains function to check for collisions.
		 *  @param sgn A reference to the second PObject used for collision checking
		 *  @return True if the two objects intersect; false otherwise. 
		 */
		//virtual bool collides(PObject& sgn)=0;
		
		/**
		 * Checks if this object's bounding rect lies completely within
		 * the given rectangle.
		 * (x,y) represents the BOTTOM left corner of the rectangle.
		 *	@return True if the object is completely within given rect; false otherwise
		 */
		bool completelyInside(float x, float y, float width, float height);
		
		/*
		 * what other functions should all physics objects have?
		 */
	
		//checks to see if this object is on the edge of a given boundry
		//do we still need this?
		//virtual bool onBound(float xcorner, float ycorner, float xwidth, float yheight)=0;
		
		/**
		 * should be overridden to allow vertex transformations to occur.
		 * PObject implementation merely returns the shape of the object.
		 */
		virtual const Point* getVertices();
		int getNumVertices() const;
		int getLastCycle();
		void setLastCycle(int cycle);
		float getMass();
		void setMass(float m);

	protected:
		Point* vertices;
		int num_vertices;
		
		float cornerx; ///< x coordinate of bottom left corner
		float cornery; ///< y coordinate of bottom left corner
		float width; ///< width of bounding rectangle
		float height; ///< height of bounding rectangle
		float mass;///<the mass of the PObject
		
	private:
		int last_cycle;
};

/*
 * remember to use display lists: compile in constructor and call in
 * the draw() function.
 */

/*
 * Idea for a rotating object class:
 * 
 * x and y refer to the center of the bounding square
 * since the object can rotate, the center of mass will be the
 * center of the square. therefore, the radius of the square
 * will be the distance from the center of mass to the
 * point furthest away from the center of mass. Ex: a rect of
 * 8x2 will have a bounding square radius of sqrt(4^2+1^2).
 * if the center of mass were the bottom left corner of the
 * rect, the square radius would be sqrt(8^2+2^2).
 */


#endif
