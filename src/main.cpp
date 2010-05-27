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
	
	PMovingObject* object = new PElipse(300,100,40, 60, 10);
	object->set_ay(-150);
	object->set_vx(40);
	object->set_vy(300);
	object->set_dtheta(.2);
	world.addObject(object);
	
	object = new PEquilateralTriangle(400,100,50);
	object->set_ay(-150);
	object->set_vx(-40);
	object->set_vy(300);
	object->set_dtheta(.1);
	world.addObject(object);
	
	event_handler.startThread();	
	event_handler.waitForStop();
	
	return 0;
}
