
#include "PMovingObject.h"
#include <iostream>
using namespace std;


PMovingObject::PMovingObject(float x, float y, float w, float h, float dx, float dy, float ddx, float ddy) : PObject(x,y,w,h)
{
	vx=dx;
	vy=dy;
	ax=ddx;
	ay=ddy;
}

void PMovingObject::set_ax(float n){
	ax=n;
}
void PMovingObject::set_ay(float n){
	ay=n;
}
void PMovingObject::set_vx(float n){
	vx=n;
}
void PMovingObject::set_vy(float n){
	vy=n;
}
float PMovingObject::get_ax() const{
	return ax;
}
float PMovingObject::get_ay() const{
	return ay;
}
float PMovingObject::get_vx() const{
	return vx;
}
float PMovingObject::get_vy() const{
	return vy;
}

void PMovingObject::move(GLuint time){
	float time_scale = time/1000.0; //convert time from milliseconds to seconds
	// This version of the velocity change provides a slightly better approximation to Newtonian motion
	float dvx = ax*time_scale/2;
	float dvy = ay*time_scale/2;
	vx +=dvx;
	vy += dvy;
	cornerx += vx*time_scale;
	cornery += vy*time_scale;
	vx +=dvx;
	vy += dvy;
	//cout << "moved to " << cornerx << " " << cornery << endl;
}

bool PMovingObject::collides(PObject& other){
	/*
	 * subclasses should override this function so that it doesn't
	 * merely check the bounding rectangles.
	 */
	return other.intersect(cornerx,cornery,width,height);
}

bool PMovingObject::contains(float x, float y){
	return x>cornerx && y>cornery && x<cornerx+width && y<cornery+height;
}
