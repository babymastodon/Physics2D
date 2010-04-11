#include "Physics.h"

Physics::Physics(SceneGraph& world):Thread(),scene_graph(world){
}
Physics::~Physics(){}


int Physics::mainLoop(){
	GLuint oldTime = SDL_GetTicks();
	GLuint newTime;
	while(keepRunning()){
		newTime = SDL_GetTicks();
		if (newTime-oldTime <= 1000/P_REFRESH_RATE){
			SDL_Delay(1000/P_REFRESH_RATE-(newTime-oldTime));
			newTime=SDL_GetTicks();
		}
    	//GLuint delta_time = newTime-oldTime;
    	
    	//lock and update the scene graph
    	
    	oldTime=newTime;
	}
	return 0;
}

void Physics::LockQueue(){
	scene_graph.lock();
	}
	
void Physics::UnlockQueue(){
	scene_graph.unlock();
	}
	
bool Physics::isQueueLocked(){
	/// @todo Implement SceneGraph lock, unlock and isLocked functions.
	
	// return scene_graph.isLocked();
	}
