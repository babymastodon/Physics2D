#include "Physics.h"


Physics::Physics(SceneGraph& world):Thread(),scene_graph(world){
}
Physics::~Physics(){}


int Physics::mainLoop(){
	GLuint oldTime = SDL_GetTicks();
	GLuint newTime;
	while(keepRunning()){
		newTime = SDL_GetTicks();
		if (newTime-oldTime <= P_REFRESH_TIME){
			SDL_Delay(P_REFRESH_TIME-(newTime-oldTime));
			newTime=SDL_GetTicks();
		}
		
		//lock graph and move objects
		scene_graph.lock();
		const deque<PObject*>& pobjects = scene_graph.getPObjects();
		for (deque<PObject*>::const_iterator it = pobjects.begin(); it != pobjects.end(); it++){
			(*it)->move(newTime-oldTime);
		}
		scene_graph.updateTree();
		scene_graph.unlock();
		
    	oldTime=newTime;
	}
	return 0;
}
/*
void Physics::LockQueue(){
	scene_graph.lock();
	}
	
void Physics::UnlockQueue(){
	scene_graph.unlock();
	}
	
bool Physics::isQueueLocked(){
	/// @todo Implement SceneGraph lock, unlock and isLocked functions.
	
	// return scene_graph.isLocked();
	}*/
