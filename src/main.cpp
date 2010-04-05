#include "Physics.h"
#include "Graphics.h"
#include "EventHandler.h"

int main(int argc, char** argv)
{
	SceneGraph world;
	Physics physics(world);
	Graphics graphics("Title",800,600,world);
	EventHandler event_handler(physics,graphics);
	
	physics.start();
	graphics.start();
	event_handler.start();
	
	event_handler.waitForStop();
	
	graphics.stop();
	physics.stop();
	graphics.waitForStop();
	physics.waitForStop();
	return 0;
}
