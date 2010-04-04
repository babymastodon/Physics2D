#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "GraphicsObject.h"
#include "SceneGraph.h"
#include "Physics.h"
#include <vector>

using namespace std;

class Graphics{
	public:
		Graphics(const char* name, int w, int h, const Physics& ph);
		~Graphics();
		/*
		 * the function that the thread will invoke
		 */
		void mainLoop();
		void stop();
	
	private:
		void display();
		void update();
		void init();
		
		vector<GraphicsObject> gobj_list;
		/*
		 * Thread stops when quit == true
		 */
		bool quit;
		const Physics& physics;
		const char* window_name;
		int window_width;
		int window_height;
};

#endif
