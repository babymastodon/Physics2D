#include "PObject.h"

PObject::PObject()
{
	cornerx = 0;
	cornery = 0;
	width = 0;
	height = 0;
	mass = 1;
	momentInertia = 1;
	elasticity = 1;
	theta = 0;
	centerx = 0;
	centery = 0;
	vx = 0;
	vy = 0;
	dtheta = 0;
	last_cycle=0;
	num_vertices = 0;
}

PObject::~PObject()
{
	delete[] vertices;
}

int PObject::getNumVertices() const
{
	return num_vertices;
}

const Point* PObject::getVertices() const
{
	return vertices;
}

int PObject::getLastCycle() const
{
	return last_cycle;
}

void PObject::setLastCycle(int cycle)
{
	last_cycle = cycle;
}

float PObject::get_cornerx() const
{
	return cornerx;
}

float PObject::get_cornery() const
{
	return cornery;
}

float PObject::get_width() const
{
	return width;
}

float PObject::get_height() const
{
	return height;
}

float PObject::get_mass() const
{
	return mass;
}

float PObject::get_momentInertia() const
{
	return momentInertia;
}

float PObject::get_elasticity() const
{
	return elasticity;
}

float PObject::get_theta() const
{
	return theta;
}

float PObject::get_centerx() const
{
	return centerx;
}

float PObject::get_centery() const
{
	return centery;
}

float PObject::get_vx() const
{
	return vx;
}

float PObject::get_vy() const
{
	return vy;
}

float PObject::get_dtheta() const
{
	return dtheta;
}

void PObject::set_cornerx(float n)
{
	cornerx=n;
}

void PObject::set_cornery(float n)
{
	cornery=n;
}

void PObject::set_width(float n)
{
	width=n;
}

void PObject::set_height(float n)
{
	height=n;
}

void PObject::set_mass(float n)
{
	mass=n;
}

void PObject::set_momentInertia(float n)
{
	momentInertia=n;
}

void PObject::set_elasticity(float n)
{
	elasticity=n;
}

void PObject::set_theta(float n)
{
	theta=n;
}

void PObject::set_centerx(float n)
{
	centerx=n;
}

void PObject::set_centery(float n)
{
	centery=n;
}

void PObject::set_vx(float n)
{
	vx=n;
}

void PObject::set_vy(float n)
{
	vy=n;
}

void PObject::set_dtheta(float n)
{
	dtheta=n;
}

bool PObject::intersect(float x, float y, float w, float h) const
{
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

bool PObject::completelyInside(float x, float y, float w, float h) const
{
	return cornerx>x && cornery>y && cornerx+width<x+w && cornery<y+h;
}

bool PObject::intersect(const PObject* other) const
{
	return intersect(other->cornerx, other->cornery, other->width, other->height);
}

void PObject::move(GLint time){}

void PObject::applyImpulse(const Point& point, const Vect2D& impulse)
{
	Vect2D r(point.x-centerx, point.y-centery);
	dtheta += r.cross(impulse)/momentInertia;
	vx += impulse.x/mass;
	vy += impulse.y/mass;
}
