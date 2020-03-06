#include "Point.h"
Point::Point(int xx,int yy)
{
	x = xx;
	y = yy;
}
Point& Point::operator+=(Point &ref_in)
{
	if (this != &ref_in)
	{
		x = x + ref_in.x;
		y = y + ref_in.y;
	}
	return *this;
}
Point& Point::operator+=(int XY)
{
		x = x + XY;
		y = y + XY;
	return *this;
}
bool Point::operator<(const Point  &b) const
{
	if (x < b.x && y < b.y) return true;
	else return false;
}
bool Point::operator==(const Point & b) const
{
	if ((this->x == b.x) && (this->y == b.y))
	{
		return true;
	}
	return false;
}
bool Point::operator!=(const Point & b) const
{
	if ((this->x == b.x) && (this->y == b.y))
	{
		return false;
	}
	return true;
}//Можно делегировать ==
/*Point& Point::operator+(const int XY)
{
	return Point(x + XY, y + XY);
}*/
Point Point::operator+(const Point &ref_in)
{
	return Point(x + ref_in.x, y + ref_in.y);
}
