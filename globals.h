#pragma once
#include <SDL2/SDL_opengl.h>
#include <vector>
#include <iostream>
#ifdef CONST
#undef CONST
#endif


enum TokenId{
	// Binary operators
	SUM,
	SUB,
	MULT,
	DIV,
	POW,
	// Unary operators
	SIN,
	COS,
	TAN,
	ATAN,
	SQRT,
	// Variables
	VARX,
	VARY,
	// Constants
	CONST
};

typedef struct{
	double x;
	double y;
} Vec2d;

class Vector3f
{
public:
	Vector3f(void);
	Vector3f(float x, float y, float z);

	void set(float x, float y, float z);
	float getMagnitude(void);
	Vector3f getNormal(void);
	float* getArray(void);
	GLfloat x, y, z;
};

struct Range{
	float low;
	float high;
	Range(float low, float high) : low(0), high(0){
		this->low = low;
		this->high = high;
	}
};

struct PlotData{
	std::vector<Vector3f> points;
	int rows; int cols;
	Range xrange;
	Range yrange;
	Range zrange;
	float step;

	PlotData() : xrange(0,0), yrange(0,0), zrange(0,0) {
		
	}
};

static const float PI = 3.14159265359f;

float radtodeg(float rad);

float degtorad(float deg);
