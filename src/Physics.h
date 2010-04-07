#ifndef PHYSICS_H
#define PHYSICS_H

#include "SceneGraph.h"
#include <SDL/SDL.h>
#include <queue>
#include "Thread.h"

using namespace std;

class Physics: public Thread{
	public:
		/**
		 * Physics Constructor:
		 * 1) Creates the mutex
		 * 2) Sets scene_graph to the SceneGraph passed as parameter
		 * @param world A reference to the SceneGraph that will be assosciated with this Physics object.
		 */
		Physics(SceneGraph& world); 
		~Physics();
	
		
		// TODO: need functions that will modify the behavior of physics

		
	private:
		/*!
		 * the function for the thread that was overridden:
		 */
		int mainLoop();
		
		void processEvents();


		void lockQueue(); ///< internal wrapper for the SDL mutex P and V functions
		void unlockQueue(); ///< internal wrapper for the SDL mutex P and V functions
		
		
		SceneGraph& scene_graph; 
};

#endif
