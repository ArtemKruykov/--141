#pragma once
#include <string>

class Shape {
public:
    virtual ~Shape() = default;
    virtual std::string toString() const = 0;
    void draw() const;
    virtual void readFromInput() = 0;
};