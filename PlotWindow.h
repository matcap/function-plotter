#include <SDL2\SDL.h>
#include <SDL2\SDL_opengl.h>
#include <SDL2\SDL_main.h>

#pragma once
class PlotWindow
{
public:
	PlotWindow();
	void create();

	virtual ~PlotWindow();

protected:
	SDL_Window* wnd;
	SDL_Renderer* rndr;
	SDL_GLContext ctx;
};

