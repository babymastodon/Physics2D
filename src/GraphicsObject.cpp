#include "GraphicsObject.h"
#include <math.h>

#ifndef PI
#define PI 3.14159265359
#endif

GraphicsObject::GraphicsObject(const PhysicsObject& po) : physics_object(po){}
GraphicsObject::~GraphicsObject(){}

GCircle::GCircle(const PCircle& po, int edges, int col) : GraphicsObject(po){
	GLbyte red = GLbyte(col&0xff0000>>16);
	GLbyte green = GLbyte(col&0x00ff00>>8);
	GLbyte blue = GLbyte(col&0x0000ff);
	displayList = glGenLists(1);
	
	glNewList(displayList,GL_COMPILE);
		glPushMatrix();
			glTranslatef(physics_object.getx(),physics_object.gety(),0);
			glColor3b(red,green,blue);
			glBegin(GL_TRIANGLE_FAN);
				glVertex2f(0.0,0.0);
				for (int i=0; i<=edges; i++){
					float r=physics_object.getradius();
					glVertex2f(r*cos(2*PI*i/edges),-r*sin(2*PI*i/edges));
				}
			glEnd();
		glPopMatrix();
	glEndList();
}
GCircle::~GCircle(){
	glDeleteLists(displayList,1);
}

void GCircle::draw() const{
	glCallList(displayList);
}
