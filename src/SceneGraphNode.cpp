#include "SceneGraphNode.h"

SceneGraphNode::SceneGraphNode(GraphicsObject* g, PhysicsObject* p){
	graphics_object = g;
	physics_object = p;
}
SceneGraphNode::~SceneGraphNode(){
	delete graphics_object;
	delete physics_object;
}

GraphicsObject* SceneGraphNode::getGraphicsObject(){
	return graphics_object;
}
PhysicsObject* SceneGraphNode::getPhysicsObject(){
	return physics_object;
}
