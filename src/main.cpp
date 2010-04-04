#include "Physics.h"
#include "Graphics.h"
#include "EventHandler.h"

int main(int argc, char** argv)
{
	Physics physics;
	Graphics graphics("Title",800,600,physics);
	EventHandler event_handler(physics,graphics);
	return 0;
}
