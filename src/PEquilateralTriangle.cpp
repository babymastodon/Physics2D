/*
 *  PEquilateralTriangle.cpp
 *  
 *
 *  Created by Nicholas Lima on 5/9/10.
 *  Copyright 2010 Phillips Exeter Academy. All rights reserved.
 *
 */

#include "PEquilateralTriangle.h"

PEquilateralTriangle::PEquilateralTriangle(float x, float y, float sidelength) : PMovingObject(x, y, sidelength, sqrt(3) * sidelength / 2)
{
}

void PEquilateralTriangle::compileList()
{
	display_list = glGenLists(3);
	
	if (display_list != 0) 
	{
		glNewList(display_list, GL_COMPILE);
		glBegin(GL_TRIANGLE_FAN);
		glNormal3f(0, 0, 1);
		glVertex2f(0.0, 0.0);
		glVertex2f(width, 0.0);
		glVertex2f(width / 2, height);
		glEnd();
		glEndList();
	}
}

void PEquilateralTriangle::draw()
{
	if (display_list==0) compileList();
	glPushMatrix();
	glTranslatef(cornerx, cornery, 0);
	glCallList(display_list);
	glPopMatrix();
}

bool PEquilateralTriangle::collides(PObject& other){
	return false;
}

void PEquilateralTriangle::resetGraphics(){
	display_list=0;
}
