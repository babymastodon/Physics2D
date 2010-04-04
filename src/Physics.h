#ifndef PHYSICS_H
#define PHYSICS_H

#include "SceneGraph.h"
#include <SDL/SDL.h>
#include "PhysicsEvent.h"
#include <queue>

using namespace std;

class Physics{
	public:
		/*
		 * remember to:
		 * create and destroy the mutex
		 * empty the list of physics objects when done
		 */
		Physics();
		~Physics();
		/*
		 * automaticallt locks the queue mutex, adds the event,
		 * then releases it
		 */
		void addEvent(PhysicsEvent pe);
		/*
		 * the scene graph can only be modified by the physics object
		 */
		const SceneGraph& getSceneGraph() const;
	
	private:
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
