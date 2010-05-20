#include "SceneGraph.h"

SceneGraph::SceneGraph(int width, int height){
	worldWidth = width;
	worldHeight = height;
	mutex = SDL_CreateMutex();
	
	rootNode = new WorldTreeNode::WorldTreeNode(0,0, width, height);
}
SceneGraph::~SceneGraph(){
	SDL_DestroyMutex(mutex);
}

void SceneGraph::addObject(PObject* addthis){
	rootNode->add(addthis);
}

void SceneGraph::removeObject(PObject* removethis){
	rootNode->remove(removethis);
}

void SceneGraph::lock() const{
	SDL_mutexP(mutex);
}

void SceneGraph::unlock() const{
	SDL_mutexV(mutex);
}
