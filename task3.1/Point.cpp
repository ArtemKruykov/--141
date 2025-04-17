#include "point.h"

Point::Point(unsigned int x, unsigned int y) : x(x), y(y) {}

unsigned int Point::getX() const { return x; }
unsigned int Point::getY() const { return y; }

bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& point) {
    char ch;
    is >> ch; // читаем '('
    is >> point.x;
    is >> ch; // читаем ','
    is >> point.y;
    is >> ch; // читаем ')'
    return is;
}

Point Point::operator+(unsigned int value) const {
    return Point(x + value, y + value);
}

Point Point::operator-(unsigned int value) const {
    return Point(x - value, y - value);
}