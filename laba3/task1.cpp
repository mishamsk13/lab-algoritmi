#include <iostream>
#include <vector>
#include <cstdlib> // для rand() и srand()
#include <ctime>   // для time()

// Функция быстрой сортировки
void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high]; // выбираем опорный элемент
        int i = low - 1; // индекс более мелкого элемента
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) { // если текущий элемент меньше опорного
                i++; // увеличиваем индекс более мелкого элемента
                std::swap(arr[i], arr[j]); // меняем местами
            }
        }
        std::swap(arr[i + 1], arr[high]); // меняем опорный элемент на его место
        int pi = i + 1; // индекс опорного элемента

        quicksort(arr, low, pi - 1); // сортируем левую часть
        quicksort(arr, pi + 1, high); // сортируем правую часть
    }
}

int main() {
    const int SIZE = 1000;
    std::vector<int> numbers(SIZE);

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(0)));

    // Заполнение массива случайными целыми числами
    for (int i = 0; i < SIZE; i++) {
        numbers[i] = rand() % 10000; // случайные числа от 0 до 9999
    }

    // Сортировка массива
    quicksort(numbers, 0, SIZE - 1);

    // Вывод отсортированного массива
    std::cout << "Отсортированный массив: " << std::endl;
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
