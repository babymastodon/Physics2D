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
					trueCollision = true;
				}
			}
		}
	}
	if (trueCollision){
		intersection.x = sumx/numPoints;
		intersection.y = sumy/numPoints;
		cout << "collision at " << intersection.x << " " << intersection.x << endl;
	}
}

Collision::~Collision(){}

PObject** Collision::get_objects()
{
	return objects;
}

Point Collision::get_pointOf()
{
	return intersection;
}

bool Collision::isTrueCollision()
{
	return trueCollision;
}

