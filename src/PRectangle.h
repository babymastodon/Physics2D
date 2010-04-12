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
		PRectange(float x, float y, float width, float height,int ed=4);
		virtual void draw();
		virtual void compileList();
			
	private:
		GLuint display_list;
		int edges;
};

#endif