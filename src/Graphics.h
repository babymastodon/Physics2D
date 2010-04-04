#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "GraphicsObject.h"
#include "SceneGraph.h"
#include "Physics.h"
#include "Thread.h"
#include <SDL/SDL.h>
#include <vector>

using namespace std;

class Graphics: public Thread{
	public:
		Graphics(const char* name, int w, int h, const Physics& ph);
		~Graphics();
		
	private:
		/*
		 * the function for Thread that was overridden:
		 */
		int mainLoop();
		
		void display();
		void update();
		void init();
		
		vector<GraphicsObject> gobj_list;
		const Physics& physics;
		
		const char* window_name;
		int window_width;
		int window_height;
};

#endif
