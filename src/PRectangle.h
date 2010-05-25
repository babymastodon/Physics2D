/*
 *  this is me trying to convert your ellipse class to a rectangle, please fix it 
 *  however it needs to be fixed! I'll learn from your changes how the gl stuff works so
 *  that I can help with it more
 */
#ifndef PRECTANGLE_H
#define PRECTANGLE_H

#include "PMovingObject.h"

class PRectangle: public PMovingObject
{
	public:
		PRectangle(float x, float y, float width, float height);
		virtual void draw();
		virtual void resetGraphics();
			
	private:
		GLuint display_list;
		void compileList();
};

#endif
