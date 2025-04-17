#pragma once
#include <iostream>

class Point {
private:
    unsigned int x;
    unsigned int y;

public:
    Point(unsigned int x = 0, unsigned int y = 0);

    // Геттеры
    unsigned int getX() const;
    unsigned int getY() const;

    // Операторы сравнения
    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;

    // Операторы сдвига для ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const Point& point);
    friend std::istream& operator>>(std::istream& is, Point& point);

    // Операторы сложения и вычитания с целым числом
    Point operator+(unsigned int value) const;
    Point operator-(unsigned int value) const;
};