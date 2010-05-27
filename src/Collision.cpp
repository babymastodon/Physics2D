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
	
	/*
	 * the following was written before the Vect2D class was written
	 * (and that's why it's so messy)
	 */
	Vect2D norm;
	Point p1,p2;
	
	const Point* obj1vertices = objects[0]->getVertices();
	const Point* obj2vertices = objects[1]->getVertices();
	int numPoints=0;
	float sumx=0;
	float sumy=0;
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
	
	/*
	 * x1+k*t = x2+c*k
	 * y1+b*t = y2+d*k
	 */
	
	for (int i = 0; i < objects[0]->getNumVertices(); i++)
	{
		vec1x = obj1vertices[i].x;//x1
		vec1y = obj1vertices[i].y;//y1
		
		vec1deltax = obj1vertices[(i + 1) % objects[0]->getNumVertices()].x - vec1x;//a
		vec1deltay = obj1vertices[(i + 1) % objects[0]->getNumVertices()].y - vec1y;//b
		
		for (int j = 0; j < objects[1]->getNumVertices(); j++)
		{
			vec2x = obj2vertices[j].x;//x2
			vec2y = obj2vertices[j].y;//y2
			
			vec2deltax = obj2vertices[(j + 1) % objects[1]->getNumVertices()].x - vec2x;//c
			vec2deltay = obj2vertices[(j + 1) % objects[1]->getNumVertices()].y - vec2y;//d
			
			denominator = (vec1deltax * vec2deltay) - (vec2deltax * vec1deltay);//ad-bc
			if (denominator != 0)
			{
				deltax = vec1x-vec2x;//x1-x2
				deltay = vec1y-vec2y;//y1-y2
				
				parametric = ((vec2deltax * (deltay)) - vec2deltay * (deltax)) / (denominator);//t
				parametric2 = ((vec1deltax * (deltay)) - vec1deltay * (deltax)) / (denominator);//k

				if (parametric <= 1 && parametric >= 0 && parametric2 <= 1 && parametric2 >= 0)
				{
					numPoints++;
					sumx += vec1x + (parametric * vec1deltax);//x = x1+a*t
					sumy += vec1y + (parametric * vec1deltay);//y = y1+b*t
					//uses the normal vector of the first collision
					if (!trueCollision){
						/* old way of finding
						//figure out which one collided on the corner
						if (abs(parametric2-.5) < abs(parametric-.5)){
							//vector1's point of collision was closer to the corner
							norm.set(vec2deltay,-vec2deltax);
						}
						else
						{
							norm.set(vec2deltax,-vec2deltay);
						}*/
						//VERY crude approximation for normal vector at collision point
						norm.set(objects[1]->get_centerx()-objects[0]->get_centerx(), objects[1]->get_centery()-objects[0]->get_centery());
						norm.normalize();
					}
					trueCollision = true;
				}
			}
		}
	}
	if (trueCollision)
	{
		intersection.x = sumx/numPoints;
		intersection.y = sumy/numPoints;
		//calculate impulse here
		float e = objects[0]->get_elasticity()*objects[1]->get_elasticity();
		Vect2D r1(intersection.x-objects[0]->get_centerx(), intersection.y-objects[0]->get_centery());
		Vect2D r2(intersection.x-objects[1]->get_centerx(), intersection.y-objects[1]->get_centery());
		//vap = vcenter + w x r1 where w is angular velocity vector that points into screen
		//vap = velocity of point of collision on each object
		Vect2D vap(objects[0]->get_vx()-objects[0]->get_dtheta()*r1.y, objects[0]->get_vy()+objects[0]->get_dtheta()*r1.x);
		Vect2D vbp(objects[1]->get_vx()-objects[1]->get_dtheta()*r2.y, objects[1]->get_vy()+objects[1]->get_dtheta()*r2.x);
		Vect2D& vabp = vap-vbp;
		float ran = r1.cross(norm);
		float rbn = r2.cross(norm);
		//source: http://www.myphysicslab.com/collision.html
		float j= (-(1+e)*vabp.dot(norm))/(1/objects[0]->get_mass() + 1/objects[1]->get_mass() + ran*ran/objects[0]->get_momentInertia() + rbn*rbn/objects[1]->get_momentInertia());
		
		impulse.set(norm);
		impulse.scale(j);
		
		cout << "collision at " << intersection.x << " " << intersection.x << endl;
		cout << j << endl;
		cout << "impulse = " << impulse.x << " " << impulse.y << endl;
	}
}

Collision::~Collision(){}

PObject* Collision::get_object1() const
{
	return objects[0];
}

PObject* Collision::get_object2() const
{
	return objects[1];
}

const Point& Collision::get_pointOf() const
{
	return intersection;
}

bool Collision::isTrueCollision() const
{
	return trueCollision;
}

const Vect2D& Collision::get_impulse() const
{
	return impulse;
}
