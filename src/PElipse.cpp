
#include "PElipse.h"

PElipse::PElipse(float x, float y, float w, float h,int ed) : PMovingObject(x,y,w,h) {
	edges = ed;
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
	glPushMatrix();
		glTranslatef(cornerx+width/2,cornery+height/2,0);
		glCallList(display_list);
	glPopMatrix();
}


