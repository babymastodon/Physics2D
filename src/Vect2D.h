#ifndef VECT2D_H
#define VECT2D_H

#define PI 3.14159265359
#include <cmath>
#include "Point.h"

/*!
 *	The Vect2D class represents a vector
 *	in 2D space.  
 */
class Vect2D{
	public:
	
		/*!
		 *	The Vect2D constructors can either take the change-in-x
		 *	and change-in-y values of the vector, or two points that 
		 *	the vector is to be in between (the firstpoint is the 
		 *	endpoint of the vector, the second is the head) or another 
		 *	vector that the new vector should be equal to.
		 */
		Vect2D(float setx=0, float sety=0);
		Vect2D(const Point& p1, const Point& p2);
		Vect2D(const Vect2D& other);
		~Vect2D();
	
		/*!
		 *	The nomralize method adjusts the vectors magnitude one unit.
		 */
		void normalize();	
	
		/*!
		 *	The Vect2D class' operators use vector arithmatic to 
		 *	add or subtract a vector to or form the vector that 
		 *	the instance of the class represents.
		 */
		Vect2D& operator+(const Vect2D& other) const;
		Vect2D& operator-(const Vect2D& other) const;
		void operator+=(const Vect2D& other);
		void operator-=(const Vect2D& other);
	
		/*!
		 *	The scale method slales the vector represented by the 
		 *	instance of the class by the given value.
		 */
		void scale(float n);
	
		/*!
		 *	The set method sets the x and y values of the vector.
		 *	This can be done by passing the method two floats 
	     *	containing the disired x and y values, or two point 
		 *	that the vector goes between, or another vector that 
		 *	the instance of this vector should equal.
		 */
		void set(float x, float y);
		void set(const Point& p1, const Point& p2);
		void set(const Vect2D& other);
	
		/*!
		 *	The dot method returns the dot product of this vector
		 *	and the vector passed to the method.
		 */
		float dot(const Vect2D& other) const;
	
		/*!
		 *	The cross method returns the determinant of this vector
		 *	and the vector passed to the methed.
		 */
		float cross(const Vect2D& other) const;
		
		/*!
		 *	The mag method returns the magnitude of this vector.
		 */
		float mag() const;
	
		/*!
		 *	The floats x and y store the x and y values of the vector.	
		 */
		float x;
		float y;
};

#endif
