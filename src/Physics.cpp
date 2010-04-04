#include "Physics.h"

Physics::Physics():Thread(){
}
Physics::~Physics(){}

const SceneGraph& Physics::getSceneGraph() const{
	return scene_graph;
}

int Physics::mainLoop(){
	while(keepRunning()){
    	SDL_Delay(1000);
	}
	return 0;
}
