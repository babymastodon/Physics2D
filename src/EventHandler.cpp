#include "EventHandler.h"

EventHandler::EventHandler(Physics& ph, Graphics& gr, SceneGraph& sg) : Thread(), physics(ph), graphics(gr), scene_graph(sg)
{
	srand(static_cast<const int>(time(0)));
}
EventHandler::~EventHandler(){}

/**
	 * TODO: Function mainLoop() implementation:
	 * 1. get the SDL events
	 * 2. process the SDL events (send the physics object physics events
	 *    and possibly the graphics object some also)
	 * 3. delay a few milliseconds
	 * 4. repeat
	 * 
	 * if quit event, send stop signal to phys and graphics objects and return.
*/
int EventHandler::mainLoop()
{
	graphics.startThread();
	while (!graphics.isInitialized()) SDL_Delay(10);
	physics.startThread();
	
	GLuint oldTime = SDL_GetTicks();
	GLuint newTime;
	while(keepRunning()){
		newTime = SDL_GetTicks();
		if (newTime-oldTime <= EVENT_CHECK_TIME)
		{
			SDL_Delay(EVENT_CHECK_TIME-(newTime-oldTime));
			newTime=SDL_GetTicks();
		}
    	if (graphics.isInitialized()) handleEvents();
    	oldTime=newTime;
	}
	
	physics.stopThread();
	physics.waitForStop();
	graphics.stopThread();
	graphics.waitForStop();
	
	return 0;
}

void EventHandler::handleEvents()
{
	SDL_Event event;
	while(SDL_PollEvent(&event) && keepRunning())
	{
		switch(event.type)
		{
			case SDL_QUIT:
				stopThread();
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
			{
					case SDLK_p:
						physics.togglePause();
						break;
					case SDLK_q:
						stopThread();
						break;
					default:
						break;
				}break;
			case SDL_KEYUP:
				switch(event.key.keysym.sym)
			{
					default:
						break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch(event.button.button)
			{
					case SDL_BUTTON_LEFT:
						addRandomPMovingObject(event.button.x, graphics.getWindowHeight()-event.button.y);
						break;
					default: break;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				switch(event.button.button)
			{
					case SDL_BUTTON_LEFT:
						break;
					default:
						break;
				}
				break;
		}
	}
}

void EventHandler::addRandomPMovingObject(int x, int y)
{
	
	
	double randomness = rand() % 9;
	
	if (randomness <=3)
	{	
		PMovingObject* object = new PRectangle(x-5,y-5,30,80);
		object->set_ay(-150);
		object->set_vx(20);
		object->set_vy(300);
		//object->set_dtheta(.3);
		object->set_theta(0);
		scene_graph.lock();
		scene_graph.addObject(object);
		scene_graph.unlock();
	}
	else if (randomness > 3 && randomness <= 6)
	{
		PMovingObject* object = new PEquilateralTriangle(x-5,y-5,50);
		object->set_ay(-150);
		object->set_vx(20);
		object->set_vy(300);
		object->set_dtheta(.1);
		scene_graph.lock();
		scene_graph.addObject(object);
		scene_graph.unlock();
	}
	else if (randomness > 6)
	{
		PMovingObject* object = new PElipse(x-5,y-5,40, 60, 10);
		object->set_ay(-150);
		object->set_vx(20);
		object->set_vy(300);
		object->set_dtheta(.2);
		scene_graph.lock();
		scene_graph.addObject(object);
		scene_graph.unlock();
	}
}
