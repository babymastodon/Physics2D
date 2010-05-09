/*
 *  PEquilateralTriangle.cpp
 *  
 *
 *  Created by Nicholas Lima on 5/9/10.
 *  Copyright 2010 Phillips Exeter Academy. All rights reserved.
 *
 */

#include "PEquilateralTriangle.h"

PEquilateralTriangle::PEquilateralTriangle(float x, float y, float sidelength) : PMovingObject(x, y, sidelength, sidelength)
{
}

void PEquilateralTriangle::compileList()
{
	dislplay_list = glGenLists(3);
	
	if (display_list != 0) 
	{
		glNewList(display_list, GL_COMPILE);
		glBegin(GL_TRIANGLE_FAN);
		glNormal3f(0, 0, 1);
		glVertex2f(0.0, 0.0);
		glVertex2f(sidelength, 0.0);
		glVertex2f(sidelength / 2, Sqrt(3) * sidelength / 2)
		glEnd();
		glEndList();
	}
}

void PEquilateralTriangle::draw()
{
	glPushMatrix();
	glTranslatef(x, y, 0);
	glCallList(display_list);
	glPopMatrix();
}

