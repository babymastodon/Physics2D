#ifndef GRAPHICSOBJECT_H
#define GRAPHICSOBJECT_H

#include "PhysicsObject.h"
#include <SDL/SDL_opengl.h>

class GraphicsObject{
	public:
		GraphicsObject(const PhysicsObject& po);
		~GraphicsObject();
		
		/*
		 * implementations should translate to the correct coordinates
		 * and draw the object
		 */
		virtual void draw() const =0;
		
	protected:
		const PhysicsObject& physics_object;
};

//add all the subclasses for the graphics object

class GCircle: public GraphicsObject{
	public:
		/*
		 * color is in form ARGB
		 */
		GCircle(const PCircle& po, int ed=10, int col=0xffffff);
		~GCircle();
		
		void draw() const;
	private:
		GLuint displayList;
};

#endif

