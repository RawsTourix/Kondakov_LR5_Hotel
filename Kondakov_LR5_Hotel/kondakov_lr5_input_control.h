/**
 * @file kondakov_lr5_input_control.h
 * @brief Заголовочный файл для управления вводом данных
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup input_control
 */

#ifndef KONDAKOV_LR5_INPUT_CONTROL_H
#define KONDAKOV_LR5_INPUT_CONTROL_H

#include "kondakov_lr5_def.h"

/**
 * @namespace InputControl
 * @brief Пространство имён для функций управления вводом данных
 */
namespace InputControl {
    /**
     * @brief Шаблонный класс для работы с разделителями (базовый шаблон)
     * @tparam Delim Разделитель
     * @tparam Container Тип контейнера
     * @tparam SFINAE Вспомогательный параметр для SFINAE
     */
    template <char Delim, typename Container, typename = void>
    struct DelimitedContainer;

    /**
     * @brief Специализация DelimitedContainer для работы со строками
     * @tparam Delim Разделитель
     * @tparam Container Тип контейнера (должен содержать строки)
     */
    template <char Delim, typename Container>
    struct DelimitedContainer<Delim, Container&, enable_if_t<is_same_v<typename Container::value_type, string>, void>>;

    /**
     * @brief Удаляет пробелы в начале и конце строки
     * @param str Строка для обработки
     */
    void trim(string& str);

    /**
     * @brief Разделяет строку на подстроки по разделителю
     * @tparam Delim Разделитель
     * @tparam Container Тип контейнера для результатов
     * @param input_line Входная строка
     * @param dc Контейнер с разделителем
     */
    template <char Delim, typename Container>
    void split(const string& input_line, DelimitedContainer<Delim, Container&>& dc);

    /**
     * @brief Преобразует строку в нижний регистр
     * @param str Входная строка
     * @return Строка в нижнем регистре
     */
    string get_lowercase(const string str);

    /**
     * @brief Делает первую букву строки заглавной
     * @param str Строка для обработки
     */
    void make_first_letter_uppercase(string& str);

    /**
     * @brief Проверяет, является ли ввод пустым (для отмены операции)
     * @param input Входная строка
     * @return true если ввод пустой, иначе false
     */
    bool is_input_empty(const string& input);

    /**
     * @brief Проверяет число на вхождение в диапазон
     * @tparam T Тип числа
     * @param number Проверяемое число
     * @param min Минимальное значение
     * @param max Максимальное значение
     * @return true если число в диапазоне, иначе false
     */
    template <typename T>
    bool check_min_max(const T& number, T min, T max);

    /**
     * @brief Функция ввода для строк
     * @param varLink Ссылка на переменную для сохранения результата
     * @param label Подпись для ввода
     * @return true если операция отменена, иначе false
     */
    bool input(string& varLink, const string& label);
    
    /**
     * @brief Функция ввода для bool
     * @param varLink Ссылка на переменную для сохранения результата
     * @param label Подпись для ввода
     * @return true если операция отменена, иначе false
     */
    bool input(bool& varLink, const string& label);

    /**
     * @brief Функция ввода для чисел
     * @tparam T Арифметический тип данных
     * @param varLink Ссылка на переменную для сохранения результата
     * @param label Подпись для ввода
     * @param min Минимальное значение
     * @param max Максимальное значение
     * @return true если операция отменена, иначе false
     */
    template <typename T>
    enable_if_t<is_arithmetic_v<T>, bool>
    input(T& varLink, const string& label, T min = 0, T max = numeric_limits<T>::max());

    /**
     * @brief Получает один символ из ввода
     * @return Введённый символ
     */
    char get_char();

    /**
     * @brief Запрашивает подтверждение (y/n)
     * @param label Подпись для запроса
     * @return true если введено 'y' или 'Y', false если 'n' или 'N'
     */
    bool yes_or_no(const string& label);
}

#include "kondakov_lr5_input_control.hpp"
#include "kondakov_lr5_container_operations.hpp"  ///< Дополнение для работы с контейнерами

#endif // KONDAKOV_LR5_INPUT_CONTROL_H