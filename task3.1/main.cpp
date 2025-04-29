#include "../decision/Polygon.h"
#include <locale>
#include <iostream>
#include <vector>

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        const unsigned int MAX_COORD = 1920; 

    
        std::vector<Point> points = { Point(100, 100), Point(200, 100), Point(200, 200), Point(100, 200) };
        Polygon polygon1(points, MAX_COORD);
        polygon1.draw();

        std::vector<std::pair<unsigned int, unsigned int>> coords = { {300, 300}, {400, 300}, {400, 400}, {300, 400} };
        Polygon polygon2(coords, MAX_COORD);
        polygon2.draw();

        Polygon polygon3 = Polygon::ReadFromInput(MAX_COORD);
        polygon3.draw();

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}