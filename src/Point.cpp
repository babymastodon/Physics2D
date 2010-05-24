#include "Point.h"

Point::Point(float setx, float sety)
{
	x = setx;
	y = sety;
}

Point::~Point(){}

void Point:: translate(float dx, float dy)
{
	x += dx;
	y += dy;
}
