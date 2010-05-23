
#ifndef PELIPSE_H
#define PELIPSE_H

#include "PMovingObject.h"

class PElipse: public PMovingObject
{
	public:
		PElipse(float x, float y, float width, float height,int ed=20);
		virtual void draw();
		virtual void resetGraphics();
			
	private:
		GLuint display_list;
		int edges;
		void compileList();
};

#endif /* PELIPSE_H */ 
