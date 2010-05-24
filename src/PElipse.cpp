
#include "PElipse.h"

PElipse::PElipse(float x, float y, float w, float h,int ed) : PMovingObject(x,y,w,h) {
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
		vertices[i].y=-yaxis*sin(2*PI*i/edges);
	}
}

void PElipse::compileList(){
	float xaxis = width/2;
	float yaxis = height/2;
	display_list = glGenLists(1);
	
	if (display_list!=0){
		glNewList(display_list,GL_COMPILE);
			glBegin(GL_TRIANGLE_FAN);
				glNormal3f(0,0,1);
				glVertex2f(0.0,0.0);
				for (int i=0; i<=edges; i++){
					glVertex2f(xaxis*cos(2*PI*i/edges),-yaxis*sin(2*PI*i/edges));
				}
			glEnd();
		glEndList();
	}
}

void PElipse::draw(){
	if (display_list == 0) compileList();
	glPushMatrix();
		glTranslatef(cornerx+width/2,cornery+height/2,0);
		glCallList(display_list);
	glPopMatrix();
}

void PElipse::resetGraphics(){
	display_list=0;
}

const Point* PElipse::getVertices(){
	memcpy(returnVertices,vertices,num_vertices*sizeof(Point));
	for (int i=0; i<num_vertices; i++){
		returnVertices[i].translate(cornerx, cornery);
	}
	return returnVertices;
}
