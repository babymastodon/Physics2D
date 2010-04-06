#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "SceneGraph.h"
#include "Physics.h"
#include "Thread.h"
#include <SDL/SDL_opengl.h>
#include <vector>

using namespace std;

class Graphics: public Thread{
	public:
		Graphics(const char* name, int w, int h, const SceneGraph& world);
		~Graphics();
		
		/*
		 * need functions that will modify the behavior of graphics
		 * such as moving the display around (remember that the 
		 * whole world is not necessarily displayed on the screen)
		 */
		
	private:
		/*
		 * the function for Thread that was overridden:
		 */
		int mainLoop();
		
		void display();
		void update();
		void init();
		
		const char* window_name;
		int window_width;
		int window_height;
		/*
		 * coordinates of the bottom left corner of the viewport
		 */
		float viewport_x;
		float viewport_y;
		
		const SceneGraph& scene_graph;
};

#endif
