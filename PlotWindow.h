#include <SDL2\SDL.h>
#include <SDL2\SDL_opengl.h>
#include <SDL2\SDL_main.h>
#include <gl\GLU.h>
#include <vector>
#include <string>
#include "OGLRenderer.h"
#include "globals.h"
#pragma once
using namespace std;
class PlotWindow
{

public:
	PlotWindow();
	bool create(GLuint width, GLuint height, string title);
	void display();
	void destroy();
	virtual ~PlotWindow();
	void setPlotData(PlotData* data);

protected:
	void input();
	void render();
	void update();
	
	GLuint WIDTH, HEIGHT;
	SDL_Window* wnd;
	SDL_Renderer* rndr;
	SDL_GLContext ctx;
	OGLRenderer* renderer;
	
	int num;
	float* vertices;

	bool mousedown;
	bool loop;
};

