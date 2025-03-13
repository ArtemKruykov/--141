#include <iostream>
#include "Triangle.h"

using namespace std;

/**
* @brief Точка входа в программу.
* @return 0 при выполнении программы без ошибок.
*/
int main() {
    Point A(2, 4);
    Point B(5, 2);
    Point C(-3, 6);
    Triangle triangle(A, B, C);
    cout << "Inradius: " << triangle.inradius() << endl;
    cout << "Circumradius: " << triangle.circumradius() << endl;
    return 0;
}