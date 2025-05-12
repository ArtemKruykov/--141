#include "Shape.h"
#include <iostream>

void Shape::draw() const
{
	std::cout << toString() << std::endl;
}