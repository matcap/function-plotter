#include "OGLRenderer.h"


Vector3f::Vector3f(void)
{
	x = y = z = 0;
}

Vector3f::Vector3f(float x, float y, float z)
{
	this->set(x, y, z);
}

void Vector3f::set(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float* Vector3f::getArray(void)
{
	float arr[] = { x, y, z };
	return arr;
}

Vector3f Vector3f::getNormal(void)
{
	float mag = this->getMagnitude();
	return Vector3f(x / mag, y / mag, z / mag);
}

float Vector3f::getMagnitude(void)
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

OGLRenderer::OGLRenderer()
{
}


OGLRenderer::~OGLRenderer()
{
}

void OGLRenderer::init(void)
{
	glClearColor(.5, .5, .5, 1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	
	camera = new Camera();
}

void OGLRenderer::render(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	drawGrids();
}

void OGLRenderer::setView(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, double(width) / double(height), 0.01, 100.0);
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void drawGrids(void)
{
	glPushMatrix();
	glLineWidth(10);
	glBegin(GL_LINES);
	{
		glColor3f(1, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(20, 0, 0);
		glColor3f(0, 1, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 20, 0);
		glColor3f(0, 0, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 20);
	}
	glEnd();

	glLineWidth(1);
	for (int i = -20; i < 21; i++){
		glBegin(GL_LINES);
		{
			// XZ plane
			glColor3f(.5, 0, 0);
			glVertex3f(-20, 0, i);
			glVertex3f(20, 0, i);
			glColor3f(0, 0, .5);
			glVertex3f(i, 0, -20);
			glVertex3f(i, 0, 20);
		}
		glEnd();
	}
	glPopMatrix();
}