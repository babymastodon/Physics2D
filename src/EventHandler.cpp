#include "EventHandler.h"

EventHandler::EventHandler(Physics& ph, Graphics& gr, SceneGraph& sg) : Thread(), physics(ph), graphics(gr), scene_graph(sg){
}
EventHandler::~EventHandler(){}

/**
	 * TODO: Function mainLoop() implementation:
	 * 1. get the SDL events
	 * 2. process the SDL events (send the physics object physics events
	 *    and possibly the graphics object some also)
	 * 3. delay a few milliseconds
	 * 4. repeat
	 * 
	 * if quit event, send stop signal to phys and graphics objects and return.
*/
int EventHandler::mainLoop(){
	GLuint oldTime = SDL_GetTicks();
	GLuint newTime;
	while(keepRunning()){
		newTime = SDL_GetTicks();
		if (newTime-oldTime <= 1000/EVENT_CHECK_RATE){
			SDL_Delay(1000/EVENT_CHECK_RATE-(newTime-oldTime));
			newTime=SDL_GetTicks();
		}
    	if (graphics.isInitialized()) handleEvents();
    	oldTime=newTime;
	}
	return 0;
}

void EventHandler::handleEvents(){
	SDL_Event event;
	while(SDL_PollEvent(&event) && keepRunning()){
		switch(event.type){
			case SDL_QUIT: stopThread(); break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
					default: break;
				}break;
			case SDL_KEYUP:
				switch(event.key.keysym.sym){
					default: break;
				}break;
		}
	}
}
