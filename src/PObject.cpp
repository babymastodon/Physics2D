#include "PObject.h"

PObject::PObject(){
	last_cycle=0;
}
PObject::~PObject(){}

int PObject::getNumVertices() const{
	return num_vertices;
}

const Point* PObject::getVertices() const{
	return vertices;
}

int PObject::getLastCycle(){
	return last_cycle;
}
void PObject::setLastCycle(int cycle){
	last_cycle = cycle;
}
