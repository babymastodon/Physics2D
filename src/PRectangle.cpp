
#include "PRectangle.h"

PRectangle::PRectangle(float x, float y, float w, float h) : PMovingObject(x,y,w,h) 
{
	display_list = 0;
	num_vertices = 4;
	vertices = new Point[num_vertices];
	vertices[0] = new Point(x, y);
	vertices[1] = new Point(x + w, y);
	vertices[2] = new Point(x + w, y + h);
	vertices[4] = new Point(x, y + h);
}
void PRectangle::compileList()
{
	
	display_list = glGenLists(1);
	
	if (display_list!=0){
		glNewList(display_list,GL_COMPILE);
		glBegin(GL_TRIANGLE_FAN);
		glNormal3f(0,0,1);
		//it's ok now
		glVertex2f(0.0,0.0);
		glVertex2f(width, 0);
		glVertex2f(width, height);
		glVertex2f(0, height);
		glEnd();
		glEndList();
	}
}

void PRectangle::draw()
{
	if (display_list==0) compileList();
	glPushMatrix();
		glTranslatef(cornerx,cornery,0);
		glCallList(display_list);
	glPopMatrix();
	//std::cout << "drew rect at " << cornerx << " " << cornery << std::endl;
}

void PRectangle::resetGraphics(){
	display_list = 0;
}

