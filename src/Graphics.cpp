#include "Graphics.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>

Graphics::Graphics(const char* n, int w, int h, const Physics& ph) : Thread(), physics(ph){
	window_name = n;
	window_width = w;
	window_height = h;
}

Graphics::~Graphics(){
}

void Graphics::init(){
	SDL_Init(SDL_INIT_VIDEO);
	const SDL_VideoInfo* info = NULL;
	info = SDL_GetVideoInfo();
	//SDL_Surface *icon = SDL_LoadBMP("icon.bmp");
	SDL_WM_SetCaption(window_name,window_name);
	//SDL_WM_SetIcon(icon,NULL);
	SDL_SetVideoMode(window_width,window_height,info->vfmt->BitsPerPixel,SDL_OPENGL);
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
    
    //Should we do an orthagonal or 3D projection?   
    glViewport(0,0,window_width,window_height); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(45,(float)window_width/(float)window_height, .01, 1000);
    glOrtho(0,window_width,0,window_height,-1,1);
    glMatrixMode(GL_MODELVIEW);
}

int Graphics::mainLoop(){
	init();
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
	while(keepRunning()){
		display();
    	SDL_Delay(1000);
	}
	SDL_Quit();
	return 0;
}

void Graphics::display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GLfloat lightPos0[] = {0,0,0,1};
    
    glLoadIdentity();
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos0);
    
    //move the viewport
    glTranslatef(-viewport_x,-viewport_y,0);
    
    //draw stuff
    
    SDL_GL_SwapBuffers();
}

void Graphics::update(){
	//const SceneGraph& scene_graph = physics.getSceneGraph();
	//lock scene graph and update graphics objects
}
