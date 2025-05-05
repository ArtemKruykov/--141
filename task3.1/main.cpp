#include "../decision/Polygon.h"
#include <locale>
#include <iostream>
#include <vector>
#include <sstream>


Polygon readPolygonFromStream(std::istream& input, unsigned int MAX_COORD);

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        const int MAX_COORD = 1920; 

        std::cout << "=== Ввод первого многоугольника ===" << std::endl;
        Polygon polygon1 = readPolygonFromStream(std::cin, MAX_COORD);
        polygon1.draw();
        
        std::cout << "\n=== Ввод второго многоугольника ===" << std::endl;
        Polygon polygon2 = Polygon::ReadFromInput(MAX_COORD);
        polygon2.draw();

    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

Polygon readPolygonFromStream(std::istream& input, unsigned int MAX_COORD) {
    std::vector<Point> points;
    std::string line;

    std::cout << "Введите количество вершин многоугольника: ";
    size_t vertexCount;
    input >> vertexCount;
    input.ignore();

    std::cout << "Введите координаты вершин (формат: x y):" << std::endl;
    for (size_t i = 0; i < vertexCount; ++i) {
        unsigned int x, y;
        input >> x >> y;
        points.emplace_back(x, y);
    }

    return Polygon(points, MAX_COORD);
}