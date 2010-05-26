#ifndef POINT_H
#define POINT_H

#define PI 3.14159265359

/*!
 *	The point class represents a point in 2D space.
 */
class Point
{
	
	public:
	
		/*!
		 *	The Point constructor sets the initial values
		 *	of the Point's x and y coordinates.
		 */
		Point(float setx=0, float sety=0);
		~Point();
	
		float x;
		float y;
	
};

#endif
