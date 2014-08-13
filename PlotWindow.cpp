#include "PlotWindow.h"

PlotWindow::PlotWindow()
{
}


PlotWindow::~PlotWindow()
{
	destroy();
	delete renderer;
}

bool PlotWindow::create(GLuint width, GLuint height, string title){

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;
	
	if (SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE, &wnd, &rndr) < 0)
		return false;

	SDL_SetWindowTitle(wnd, title.c_str());
	ctx = SDL_GL_CreateContext(wnd);

	renderer = new OGLRenderer();
	renderer->camFocus.set(0, 0, 0);
	renderer->camradius = 5;
	renderer->setView(width, height);

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
			mousedown = true;
			break;
		case SDL_MOUSEWHEEL:
			renderer->camradius -= event.wheel.y * 0.1f;
			break;
		case SDL_MOUSEBUTTONUP:
			mousedown = false;
			break;

		case SDL_MOUSEMOTION:
			if (mousedown){
				renderer->camAngularVel.x += atan(degtorad(event.motion.yrel)) * 2;
				renderer->camAngularVel.y += atan(degtorad(event.motion.xrel)) * 2;
			}
			break;

		case SDL_WINDOWEVENT:
			switch (event.window.event){
			case SDL_WINDOWEVENT_RESIZED:
				WIDTH = event.window.data1;
				HEIGHT = event.window.data2;
				renderer->setView(WIDTH, HEIGHT);
				break;
			}

		default:
			break;
		}
	}
}

void PlotWindow::render(){
	renderer->render();
	SDL_GL_SwapWindow(wnd);
}

void PlotWindow::update(){
	renderer->update(16);
}



void PlotWindow::display(){
	while (loop){
		input();
		update();
		render();
		SDL_Delay(16);
	}

}

void PlotWindow::setPlotData(PlotData* data){
	renderer->genPlotDisplayList(data);
}