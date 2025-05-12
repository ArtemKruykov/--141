#pragma once
#include <string>

class Shape {
public:
    /**
    * @brief Виртуальный деструктор Shape.
    */
    virtual ~Shape() = default;

    /**
    * @brief Возвращает строковое представление фигуры.
    * @return Строка с описанием фигуры.
    */
    virtual std::string toString() const = 0;

    /**
     * @brief Выводит описание фигуры в стандартный вывод.
     */
    void draw() const;

    /**
     * @brief Читает параметры фигуры из входного потока.
     */
    virtual void readFromInput() = 0;
};