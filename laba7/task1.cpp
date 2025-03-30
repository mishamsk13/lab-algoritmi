#include <iostream>
#include <vector>
#include <algorithm>
 
// Структура для представления заявки на лекцию
struct Lecture {
    int start; // Время начала лекции
    int end;   // Время окончания лекции
};
 
// Функция сравнения для сортировки заявок по времени окончания
bool compareLectures(const Lecture& a, const Lecture& b) {
    return a.end < b.end;
}
 
int main() {
    int N;
    std::cin >> N; // Считываем количество заявок
 
    std::vector<Lecture> lectures(N); // Вектор для хранения заявок
 
    // Считываем заявки
    for (int i = 0; i < N; ++i) {
        std::cin >> lectures[i].start >> lectures[i].end;
    }
 
    // Сортируем заявки по времени окончания
    std::sort(lectures.begin(), lectures.end(), compareLectures);
 
    int count = 0; // Счетчик для количества выполненных заявок
    int lastEndTime = 0; // Время окончания последней выбранной лекции
 
    // Проходим по отсортированным заявкам
    for (const auto& lecture : lectures) {
        // Если текущая лекция начинается после окончания последней выбранной, выбираем её
        if (lecture.start >= lastEndTime) {
            ++count;
            lastEndTime = lecture.end;
        }
    }
 
    std::cout << count << std::endl; // Выводим максимальное количество выполненных заявок
    return 0;
}
