#ifndef PHYSICSEVENT_H
#define PHYSICSEVENT_H

#include "SceneGraph.h"

/*
 * Event classes that modify the SceneGraph
 */

class PhysicsEvent{
	public:
		PhysicsEvent();
		~PhysicsEvent();
		
		virtual void execute(SceneGraph sg){}
	private:
};

/*
 * subclasses of PhysicsEvent must implement the execute function.
 * The idea is this: the event handler will send these events to a 
 * queue in the Physics object. the physics object will lock the queue,
 * then call the execute function of all of the events, passing the 
 * Scene Graph as a parameter.
 */

#endif
