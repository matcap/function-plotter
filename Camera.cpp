#include "Camera.h"


Camera::Camera(){
	pos[0] = 0;
	pos[1] = 0;
	pos[2] = 0;
	rot[0] = 0;
	rot[1] = 0;
	rot[2] = 0;
}


Camera::~Camera()
{
}

void Camera::moveForward(GLfloat dist){
	pos[2] += dist * sin(rot[1]);
	pos[0] += dist * cos(rot[1]);
}

void Camera::moveLateral(GLfloat dist){
	pos[0] += dist;
}

void Camera::moveVertical(GLfloat dist){
	pos[1] += dist;

}

void Camera::roll(GLfloat angle){
	rot[2] += angle;
}
void Camera::yaw(GLfloat angle){
	rot[1] += angle;
}
void Camera::pitch(GLfloat angle){
	rot[0] += angle;
}

void Camera::applyUpdates(){
	glRotatef(rot[0], 1, 0, 0);
	glRotatef(rot[1], 0, 1, 0);
	glRotatef(rot[2], 0, 0, 1);
	glTranslatef(pos[0], pos[1], pos[2]);
}