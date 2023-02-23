#include <iostream>

int main() {
    const int max_numbers = 1000;
    int numbers[max_numbers];
    int count = 0;
    int sum = 0;

    std::cout << "Введите набор чисел (максимум " << max_numbers << " чисел):\n";

    while (count < max_numbers) {
        std::string input;
        std::getline(std::cin, input);
        if (input.empty()) {
            break;
        }
        try {
            int number = std::stoi(input);
            numbers[count++] = number;
            sum += number;
        } catch (const std::invalid_argument&) {
            std::cout << "Ошибка: введено не число\n";
        } catch (const std::out_of_range&) {
            std::cout << "Ошибка: введено слишком большое число\n";
        }
    }

    if (count == 0) {
        std::cout << "Ни одного числа не было введено\n";
    } else {
        double average = static_cast<double>(sum) / count;
        std::cout << "Среднее арифметическое: " << average << '\n';
    }

    return 0;
}
