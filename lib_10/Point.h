#pragma once
#include "H.h"
class Point
{
	int x = 0;
	int y = 0;
public:
	Point(int xx = 0, int yy = 0);
	Point& operator+=(Point &ref_in);
	Point& operator+=(int XY);
	bool operator <(const Point &b) const;
	bool operator ==(const Point &b) const;
	bool operator !=(const Point &b) const;
	//Point& operator+(const int XY); Посмотреть что не так!!!!
	Point operator+(const Point &ref_in);
	friend std::ostream& operator<<(std::ostream& os, const Point &ms);
	friend std::ostream& operator<<(std::ostream& os, const Point *ms);
	template <typename T,int a,int b>friend void New_coordinat(T &ms);
	template<int n, int m>friend bool coord(Point ms);
	friend bool sort_coord(const Point &ms, const Point &ms2);
	//friend Point& operator-( Point &ref_in, int dec);
	//friend Point& operator-(Point &ref_in, Point &ref);
};