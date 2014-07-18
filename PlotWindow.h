#include <SDL2\SDL.h>
#include <SDL2\SDL_opengl.h>
#include <SDL2\SDL_main.h>
#include <gl\GLU.h>
#include <math.h>
#include "Camera.h"
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
	void setupView();
	
	GLuint WIDTH, HEIGHT;
	SDL_Window* wnd;
	SDL_Renderer* rndr;
	SDL_GLContext ctx;
	Camera camera;
	bool loop;
};

