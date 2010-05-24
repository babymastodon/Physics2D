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
	num_vertices = 3;
	vertices = new Point[num_vertices];
	vertices[0].x=-sidelength/2;
	vertices[0].y= -1/3*height;
	vertices[1].x=sidelength/2;
	vertices[1].y= -1/3*height;
	vertices[2].x= 0;
	vertices[2].y = 2/3*height;
}

void PEquilateralTriangle::compileList()
{
	display_list = glGenLists(3);
	
	if (display_list != 0) 
	{
		glNewList(display_list, GL_COMPILE);
			glBegin(GL_TRIANGLES);
			glNormal3f(0, 0, 1);
				for (int i=0; i<3; i++){
					glVertex2f(vertices[i].x, vertices[i].y);
				}
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
