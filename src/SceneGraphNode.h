#ifndef SCENEGRAPHNODE_H
#define SCENEGRAPHNODE_H

#include "GraphicsObject.h"
#include "PhysicsObject.h"

class SceneGraphNode{
	public:
		SceneGraphNode(GraphicsObject* g, PhysicsObject* physics);
		~SceneGraphNode();
		
		GraphicsObject* getGraphicsObject();
		PhysicsObject* getPhysicsObject();
		
		void draw();
		
	private:
		GraphicsObject* graphics_object;
		PhysicsObject* physics_object;
};

#endif
