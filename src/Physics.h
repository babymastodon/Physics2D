#ifndef PHYSICS_H
#define PHYSICS_H

#include "SceneGraph.h"
#include <SDL/SDL.h>
#include <queue>
#include "Thread.h"

#define P_REFRESH_RATE 100 //frequency of the physics engine;

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
	
		
		/// @todo need functions that will modify the behavior of physics

		
	private:
		/*!
		 * the function for the thread that was overridden:
		 */
		int mainLoop();
		
		void processEvents();


		bool isQueueLocked(); ///< returns true if mutex is currently locked
		void lockQueue(); ///< internal wrapper for the SDL mutex P and V functions
		void unlockQueue(); ///< internal wrapper for the SDL mutex P and V functions
		
		SceneGraph& scene_graph; 
};

#endif
