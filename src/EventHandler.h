#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "Physics.h"
#include "Graphics.h"
#include "Thread.h"
#include "SceneGraph.h"
#include <SDL/SDL.h>

#define EVENT_CHECK_TIME 100///< delay between event checks in milliseconds

/*!
 * The EventHandler class recieves SDL events, interprets them, passes them
 * to either the Physics or Grahics objects.
 * it starts, stops, and manages both the physics and graphics threads
 */

class EventHandler: public Thread{
	public:
		EventHandler(Physics& ph, Graphics& gr, SceneGraph& sg);
		~EventHandler();
		
	private:
		/*!
		 * the function for the overriden thread
		 */
		int mainLoop();
		void handleEvents();
		
		///not const so that it can modify behavior
		Physics& physics;
		///not const so that it can modify behavior
		Graphics& graphics;
		SceneGraph& scene_graph;
};

#endif
