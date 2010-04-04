#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "Physics.h"
#include "Graphics.h"
#include "Thread.h"
#include <SDL/SDL.h>

/*
 * This class recieves SDL events, interprets them, and send them off
 * to either the Physics or Grahics objects.
 * it runs on a separate thread
 */

class EventHandler: public Thread{
	public:
		EventHandler(Physics& ph, Graphics& gr);
		~EventHandler();
		
	private:
		/*
		 * the function for the thread that was overridden:
		 */
		int mainLoop();
		
		//not const so that it can modify behavior
		Physics& physics;
		Graphics& graphics;
};

#endif
