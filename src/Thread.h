#ifndef THREAD_H
#define THREAD_H

#include <SDL/SDL.h>

/*!
 *	Thread class - a generic class for dealing with Threads in the Physics2D program
 *	Slightly similar to the Java thread class; implements start, stop, and waitForStop 
 *	methods.
 */
class Thread
{
	public:
	
		/*!
		 *  The Default Thread constructor initializes the thred
		 *	to null, and is represented through an SDL_Thread pointer.
		 */
		Thread();
		
		/*!
		 *	The startThread method starts the current thread,
		 *	but only if thread == null.
		 */
		void startThread();
	
		/*!
		 *	The stopThread method stops pauses the current thread.
		 */
		void stopThread(); 
	
		/*!
		 *	The waitForStop method waits for the current thread to 
		 *	finish then clearls the thread pointer.
		 */
		void waitForStop();		
		
	protected:
	
		/*!
		 *	The keepRunning method returns !quit, The boolean variable
		 *	that determines whether the thread has completed execution.
		 */
		bool keepRunning();
	
	private:
	
		/*!
		 *	The mainLoop method contains the instructions for the main loop
		 *	of the Thread.
		 */
		virtual int mainLoop() =0;
		
		/*!
		 *	The threadFunc method is used as a hack to call the mainLoop of a thread.
		 *	@param data A pointer to the Thread object, casted to the generic (void*) datatype.
		 *	@return none
		 */
		static int threadFunc(void* data);
		
		/*!
		 *	Thread stops when quit_now == true.
		 */
		bool quit_now;
	
		/*!
		 *	the thread variable stores the current SDL_Thread.
		 */
		SDL_Thread* thread;
};

#endif
