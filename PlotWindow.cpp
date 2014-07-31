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
				break;
			case SDLK_DOWN:
				break;
			case SDLK_LEFT:
				break;
			case SDLK_RIGHT:
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
		case SDL_MOUSEWHEEL:
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
float rot = 0;

void PlotWindow::render(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();


	//Draw the "world":
	glRotatef(rot, 0, 1, 0);
	drawGrids();
	

	camera.applyView();
	rot += 1;
	SDL_GL_SwapWindow(wnd);
}

void PlotWindow::update(){
	
}

void PlotWindow::initOpenGL(){
	SDL_GL_SetSwapInterval(1);
	
}

void PlotWindow::setupView(){
	
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