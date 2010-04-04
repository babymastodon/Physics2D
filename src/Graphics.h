#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "GraphicsObject.h"
#include <vector>

using namespace std;

class Graphics{
	public:
		Graphics(const char* name, int w, int h);
		~Graphics();
		void gameLoop();
	
	private:
		void display();
		void update();
		
		vector<GraphicsObject> gobj_list;
		/*
		 * Thread stops when quit == true
		 */
		bool quit;
};

#endif
