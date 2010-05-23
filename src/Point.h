#ifndef POINT_H
#define POINT_H

#define PI 3.14159265359

class Point
{
public:
	Point(float setx, float sety);
	~Point();
	
	float x;
	float y;
	
	viod translate(Point p, float dx, float dy);
}

#endif
