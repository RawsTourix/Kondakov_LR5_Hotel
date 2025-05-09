/**
 * @file kondakov_lr5_input_control.hpp
 * @brief Реализация шаблонных функций управления вводом
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup input_control
 */

#ifndef KONDAKOV_LR5_INPUT_CONTROL_HPP
#define KONDAKOV_LR5_INPUT_CONTROL_HPP

#include "kondakov_lr5_input_control.h"

/**
 * @brief Разделяет строку на подстроки по разделителю
 * @tparam Delim Разделитель
 * @tparam Container Тип контейнера для результатов
 * @param input_line Входная строка
 * @param dc Контейнер с разделителем
 * @details Очищает целевой контейнер, разделяет строку по разделителю,
 *          удаляет пустые элементы, проверяет на дубликаты (без учёта регистра),
 *          делает первую букву каждого элемента заглавной
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

            // Поиск дубликатов
            auto it = find_if(target.begin(), target.end(),
                [&item](const string& s) {
                    return get_lowercase(s) == get_lowercase(item);
                });

            // Добавление с учётом параметров регистра
            if (it == target.end()) {
                make_first_letter_uppercase(item);
                target.push_back(item);
            }
        }
    }
}

/**
 * @brief Проверяет число на вхождение в диапазон
 * @tparam T Тип числа
 * @param number Проверяемое число
 * @param min Минимальное значение
 * @param max Максимальное значение
 * @return true если число в диапазоне, иначе false
 * @details Выводит сообщение об ошибке если число вне диапазона
 */
template <typename T>
bool InputControl::check_min_max(const T& number, T min, T max) {
    if (number < min) { 
        cout << endl << "Вы ввели \"" << number << "\" — значение должно быть не меньше \"" << min << "\"" << endl << endl; 
        return false; 
    }
    if (number > max) { 
        cout << endl << "Вы ввели \"" << number << "\" — значение должно быть не больше \"" << max << "\"" << endl << endl; 
        return false; 
    }
    return true;
}

/**
 * @brief Функция ввода для чисел
 * @tparam T Арифметический тип данных
 * @param varLink Ссылка на переменную для сохранения результата
 * @param label Подпись для ввода
 * @param min Минимальное значение
 * @param max Максимальное значение
 * @return true если операция отменена, иначе false
 * @details Запрашивает ввод пока не будет получено корректное число в заданном диапазоне
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
        if (is_input_empty(raw_input)) return true;  // Отмена операции
        stringstream ss(raw_input);
        if (ss >> number && ss.eof()) {
            if (check_min_max(number, min, max)) break;
        }
        else cout << endl << "Введённое значение \"" << raw_input << "\" не является числом!" << endl << endl;
    }

    varLink = number;
    return false;  // Продолжение операции
}

#endif // KONDAKOV_LR5_INPUT_CONTROL_HPP