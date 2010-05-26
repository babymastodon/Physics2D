#ifndef PRECTANGLE_H
#define PRECTANGLE_H

#include "PMovingObject.h"

/*!
 *	PRectangle represents a rectangle that inherits from PMovingObject.
 *	As well as storing the location of the vertices of the rectangle,
 *	it creates a representation of the rectangle using openGL so that 
 *	it can be drawn to the screen.
 */
class PRectangle: public PMovingObject
{
	
	public:
	
		/*!
		 *	The PRectangle constructor takes the coordinates of 
		 *	the bottom left corner of the rectangle and its 
		 *	height and width.
		 */
		PRectangle(float x, float y, float width, float height);
	
		/*!
		 *	The draw method sets the graphics neccessary to dislpay
		 *	the rectangle on the screen.  It then displays the rectangle
		 *	in its proper location and orientation on the screen.
		 */
		virtual void draw();
	
		/*!
		 *	The resetGraphics method resets the GLuint initialized in the 
		 *	compileList method which is called in the draw method.
		 */
		virtual void resetGraphics();
			
	private:
	
		/*!
		 *	display_list stores the GLuint used to hold the graphics 
		 *	information of the rectangle.
		 */
		GLuint display_list;	
	
		/*!
		 *	The compileList method sets display_list to its proper values
		 *	to allow the rectangle to be displayed to its correct position
		 *	and orientation on the screen.
		 */
		void compileList();
	
};

#endif
