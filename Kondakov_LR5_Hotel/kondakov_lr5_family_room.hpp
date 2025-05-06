/**
 * @file kondakov_lr5_family_room.hpp
 * @brief Реализация методов класса FamilyRoom
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#ifndef KONDAKOV_LR5_FAMILY_ROOM_HPP
#define KONDAKOV_LR5_FAMILY_ROOM_HPP

#include "kondakov_lr5_family_room.h"

/**
 * @brief Получить количество детских кроватей
 * @return Количество детских кроватей
 */
inline int FamilyRoom::get_child_beds() const {
    return child_beds;
}

/**
 * @brief Получить наличие набора игрушек
 * @return true если набор есть, false если нет
 */
inline bool FamilyRoom::get_toy_kit() const {
    return toy_kit;
}

/**
 * @brief Получить список удобств
 * @return Константная ссылка на вектор удобств
 */
inline const vector<string>& FamilyRoom::get_amenities() const {
    return amenities;
}

/**
 * @brief Получить полное название комнаты
 * @return Строка вида "Семейная комната №X"
 */
inline string FamilyRoom::get_full_name() const {
    ostringstream oss;
    oss << ROOM_TYPE << " №" << room_number;
    return oss.str();
}

/**
 * @brief Установить количество детских кроватей
 * @param child_beds Новое количество кроватей
 */
inline void FamilyRoom::set_child_beds(int child_beds) {
    this->child_beds = child_beds;
}

/**
 * @brief Установить наличие набора игрушек
 * @param toy_kit Новое значение наличия набора
 */
inline void FamilyRoom::set_toy_kit(bool toy_kit) {
    this->toy_kit = toy_kit;
}

/**
 * @brief Установить список удобств
 * @param amenities Новый список удобств
 */
inline void FamilyRoom::set_amenities(vector<string> amenities) {
    this->amenities = move(amenities);
}

/**
 * @brief Ввод количества детских кроватей
 * @return true если ввод отменен, false если успешен
 * @note Использует оператор [] для доступа к полю
 */
inline bool FamilyRoom::input_child_beds() {
    if (InputControl::input((*this).operator[]<int>(2), "Количество детских кроватей: ", 1, 5)) { 
        return true; 
    }
    return false;
}

/**
 * @brief Ввод наличия набора игрушек
 * @return true если ввод отменен, false если успешен
 * @note Использует оператор [] для доступа к полю
 */
inline bool FamilyRoom::input_toy_kit() {
    if (InputControl::input((*this).operator[]<bool>(3), "Наличие набора детских игрушек: (1/0): ")) { 
        return true; 
    }
    return false;
}

/**
 * @brief Ввод удобств с разделителем
 * @tparam Delim Разделитель (по умолчанию ',')
 * @return true если ввод отменен, false если успешен
 */
template <char Delim>
inline bool FamilyRoom::input_amenities() {
    cout << "Ввод удобств осуществляется в одну строку через разделитель '" << Delim << "'." << endl << endl;
    cout << "Удобства: ";
    InputControl::DelimitedContainer<Delim, vector<string>&> dc(amenities);
    if (cin >> dc) { return false; }
    else { cin.clear(); return true; }
}

/**
 * @brief Получить тип комнаты
 * @return Константная ссылка на строку с типом
 */
inline const string& FamilyRoom::get_room_type() const {
    return ROOM_TYPE;
}

/**
 * @brief Получить тип для JSON
 * @return Константная ссылка на строку с типом
 */
inline const string& FamilyRoom::get_json_type() const {
    return JSON_TYPE;
}

/**
 * @brief Расчет общей стоимости проживания
 * @param night_count Количество ночей
 * @return Общая стоимость (цена * ночи + 1000 руб./ребенок)
 */
inline float FamilyRoom::calculate_total(int night_count) const {
    return price_per_night * night_count + static_cast<float>(child_beds * 1000);
}

/**
 * @brief Проверка валидности номера
 * @return true если количество детских кроватей <= 4, иначе false
 */
inline bool FamilyRoom::validate() const {
    return child_beds <= 4;
}

/**
 * @brief Активировать игровую зону
 * @details Добавляет 1500 руб. к стоимости и устанавливает флаг наличия игрушек
 */
inline void FamilyRoom::add_play_area() {
    toy_kit = !toy_kit;
    price_per_night += 1500.0f * (toy_kit ? 1 : -1);
}

/**
 * @brief Деактивировать игровую зону
 * @details Убирает 1500 руб. из стоимости, если игровая зона была активна
 */
inline void FamilyRoom::remove_play_area() {
    if (toy_kit) {
        toy_kit = false;
        price_per_night -= 1500.0f;
    }
}

/**
 * @brief Шаблонный оператор доступа по индексу (const)
 * @tparam T Тип возвращаемого значения
 * @param index Индекс поля (0-4)
 * @return Значение запрошенного поля
 * @throw invalid_argument Если индекс не соответствует типу
 */
template <typename T>
typename enable_if_t<is_same_v<T, float>, T>
FamilyRoom::operator[](int index) const {
    if (index == 0) return child_care_price;
    throw invalid_argument("Неверный индекс для float");
}

template <typename T>
typename enable_if_t<is_same_v<T, bool>, T>
FamilyRoom::operator[](int index) const {
    if (index == 1) return has_child_care;
    if (index == 3) return toy_kit;
    throw invalid_argument("Неверный индекс для bool");
}

template <typename T>
typename enable_if_t<is_same_v<T, int>, T>
FamilyRoom::operator[](int index) const {
    if (index == 2) return child_beds;
    throw invalid_argument("Неверный индекс для int");
}

template <typename T>
typename enable_if_t<is_same_v<T, string>, T>
FamilyRoom::operator[](int index) const {
    if (index == 4) return amenities;
    throw invalid_argument("Неверный индекс для string");
}

/**
 * @brief Шаблонный оператор доступа по индексу (non-const)
 * @tparam T Тип возвращаемого значения
 * @param index Индекс поля (0-4)
 * @return Ссылка на запрошенное поле
 * @throw invalid_argument Если индекс не соответствует типу
 */
template <typename T>
typename enable_if_t<is_same_v<T, float>, T&>
FamilyRoom::operator[](int index) {
    if (index == 0) return child_care_price;
    throw invalid_argument("Неверный индекс для float");
}

template <typename T>
typename enable_if_t<is_same_v<T, bool>, T&>
FamilyRoom::operator[](int index) {
    if (index == 1) return has_child_care;
    if (index == 3) return toy_kit;
    throw invalid_argument("Неверный индекс для bool");
}

template <typename T>
typename enable_if_t<is_same_v<T, int>, T&>
FamilyRoom::operator[](int index) {
    if (index == 2) return child_beds;
    throw invalid_argument("Неверный индекс для int");
}

template <typename T>
typename enable_if_t<is_same_v<T, string>, T&>
FamilyRoom::operator[](int index) {
    if (index == 4) return amenities;
    throw invalid_argument("Неверный индекс для string");
}

#endif // KONDAKOV_LR5_FAMILY_ROOM_HPP