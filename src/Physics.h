#ifndef PHYSICS_H
#define PHYSICS_H

#include "SceneGraph.h"
#include <SDL/SDL.h>
#include <queue>
#include "Thread.h"

using namespace std;

class Physics: public Thread{
	public:
		/*
		 * remember to:
		 * create and destroy the mutex
		 * empty the list of physics objects when done
		 */
		Physics(SceneGraph& world);
		~Physics();
	
		/*
		 * need functions that will modify the behavior of physics
		 */
		
	private:
		/*
		 * the function for the thread that was overridden:
		 */
		int mainLoop();
		void processEvents();
		/*
		 * internal wrappers for the SDL mutex P and V functions
		 */
		void lockQueue();
		void unlockQueue();
		
		
		SceneGraph& scene_graph;
};

#endif
