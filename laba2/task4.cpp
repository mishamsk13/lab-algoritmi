#include <iostream>

void findPrimeDivisors(int n, int divisor = 2) {
    // Если n меньше делителя, значит мы закончили
    if (n < divisor) {
        return;
    }

    // Проверяем, делится ли n на текущий делитель
    if (n % divisor == 0) {
        std::cout << divisor << " "; // Выводим делитель
        // Вызываем функцию рекурсивно для n, делённого на текущий делитель
        findPrimeDivisors(n / divisor, divisor);
    }
    else {
        // Если не делится, пробуем следующий делитель
        findPrimeDivisors(n, divisor + 1);
    }
}

int main() {
    int n;
    std::cout << "Введите натуральное число n > 1: ";
    std::cin >> n;

    if (n <= 1) {
        std::cout << "Число должно быть больше 1." << std::endl;
    }
    else {
        std::cout << "Простые делители числа " << n << ": ";
        findPrimeDivisors(n); // Начинаем поиск простых делителей
        std::cout << std::endl;
    }

    return 0;
}
