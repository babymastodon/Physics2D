#ifndef THREAD_H
#define THREAD_H

#include <SDL/SDL.h>

/*
 * A combination of the Java runnable interface + Thread class
 */

class Thread{
	public:
		Thread();
		void start();
		void stop();
		void waitForStop();
		
		
	protected:
		bool keepRunning();
	private:
		virtual int mainLoop() =0;
		static int threadFunc(void* data);
		
		/*
		 * Thread stops when quit == true
		 * Possible problem: the quit variable is not thread safe,
		 * but should be fine since it is rarely used
		 */
		bool quit;
		SDL_Thread* thread;
};
#endif
