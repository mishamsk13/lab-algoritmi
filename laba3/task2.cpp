#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void quickSort(std::vector<int>& arr, int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2]; // Опорный элемент

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // Рекурсивные вызовы для левой и правой части массива
    if (left < j) {
        quickSort(arr, left, j);
    }
    if (i < right) {
        quickSort(arr, i, right);
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел

    const int SIZE = 20; // Размер массива
    std::vector<int> arr(SIZE);

    // Заполнение массива случайными числами в интервале [50, 100]
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 51 + 50; // Случайное число от 50 до 100
    }

    std::cout << "Исходный массив: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Сортировка массива
    quickSort(arr, 0, SIZE - 1);

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
