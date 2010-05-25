
#include "PRectangle.h"

PRectangle::PRectangle(float x, float y, float w, float h) : PMovingObject(x,y,w,h) 
{
	display_list = 0;
	num_vertices = 4;
	vertices = new Point[num_vertices];
	returnVertices = new Point[num_vertices];
	float w2 = width/2;
	float h2 = height/2;
	vertices[0].x = -w2;
	vertices[0].y = -h2;
	vertices[1].x = w2;
	vertices[1].y = -h2;
	vertices[2].x = w2;
	vertices[2].y = h2;
	vertices[3].x = -w2;
	vertices[3].y = h2;
}
void PRectangle::compileList(){
	display_list = glGenLists(1);
	
	if (display_list!=0){
		glNewList(display_list,GL_COMPILE);
		glBegin(GL_TRIANGLE_FAN);
			glNormal3f(0,0,1);
			//it's ok now
			for (int i=0; i<4; i++){
				glVertex2f(vertices[i].x, vertices[i].y);
			}
		glEnd();
		glEndList();
	}
}

void PRectangle::draw()
{
	if (display_list==0) compileList();
	glPushMatrix();
		glTranslatef(centerx,centery,0);
		glRotatef(theta,0,0,1);
		glCallList(display_list);
	glPopMatrix();
	//std::cout << "drew rect at " << cornerx << " " << cornery << std::endl;
}

void PRectangle::resetGraphics(){
	display_list = 0;
}

/*void PRectangle::move(GLuint time){
	((PMovingObject*)this)->move(time);
	memcpy(returnVertices,vertices,4*sizeof(Point));
	for (int i=0; i<4; i++){
		returnVertices[i].translate(cornerx, cornery);
	}
}*/
