#include <iostream> // Включает библиотеку для работы с стандартным вводом и выводом
#include <vector>   // Включает библиотеку для работы с динамическими массивами (векторами)
#include <string>   // Включает библиотеку для работы со строками
#include <algorithm> // Включает библиотеку, содержащую алгоритмы, в том числе std::swap

// Функция для сортировки телефонных номеров методом выбора
void selectionSort(std::vector<std::string>& phones) {
    int n = phones.size(); // Получаем количество элементов в векторе phones
    for (int i = 0; i < n - 1; ++i) { // Внешний цикл, перебирающий все элементы, кроме последнего
        int minIndex = i; // Предполагаем, что текущий элемент является минимальным
        for (int j = i + 1; j < n; ++j) { // Внутренний цикл для поиска минимального элемента в оставшейся части массива
            // Если текущий элемент больше, чем элемент по индексу minIndex, обновляем minIndex
            if (phones[j] < phones[minIndex]) {
                minIndex = j; // Обновляем индекс минимального элемента
            }
        }
        // Меняем местами текущий элемент и минимальный элемент, найденный во внутреннем цикле
        std::swap(phones[i], phones[minIndex]); // Функция swap меняет местами два элемента, в первых двух задачах меняли их вручную
    }
}

// Функция для вывода списка телефонных номеров
void printPhones(const std::vector<std::string>& phones) {
    for (const std::string& phone : phones) { // Цикл для перебора каждого телефонного номера в векторе
        std::cout << phone << std::endl; // Выводим текущий телефонный номер
    }
}

// Главная функция, с которой начинается выполнение программы
int main() {
    // Инициализация вектора телефонных номеров как строк
    std::vector<std::string> phones = {
        "23-45-67",  // Первый телефонный номер
        "12-34-56",  // Второй телефонный номер
        "34-12-45",  // Третий телефонный номер
        "23-45-66",  // Четвертый телефонный номер
        "12-34-57"   // Пятый телефонный номер
    };

    std::cout << "Список телефонных номеров до сортировки:\n"; // Выводим сообщение о начальном списке
    printPhones(phones); // Вызываем функцию для печати телефонных номеров

    // Сортировка телефонных номеров с использованием алгоритма выбором
    selectionSort(phones); // Вызываем функцию сортировки

    std::cout << "\nСписок телефонных номеров после сортировки:\n"; // Выводим сообщение о списке после сортировки
    printPhones(phones); // Печатаем отсортированные телефонные номера

    return 0; // Возвращаем 0, что означает успешное завершение программы
}
