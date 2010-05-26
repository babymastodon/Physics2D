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

const Point* PObject::getVertices() const{
	return vertices;
}

int PObject::getLastCycle() const{
	return last_cycle;
}
void PObject::setLastCycle(int cycle){
	last_cycle = cycle;
}

float PObject::getcornerx() const{
	return cornerx;
}
float PObject::getcornery() const{
	return cornery;
}
float PObject::getwidth() const{
	return width;
}
float PObject::getheight() const{
	return height;
}
float PObject::getmass() const{
	return mass;
}
float PObject::getelasticity() const{
	return elasticity;
}
float PObject::gettheta() const{
	return theta;
}
float PObject::getcenterx() const{
	return centerx;
}
float PObject::getcentery() const{
	return centery;
}
float PObject::get_vx() const{
	return vx;
}
float PObject::get_vy() const{
	return vy;
}

void PObject::setcornerx(float n){
	cornerx=n;
}
void PObject::setcornery(float n){
	cornery=n;
}
void PObject::setwidth(float n){
	width=n;
}
void PObject::setheight(float n){
	height=n;
}
void PObject::setmass(float n){
	mass=n;
}
void PObject::setmomentInertia(float n){
	momentInertia=n;
}
void PObject::setelasticity(float n){
	elasticity=n;
}
void PObject::settheta(float n){
	theta=n;
}
void PObject::setcenterx(float n){
	centerx=n;
}
void PObject::setcentery(float n){
	centery=n;
}
void PObject::set_vx(float n){
	vx=n;
}
void PObject::set_vy(float n){
	vy=n;
}

bool PObject::intersect(float x, float y, float w, float h) const{
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

bool PObject::completelyInside(float x, float y, float w, float h) const{
	return cornerx>x && cornery>y && cornerx+width<x+w && cornery<y+h;
}

bool PObject::intersect(const PObject* other) const{
	return intersect(other->cornerx, other->cornery, other->width, other->height);
}
