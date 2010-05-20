#include "Physics.h"
#include "Graphics.h"
#include "EventHandler.h"

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
	
	PMovingObject* object = new PRectangle(40,40,100,50);
	object->set_ay(-150);
	object->set_vx(100);
	object->set_vy(400);
	world.addObject(object);
	
	graphics.startThread();
	while (!graphics.isInitialized()) SDL_Delay(10);
	physics.startThread();
	event_handler.startThread();
	
	event_handler.waitForStop();
	return 0;
}
