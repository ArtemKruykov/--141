#pragma once
#include <iostream>

class Point {
private:
    unsigned int x;
    unsigned int y;

public:
    Point(unsigned int x = 0, unsigned int y = 0);

    unsigned int getX() const;
    unsigned int getY() const;

    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Point& point);
    friend std::istream& operator>>(std::istream& is, Point& point);

    Point operator+(unsigned int value) const;
    Point operator-(unsigned int value) const;
};