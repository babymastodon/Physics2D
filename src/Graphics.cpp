#include "Graphics.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>

using namespace std;

Graphics::Graphics(const char* name, int w, int h){
	SDL_Init(SDL_INIT_VIDEO);
	const SDL_VideoInfo* info = NULL;
	info = SDL_GetVideoInfo();
	//SDL_Surface *icon = SDL_LoadBMP("icon.bmp");
	SDL_WM_SetCaption(name,name);
	//SDL_WM_SetIcon(icon,NULL);
	SDL_SetVideoMode(w,h,info->vfmt->BitsPerPixel,SDL_OPENGL);
	SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
	
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_SMOOTH);
    
    GLfloat specColor0[] = {1,1,1,0};
    GLfloat diffColor0[] = {.5,.5,1,0};
    GLfloat lightPos0[] = {1,1,1,0};
    GLfloat ambientColor[] = {0,0,0,1};
    
    glLightfv(GL_LIGHT0, GL_SPECULAR, specColor0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glClearColor(1,.6,.5,1);
    glColor3f(1,1,1);
    
    glViewport(0,0,w,h); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,(float)w/(float)h, .01, 1000);
    glMatrixMode(GL_MODELVIEW);
}

Graphics::~Graphics(){
	SDL_Quit();
}

void Graphics::gameLoop(){
	/*GLuint oldTime = SDL_GetTicks();
	GLuint newTime;
	while(!quit){
		newTime = SDL_GetTicks();
		if (newTime-oldTime <= 1000/fpsCap){
			SDL_Delay(1000/fpsCap-(newTime-oldTime));
			newTime=SDL_GetTicks();
		}
    	display();
    	
    	oldTime=newTime;
	}*/
	display();
	SDL_Delay(5000);
}

void Graphics::display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GLfloat lightPos0[] = {0,0,0,1};
    
    glLoadIdentity();
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos0);
    glPushMatrix();
    	glTranslatef(0,0,-10);
	glPopMatrix();
    
    SDL_GL_SwapBuffers();
}
