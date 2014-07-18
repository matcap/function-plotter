#include <SDL2\SDL.h>
#include <SDL2\SDL_opengl.h>
#include <SDL2\SDL_main.h>

#pragma once
class PlotWindow
{
public:
	PlotWindow();
	bool create(GLuint width, GLuint height);
	void display();
	void destroy();
	virtual ~PlotWindow();

protected:
	void input();
	void render();
	void update();
	void initOpenGL();

	GLuint WIDTH, HEIGHT;
	SDL_Window* wnd;
	SDL_Renderer* rndr;
	SDL_GLContext ctx;
	bool loop;
};

