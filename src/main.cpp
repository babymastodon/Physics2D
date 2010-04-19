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
	SceneGraph world;
	Physics physics(world);
	Graphics graphics("Title",800,600,world);
	EventHandler event_handler(physics,graphics,world);
	
	physics.startThread();
	graphics.startThread();
	event_handler.startThread();
	
	event_handler.waitForStop();
	
	graphics.stopThread();
	physics.stopThread();
	graphics.waitForStop();
	physics.waitForStop();
	return 0;
}
