#ifndef POBJECT_H
#define POBJECT_H

#include <SDL/SDL_opengl.h>
/*
 * Forget about separation of domain and representation. I'm putting
 * the functions for physics and drawing into the same class.
 * Sorry, couldn't think of a better name
 */

class PObject{
	public:
		PObject();
		~PObject();
		
		virtual void draw() =0;
		virtual void move(GLuint time) =0;
		/*
		 * check for simple bounding box intersection with the
		 * rectangle defined by x y width height.
		 */
		virtual bool intersect(float x, float y, float width, float height)=0;
		/*
		 * accurately determines if point x,y lies within the object.
		 */
		virtual bool contains(float x, float y)=0;
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
