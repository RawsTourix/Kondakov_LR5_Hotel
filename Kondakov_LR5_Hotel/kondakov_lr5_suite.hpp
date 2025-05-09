/**
 * @file kondakov_lr5_suite.hpp
 * @brief Реализация методов класса Suite
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#ifndef KONDAKOV_LR5_SUITE_HPP
#define KONDAKOV_LR5_SUITE_HPP

#include "kondakov_lr5_suite.h"

/**
 * @brief Получить наличие обслуживания
 * @return true если есть обслуживание, иначе false
 */
inline bool Suite::get_room_service() const {
    return room_service;
}

/**
 * @brief Получить наличие джакузи
 * @return true если есть джакузи, иначе false
 */
inline bool Suite::get_jacuzzi() const {
    return jacuzzi;
}

/**
 * @brief Получить список удобств
 * @return Константная ссылка на вектор удобств
 */
inline const vector<string>& Suite::get_amenities() const {
    return amenities;
}

/**
 * @brief Получить полное название комнаты
 * @return Строка с названием формата "Люкс комната №X"
 */
inline string Suite::get_full_name() const {
    ostringstream oss;
    oss << ROOM_TYPE << " №" << room_number;
    return oss.str();
}

/**
 * @brief Установить наличие обслуживания
 * @param room_service Новое значение
 */
inline void Suite::set_room_service(bool room_service) {
    this->room_service = room_service;
}

/**
 * @brief Установить наличие джакузи
 * @param jacuzzi Новое значение
 */
inline void Suite::set_jacuzzi(bool jacuzzi) {
    this->jacuzzi = jacuzzi;
}

/**
 * @brief Установить список удобств
 * @param amenities Новый список удобств
 */
inline void Suite::set_amenities(vector<string> amenities) {
    this->amenities = move(amenities);
}

/**
 * @brief Ввод наличия обслуживания
 * @return true если операция отменена, иначе false
 */
inline bool Suite::input_room_service() {
    if (InputControl::input(room_service, "Наличие обслуживания (1/0): ")) { return true; }
    return false;
}

/**
 * @brief Ввод наличия джакузи
 * @return true если операция отменена, иначе false
 */
inline bool Suite::input_jacuzzi() {
    if (InputControl::input(jacuzzi, "Наличие джакузи (1/0): ")) { return true; }
    return false;
}

/**
 * @brief Ввод удобств с разделителем
 * @tparam Delim Разделитель для ввода
 * @return true если операция отменена, иначе false
 */
template <char Delim>
inline bool Suite::input_amenities() {
    cout << "Ввод удобств осуществляется в одну строку через разделитель '" << Delim << "'." << endl;
    cout << "Удобства: ";
    InputControl::DelimitedContainer<Delim, vector<string>&> dc(amenities);
    if (cin >> dc) { return false; }
    else { cin.clear(); return true; }
}

/**
 * @brief Получить тип комнаты
 * @return Константная ссылка на строку с типом
 */
inline const string& Suite::get_room_type() const {
    return ROOM_TYPE;
}

/**
 * @brief Получить тип для JSON
 * @return Константная ссылка на строку с типом
 */
inline const string& Suite::get_json_type() const {
    return JSON_TYPE;
}

/**
 * @brief Расчет общей стоимости проживания
 * @param night_count Количество ночей
 * @return Общая стоимость (цена * ночи + фиксированная плата за услуги)
 */
inline float Suite::calculate_total(int night_count) const {
    return price_per_night * static_cast<float>(night_count) + SERVICE_PRICE;
}

/**
 * @brief Проверка валидности номера
 * @return true если общая стоимость за 1 ночь >= 10000, иначе false
 */
inline bool Suite::validate() const {
    return calculate_total(1) >= 10000.0f;
}

/**
 * @brief Добавить услугу
 * @param amenity Название услуги
 * @details Увеличивает цену на 2000 руб. и добавляет услугу в список
 */
inline void Suite::order_champagne(string amenity) {
    price_per_night += 2000.0f;
    InputControl::make_first_letter_uppercase(amenity);
    *this += amenity;
}

#endif // KONDAKOV_LR5_SUITE_HPP