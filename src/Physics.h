#ifndef PHYSICS_H
#define PHYSICS_H

#include "SceneGraph.h"
#include <SDL/SDL.h>
#include "PhysicsEvent.h"
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
		Physics();
		~Physics();
		/*
		 * automatically locks the queue mutex, adds the event,
		 * then releases it
		 */
		void addEvent(PhysicsEvent pe);
		/*
		 * the scene graph can only be modified by the physics object
		 */
		const SceneGraph& getSceneGraph() const;
	
	private:
		/*
		 * the function for the thread that was overridden:
		 */
		int mainLoop();
		
		SceneGraph scene_graph;
		SDL_mutex* queue_mutex;
		queue<PhysicsEvent> event_queue;
		
		void processEvents();
		/*
		 * internal wrappers for the SDL mutex P and V functions
		 */
		void lockQueue();
		void unlockQueue();
};

#endif
