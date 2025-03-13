#include <cmath>
#include "Triangle.h"

/**
* @brief Треугольник заданный тремя точками.
*/
Triangle::Triangle(const Point& a, const Point& b, const Point& c) : A(a), B(b), C(c) 
{
}

/**
* @brief Вычисляем длину стороны треугольника.
* @param  p1 Первая точка.
* @param  p2 Вторая точка.
*/
double Triangle::sideLength(const Point& p1, const Point& p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

/**
* @brief Вычисляем периметр треугольника.
*/
double Triangle::perimeter()
{
    double a = sideLength(B, C);
    double b = sideLength(A, C);
    double c = sideLength(A, B);
    return a + b + c;
}

/**
* @brief Вычисляем площадь треугольника.
*/
double Triangle::area()
{
    double a = sideLength(B, C);
    double b = sideLength(A, C);
    double c = sideLength(A, B);
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
    double a = sideLength(B, C);
    double b = sideLength(A, C);
    double c = sideLength(A, B);
    return (a * b * c) / (4 * area());
}
