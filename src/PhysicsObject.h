#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

class PhysicsObject{
	public:
		PhysicsObject(float x_, float y_, float r_);
		~PhysicsObject();
		
		/*
		 * x and y refer to the center of the bounding square
		 * since the object can rotate, the center of mass will be the
		 * center of the square. therefore, the radius of the square
		 * will be the distance from the center of mass to the
		 * point furthest away from the center of mass. Ex: a rect of
		 * 8x2 will have a bounding square radius of sqrt(4^2+1^2).
		 * if the center of mass were the bottom left corner of the
		 * rect, the square radius would be sqrt(8^2+2^2).
		 */
		float getx() const;
		float gety() const;
		float getradius() const;
	protected:
		float radius,x,y;
};

//add all the subclasses for the physics object

class PCircle: public PhysicsObject{
	public:
		PCircle(float x_, float y_, float r_);
	private:
};

#endif
