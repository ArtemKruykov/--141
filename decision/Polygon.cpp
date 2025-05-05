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

Polygon::Polygon(const std::vector<Point>& points, double getMaxCoord())
    : vertices(points), maxCoordinate(getMaxCoord()) {
    if (!isValid()) {
        throw std::invalid_argument("Недопустимые координаты многоугольника");
    }
}

Polygon::Polygon(const std::vector<std::pair<unsigned int, unsigned int>>& coords, double getMaxCoord())
    : maxCoordinate(getMaxCoord()) {
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

std::string Polygon::ToString(const Polygon& polygon) {
    std::stringstream ss;
    ss << "Многоугольник с вершинами: ";
    for (size_t i = 0; i < polygon.vertices.size(); ++i) {
        ss << polygon.vertices[i];
        if (i != polygon.vertices.size() - 1) {
            ss << ", ";
        }
    }
    return ss.str();
}

std::string Polygon::toString() const {
    return ToString(*this);
}

void Polygon::draw() const {
    std::cout << toString() << std::endl;
}

Polygon Polygon::ReadFromInput(unsigned int maxCoord) {
    std::vector<Point> points;
    std::os << "Введите количество вершин: ";
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