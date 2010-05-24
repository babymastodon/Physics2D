#ifndef PHYSICS_H
#define PHYSICS_H

#include "SceneGraph.h"
#include <SDL/SDL.h>
#include <queue>
#include <list>
#include "Thread.h"

#define P_REFRESH_TIME 10 //milliseconds per refresh

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
		
		void pause();
		void unpause();
		void togglePause();
		
	private:
		/*!
		 * the function for the thread that was overridden:
		 */
		int mainLoop();
		
		void processEvents();

		/*
		 * I think I ditched the event queue. Scene graph should
		 * implement lock and unlock methods.
		 */
		/*bool isQueueLocked(); ///< returns true if mutex is currently locked
		void lockQueue(); ///< internal wrapper for the SDL mutex P and V functions
		void unlockQueue(); ///< internal wrapper for the SDL mutex P and V functions*/
		
		SceneGraph& scene_graph;
		bool pause_flag;
};

#endif
