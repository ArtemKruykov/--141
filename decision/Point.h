#pragma once
#include <iostream>

class Point {
private:
    double x;
    double y;

public:
    /**
     * @brief Конструктор точки.
     * @param x Координата X.
     * @param y Координата Y.
     */
    Point(double x = 0, double y = 0);

    /**
     * @brief Возвращает координату X.
     * @return Значение координаты X.
     */
    double getX() const;

    /**
     * @brief Возвращает координату Y.
     * @return Значение координаты Y.
     */
    double getY() const;

    /**
     * @brief Оператор сравнения точек.
     * @param other Другая точка для сравнения.
     * @return True если точки равны.
     */
    bool operator==(const Point& other) const;
    
    /**
     * @brief Оператор неравенства точек.
     * @param other Другая точка для сравнения.
     * @return True если точки не равны.
     */
    bool operator!=(const Point& other) const;

    /**
    * @brief Оператор вывода точки в поток.
    * @param os Выходной поток.
    * @param point Точка для вывода.
    * @return Ссылка на поток.
    */
    friend std::ostream& operator<<(std::ostream& os, const Point& point);

    /**
    * @brief Оператор ввода точки из потока.
    * @param is Входной поток.
    * @param point Точка для ввода.
    * @return Ссылка на поток.
    */
    friend std::istream& operator>>(std::istream& is, Point& point);
};