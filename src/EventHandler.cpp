#include "EventHandler.h"

EventHandler::EventHandler(Physics& ph, Graphics& gr, SceneGraph& sg) : Thread(), physics(ph), graphics(gr), scene_graph(sg){
}
EventHandler::~EventHandler(){}

int EventHandler::mainLoop(){
	/*
	 * implementation:
	 * 1. get the SDL events
	 * 2. process the SDL events (send the physics object physics events
	 *    and possibly the graphics object some also)
	 * 3. delay a few milliseconds
	 * 4. repeat
	 * 
	 * if quit event, send stop signal to phys and graphics objects and
	 * return.
	 */
	SDL_Delay(6000);
	return 0;
}
