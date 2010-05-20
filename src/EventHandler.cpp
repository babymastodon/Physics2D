#include "EventHandler.h"

#include <iostream>
using namespace std;

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
	graphics.startThread();
	while (!graphics.isInitialized()) SDL_Delay(10);
	physics.startThread();
	
	GLuint oldTime = SDL_GetTicks();
	GLuint newTime;
	while(keepRunning()){
		newTime = SDL_GetTicks();
		if (newTime-oldTime <= EVENT_CHECK_TIME){
			SDL_Delay(EVENT_CHECK_TIME-(newTime-oldTime));
			newTime=SDL_GetTicks();
		}
    	if (graphics.isInitialized()) handleEvents();
    	oldTime=newTime;
	}
	
	physics.stopThread();
	physics.waitForStop();
	graphics.stopThread();
	graphics.waitForStop();
	
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
