#pragma once

class Point
{
public:
	/**
	* @brief Переменная координаты x
	*/
	double x;

	/**
	* @brief Переменная координаты y
	*/
	double y;

	/**
	* @brief Изначальные координаты х и у для точки
	*/
	Point(const double x = 0, const double y = 0);
};