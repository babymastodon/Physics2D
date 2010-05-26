#ifndef PEquilateralTriangle_H
#define PEquilateralTriangle_H

#include "PMovingObject.h"

/*!
 *	PElquilateralTriangle represents an equilateral triangle
 *	that inherits from PMovingObject.  As well as storing the 
 *	location of the vertices of the elipse, it creates a 
 *	representation of the elipse using openGL so that it can 
 *	be drawn to the screen.
 */
class PEquilateralTriangle : public PMovingObject
{
	
	public: 
	
		/*!
		 *	The PEquilateralTriangle constructor takes the coordinates
		 *	of the bottow left corner of the triangle and the length
		 *	of the triangle's sides
		 */
		PEquilateralTriangle(float x, float y, float sidelength, float mass=1);
	
		/*!
		 *	The draw method sets the graphics neccessary to dislpay
		 *	the triangle on the screen.  It then displays the triangle
		 *	in its proper location and orientation on the screen.
		 */
		virtual void draw();
	
		/*!
		 *	The resetGraphics method resets the GLuint initialized in 
		 *	the compileList method which is called in the draw method.
		 */
		virtual void resetGraphics();
	
	private:
		
		/*!
		 *	display_list stores the GLuint used to hold the graphics 
		 *	information of the triangle.
		 */
		GLuint display_list;
	
		/*!
		 *	The compileList method sets display_list to its proper values
		 *	to allow the triangle to be displayed to its correct position
		 *	and orientation on the screen.
		 */
		void compileList();
	
};

#endif
