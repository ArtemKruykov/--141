#pragma once
#include "shape.h"
#include "point.h"
#include <vector>
#include <stdexcept>

class Polygon : public Shape {
private:
    std::vector<Point> vertices;
    static maxCoordinate;

    bool isValid() const;

public:
    Polygon(const std::vector<Point>& points, double getMaxCoord());
    Polygon(const std::vector<std::pair<unsigned int, unsigned int>>& coords, double getMaxCoord());
    double getMaxCoord() const;
    std::string toString() const override;

    static Polygon ReadFromInput(unsigned int maxCoord);
    void readFromInput() override;
};