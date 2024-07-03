#include "Vec2D.h"

void Vec2D::Set(double _x, double _y)
{
	x = _x;
	y = _y;
}


Vec2D Vec2D::operator+(Vec2D& v)
{
	return (Vec2D(x + v.x, y + v.y));
}

Vec2D Vec2D::operator-(Vec2D& v)
{
	
	return Vec2D(x - v.x, y - v.y);

}

Vec2D Vec2D::operator*(double n)
{
	return Vec2D(x * n, y * n);
}

Vec2D Vec2D::operator/(double n)
{
	return Vec2D(x / n, y / n);
}

Vec2D& Vec2D::operator+=(double n)
{
	x += n;
	y += n;
	return *this;
}

Vec2D& Vec2D::operator-=(double n)
{
	x -= n;
	y -= n;
	return *this;
}

Vec2D& Vec2D::operator*=(double n)
{
	x *= n;
	y *= n;
	return *this;
}

Vec2D& Vec2D::operator/=(double n)
{
	x /= n;
	y /= n;
	return *this;
}

Vec2D& Vec2D::operator+=(Vec2D& n)
{
	x += n.x;
	y += n.y;
	return *this;
}

Vec2D& Vec2D::operator-=(Vec2D& n)
{
	x -= n.x;
	y -= n.y;
	return *this;
}



double Vec2D::Direction()
{
	return atan2(y, x);
}


Vec2D Vec2D::Normalise()
{
	return Vec2D(*this / Length());
}

void Vec2D::SetUnitFromAngle(double _rotation)
{
	double theta = _rotation * pi / 180;

	x = cos(theta);
	y = sin(theta);
	 
}

double Vec2D::Length()
{
	return std::sqrt(x * x + y * y);
}


