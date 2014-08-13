#include "globals.h"
#include <cmath>

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

float radtodeg(float rad)
{
	return rad * 180 / PI;
}

float degtorad(float deg){
	return deg * PI / 180;
}
