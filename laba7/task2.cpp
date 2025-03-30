#include <iostream>
#include <vector>
#include <algorithm>
 
// Структура для хранения информации о коробке
struct Box {
    int weight;    // Вес коробки
    int capacity;  // Максимальный вес, который она может выдержать
};
 
// Функция сравнения для сортировки коробок по их максимальной грузоподъемности
bool compareBoxes(const Box& a, const Box& b) {
    return a.capacity > b.capacity;
}
 
int main() {
    int n;
    std::cin >> n;  // Считываем количество коробок
 
    std::vector<Box> boxes(n);  // Вектор для хранения информации о коробках
 
    // Считываем информацию о каждой коробке
    for (int i = 0; i < n; ++i) {
        std::cin >> boxes[i].weight >> boxes[i].capacity;
    }
 
    // Сортируем коробки по убыванию их максимальной грузоподъемности
    std::sort(boxes.begin(), boxes.end(), compareBoxes);
 
    int maxBoxes = 0;  // Максимальное количество коробок, которые можно сложить
    int currentWeight = 0;  // Текущий вес коробок в стопке
 
    // Проходим по отсортированным коробкам и пытаемся сложить их
    for (const auto& box : boxes) {
        if (currentWeight <= box.capacity) {
            currentWeight += box.weight;
            maxBoxes++;
        }
    }
 
    std::cout << maxBoxes << std::endl;  // Выводим результат
    return 0;
}
