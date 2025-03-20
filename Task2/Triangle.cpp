#include <cmath>
#include "Triangle.h"

/**
* @brief Треугольник заданный тремя точками.
*/
Triangle::Triangle(const Point& a, const Point& b, const Point& c) : A(a), B(b), C(c) 
{
    this->a = sideLength(B, C);
    this->b = sideLength(A, C);
    this->c = sideLength(A, B);
}

/**
* @brief Вычисляем длину стороны треугольника.
* @param  p1 Первая точка.
* @param  p2 Вторая точка.
*/
double Triangle::sideLength(const Point& p1, const Point& p2)
{
    return sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
}

/**
* @brief Вычисляем периметр треугольника.
*/
double Triangle::perimeter()
{
    return a + b + c;
}

/**
* @brief Вычисляем площадь треугольника.
*/
double Triangle::area()
{
    double p = perimeter() / 2; 
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

/**
* @brief Вычисляем радиус вписанной окружности.
*/
double Triangle::inradius()
{
    return area() / (perimeter() / 2);
}

/**
* @brief Вычисляем радиус описанной окружности.
*/
double Triangle::circumradius()
{
    return (a * b * c) / (4 * area());
}
