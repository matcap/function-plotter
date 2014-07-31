#pragma once
#include <SDL2\SDL_opengl.h>
#include <gl\GLU.h>
#include <cmath>
#include "Camera.h"
#ifndef M_PI
#define M_PI 3.14159265359
#endif


static const float PI = 3.14159265359;

static float degtorad(float deg){
	return deg * PI / 180;
}

static float radtodeg(float rad){
	return rad * 180 / PI;
}

class Vector3f
{
public:
	Vector3f(void);
	Vector3f(float x, float y, float z);
	void set(float x, float y, float z);
	float getMagnitude(void);
	Vector3f getNormal(void);
	float* getArray(void);
	float x, y, z;
};


class OGLRenderer
{
public:
	OGLRenderer();
	virtual ~OGLRenderer();
	void render(void);
	void init(void);
	void setView(int width, int height);
	Camera* camera;

protected:
	int width;
	int height;
};

