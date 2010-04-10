#ifndef SCENE_GRAPH_H
#define SCENE_GRAPH_H

#include <SDL/SDL.h>
#include <deque>
#include "PObject.h"

using namespace std;

/**
 * The SceneGraph class contains a vector of PObjects, and serves
 * as a container for all of the objects in the world. It's different from the 
 * Graphics object in that it's not limited to the boundaries of the window.
 */

class SceneGraph{
	public:
		/*!
		 * SceneGraph constructor:
		 * 1) Populate pobj_list with PObject pointers
		 * 2) Generate the mutex for further use
		 */
		SceneGraph();
		/*!
		 * The SceneGraph destructor empties the p_object vector
		 * of any remaining PObjects (free the memory to avoid a memory leak)
		 * It also destroys the private mutex that it instantiated in the constructor
		 */
		~SceneGraph();
		/*!
		 * Wrappers for the SDL mutex P and V function
		 * Will lock and unlock the private mutex
		 * The sceneGraph must be explicitly locked before any of its
		 * functions are called. (however, the compiler won't catch any
		 * errors, so please remember to lock and unlock.) This is
		 * not the behavior of the java "Syncronized" functions, which
		 * automatically lock the object's mutex whenever a synchronized
		 * method is called.
		 * This is to allow the physics and graphics threads to complete
		 * processing before handing off the SceneGraph to each other.
		 * for more info, wikipedia: counting semaphore
		 */
		void lock() const;
		void unlock() const;
		
		/*!
		 * All of the accessor functions are declared const so
		 * that the graphics class can access them
		 */
		float getWorldWidth() const; ///< @return worldWidth A float representing the width of the SceneGraph
		float getWorldHeight() const; ///< @return worldWidth A float representing the width of the SceneGraph
	
	private:
	
		SDL_mutex* mutex;
		deque<PObject*> pobj_list;
		
		
		float worldWidth; ///< Width of the SceneGraph - Can be larger than window
		float worldHeight; ///< Height of the SceneGraph - Can be larger than window
};


#endif
