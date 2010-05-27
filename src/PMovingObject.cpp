
#include "PMovingObject.h"
#include <iostream>
using namespace std;


PMovingObject::PMovingObject(float x, float y, float w, float h, float th, float dx, float dy, float dth, float ddx, float ddy) : PObject(){
	vx=dx;
	vy=dy;
	ax=ddx;
	ay=ddy;
	centerx = x;
	centery = y;
	theta = th;
	dtheta = dth;
	cornerx = x-w/2;
	cornery = y-h/2;
	width = w;
	height = h;
	recalculateVertices = true;
}

void PMovingObject::set_ax(float n){
	ax=n;
}
void PMovingObject::set_ay(float n){
	ay=n;
}
float PMovingObject::get_ax() const{
	return ax;
}
float PMovingObject::get_ay() const{
	return ay;
}

void PMovingObject::move(GLint time){
	float time_scale = time/1000.0; //convert time from milliseconds to seconds
	vx +=ax*time_scale;
	vy += ay*time_scale;
	float vxt = vx*time_scale;
	float vyt = vy*time_scale;
	cornerx += vxt;
	cornery += vyt;
	centerx += vxt;
	centery += vyt;
	theta += dtheta*time_scale;
	recalculateVertices = true;
}

bool PMovingObject::contains(float x, float y) const{
	return x>cornerx && y>cornery && x<cornerx+width && y<cornery+height;
}

const Point* PMovingObject::getVertices() const{
	if (recalculateVertices){
		float cost = cos(theta);
		float sint = sin(theta);
		for (int i=0; i<num_vertices; i++){
			returnVertices[i].x = vertices[i].x*cost-vertices[i].y*sint+centerx;
			returnVertices[i].y = vertices[i].y*sint+vertices[i].y*cost+centery;
		}
		recalculateVertices = false;
	}
	return returnVertices;
}
