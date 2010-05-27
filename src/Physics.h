#ifndef PHYSICS_H
#define PHYSICS_H

#include "SceneGraph.h"
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
		
		void pause();
		void unpause();
		void togglePause();
		
	private:
		/*!
		 * the function for the thread that was overridden:
		 */
		int mainLoop();
		
		void processEvents();
		
		SceneGraph& scene_graph;
		bool pause_flag;
};

#endif
