#include "Vect2D.h"

Vect2D::Vect2D(float setx, float sety){
	x = setx;
	y = sety;
}

Vect2D::Vect2D(const Point& p1, const Point& p2){
	x = p2.x-p1.x;
	y = p2.y-p1.y;
}

Vect2D::Vect2D(const Vect2D& other){
	x = other.x;
	y = other.y;
}

void Vect2D::normalize(){
	float mag = sqrt(x*x+y*y);
	x/=mag;
	y/=mag;
}
Vect2D& Vect2D::operator+(const Vect2D& other) const{
	Vect2D* tmp = new Vect2D(other);
	tmp->x+=x;
	tmp->y+=y;
	return *tmp;
}
Vect2D& Vect2D::operator-(const Vect2D& other) const{
	Vect2D* tmp = new Vect2D(*this);
	tmp->x-=other.x;
	tmp->y-=other.y;
	return *tmp;
}
void Vect2D::operator+=(const Vect2D& other){
	x+=other.x;
	y+=other.y;
}
void Vect2D::operator-=(const Vect2D& other){
	x-=other.x;
	y-=other.y;
}
float Vect2D::dot(const Vect2D& other) const{
	return x*other.x+y*other.y;
}
float Vect2D::cross(const Vect2D& other) const{
	return x*other.y-y*other.x;
}
void Vect2D::set(float a, float b){
	x=a;
	y=b;
}
void Vect2D::set(const Point& p1, const Point& p2){
	x = p2.x-p1.x;
	y = p2.y-p1.y;
}
void Vect2D::set(const Vect2D& other){
	x = other.x;
	y = other.y;
}
void Vect2D::scale(float n){
	x/=n;
	y/=n;
}
Vect2D::~Vect2D(){}
