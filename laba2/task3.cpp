#include <iostream>

int sumOfDigits(int n) {
    // Базовый случай: если n равно 0, то сумма цифр равна 0
    if (n == 0) {
        return 0;
    }
    // Рекурсивный случай: последняя цифра n + сумма цифр остатка от деления n на 10
    return n % 10 + sumOfDigits(n / 10);
}

int main() {
    int N;

    std::cout << "Введите натуральное число N: ";
    std::cin >> N;

    // Проверяем, что число положительное
    if (N <= 0) {
        std::cout << "Пожалуйста, введите натуральное число." << std::endl;
        return 1;
    }

    int sum = sumOfDigits(N);
    std::cout << "Сумма цифр числа " << N << " равна " << sum << std::endl;

    return 0;
}
