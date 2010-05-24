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
	
	float x;
	float y;
	float parametric;
	float parametric2;
	
	float vec1x;
	float vec1y;
	float vec1deltax;
	float vec1deltay;
	
	float vec2x;
	float vec2y;
	float vec2deltax;
	float vec2deltay;
	
	bool loopFlag = true;
	
	for (int i = 0; i < objects[0]->getNumVertices() && loopFlag; i++)
	{
		vec1x = obj1vertices[i].x;
		vec1y = obj1vertices[i].y;
		
		vec1deltax = obj1vertices[(i + 1) % objects[0]->getNumVertices()].x - vec1x;
		vec1deltay = obj1vertices[(i + 1) % objects[0]->getNumVertices()].y - vec1y;
		
		for (int j = 0; j < objects[1]->getNumVertices() && loopFlag; j++)
		{
			vec2x = obj2vertices[j].x;
			vec2y = obj2vertices[j].y;
			
			vec2deltax = obj2vertices[(j + 1) % objects[1]->getNumVertices()].x - vec2x;
			vec2deltay = obj2vertices[(j + 1) % objects[1]->getNumVertices()].y - vec2y;
			
			
			parametric = ((vec2deltax * (vec1y - vec2y)) - (vec2deltay * (vec1x - vec2x))) / ((vec1deltax * vec2deltay) - (vec2deltax * vec1deltay));
			parametric2 = ((vec1deltax * (vec1y - vec2y)) - (vec1deltay * (vec1x - vec2x))) / ((vec1deltax * vec2deltay) - (vec2deltax * vec1deltay));
			
			if (parametric <= 1 && parametric >= 0 && parametric2 <= 1 && parametric2 >= 0)
			{
				x = vec1x + (parametric * vec1deltax);
				y = vec1y + (parametric * vec1deltay);
				cout << "collision at " << x << " " << y << endl;
				trueCollision = true;
				loopFlag=false;
			}
		}
	}

	intersection.x = x;
	intersection.y = y;
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

