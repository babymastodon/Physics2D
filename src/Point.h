#ifndef POINT_H
#define POINT_H

#define PI 3.14159265359

class Point
{
public:
	Point(float setx=0, float sety=0);
	~Point();
	
	float x;
	float y;
	
	void translate(float dx, float dy);
};

#endif
