#pragma once
#ifndef _VEC2D_H_
#define _VEC2D_H_


#include <cmath>

class Vec2D
{
public:
	const double pi = 3.14159265;
	double x, y;

	Vec2D() : x(0), y(0) {};
	Vec2D(double _x, double _y) : x(_x), y(_y) {};

	void Set(double _x, double _y);

	Vec2D operator+(Vec2D& v);

	Vec2D operator- (Vec2D& v);

	Vec2D operator *(double n);

	Vec2D operator /(double n);

	Vec2D& operator +=(double n);

	Vec2D& operator -=(double n);

	Vec2D& operator *=(double n);

	Vec2D& operator /=(double n);

	Vec2D& operator +=(Vec2D& n);

	Vec2D& operator -=(Vec2D& n);

	double Length();

	double Direction();

	Vec2D Normalise();

	void SetUnitFromAngle(double _rotation);

};

#endif // !_VEC2D_H_