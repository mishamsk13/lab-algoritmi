#include <iostream>

void printNumbers(int n) {
    // Базовый случай: если n меньше 1, то просто выходим из функции
    if (n < 1) {
        return;
    }
    // Рекурсивный вызов: сначала вызываем функцию для n-1
    printNumbers(n - 1);
    // Затем выводим текущее значение n
    std::cout << n << " ";
}

int main() {
    int n;
    std::cout << "Введите натуральное число: ";
    std::cin >> n;

    // Вызов функции для вывода чисел от 1 до n
    printNumbers(n);

    std::cout << std::endl; // Для завершения строки после вывода
    return 0;
}
