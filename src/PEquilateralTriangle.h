/*
 *  PEquilateralTriangle.h
 *  
 *
 *  Created by Nicholas Lima on 5/9/10.
 *
 */
#ifndef PEquilateralTriangle_H
#define PEquilateralTriangle_H

#include "PMovingObject.h"

class PEquilateralTriangle : public PMovingObject
{
public: 
	PEquilateralTriangle(float x, float y, float sidelength);
	virtual void draw();
	virtual void resetGraphics();
	virtual const Point* getVertices();
	
	virtual bool collides(PObject& other);
	
private:
	GLuint display_list;
	Point returnVertices[3];
	void compileList();
};
#endif
