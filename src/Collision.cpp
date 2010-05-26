#include "Collision.h"
#include <iostream>

using namespace std;

Collision::Collision(PObject* obj1, PObject* obj2)
{
	cout << "new collision" << endl;
	trueCollision = false;
	
	objects = new PObject*[2];
	objects[0] = obj1;
	objects[1] = obj2;
	
	const Point* obj1vertices = objects[0]->getVertices();
	const Point* obj2vertices = objects[1]->getVertices();
	
	/*
	 * the following was written before the Vect2D class was written
	 * (and that's why it's so messy)
	 */
	float sumx=0;
	float sumy=0;
	int numPoints=0;
	float parametric;
	float parametric2;
	float denominator;
	
	float vec1x;
	float vec1y;
	float vec1deltax;//between this point and the next one in the shape (going counterclockwise)
	float vec1deltay;
	
	float vec2x;
	float vec2y;
	float vec2deltax;
	float vec2deltay;
	
	float deltax, deltay; //between the two points on different shapes
	Vect2D norm;
	
	for (int i = 0; i < objects[0]->getNumVertices(); i++)
	{
		
		vec1x = obj1vertices[i].x;
		vec1y = obj1vertices[i].y;
		
		vec1deltax = obj1vertices[(i + 1) % objects[0]->getNumVertices()].x - vec1x;
		vec1deltay = obj1vertices[(i + 1) % objects[0]->getNumVertices()].y - vec1y;
		
		for (int j = 0; j < objects[1]->getNumVertices(); j++)
		{
			vec2x = obj2vertices[j].x;
			vec2y = obj2vertices[j].y;
			
			vec2deltax = obj2vertices[(j + 1) % objects[1]->getNumVertices()].x - vec2x;
			vec2deltay = obj2vertices[(j + 1) % objects[1]->getNumVertices()].y - vec2y;
			
			denominator = (vec1deltax * vec2deltay) - (vec2deltax * vec1deltay);
			
			if (denominator != 0)
			{
				deltax = vec1x-vec2x;
				deltay = vec1y-vec2y;
				
				parametric = ((vec2deltax * (deltay)) - vec2deltay * (deltax)) / (denominator);
				parametric2 = ((vec1deltax * (deltay)) - vec1deltay * (deltax)) / (denominator);

				if (parametric <= 1 && parametric >= 0 && parametric2 <= 1 && parametric2 >= 0)
				{
					sumx += vec1x + (parametric * vec1deltax);
					sumy += vec1y + (parametric * vec1deltay);
					numPoints++;
					//uses the normal vector of the first collision
					if (!trueCollision){
						//figure out which one collided on the corner
						if (abs(parametric2-.5) < abs(parametric-.5)){
							//vector1's point of collision was closer to the corner
							norm.set(vec2deltay,-vec2deltax);
						}
						else{
							norm.set(vec2deltax,-vec2deltay);
						}
						norm.normalize();
					}
					trueCollision = true;
				}
			}
		}
	}
	if (trueCollision){
		intersection.x = sumx/numPoints;
		intersection.y = sumy/numPoints;
		//calculate impulse here
		float e = objects[0]->get_elasticity()*objects[1]->get_elasticity();
		Vect2D r1(intersection.x-objects[0]->get_centerx(), intersection.y-objects[0]->get_centery());
		Vect2D r2(intersection.x-objects[1]->get_centerx(), intersection.y-objects[1]->get_centery());
		//vap = vcenter + w x r1 where w is angular velocity vector that points into screen
		Vect2D vap(objects[0]->get_vx()-objects[0]->get_dtheta()*r1.y, objects[0]->get_vy()+objects[0]->get_dtheta()*r1.x);
		Vect2D vbp(objects[1]->get_vx()-objects[1]->get_dtheta()*r2.y, objects[1]->get_vy()+objects[1]->get_dtheta()*r2.x);
		Vect2D& vabp = vap-vbp;
		//float j=
		
		cout << "collision at " << intersection.x << " " << intersection.x << endl;
	}
}

Collision::~Collision(){}

PObject* Collision::get_object1() const{
	return objects[0];
}

PObject* Collision::get_object2() const{
	return objects[1];
}

const Point& Collision::get_pointOf() const{
	return intersection;
}

bool Collision::isTrueCollision() const
{
	return trueCollision;
}

const Vect2D& Collision::getimpulse() const{
	return impulse;
}
