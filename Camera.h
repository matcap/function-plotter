#pragma once
#include <cmath>
#include <SDL2\SDL_opengl.h>
#include <gl\GLU.h>
#include "OGLRenderer.h"

using namespace std;





class Camera
{
public:
	Camera();
	virtual ~Camera();
	Vector3f pos;
	Vector3f cen;
	void applyView();

private:
	float theta;
	float phi;
};

