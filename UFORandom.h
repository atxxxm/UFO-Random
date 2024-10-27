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
    /// \brief ���������� ��������� ����� ����� � ��������� �� 0 �� max (������������).
   /// \param max ������������ �������� ������������� �����.
   /// \return ��������� ����� �����.
    int range(int max) {
        std::uniform_int_distribution<int> distrib(0, max);
        return distrib(gen);
    }
    /// \brief ���������� ��������� ����� ����� � ��������� �� start �� finish (������������).
    /// \param start ����������� �������� ������������� �����.
    /// \param finish ������������ �������� ������������� �����.
    /// \return ��������� ����� �����.
    int randInt(int start, int finish) {
        std::uniform_int_distribution<> distrib(start, finish);
        return distrib(gen);
    }
    /// \brief ���������� ��������� ����� � ��������� ������ � ��������� �� start �� finish (������������), ���������� �� ������ ����� ����� �������.
    /// \param start ����������� �������� ������������� �����.
    /// \param finish ������������ �������� ������������� �����.
    /// \return ��������� ����� � ��������� ������, ����������� �� ������ ����� ����� �������.
    float randFloat(float start, float finish) {
        std::uniform_real_distribution<> distrib(start, finish);
        float float_number = distrib(gen);
        return std::round(float_number * 10.0f) / 10.0f;
    }
    /// \brief ���������� ��������� ������.
    /// \param mode ����� ���������: 0 - ������ �������, 1 - ������� �������.  �� ��������� - ������ �������.
    /// \return ��������� ������.
    /// \throw std::runtime_error ���� mode �� ����� 0 ��� 1.
    char randChar(int mode = 0) {
        std::locale loc("ru_RU.UTF-8");
        std::vector<char> list_lower = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
        std::vector<char> list_upper = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

        std::vector<char>& list = (mode == 0) ? list_lower : ((mode == 1) ? list_upper : throw std::runtime_error("������! mode ����� ���� ������ ����� 0 - ������ ������� ��� 1 - ������� �������"));

        std::uniform_int_distribution<int> distrib(0, list.size() - 1);
        return list[distrib(gen)];
    }
    /// \brief ���������� ��������� ������ �������� (true ��� false) � ������ ������������.
    /// \return true ��� false.
    bool randBool() {
        std::bernoulli_distribution distrib(0.5);
        return distrib(gen);
    }
    /// \brief �������� ��������� ������� �� ������� �����.
    /// \param array ������ �����.
    /// \return ��������� ������� �� �������.
    /// \throw std::runtime_error ���� ������ ������.
    std::string choiceVector(const std::vector<std::string>& array) {
        if (array.empty()) {
            throw std::runtime_error("������ ������!");
        }
        std::uniform_int_distribution<> distrib(0, array.size() - 1);
        return array[distrib(gen)];
    }
    /// \brief �������� ��������� ���������� ��������� ��������� �� ������� ����� � ��������� �����������.
   /// \param array ������ �����.
   /// \param count ���������� ��������� ���������, ������� ����� �������.
   /// \return ������, ���������� ��������� ��������� ��������.
   /// \throw std::runtime_error ���� ������ ������ ��� count <= 0.
    std::vector<std::string> choicesVector(const std::vector<std::string>& array, int count) {
        if (array.empty()) {
            throw std::runtime_error("������ ������!");
        }
        if (count <= 0) {
            throw std::runtime_error("���������� �� ����� ���� ������ ��� ����� 0");
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