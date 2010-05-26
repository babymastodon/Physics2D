#ifndef VECT2D_H
#define VECT2D_H

#define PI 3.14159265359
#include <cmath>
#include "Point.h"

class Vect2D{
public:
	Vect2D(float setx=0, float sety=0);
	Vect2D(const Point& p1, const Point& p2);
	Vect2D(const Vect2D& other);
	~Vect2D();
	
	//become unit length;
	void normalize();
	Vect2D& operator+(const Vect2D& other) const;
	Vect2D& operator-(const Vect2D& other) const;
	void operator+=(const Vect2D& other);
	void operator-=(const Vect2D& other);
	void scale(float n);
	void set(float x, float y);
	void set(const Point& p1, const Point& p2);
	void set(const Vect2D& other);
	float dot(const Vect2D& other) const;
	//since it is 2D, it merely takes the determinant |[[this],[other]]| (the z coordinate of the cross product)
	float cross(const Vect2D& other) const;
	
	
	float x;
	float y;
};

#endif
