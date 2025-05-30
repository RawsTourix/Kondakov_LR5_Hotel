/**
 * @file kondakov_lr5_input_control.hpp
 * @brief ���������� ��������� ������� ���������� ������
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup input_control
 */

#ifndef KONDAKOV_LR5_INPUT_CONTROL_HPP
#define KONDAKOV_LR5_INPUT_CONTROL_HPP

#include "kondakov_lr5_input_control.h"

/**
 * @brief ��������� ������ �� ��������� �� �����������
 * @tparam Delim �����������
 * @tparam Container ��� ���������� ��� �����������
 * @param input_line ������� ������
 * @param dc ��������� � ������������
 * @details ������� ������� ���������, ��������� ������ �� �����������,
 *          ������� ������ ��������, ��������� �� ��������� (��� ����� ��������),
 *          ������ ������ ����� ������� �������� ���������
 */
template <char Delim, typename Container>
void InputControl::split(const string& input_line, DelimitedContainer<Delim, Container&>& dc) {
    Container& target = dc.ref;
    target.clear();

    istringstream iss(input_line);
    string item;

    while (getline(iss, item, Delim)) {
        if (!item.empty()) {
            InputControl::trim(item);

            // ����� ����������
            auto it = find_if(target.begin(), target.end(),
                [&item](const string& s) {
                    return get_lowercase(s) == get_lowercase(item);
                });

            // ���������� � ������ ���������� ��������
            if (it == target.end()) {
                make_first_letter_uppercase(item);
                target.push_back(item);
            }
        }
    }
}

/**
 * @brief ��������� ����� �� ��������� � ��������
 * @tparam T ��� �����
 * @param number ����������� �����
 * @param min ����������� ��������
 * @param max ������������ ��������
 * @return true ���� ����� � ���������, ����� false
 * @details ������� ��������� �� ������ ���� ����� ��� ���������
 */
template <typename T>
bool InputControl::check_min_max(const T& number, T min, T max) {
    if (number < min) { 
        cout << endl << "�� ����� \"" << number << "\" � �������� ������ ���� �� ������ \"" << min << "\"" << endl << endl; 
        return false; 
    }
    if (number > max) { 
        cout << endl << "�� ����� \"" << number << "\" � �������� ������ ���� �� ������ \"" << max << "\"" << endl << endl; 
        return false; 
    }
    return true;
}

/**
 * @brief ������� ����� ��� �����
 * @tparam T �������������� ��� ������
 * @param varLink ������ �� ���������� ��� ���������� ����������
 * @param label ������� ��� �����
 * @param min ����������� ��������
 * @param max ������������ ��������
 * @return true ���� �������� ��������, ����� false
 * @details ����������� ���� ���� �� ����� �������� ���������� ����� � �������� ���������
 */
template <typename T>
enable_if_t<is_arithmetic_v<T>, bool>
InputControl::input(T& varLink, const string& label, T min, T max) {
    string raw_input;
    T number = 0;

    while(true) {
        cout << label;
        getline(cin, raw_input);
        trim(raw_input);
        if (is_input_empty(raw_input)) return true;  // ������ ��������
        stringstream ss(raw_input);
        if (ss >> number && ss.eof()) {
            if (check_min_max(number, min, max)) break;
        }
        else cout << endl << "�������� �������� \"" << raw_input << "\" �� �������� ������!" << endl << endl;
    }

    varLink = number;
    return false;  // ����������� ��������
}

#endif // KONDAKOV_LR5_INPUT_CONTROL_HPP