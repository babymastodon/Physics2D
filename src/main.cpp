#include "Physics.h"
#include "Graphics.h"
#include "EventHandler.h"

#include "PRectangle.h"
#include "PElipse.h"
#include "PEquilateralTriangle.h"

#include <iostream>
using namespace std;

/**
	@mainpage Physics2D - A project to simulate physical interactions of two dimensional objects
	@version 1.0 Pre-Alpha Release
	@author Zack Drach
	@author Nicholas Lima
	@date Tuesday, April 6, 2010
*/

int main(int argc, char* argv[])
{
	
	SceneGraph world(800,600);
	Physics physics(world);
	Graphics graphics("Fun with Shapes",800,600,world);
	EventHandler event_handler(physics,graphics,world);
	
	PMovingObject* object = new PRectangle(100,320,50,50);
	object->set_ay(0);
	object->set_vx(50);
	object->set_vy(0);
	world.addObject(object);
	
	object = new PRectangle(400,300,50,50);
	object->set_ay(0);
	object->set_vx(-50);
	object->set_vy(0);
	world.addObject(object);
	
	event_handler.startThread();	
	event_handler.waitForStop();
	
	return 0;
}
