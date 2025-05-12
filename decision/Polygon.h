#pragma once
#include "shape.h"
#include "point.h"
#include <vector>
#include <stdexcept>

class Polygon : public Shape {
private:
    std::vector<Point> vertices;
    double maxCoordinate;

    /**
     * @brief Проверяет валидность многоугольника.
     * @return True если многоугольник валиден.
     */
    bool isValid() const;

public:
    /**
     * @brief Конструктор из вектора точек.
     * @param points Вектор точек.
     * @param maxCoord Максимальная допустимая координата.
     */
    Polygon(const std::vector<Point>& points, double maxCoord);

    /**
     * @brief Конструктор из вектора пар координат.
     * @param coords Вектор пар координат.
     * @param maxCoord Максимальная допустимая координата.
     */
    Polygon(const std::vector<std::pair<double, double>>& coords, double maxCoord);

    /**
     * @brief Возвращает максимальную допустимую координату.
     * @return Значение максимальной координаты.
     */
    double getMaxCoord() const;

    /**
     * @brief Возвращает строковое представление многоугольника.
     * @return Строка с описанием многоугольника.
     */
    std::string toString() const override;

    /**
     * @brief Создает многоугольник из входного потока.
     * @param maxCoord Максимальная допустимая координата.
     * @return Созданный многоугольник.
     */
    static Polygon ReadFromInput(unsigned int maxCoord);

    /**
     * @brief Читает параметры многоугольника из входного потока.
     */
    void readFromInput() override;

    /**
     * @brief Оператор вывода многоугольника в поток.
     */
    friend std::ostream& operator<<(std::ostream& os, const Polygon& rect);

    /**
     * @brief Оператор ввода многоугольника из потока.
     */
    friend std::istream& operator>>(std::istream& is, Polygon& rect);
};