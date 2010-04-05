#include "Physics.h"

Physics::Physics(SceneGraph& world):Thread(),scene_graph(world){
}
Physics::~Physics(){}


int Physics::mainLoop(){
	while(keepRunning()){
    	SDL_Delay(1000);
	}
	return 0;
}
