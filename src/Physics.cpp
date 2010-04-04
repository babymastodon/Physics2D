#include "Physics.h"

Physics::Physics(){}
Physics::~Physics(){}

const SceneGraph& Physics::getSceneGraph() const{
	return scene_graph;
}
