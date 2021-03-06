#include "PEquilateralTriangle.h"

PEquilateralTriangle::PEquilateralTriangle(float x, float y, float sidelength, float m) : PMovingObject(x, y, sidelength, sqrt(3) * sidelength / 2)
{
	num_vertices = 3;
	vertices = new Point[num_vertices];
	returnVertices = new Point[num_vertices];
	vertices[0].x = -sidelength/2;
	vertices[0].y = -1.0/3*height;
	vertices[1].x = sidelength/2;
	vertices[1].y = -1.0/3*height;
	vertices[2].x = 0;
	vertices[2].y = 2.0/3*height;
	
	display_list = 0;
	mass = m;
	//someone check the math, I might have messed up the integral
	momentInertia = mass*sidelength*sidelength/8;
}

void PEquilateralTriangle::compileList()
{
	display_list = glGenLists(1);
	
	if (display_list != 0)
	{
		glNewList(display_list, GL_COMPILE);
			glBegin(GL_TRIANGLES);
			glNormal3f(0, 0, 1);
			glColor3f(.9,.3,.5);
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
	glRotatef(theta*180/PI,0,0,1);
	glCallList(display_list);
	glPopMatrix();
}

void PEquilateralTriangle::resetGraphics()
{
	display_list=0;
}
