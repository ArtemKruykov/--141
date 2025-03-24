#include <iostream>
#include <locale>
#include "Triangle.h"

using namespace std;

/**
* @brief Ввод координат с клавиатуры
* @param message Сообщение перед вводом
*/
Point getPoint(string message);

/**
* @brief Создание треугольника по 3 точкам.
*/
Triangle getTriangle();

/**
* @brief Точка входа в программу.
* @return 0 при выполнении программы без ошибок.
*/
int main() {
    setlocale(LC_ALL, "Russian");
    Triangle triangle = getTriangle();
    cout << "Inradius: " << triangle.inradius() << endl;
    cout << "Circumradius: " << triangle.circumradius() << endl;
    return 0;
}

Point getPoint(string message)
{
    cout << message << endl;
    double x = 0.0;
    double y = 0.0;
    cin >> x >> y;
    if (cin.fail())
    {
        throw invalid_argument("Введено некорректное значение");
    }
    return Point(x, y);
}

Triangle getTriangle() {
    Point A = getPoint("Введите координаты x и y для первой точки: ");
    Point B = getPoint("Введите координаты x и y для второй точки: ");
    Point C = getPoint("Введите координаты x и y для третьей точки: ");
    return Triangle(A, B, C);
}