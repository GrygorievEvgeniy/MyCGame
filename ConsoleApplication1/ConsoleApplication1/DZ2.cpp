/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

// функция чтения чисел с консоли пока не введен 0
std::vector<int> readNumbers() {
    std::vector<int> numbers;
    int input;

    std::cout << "Input numbers (0 to finish):" << std::endl;
    while (std::cin >> input && input != 0) {
        numbers.push_back(input);
    }

    // Очищаем поток ввода, чтобы не было проблем с последующим вводом
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return numbers;
}

// Функция для поиска максимального урона
void maxDamage(const std::vector<int>& numbers) {
    auto it = std::max_element(numbers.begin(), numbers.end());
    if (it != numbers.end() && *it > 0) {
        std::cout << "Max damage is: " << *it << std::endl;
    } else {
        std::cout << "No damage recorded." << std::endl;
    }
}

// Функция для поиска минимального урона
void minDamage(const std::vector<int>& numbers) {
    int min = std::numeric_limits<int>::max();
    for (int num : numbers) {
        if (num > 0 && num < min) {
            min = num;
        }
    }
    if (min != std::numeric_limits<int>::max()) {
        std::cout << "Min damage is: " << min << std::endl;
    } else {
        std::cout << "No damage recorded." << std::endl;
    }
}

// Функция для поиска лечения
void cure(const std::vector<int>& numbers) {
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0, [](int total, int num) {
        return num < 0 ? total + num : total;
    });
    std::cout << "Total cure is: " << -sum << std::endl; // Cure is represented as negative, so make it positive for display
}

// Функция для поиска урона
void harm(const std::vector<int>& numbers) {
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0, [](int total, int num) {
        return num > 0 ? total + num : total;
    });
    std::cout << "Total harm is: " << sum << std::endl;
}

// Функция для поиска нулей
void zero(const std::vector<int>& numbers) {
    int count = std::count(numbers.begin(), numbers.end(), 0);
    std::cout << "Number of zeros: " << count << std::endl;
}

int main() {
    std::vector<int> numbers = readNumbers();

    // Меню
    int choice = 0;
    do {
        std::cout << "Choose function:" << std::endl;
        std::cout << "1. Max damage" << std::endl;
        std::cout << "2. Min damage" << std::endl;
        std::cout << "3. Cure" << std::endl;
        std::cout << "4. Harm" << std::endl;
        std::cout << "5. Zero" << std::endl;
        std::cout << "6. Exit" << std::endl;

        std::cin >> choice;

        switch (choice) {
            case 1:
                maxDamage(numbers);
                break;
            case 2:
                minDamage(numbers);
                break;
            case 3:
                cure(numbers);
                break;
            case 4:
                harm(numbers);
                break;
            case 5:
                zero(numbers);
                break;
            case 6:
                std::cout << "Exiting." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 6);

    return 0;
}
*/
