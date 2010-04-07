#ifndef POBJECT_H
#define POBJECT_H

#include <SDL/SDL_opengl.h>

/*
 * Forget about separation of domain and representation. I'm putting
 * the functions for physics and drawing into the same class.
 * Sorry, couldn't think of a better name
 */

/**
 * A generic class that is responsible for both the Physical and Graphical aspects
 * of the object. A PObject knows its own coordinates relative to the window, the orientation,
 * and other physical constants or variables.
 */

class PObject{
	public:
		PObject();
		~PObject();
		
		/**
		 * Function responsible for the graphical display of the PObject onto the screen.
		 * Assumes that the center of the current perspective is at the origin of the window.
		 * PObject knows its own position in the window.
		 */
		virtual void draw() =0;  
		virtual void move(GLuint time) =0;
		
		/**
		 * Checks for a collision between the bounding rectangle of
		 * this PObject and the rectangle defined by the parameters.
		 * (x,y) represents the top left corner of the rectangle.
		 *	@return True if the two rectangles intersect; false otherwise
		 */
		virtual bool intersect(float x, float y, float width, float height)=0;
		
		/*!
		 *  Determines if point (x,y) lies within the current object.
		 *  @param x The x coordinate of the point in question
		 *  @param y The y coordinate of the point in question
		 *  @return True if (x,y) lies inside the current object, False otherwise
		 */
		virtual bool contains(float x, float y)=0;
		
		/*!
		 *  Checks for collisions between this PObject and the one passed
		 *  as a parameter. Uses bounding rectangles to check for collisions.
		 *  @param sgn A reference to the second PObject used for collision checking
		 *  @return True if the bounding rectangles for the two objects intersect; false otherwise. 
		 */
		virtual bool collides(PObject& sgn)=0;
		
		/*
		 * what other functions should all physics objects have?
		 */
	private:
};

/*
 * how to draw circle:
glNewList(displayList,GL_COMPILE);
	glPushMatrix();
		glTranslatef(physics_object.getx(),physics_object.gety(),0);
		glColor3b(red,green,blue);
		glBegin(GL_TRIANGLE_FAN);
			glVertex2f(0.0,0.0);
			for (int i=0; i<=edges; i++){
				float r=physics_object.getradius();
				glVertex2f(r*cos(2*PI*i/edges),-r*sin(2*PI*i/edges));
			}
		glEnd();
	glPopMatrix();
glEndList();
 */

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
