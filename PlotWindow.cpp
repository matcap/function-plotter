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

	initOpenGL();

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

		default:
			break;
		}
	}
}

void PlotWindow::render(){
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	SDL_GL_SwapWindow(wnd);
	SDL_Delay(10);
}

void PlotWindow::update(){

}

void PlotWindow::initOpenGL(){
	SDL_GL_SetSwapInterval(1);
	glClearColor(.5, .2, .2, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

}

void PlotWindow::display(){

	while (loop){
		input();
		update();
		render();
		SDL_Delay(32);
	}

}