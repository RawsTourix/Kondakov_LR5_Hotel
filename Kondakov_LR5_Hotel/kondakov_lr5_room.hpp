/**
 * @file kondakov_lr5_room.hpp
 * @brief Реализация методов класса Room
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#ifndef KONDAKOV_LR5_ROOM_HPP
#define KONDAKOV_LR5_ROOM_HPP

#include "kondakov_lr5_room.h"

/**
 * @brief Получить номер комнаты
 * @return Номер комнаты
 */
inline int Room::get_room_number() const {
    return room_number;
}

/**
 * @brief Получить цену за ночь
 * @return Цена за ночь
 */
inline float Room::get_price_per_night() const {
    return price_per_night;
}

/**
 * @brief Получить статус бронирования
 * @return true если номер забронирован, иначе false
 */
inline bool Room::get_is_booked() const {
    return is_booked;
}

/**
 * @brief Установить номер комнаты
 * @param room_number Новый номер комнаты
 */
inline void Room::set_room_number(int room_number) {
    this->room_number = room_number;
}

/**
 * @brief Установить цену за ночь
 * @param price_per_night Новая цена за ночь
 */
inline void Room::set_price_per_night(float price_per_night) {
    this->price_per_night = price_per_night;
}

/**
 * @brief Установить статус бронирования
 * @param is_booked Новый статус бронирования
 */
inline void Room::set_is_booked(bool is_booked) {
    this->is_booked = is_booked;
}

/**
 * @brief Ввод номера комнаты
 * @return true если операция отменена, иначе false
 */
inline bool Room::input_room_number() {
    if (InputControl::input(room_number, "Номер комнаты: ", 1, 1000)) { return true; }
    return false;
}

/**
 * @brief Ввод номера комнаты с проверкой уникальности
 * @tparam Container Тип контейнера с номерами комнат
 * @param room_numbers Контейнер с существующими номерами комнат
 * @return true если операция отменена, иначе false
 */
template <typename Container>
inline typename enable_if_t<is_same_v<typename Container::value_type, int>, bool>
Room::input_room_number(const Container& room_numbers) {
    int room_number_temp = 0;
    if (InputControl::input(room_number_temp, "Номер комнаты: ", 1, 1000)) { return true; }

    while (find(room_numbers.begin(), room_numbers.end(), room_number_temp) != room_numbers.end()) {
        cout << endl << "Комната с номером \"" << room_number_temp << "\" уже существует!" << endl << endl;
        if (InputControl::input(room_number_temp, "Номер комнаты: ", 1, 1000)) { return true; }
    }

    room_number = room_number_temp;
    return false;
}

/**
 * @brief Ввод цены за ночь
 * @return true если операция отменена, иначе false
 */
inline bool Room::input_price_per_night() {
    ostringstream message;
    message << "Цена за ночь (" << CURRENCY << "): ";
    if (InputControl::input(price_per_night, message.str(), 0.0f, 100000.0f)) { return true; }
    return false;
}

/**
 * @brief Ввод статуса бронирования
 * @return true если операция отменена, иначе false
 */
inline bool Room::input_is_booked() {
    if (InputControl::input(is_booked, "Стасус бронирования (1/0): ")) { return true; }
    return false;
}

/**
 * @brief Вывод контейнера комнат
 * @tparam Container Тип контейнера (должен содержать shared_ptr<Room>)
 * @param os Поток вывода
 * @param rooms Контейнер с комнатами
 * @return Поток вывода
 */
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, ostream&>
operator<<(ostream& os, const Container& rooms) {
    for (const auto& room : rooms) {
        room->print();
    }
    return os;
}

#endif // KONDAKOV_LR5_ROOM_HPP