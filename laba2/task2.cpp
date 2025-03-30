#include <iostream>

void printNumbers(int A, int B) {
    if (A == B) {
        std::cout << A << std::endl; // Выводим число, если A равно B
        return;
    }
    else if (A < B) {
        std::cout << A << std::endl; // Выводим текущее A
        printNumbers(A + 1, B); // Рекурсивно вызываем функцию с A увеличенным на 1
    }
    else {
        std::cout << A << std::endl; // Выводим текущее A
        printNumbers(A - 1, B); // Рекурсивно вызываем функцию с A уменьшенным на 1
    }
}

int main() {
    int A, B;
    std::cout << "Введите первое число (A): ";
    std::cin >> A;
    std::cout << "Введите второе число (B): ";
    std::cin >> B;

    printNumbers(A, B); // Запуск рекурсивной функции

    return 0;
}
