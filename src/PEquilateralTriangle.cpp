#include "PEquilateralTriangle.h"
#include <iostream>
using namespace std;

PEquilateralTriangle::PEquilateralTriangle(float x, float y, float sidelength) : PMovingObject(x, y, sidelength, sqrt(3) * sidelength / 2)
{
	num_vertices = 3;
	vertices = new Point[num_vertices];
	returnVertices = new Point[num_vertices];
	cout << height << " " << sidelength << endl;
	vertices[0].x = -sidelength/2;
	vertices[0].y = -1.0/3*height;
	vertices[1].x = sidelength/2;
	vertices[1].y = -1.0/3*height;
	vertices[2].x = 0;
	vertices[2].y = 2.0/3*height;
	
	display_list = 0;
}

void PEquilateralTriangle::compileList()
{
	display_list = glGenLists(1);
	
	if (display_list != 0)
	{
		glNewList(display_list, GL_COMPILE);
			glBegin(GL_TRIANGLES);
			glNormal3f(0, 0, 1);
				for (int i=0; i<3; i++)
				{
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
	glTranslatef(centerx, centery, 0);
	glRotatef(theta,0,0,1);
	glCallList(display_list);
	glPopMatrix();
}

void PEquilateralTriangle::resetGraphics()
{
	display_list=0;
}
