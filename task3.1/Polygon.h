#pragma once
#include "shape.h"
#include "point.h"
#include <vector>
#include <stdexcept>

class Polygon : public Shape {
private:
    std::vector<Point> vertices;
    unsigned int maxCoordinate;

    bool isValid() const;

public:
    Polygon(const std::vector<Point>& points, unsigned int maxCoord);
    Polygon(const std::vector<std::pair<unsigned int, unsigned int>>& coords, unsigned int maxCoord);

    static std::string ToString(const Polygon& polygon);
    std::string toString() const override;
    void draw() const override;

    static Polygon ReadFromInput(unsigned int maxCoord);
    void readFromInput() override;
};