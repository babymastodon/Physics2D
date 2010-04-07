#include "Thread.h"

Thread::Thread(){
	quit=true;
	thread=NULL;
}

int Thread::threadFunc(void* data){
	return ((Thread*)data)->mainLoop();
}

void Thread::stop(){
	quit=true;
}

void Thread::start(){
	if (thread==NULL){
		quit=false;
		// Creates a separate thread to run the mainLoop function defined in this class
		thread = SDL_CreateThread(threadFunc,this);
	}
}

void Thread::waitForStop(){
	SDL_WaitThread(thread,NULL);
	thread = NULL;
}

bool Thread::keepRunning() {
	return !quit;
}
