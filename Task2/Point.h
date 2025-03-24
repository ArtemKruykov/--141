#pragma once

class Point
{
private:
	/**
	* @brief Переменная координаты x
	*/
	double x;

	/**
	* @brief Переменная координаты y
	*/
	double y;
public:
	/**
	* @brief Изначальные координаты х и у для точки
	*/
	Point(const double x = 0, const double y = 0);
	double getX() const;
	double getY() const;
};
bool operator==(const Point& point1, const Point& point2);
bool operator!=(const Point& point1, const Point& point2);