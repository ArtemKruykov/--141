#include <limits>
#include <cmath>
#include "Point.h"

/**
* @brief Создает точку по координатам
*/
Point::Point(const double x, const double y) : x{ x }, y{ y }
{
}

double Point::getX() const
{
	return x;
}

double Point::getY() const
{
	return y;
}

bool operator==(const Point& point1, const Point& point2)
{
	return std::abs(point1.getX() - point2.getX()) <= std::numeric_limits<double>::epsilon()
		&& std::abs(point1.getY() - point2.getY()) <= std::numeric_limits<double>::epsilon();
}

bool operator!=(const Point& point1, const Point& point2)
{
	return !(point1 == point2);
}