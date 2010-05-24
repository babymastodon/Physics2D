#include "PObject.h"

PObject::PObject(float x, float y, float w, float h){
	cornerx=x;
	cornery=y;
	width=w;
	height=h;
	last_cycle=0;
}
PObject::~PObject(){}

int PObject::getNumVertices() const{
	return num_vertices;
}

const Point* PObject::getVertices(){
	return vertices;
}

int PObject::getLastCycle(){
	return last_cycle;
}
void PObject::setLastCycle(int cycle){
	last_cycle = cycle;
}

bool PObject::intersect(float x, float y, float w, float h){
	if (cornerx>x){
		if (cornerx-x<w){
			if (cornery>y)
				return cornery-y<h;
			else
				return y-cornery<height;
		}
	}
	else{
		if (x-cornerx<width){
			if (cornery>y)
				return cornery-y<h;
			else
				return y-cornery<height;
		}
	}
	return false;
}

bool PObject::completelyInside(float x, float y, float w, float h){
	return cornerx>x && cornery>y && cornerx+width<x+w && cornery<y+h;
}

bool PObject::intersect(PObject* other){
	return intersect(other->cornerx, other->cornery, other->width, other->height);
}
