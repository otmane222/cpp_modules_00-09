#pragma once

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const float a, const float b);
		Point(const Point& copy);
		Point& operator=(const Point &src);
		Fixed	getX(void) const;
		Fixed	getY(void) const;
		static float calculateTriangleArea(const Point& A, const Point& B, const Point& C);
		~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point); // the shoelace formula