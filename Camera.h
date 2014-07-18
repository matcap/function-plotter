#pragma once
#include <math.h>
#include <SDL2\SDL_opengl.h>


class Camera
{
public:
	Camera();
	virtual ~Camera();
	GLfloat pos[3];
	GLfloat rot[3];

	void moveForward(GLfloat dist);
	void moveLateral(GLfloat dist);
	void moveVertical(GLfloat dist);

	void roll(GLfloat angle);  // Z-rot
	void yaw(GLfloat angle);   // Y-rot
	void pitch(GLfloat angle); // X-rot
	
	void applyUpdates();
};

