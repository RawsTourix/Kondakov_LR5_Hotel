/**
 * @file kondakov_lr5_container_operations.hpp
 * @brief Операции с контейнерами строк
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup container_operations
 */

#ifndef KONDAKOV_LR5_CONTAINER_OPERATIONS_HPP
#define KONDAKOV_LR5_CONTAINER_OPERATIONS_HPP

#include "kondakov_lr5_input_control.h"

 /**
  * @brief Специализация DelimitedContainer для работы со строками
  * @tparam Delim Разделитель
  * @tparam Container Тип контейнера (должен содержать строки)
  * @details Хранит ссылку на контейнер строк для последующей обработки
  */
template <char Delim, typename Container>
struct InputControl::DelimitedContainer<Delim, Container&, enable_if_t<is_same_v<typename Container::value_type, string>, void>> {
    Container& ref; ///< Ссылка на целевой контейнер
    explicit DelimitedContainer(Container& r) : ref(r) {} ///< Конструктор
};

/**
 * @brief Перегрузка оператора вывода для контейнера строк
 * @tparam Container Тип контейнера (должен содержать строки)
 * @param os Поток вывода
 * @param strings Контейнер строк
 * @return Поток вывода
 * @details Выводит элементы контейнера через запятую
 */
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, ostream&>
operator<<(ostream& os, const Container& strings) {
    if (!strings.empty()) {
        auto it = strings.begin();
        os << *it;

        for (++it; it != strings.end(); ++it) {
            os << ", " << *it;
        }
    }
    return os;
}

/**
 * @brief Перегрузка оператора сложения для контейнеров строк
 * @tparam Container Тип контейнера (должен содержать строки)
 * @param lhs Левый операнд
 * @param rhs Правый операнд
 * @return Новый контейнер с объединёнными элементами
 * @details Объединяет контейнеры, исключая дубликаты
 */
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, Container>
operator+(const Container& lhs, const Container& rhs) {
    Container result = lhs;
    for (const auto& str : rhs) {
        if (find(result.begin(), result.end(), str) == result.end()) {
            result.push_back(str);
        }
    }
    return result;
}

/**
 * @brief Перегрузка оператора += для контейнеров строк
 * @tparam Container Тип контейнера (должен содержать строки)
 * @param lhs Левый операнд (изменяемый)
 * @param rhs Правый операнд
 * @return Ссылка на изменённый контейнер
 * @details Добавляет элементы из правого операнда, исключая дубликаты
 */
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, Container&>
operator+=(Container& lhs, const Container& rhs) {
    for (const auto& str : rhs) {
        if (find(lhs.begin(), lhs.end(), str) == lhs.end()) {
            lhs.push_back(str);
        }
    }
    return lhs;
}

/**
 * @brief Перегрузка оператора += для контейнера и строки
 * @tparam Container Тип контейнера (должен содержать строки)
 * @param lhs Левый операнд (изменяемый)
 * @param str Добавляемая строка
 * @return Ссылка на изменённый контейнер
 * @details Добавляет строку если её ещё нет в контейнере
 */
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, Container&>
operator+=(Container& lhs, const string& str) {
    if (find(lhs.begin(), lhs.end(), str) == lhs.end()) {
        lhs.push_back(str);
    }
    return lhs;
}

/**
 * @brief Перегрузка оператора ввода для DelimitedContainer
 * @tparam Delim Разделитель
 * @tparam Container Тип контейнера (должен содержать строки)
 * @param is Поток ввода
 * @param dc Контейнер с разделителем
 * @return Поток ввода
 * @details Считывает строку и разделяет её по разделителю в контейнер
 */
template <char Delim, typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, istream&>
operator>>(istream& is, InputControl::DelimitedContainer<Delim, Container&>& dc) {
    string input_line;

    if (!getline(is, input_line)) {
        is.setstate(ios::failbit);
        return is;
    }

    InputControl::trim(input_line);
    if (InputControl::is_input_empty(input_line)) {
        is.setstate(ios::failbit);
        return is;
    }

    InputControl::split(input_line, dc);
    return is;
}

/**
 * @brief Перегрузка оператора >> для разделения строки в контейнер
 * @tparam Delim Разделитель
 * @tparam Container Тип контейнера (должен содержать строки)
 * @param dc Контейнер с разделителем
 * @param input_line Входная строка
 * @return Ссылка на изменённый контейнер
 */
template <char Delim, typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, Container&>
operator>>(InputControl::DelimitedContainer<Delim, Container&>& dc, const string& input_line) {
    InputControl::split(input_line, dc);
    return dc.ref;
}

#endif // KONDAKOV_LR5_CONTAINER_OPERATIONS_HPP