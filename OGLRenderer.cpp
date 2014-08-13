#include "OGLRenderer.h"



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

OGLRenderer::OGLRenderer()
{
	camradius = 1;
	camFocus.set(0, 0, -1);
	camAngularVel.set(0, 0, 0);
	camRot.set(0, 0, 0);
	init();
}


OGLRenderer::~OGLRenderer()
{
}

void OGLRenderer::init(void)
{
	glClearColor(.1, .1, .1, 1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void OGLRenderer::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	applyView();

	//drawGrids();
	glScalef(1, 0.5, 1);
	glCallList(plotList);
	
}

void OGLRenderer::setView(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, double(width) / double(height), 0.01, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void OGLRenderer::update(int delta){
	camAngularVel.x -= camAngularVel.x * 0.01 * delta;
	camAngularVel.y -= camAngularVel.y * 0.01 * delta;

	camRot.x += camAngularVel.x;
	camRot.y += camAngularVel.y;
}

void OGLRenderer::applyView(){
	glTranslatef(0, 0, -camradius);
	glRotatef(camRot.x, 1, 0, 0);
	glRotatef(camRot.y, 0, 1, 0);
	glTranslatef(-camFocus.x, -camFocus.y, -camFocus.z);
}

void OGLRenderer::genPlotDisplayList(PlotData* data){
	plotList = glGenLists(1);
	glNewList(plotList, GL_COMPILE);

	for (int row = 0; row < data->rows; row++){
		glBegin(GL_LINE_STRIP);
		for (int col = 0; col < data->cols; col++){
			Vector3f v = data->points[row * data->cols + col];
			float red, blue, green = 0;
			green = abs(v.z) / (abs(data->zrange.high) + abs(data->zrange.low));

			if (v.z > 0)
				red = v.z / abs(data->zrange.high);
			else if (v.z < 0)
				blue = v.z / abs(data->zrange.low);

			glColor4f(red, 1 - green , blue, 1);
			glVertex3f(v.x, v.z, v.y);
		}
		glEnd();
	}
	
	for (int col = 0; col < data->cols; col++){
		glBegin(GL_LINE_STRIP);
		for (int row = 0; row < data->rows; row++){
			Vector3f v = data->points[row * data->cols + col];
			float red, blue, green = 0;
			green = abs(v.z) / (abs(data->zrange.high) + abs(data->zrange.low));

			if (v.z > 0)
				red = v.z / data->zrange.high;
			else if (v.z < 0)
				blue = v.z / data->zrange.low;

			glColor4f(red, 1 - green, blue, 1);
			glVertex3f(v.x, v.z, v.y);
		}
		glEnd();
	}

	glEndList();
	this->data = data;
}

void OGLRenderer::createVertex(Vector3f v){
	
}
