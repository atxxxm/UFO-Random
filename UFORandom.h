#ifndef UFO_RANDOM_H
#define UFO_RANDOM_H

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <locale>


class UFORandom {
private:
    std::random_device rd;
    std::mt19937 gen;

public:
    
    UFORandom() : gen(rd()) {}
    /// \brief Генерирует случайное целое число в диапазоне от 0 до max (включительно).
   /// \param max Максимальное значение генерируемого числа.
   /// \return Случайное целое число.
    int range(int max) {
        std::uniform_int_distribution<int> distrib(0, max);
        return distrib(gen);
    }
    /// \brief Генерирует случайное целое число в диапазоне от start до finish (включительно).
    /// \param start Минимальное значение генерируемого числа.
    /// \param finish Максимальное значение генерируемого числа.
    /// \return Случайное целое число.
    int randInt(int start, int finish) {
        std::uniform_int_distribution<> distrib(start, finish);
        return distrib(gen);
    }
    /// \brief Генерирует случайное число с плавающей точкой в диапазоне от start до finish (включительно), округлённое до одного знака после запятой.
    /// \param start Минимальное значение генерируемого числа.
    /// \param finish Максимальное значение генерируемого числа.
    /// \return Случайное число с плавающей точкой, округленное до одного знака после запятой.
    float randFloat(float start, float finish) {
        std::uniform_real_distribution<> distrib(start, finish);
        float float_number = distrib(gen);
        return std::round(float_number * 10.0f) / 10.0f;
    }
    /// \brief Генерирует случайный символ.
    /// \param mode Режим генерации: 0 - Нижний регистр, 1 - Верхний регистр.  По умолчанию - Нижний регистр.
    /// \return Случайный символ.
    /// \throw std::runtime_error Если mode не равен 0 или 1.
    char randChar(int mode = 0) {
        std::locale loc("ru_RU.UTF-8");
        std::vector<char> list_lower = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
        std::vector<char> list_upper = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

        std::vector<char>& list = (mode == 0) ? list_lower : ((mode == 1) ? list_upper : throw std::runtime_error("Ошибка! mode может быть только равен 0 - Нижний регистр или 1 - Верхний регистр"));

        std::uniform_int_distribution<int> distrib(0, list.size() - 1);
        return list[distrib(gen)];
    }
    /// \brief Генерирует случайное булево значение (true или false) с равной вероятностью.
    /// \return true или false.
    bool randBool() {
        std::bernoulli_distribution distrib(0.5);
        return distrib(gen);
    }
    /// \brief Выбирает случайный элемент из вектора строк.
    /// \param array Вектор строк.
    /// \return Случайный элемент из вектора.
    /// \throw std::runtime_error Если вектор пустой.
    std::string choiceVector(const std::vector<std::string>& array) {
        if (array.empty()) {
            throw std::runtime_error("Вектор пустой!");
        }
        std::uniform_int_distribution<> distrib(0, array.size() - 1);
        return array[distrib(gen)];
    }
    /// \brief Выбирает указанное количество случайных элементов из вектора строк с возможным повторением.
   /// \param array Вектор строк.
   /// \param count Количество случайных элементов, которые нужно выбрать.
   /// \return Вектор, содержащий выбранные случайные элементы.
   /// \throw std::runtime_error Если вектор пустой или count <= 0.
    std::vector<std::string> choicesVector(const std::vector<std::string>& array, int count) {
        if (array.empty()) {
            throw std::runtime_error("Вектор пустой!");
        }
        if (count <= 0) {
            throw std::runtime_error("Количество не может быть меньше или равно 0");
        }
        std::vector<std::string> result;
        for (int i = 0; i < count; i++) {
            std::uniform_int_distribution<> distrib(0, array.size() - 1);
            result.push_back(array[distrib(gen)]);
        }
        return result;
    }
    
};


#endif // !UFO_RANDOM_H