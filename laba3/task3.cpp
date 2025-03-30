#include <iostream>
#include <vector>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()
#include <algorithm> // Для sort

using namespace std;

// Функция для быстрой сортировки по первому столбцу
void quicksort(vector<vector<int>>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high][0]; // выбираем последний элемент как опорный
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j][0] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    const int rows = 10; // количество строк
    const int cols = 5;  // количество столбцов
    vector<vector<int>> array(rows, vector<int>(cols));

    srand(static_cast<unsigned int>(time(0))); // инициализируем генератор случайных чисел

    // Заполняем массив случайными числами в диапазоне от 5 до 61
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = rand() % (61 - 5 + 1) + 5; // случайное число в диапазоне от 5 до 61
        }
    }

    cout << "Исходный массив:" << endl;
    for (const auto& row : array) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    // Сортировка массива по первому столбцу
    quicksort(array, 0, rows - 1);

    cout << "Отсортированный массив:" << endl;
    for (const auto& row : array) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
