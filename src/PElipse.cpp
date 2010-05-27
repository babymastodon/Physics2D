
#include "PElipse.h"

PElipse::PElipse(float x, float y, float w, float h,int ed,float m) : PMovingObject(x,y,w,h) 
{
	edges = ed;
	display_list = 0;
	num_vertices = edges;
	float xaxis = width/2;
	float yaxis = height/2;
	vertices = new Point[num_vertices];
	returnVertices = new Point[num_vertices];
	for (int i = 0; i < edges; i++)
	{
		vertices[i].x=xaxis*cos(2*PI*i/edges);
		vertices[i].y=yaxis*sin(2*PI*i/edges);
	}
	mass = m;
	//again, probably didn't do the integral correctly
	momentInertia = mass*(3*pow(xaxis,4)+2*pow(xaxis,2)*pow(yaxis,2)+3*pow(yaxis,4))/(16*xaxis*yaxis);
}

void PElipse::compileList()
{
	display_list = glGenLists(1);
	
	if (display_list!=0)
	{
		glNewList(display_list,GL_COMPILE);
			glBegin(GL_TRIANGLE_FAN);
				glNormal3f(0,0,1);
				glColor3f(.4,.6,.8);
				glVertex2f(0.0,0.0);
				for (int i=0; i<=edges; i++)
				{
					glVertex2f(vertices[i%edges].x,vertices[i%edges].y);
				}
			glEnd();
		glEndList();
	}
}

void PElipse::draw()
{
	if (display_list == 0) compileList();
	glPushMatrix();
	glTranslatef(centerx,centery,0);
	glRotatef(theta*180/PI,0,0,1);
	glCallList(display_list);
	glPopMatrix();
}

void PElipse::resetGraphics()
{
	display_list=0;
}
