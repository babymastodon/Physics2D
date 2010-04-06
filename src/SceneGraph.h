#ifndef SCENE_GRAPH_H
#define SCENE_GRAPH_H

#include <SDL/SDL.h>
#include <vector>
#include "PObject.h"

using namespace std;

class SceneGraph{
	public:
		/*
		 * remember to:
		 * create and destroy the mutex
		 * empty the list of physics objects when done
		 */
		SceneGraph();
		~SceneGraph();
		/*
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
		/*
		 * make sure that all of the accessor functions are const so
		 * that the graphics class can access them
		 */
		float getWorldWidth() const;
		float getWorldHeight() const;
	private:
		SDL_mutex* mutex;
		vector<PObject*> pobj_list;
		
		/*
		 * width and height of the virtual world
		 * note: the whole world will not necessarily fit on the whole
		 * screen.
		 */
		float worldWidth;
		float worldHeight;
};


#endif
