#ifndef THREAD_H
#define THREAD_H

#include <SDL/SDL.h>

/*!
 * Thread class - a generic class for dealing with Threads in the Physics2D program
 * Slightly similar to the Java thread class; implements start, stop, and waitForStop methods.
 * 
 */

class Thread{
	public:
	
		/**
		 * Default Thread constructor
		 * The thread is initialized to null, and 
		 * is represented through an SDL_Thread pointer
		 */
		Thread();
		
		void startThread(); ///< Function that starts the SDL_Thread. Only starts if thread == NULL
		void stopThread(); 
		void waitForStop(); ///< Waits for the current thread to finish, then clears thread pointer
		
		
	protected:
		/**
		 * function keepRunning()
		 * @return !quit The boolean variable that determines whether the thread has completed execution
		 */
		bool keepRunning();
	
	private:
	
		/// The mainLoop function contains the instructions for the main loop in the Thread
		
		virtual int mainLoop() =0;
		
		/**
		 * threadFunc used as a hack to call the mainLoop of a thread
		 * @param data A pointer to the Thread object, casted to the generic (void*) datatype
		 * @return none
		 */
		static int threadFunc(void* data);
		
		/*!
		 * Thread stops when quit_now
		 * Possible problem: the quit_now variable is not thread safe,
		 * but should be fine since it is rarely used
		 */
		bool quit_now;
		SDL_Thread* thread;
};
#endif
