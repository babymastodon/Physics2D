#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "SceneGraph.h"
#include "Physics.h"
#include "Thread.h"
#include <SDL/SDL_opengl.h>
#include <vector>

using namespace std;

/*!
 * The Graphics class is responsible for keeping track of the SceneGraphNodes
 * in a private SceneGraph, and displaying all of them to the screen. Each
 * SceneGraphNode knows how to draw itself, starting from the origin, so the
 * only responsibility of the Graphics class is to keep track of the SceneGraph
 * and the window that the objects are being drawn in.
 */

class Graphics: public Thread{
	public:
		Graphics(const char* name, int w, int h, SceneGraph& world);
		~Graphics();
		
		/*
		 * TODO:
		 * need functions that will modify the behavior of graphics
		 * such as moving the display around (remember that the 
		 * whole world is not necessarily displayed on the screen)
		 */
		
	private:
		/*!
		 * the function for the overriden thread
		 */
		int mainLoop();
		
		void display();
		void update();
		void init();
		
		const char* window_name;
		int window_width;
		int window_height;
		
		float viewport_x; ///< x coordinate of the bottom left corner of the viewport
		float viewport_y; ///< y coordinate of the bottom left corner of the viewport
		
		SceneGraph& scene_graph; ///< Contains all of the SceneGraphNodes that are present in the program.
};

#endif
