#include "../desicion/PriorityQueue.h"
#include <iostream>
#include <locale>



int main() {
    setlocale(LC_ALL, "Russian");

    PriorityQueue pq1 = { {10, 3}, {20, 1}, {30, 5}, {40, 2} };
    std::cout << "Начальная очередь: " << pq1.toString() << std::endl;

    pq1.push(50, 4);  
    pq1 << std::make_pair(60, 0); 
    std::cout << "После добавления элементов: " << pq1.toString() << std::endl;

    int value;
    std::cout << "\nИзвлечение элементов с максимальным приоритетом:" << std::endl;
    while (pq1.popMax(value)) {
        std::cout << "Извлеченный максимум: " << value << std::endl;
    }

    std::cout << "\nОчередь пуста: " << std::boolalpha << pq1.isEmpty() << std::endl;

    PriorityQueue pq2;
    pq2.push(100, 10);
    pq2.push(200, 5);
    pq2.push(300, 20);
    std::cout << "\nВторая очередь: " << pq2.toString() << std::endl;

   
    if (pq2.peekMax(value)) {
        std::cout << "Текущий максимум: " << value << std::endl;
    }
    if (pq2.peekMin(value)) {
        std::cout << "Текущий минимум: " << value << std::endl;
    }

    PriorityQueue pq3 = pq2;
    std::cout << "\nСкопированная очередь: " << pq3.toString() << std::endl;

    std::pair<int, int> element;
    pq3 >> element;
    std::cout << "Извлечено через оператор >>: (" << element.first << ", " << element.second << ")" << std::endl;

    return 0;
}