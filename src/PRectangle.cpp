
#include "PRectangle.h"

PRectangle::PRectangle(float x, float y, float w, float h,int ed) : PMovingObject(x,y,w,h) 
{
	edges = ed;
}
void PRectangle::compileList()
{
	//float xaxis = width/2;
	//float yaxis = height/2;
	display_list = glGenLists(2);
	
	if (display_list!=0){
		glNewList(display_list,GL_COMPILE);
		glBegin(GL_TRIANGLE_FAN);
		glNormal3f(0,0,1);
		//Make sure it's counterclockwise (i fixed it)
		glVertex2f(0.0,0.0);
		glVertex2f(0, height);
		glVertex2f(width, height);
		glVertex2f(width, 0);
		glEnd();
		glEndList();
	}
}

void PRectangle::draw()
{
	glPushMatrix();
		glTranslatef(cornerx+width/2,cornery+height/2,0);
		glCallList(display_list);
	glPopMatrix();
}


