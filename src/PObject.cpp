#include "PObject.h"

PObject::PObject(){
}
PObject::~PObject(){}

int PObject::getNumVertices() const{
	return num_vertices;
}

const Point* PObject::getVertices() const{
	return vertices;
}
