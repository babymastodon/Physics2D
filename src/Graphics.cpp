#include "Graphics.h"

/**
 * Construct a new Graphics object with a name, width, height, and 
 * an assosciated SceneGraph object. Calls Thread constructor.
 * 
 * @param n Name of the main window
 * @param w Width of the main window
 * @param h Height of the main window
 * @param world A scenegraph reference that contains all of the PObjects in this world
 * 
 */
Graphics::Graphics(const char* n, int w, int h,SceneGraph& world) : Thread(), scene_graph(world){
	window_name = n;
	window_width = w;
	window_height = h;
	
	is_initialized = false;
}

bool Graphics::isInitialized(){
	return is_initialized;
}

/*!
 * Default Graphics Destructor;
 * No need to free memory: the SceneGraph was declared a reference
 */
Graphics::~Graphics(){
}

/*!
 *	The Graphics Initialization function
 * Initializes the OpenGL environment for two-dimensional
 * drawing, and sets up smooth lighting. Also initializes an
 * orthagonal projection.
 */
void Graphics::initWindow(){
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
    
    compileLists();
    
    is_initialized = true;
}

void Graphics::compileLists(){
	//compile the display list for all objects in the SceneGraph here
    //future objects must have their lists compiled before use however
    scene_graph.lock();
    const deque<PObject*>& pobjects = scene_graph.getPObjects();
    for (deque<PObject*>::const_iterator it = pobjects.begin(); it != pobjects.end(); it++){
		(*it)->compileList();
	}
    scene_graph.unlock();
}

void Graphics::quitWindow(){
	is_initialized = false;
	SDL_Quit();
}

int Graphics::mainLoop(){
	initWindow();
	compileLists();
	GLuint oldTime = SDL_GetTicks();
	GLuint newTime;
	while(keepRunning()){
		newTime = SDL_GetTicks();
		if (newTime-oldTime <= G_REFRESH_TIME){
			SDL_Delay(G_REFRESH_TIME-(newTime-oldTime));
			newTime=SDL_GetTicks();
		}
		
    	display();
    	oldTime=newTime;
	}
	
	quitWindow();
	
	return 0;
}

/**
 * Display function, which is responsible for translating to the origin,
 * and then calling the draw functions of the individual PObjects
 * in the world variable that are currently visible in the window.
 */
void Graphics::display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GLfloat lightPos0[] = {0,0,0,1};
    
    glLoadIdentity();
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos0);
    
    //move the viewport
    glTranslatef(-viewport_x,-viewport_y,0);
    
    //draw stuff
    
    scene_graph.lock();
    const deque<PObject*>& pobjects = scene_graph.getPObjects();
    for (deque<PObject*>::const_iterator it = pobjects.begin(); it != pobjects.end(); it++){
		(*it)->draw();
	}
    scene_graph.unlock();
    
    SDL_GL_SwapBuffers();
}
