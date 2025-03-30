#include <iostream>
#include <cstdlib>  // Для функции qsort
#include <cstring>  // Для функции strcmp

// Структура для представления студента
struct Student {
    char name[50];
    int id;
};

// Функция сравнения для qsort
int compare(const void* a, const void* b) {
    // Приводим указатели к типу Student*
    const Student* studentA = (const Student*)a;
    const Student* studentB = (const Student*)b;

    // Сравниваем имена студентов
    return strcmp(studentA->name, studentB->name);
}

int main() {
    // Создаем массив студентов
    Student students[] = {
        {"Anna", 1},
        {"Boris", 2},
        {"Victor", 3},
        {"Dmitry", 4}
    };

    // Количество студентов в массиве
    int numStudents = sizeof(students) / sizeof(students[0]);

    // Сортируем массив студентов по имени с использованием qsort
    qsort(students, numStudents, sizeof(Student), compare);

    // Выводим отсортированный список студентов
    std::cout << "Отсортированный список студентов:" << std::endl;
    for (int i = 0; i < numStudents; ++i) {
        std::cout << students[i].name << " (ID: " << students[i].id << ")" << std::endl;
    }

    return 0;
}
