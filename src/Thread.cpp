#include "Thread.h"

Thread::Thread()
{
	quit_now=true;
	thread=NULL;
}

int Thread::threadFunc(void* data)
{
	return ((Thread*)data)->mainLoop();
}

void Thread::stopThread()
{
	quit_now=true;
}

void Thread::startThread()
{
	if (thread==NULL)
	{
		quit_now=false;
		// Creates a separate thread to run the mainLoop function defined in this class
		thread = SDL_CreateThread(threadFunc,this);
	}
}

void Thread::waitForStop()
{
	SDL_WaitThread(thread,NULL);
	thread = NULL;
}

bool Thread::keepRunning() 
{
	return !quit_now;
}
