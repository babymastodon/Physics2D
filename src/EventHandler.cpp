#include "EventHandler.h"

EventHandler::EventHandler(Physics& ph, Graphics& gr) : Thread(), physics(ph), graphics(gr){
}
EventHandler::~EventHandler(){}

int EventHandler::mainLoop(){
	SDL_Delay(6000);
	return 0;
}
