#include "Physics.h"


Physics::Physics(SceneGraph& world):Thread(),scene_graph(world){
	pause_flag = false;
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
		if (!pause_flag){
			scene_graph.lock();
			const deque<PObject*>& pobjects = scene_graph.getPObjects();
			for (deque<PObject*>::const_iterator it = pobjects.begin(); it != pobjects.end(); it++){
				(*it)->move(newTime-oldTime);
			}
			scene_graph.updateTree();
			list<Collision*>& collisions = scene_graph.possibleCollisions();
			scene_graph.unlock();
		}
		
    	oldTime=newTime;
	}
	return 0;
}

void Physics::pause(){
	pause_flag = true;
}
void Physics::unpause(){
	pause_flag = false;
}
void Physics::togglePause(){
	pause_flag = !pause_flag;
}
