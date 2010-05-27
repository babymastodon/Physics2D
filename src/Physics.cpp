#include "Physics.h"

Physics::Physics(SceneGraph& world):Thread(),scene_graph(world)
{
	pause_flag = false;
}

Physics::~Physics(){}

int Physics::mainLoop()
{
	GLuint oldTime = SDL_GetTicks();
	GLuint newTime;
	while(keepRunning())
	{
		newTime = SDL_GetTicks();
		if (newTime-oldTime <= P_REFRESH_TIME)
		{
			SDL_Delay(P_REFRESH_TIME-(newTime-oldTime));
			newTime=SDL_GetTicks();
		}
		int dtime = newTime-oldTime;
		//lock graph and move objects
		if (!pause_flag)
		{
			scene_graph.lock();
			const deque<PObject*>& pobjects = scene_graph.getPObjects();

			for (deque<PObject*>::const_iterator it = pobjects.begin(); it != pobjects.end(); it++)
			{
				(*it)->move(dtime);
			}
			scene_graph.updateTree();
			list<Collision*>& collisions = scene_graph.possibleCollisions();
			for (list<Collision*>::iterator it = collisions.begin(); it != collisions.end(); it++)
			{
				Collision& coll = *(*it);
				if (coll.isTrueCollision())
				{
					const Vect2D& impulse = coll.get_impulse();
					Vect2D rev_impulse(-impulse.x, -impulse.y);
					coll.get_object1()->applyImpulse(coll.get_pointOf(),impulse);
					coll.get_object2()->applyImpulse(coll.get_pointOf(),rev_impulse);
					//This will separate the two objects. (fail)
					/*while (true){
						coll.get_object1()->move(dtime);
						coll.get_object2()->move(dtime);
						Collision* collision = new Collision(coll.get_object1(),coll.get_object2());
						bool stillColliding = collision->isTrueCollision();
						delete collision;
						if (!stillColliding){
							break;
						}
					}*/
				}
			}
			scene_graph.unlock();
		}
		
    	oldTime=newTime;
	}
	return 0;
}

void Physics::pause()
{
	pause_flag = true;
}

void Physics::unpause()
{
	pause_flag = false;
}

void Physics::togglePause()
{
	pause_flag = !pause_flag;
}
