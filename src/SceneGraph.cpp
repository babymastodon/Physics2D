#include "SceneGraph.h"

SceneGraph::SceneGraph(int width, int height){
	worldWidth = width;
	worldHeight = height;
	mutex = SDL_CreateMutex();
	
	root_node = new WorldTreeNode::WorldTreeNode(0,0, width, height);
	update_cycle=0;
	
	last.x=0;
	last.y=0;
}
SceneGraph::~SceneGraph(){
	SDL_DestroyMutex(mutex);
	delete root_node;
}

void SceneGraph::addObject(PObject* addthis){
	root_node->add(addthis);
}

void SceneGraph::removeObject(PObject* removethis){
	root_node->remove(removethis);
}

void SceneGraph::lock() const{
	SDL_mutexP(mutex);
}

void SceneGraph::unlock() const{
	SDL_mutexV(mutex);
}

const deque<PObject*>& SceneGraph::getPObjects() const{
	return root_node->getElements();
}

void SceneGraph::updateTree(){
	root_node->update(++update_cycle);
}

void SceneGraph::drawTree(){
	root_node->draw();
}

list<Collision*> & SceneGraph::possibleCollisions(){
	list<Collision*> *collisions = new list<Collision*>();
	root_node->addPossibleCollisions(*collisions);
	return *collisions;
}
