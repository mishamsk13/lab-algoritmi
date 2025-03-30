#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
 
int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
 
    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return 1;
    }
 
    std::unordered_set<int> numbers;
    int number;
 
    // Читаем числа из входного файла
    while (inputFile >> number) {
        if (number > 0) {
            numbers.insert(number);  // Добавляем положительное число
        } else if (number < 0) {
            numbers.erase(-number);  // Удаляем соответствующее положительное число
        } else if (number == 0) {
            // При считывании нуля выводим множество чисел в порядке возрастания
            std::vector<int> sortedNumbers(numbers.begin(), numbers.end());
            std::sort(sortedNumbers.begin(), sortedNumbers.end());
 
            for (const int& num : sortedNumbers) {
                outputFile << num << " ";
            }
            outputFile << std::endl;
            break;  // Завершаем программу
        }
    }
 
    inputFile.close();
    outputFile.close();
    return 0;
}
