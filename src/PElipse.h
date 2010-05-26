#ifndef PELIPSE_H
#define PELIPSE_H

#include "PMovingObject.h"

/*!
 *	PElipse represents an elipse that inherits from PMovingObject.
 *	As well as storing the location of the vertices of the elipse,
 *	it creates a representation of the elipse using openGL so that 
 *	it can be drawn to the screen.
 */
class PElipse: public PMovingObject
{
	
	public:
	
		/*!
		 *	The PElipse constructor takes the coordinates of the 
		 *	bottom left vertex of the elipse and the length of its
		 *	major and minor axis.  The number of edges in the elipse
		 *	is set automatically.  
		 */
		PElipse(float x, float y, float width, float height,int ed=20,float mass=1);
	
		/*!
		 *	The draw method sets the graphics neccessary to dislpay
		 *	the elipse on the screen.  It then displays the elipse
		 *	in its proper location and orientation on the screen.
		 */
		virtual void draw();
	
		/*!
		 *	The resetGraphics method resets the GLuint initialized in the compileList method
		 *	which is called in the draw method.
		 */
		virtual void resetGraphics();
			
	private:
	
		/*!
		 *	display_list stores the GLuint used to hold the graphics 
		 *	information of the elipse.
		 */
		GLuint display_list;
	
		/*!
		 *	edges stores the number of edges set in the constructor.
		 */
		int edges;
	
		/*!
		 *	The compileList method sets display_list to its proper values
		 *	to allow the elipse to be displayed to its correct position and
		 *	orientation on the screen.
		 */
		void compileList();
	
};

#endif
