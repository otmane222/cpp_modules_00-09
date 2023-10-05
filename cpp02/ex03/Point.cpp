#include "Point.hpp"

Point::Point() {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point& copy) : x(copy.x), y(copy.y) {}

Point& Point::operator=(const Point &src)
{
	if (this != &src)
	{
		const_cast<Fixed&>(x) = src.x;
		const_cast<Fixed&>(y) = src.y;
	}
	return *this;
}

Fixed	Point::getX() const
{
	return (x);
}

Fixed	Point::getY() const
{
	return (y);
}

float Point::calculateTriangleArea(const Point& A, const Point& B, const Point& C) {
    float k = 0.5f * ((A.x.toFloat() * (B.y.toFloat()) + \
						(B.x.toFloat() * C.y.toFloat()) + \
						(C.x.toFloat() * A.y.toFloat())) - \
						((A.x.toFloat() * C.y.toFloat()) + \
						(C.x.toFloat() * B.y.toFloat()) + \
						(B.x.toFloat() * A.y.toFloat())));
	if (k < 0)
		k *= -1;
	return (k);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    // Calculate the area of the main triangle ABC
    float mainTriangleArea = Point::calculateTriangleArea(a, b, c);

    // Calculate the areas of the sub-triangles formed by point P
    float area1 = Point::calculateTriangleArea(point, b, c);
    float area2 = Point::calculateTriangleArea(a, point, c);
    float area3 = Point::calculateTriangleArea(a, b, point);

    // Check if the sum of sub-triangle areas equals the main triangle area
    float k = (mainTriangleArea - (area1 + area2 + area3));
	if (k < 0)
		k *= -1;
	return (k < 1e-6);
}

Point::~Point() {}
