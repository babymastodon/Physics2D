#include "Point.h"

Point::Point(float setx, float sety)
{
	x = setx;
	y = sety;
}

Point::~Point(){}

void Point:: translate(Point p, float dx, float dy)
{
	p.x += dx;
	p.y += dy;
}
