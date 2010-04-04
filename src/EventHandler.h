#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "Physics.h"
#include "Graphics.h"

/*
 * This class recieves SDL events, interprets them, and send them off
 * to either the Physics or Grahics objects.
 * it runs on a separate thread
 */

class EventHandler{
	public:
		EventHandler(Physics& ph, Graphics& gr);
		~EventHandler();
	private:
		//not const so that it can modify behavior
		Physics& physics;
		Graphics& graphics;
};

#endif
