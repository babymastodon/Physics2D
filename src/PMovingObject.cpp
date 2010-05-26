
#include "PMovingObject.h"
#include <iostream>
using namespace std;


PMovingObject::PMovingObject(float x, float y, float w, float h, float th, float dx, float dy, float dth, float ddx, float ddy) : PObject(x-w/2,y-h/2,w,h){
	vx=dx;
	vy=dy;
	ax=ddx;
	ay=ddy;
	centerx = x;
	centery = y;
	theta = th;
	dtheta = dth;
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

void PMovingObject::move(GLuint time){
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
		float cost = cos(theta*PI/180);
		float sint = sin(theta*PI/180);
		for (int i=0; i<num_vertices; i++){
			returnVertices[i].x = vertices[i].x*cost+centerx;
			returnVertices[i].y = vertices[i].y*sint+centery;
		}
		recalculateVertices = false;
	}
	return returnVertices;
}
