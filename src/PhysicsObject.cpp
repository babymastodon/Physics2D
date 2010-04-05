#include "PhysicsObject.h"

PhysicsObject::PhysicsObject(float x_, float y_, float r_){
	x = x_;
	y = y_;
	radius = r_;
}
PhysicsObject::~PhysicsObject(){}
float PhysicsObject::getradius() const{
	return radius;
}
float PhysicsObject::getx() const{
	return x;
}
float PhysicsObject::gety() const{
	return y;
}


PCircle::PCircle(float x_, float y_, float r_):PhysicsObject(x_,y_,r_){}
