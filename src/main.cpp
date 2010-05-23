#include "Physics.h"
#include "Graphics.h"
#include "EventHandler.h"

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
	Graphics graphics("Title",800,600,world);
	EventHandler event_handler(physics,graphics,world);
	
	for (int i=0; i<15; i++){
		PMovingObject* object = new PRectangle(200+30*i,40,10,10);
		object->set_ay(-150);
		object->set_vx(10-7*i);
		object->set_vy(400);
		world.addObject(object);
	}
	
	
	event_handler.startThread();	
	event_handler.waitForStop();
	
	return 0;
}
