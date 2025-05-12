#include "polygon.h"
#include <iostream>
#include <sstream>
#include <string>

bool Polygon::isValid() const {
    if (vertices.size() < 3) return false;

    for (const auto& point : vertices) {
        if (point.getX() > maxCoordinate || point.getY() > maxCoordinate) {
            return false;
        }
    }

    return true;
}

Polygon::Polygon(const std::vector<Point>& points, double maxCoord)
    : vertices(points), maxCoordinate(maxCoord) {
    if (!isValid()) {
        throw std::invalid_argument("Недопустимые координаты многоугольника");
    }
}

Polygon::Polygon(const std::vector<std::pair<double, double>>& coords, double maxCoord)
    : maxCoordinate(maxCoord) {
    for (const auto& coord : coords) {
        vertices.emplace_back(coord.first, coord.second);
    }
    if (!isValid()) {
        throw std::invalid_argument("Недопустимые координаты многоугольника");
    }
}

double Polygon::getMaxCoord() const
{
    return maxCoordinate;
}

std::string Polygon::toString() const {
    std::stringstream ss;
    ss << "Многоугольник с вершинами: ";
    for (size_t i = 0; i < vertices.size(); ++i) {
        ss << vertices[i];
        if (i != vertices.size() - 1) {
            ss << ", ";
        }
    }
    return ss.str();
}

Polygon Polygon::ReadFromInput(unsigned int maxCoord) {
    std::vector<Point> points;
    std::cout << "Введите количество вершин: ";
    size_t count;
    std::cin >> count;

    std::cout << "Введите вершины (Формата: (x,y)):" << std::endl;
    for (size_t i = 0; i < count; ++i) {
        Point p;
        std::cin >> p;
        points.push_back(p);
    }

    return Polygon(points, maxCoord);
}

void Polygon::readFromInput() {
    *this = ReadFromInput(maxCoordinate);
}

std::ostream& operator<<(std::ostream& os, const Polygon& pol) {
    os << pol.toString();
    return os;
}

std::istream& operator>>(std::istream& is, Polygon& pol) {
    pol.readFromInput();
    return is;
}