#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "Physics.h"
#include "Graphics.h"
#include "Thread.h"
#include "SceneGraph.h"
#include <SDL/SDL.h>

#define EVENT_CHECK_RATE 20///< # checks per second

/*!
 * The EventHandler class recieves SDL events, interprets them, passes them
 * to either the Physics or Grahics objects.
 * it runs in a separate thread
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
