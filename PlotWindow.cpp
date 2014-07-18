#include "PlotWindow.h"


PlotWindow::PlotWindow()
{
}


PlotWindow::~PlotWindow()
{
	destroy();
}

bool PlotWindow::create(GLuint width, GLuint height){

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;
	
	if (SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE, &wnd, &rndr) < 0)
		return false;

	ctx = SDL_GL_CreateContext(wnd);

	WIDTH = width;
	HEIGHT = height;
	loop = true;

	return true;
}

void PlotWindow::destroy(){
	SDL_DestroyRenderer(rndr);
	SDL_DestroyWindow(wnd);
	SDL_Quit();
}

void PlotWindow::input(){
	SDL_Event event;

	while (SDL_PollEvent(&event)){
		switch (event.type){
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym){
			case SDLK_UP:
				camera.moveForward(0.1);
				break;
			case SDLK_DOWN:
				camera.moveForward(-0.1);
				break;
			case SDLK_LEFT:
				camera.yaw(1);
				break;
			case SDLK_RIGHT:
				camera.yaw(-1);
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym){
			case SDLK_ESCAPE:
				loop = false;
				break;
			default:
				break;
			}
			break;

		case SDL_QUIT:
			loop = false;
			break;

		case SDL_MOUSEBUTTONDOWN:
			break;

		case SDL_MOUSEBUTTONUP:
			
			break;

		case SDL_MOUSEMOTION:
			
			break;

		case SDL_WINDOWEVENT:
			switch (event.window.event){
			case SDL_WINDOWEVENT_RESIZED:
				WIDTH = event.window.data1;
				HEIGHT = event.window.data2;
				setupView();
				break;
			}

		default:
			break;
		}
	}
}

void PlotWindow::render(){
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	camera.applyUpdates();

	glPushMatrix();
	glTranslatef(0, 0, -5);

		glBegin(GL_TRIANGLES);
			glColor3f(1, 0, 0);
			glVertex3d(-0.5, 0, 0);
			glColor3f(0, 1, 0);
			glVertex3d(0.5, 0, 0);
			glColor3f(0, 0, 1);
			glVertex3d(0, 1, 0);
		glEnd();
	glPopMatrix();
	
	SDL_GL_SwapWindow(wnd);
}

void PlotWindow::update(){
}

void PlotWindow::initOpenGL(){
	SDL_GL_SetSwapInterval(1);
	glClearColor(.25, .25, .25, 1);
	
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
}

void PlotWindow::setupView(){
	glViewport(0, 0, WIDTH, HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, double(WIDTH) / double(HEIGHT), 0.01, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void PlotWindow::display(){
	initOpenGL();
	setupView();

	while (loop){
		input();
		update();
		render();
		SDL_Delay(16);
	}

}