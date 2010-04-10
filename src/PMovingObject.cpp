
#include "PMovingObject.h"
#include <iostream>
using namespace std;


PMovingObject::PMovingObject(float x, float y, float w, float h, float dx, float dy, float ddx, float ddy) : PObject()
{
	cornerx=x;
	cornery=y;
	vx=dx;
	vy=dy;
	width=w;
	height=h;
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
	vx +=ax*time_scale;
	vy += ay*time_scale;
	cornerx += vx*time_scale;
	cornery += vy*time_scale;
	cout << "moved to " << cornerx << " " << cornery << endl;
}


bool PMovingObject::intersect(float x, float y, float w, float h){
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

bool PMovingObject::contains(float x, float y){
	return x>cornerx && y>cornery && x<cornerx+width && y<cornery+height;
}
bool PMovingObject::collides(PObject& other){
	/*
	 * subclasses should override this function so that it doesn't
	 * merely check the bounding rectangles.
	 */
	return other.intersect(cornerx,cornery,width,height);
}
