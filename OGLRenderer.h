#pragma once
#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>
#include <cmath>
#include <vector>
#include "globals.h"
using namespace std;


class OGLRenderer
{
public:
	OGLRenderer();
	virtual ~OGLRenderer();
	void render();
	void init(void);
	void setView(int width, int height);
	void update(int delta);
	void applyView();
	void genPlotDisplayList(PlotData* data);
	
	Vector3f camFocus;
	Vector3f camAngularVel;
	Vector3f camRot;
	float camradius;

protected:
	void createVertex(Vector3f v);
	int width;
	int height;
	int fps;
	GLint plotList;
	PlotData* data;
};

