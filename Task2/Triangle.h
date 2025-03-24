#pragma once
#include "Point.h"

class Triangle {
private:
    /**
    * @brief Первая точка.
    */
    Point A;
    
    /**
    * @brief Вторая точка.
    */
    Point B;
    
    /**
    * @brief Третья точка.
    */
    Point C;
    double a, b, c;
public:
    /**
    * @brief Треугольник заданный тремя точками.
    */
    Triangle(const Point& a, const Point& b, const Point& c);

    /**
    * @brief Вычисляем длину стороны треугольника.
    * @param  p1 Первая точка.
    * @param  p2 Вторая точка.
    */
    double sideLength(const Point& p1, const Point& p2);
    
    /**
    * @brief Вычисляем периметр треугольника.
    */
    void check();

    /**
    * @brief Вычисляем периметр треугольника.
    */
    double perimeter();

    /**
    * @brief Вычисляем площадь треугольника.
    */
    double area();

    /**
    * @brief Вычисляем радиус вписанной окружности.
    */
    double inradius();

    /**
   * @brief Вычисляем радиус описанной окружности.
   */
    double circumradius();

};

