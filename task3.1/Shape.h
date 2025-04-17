#pragma once
#include <string>

class Shape {
public:
    virtual ~Shape() = default;
    virtual std::string toString() const = 0;
    virtual void draw() const = 0;
    virtual void readFromInput() = 0;
};