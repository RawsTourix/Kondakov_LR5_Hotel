/**
 * @file kondakov_lr5_standard_room.hpp
 * @brief Реализация методов класса StandardRoom
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#ifndef KONDAKOV_LR5_STANDARD_ROOM_HPP
#define KONDAKOV_LR5_STANDARD_ROOM_HPP

#include "kondakov_lr5_standard_room.h"

/**
 * @brief Получить количество кроватей
 * @return Количество кроватей
 */
inline int StandardRoom::get_bed_count() const {
    return bed_count;
}

/**
 * @brief Получить наличие телевизора
 * @return true если есть телевизор, иначе false
 */
inline bool StandardRoom::get_has_tv() const {
    return has_tv;
}

/**
 * @brief Получить список удобств
 * @return Константная ссылка на вектор удобств
 */
inline const vector<string>& StandardRoom::get_amenities() const {
    return amenities;
}

/**
 * @brief Получить полное название комнаты
 * @return Строка с полным названием комнаты
 */
inline string StandardRoom::get_full_name() const {
    ostringstream oss;
    oss << ROOM_TYPE << " №" << room_number;
    return oss.str();
}

/**
 * @brief Установить количество кроватей
 * @param bed_count Новое количество кроватей
 */
inline void StandardRoom::set_bed_count(int bed_count) {
    this->bed_count = bed_count;
}

/**
 * @brief Установить наличие телевизора
 * @param has_tv Наличие телевизора
 */
inline void StandardRoom::set_has_tv(bool has_tv) {
    this->has_tv = has_tv;
}

/**
 * @brief Установить список удобств
 * @param amenities Новый список удобств
 */
inline void StandardRoom::set_amenities(vector<string> amenities) {
    this->amenities = move(amenities);
}

/**
 * @brief Ввод количества кроватей
 * @return true если операция отменена, иначе false
 */
inline bool StandardRoom::input_bed_count() {
    if (InputControl::input(bed_count, "Количество кроватей: ", 1, 5)) { return true; }
    return false;
}

/**
 * @brief Ввод наличия телевизора
 * @return true если операция отменена, иначе false
 */
inline bool StandardRoom::input_has_tv() {
    if (InputControl::input(has_tv, "Наличие телевизора (1/0): ")) { return true; }
    return false;
}

/**
 * @brief Ввод удобств с разделителем
 * @tparam Delim Разделитель для ввода
 * @return true если операция отменена, иначе false
 */
template <char Delim>
inline bool StandardRoom::input_amenities() {
    cout << "Ввод удобств осуществляется в одну строку через разделитель '" << Delim << "'." << endl;
    cout << "Удобства: ";
    InputControl::DelimitedContainer<Delim, vector<string>&> dc(amenities);
    if (cin >> dc) { return false; }
    else { cin.clear(); return true; }
}

/**
 * @brief Получить тип комнаты
 * @return Константная ссылка на строку с типом комнаты
 */
inline const string& StandardRoom::get_room_type() const {
    return ROOM_TYPE;
}

/**
 * @brief Получить тип для JSON
 * @return Константная ссылка на строку с типом для JSON
 */
inline const string& StandardRoom::get_json_type() const {
    return JSON_TYPE;
}

/**
 * @brief Расчет общей стоимости проживания
 * @param night_count Количество ночей
 * @return Общая стоимость
 */
inline float StandardRoom::calculate_total(int night_count) const {
    return price_per_night * static_cast<float>(night_count);
}

/**
 * @brief Проверка валидности номера
 * @return true если номер валиден (количество кроватей >= 1), иначе false
 */
inline bool StandardRoom::validate() const {
    return bed_count >= 1;
}

/**
 * @brief Добавить дополнительную кровать
 * @details Увеличивает цену на 20% и количество кроватей на 1
 */
inline void StandardRoom::exstra_bed() {
    price_per_night += price_per_night * 0.2f;
    bed_count++;
}

#endif // KONDAKOV_LR5_STANDARD_ROOM_HPP