/**
 * @file kondakov_lr5_room.cpp
 * @brief Реализация методов класса Room
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#include "kondakov_lr5_room.h"

/// Валюта по умолчанию
const string Room::CURRENCY = "руб.";

/**
 * @brief Конструктор по умолчанию
 */
Room::Room()
    : Room(0, 0.0f, false) {
}

/**
 * @brief Конструктор преобразования
 * @param room_number Номер комнаты
 */
Room::Room(int room_number)
    : Room(room_number, 0.0f, false) {
}

/**
 * @brief Конструктор с параметрами
 * @param room_number Номер комнаты
 * @param price_per_night Цена за ночь
 * @param is_booked Статус бронирования
 */
Room::Room(int room_number, float price_per_night, bool is_booked)
    : room_number(room_number),
    price_per_night(price_per_night),
    is_booked(is_booked) {
}

/**
 * @brief Конструктор перемещения
 * @param other Другой объект Room
 */
Room::Room(Room&& other) noexcept
    : room_number(exchange(other.room_number, 0)),
    price_per_night(exchange(other.price_per_night, 0.0f)),
    is_booked(other.is_booked) {
}

/// @name Операторы сравнения
/// @{
bool operator==(const Room& r1, const Room& r2) { return r1.room_number == r2.room_number; }
bool operator==(int room_number, const Room& r2) { return room_number == r2.room_number; }
bool operator==(const Room& r1, int room_number) { return r1.room_number == room_number; }
bool operator>=(const Room& r1, const Room& r2) { return r1.room_number >= r2.room_number; }
bool operator>=(int room_number, const Room& r2) { return room_number >= r2.room_number; }
bool operator>=(const Room& r1, int room_number) { return r1.room_number >= room_number; }
bool operator<=(const Room& r1, const Room& r2) { return r1.room_number <= r2.room_number; }
bool operator<=(int room_number, const Room& r2) { return room_number <= r2.room_number; }
bool operator<=(const Room& r1, int room_number) { return r1.room_number <= room_number; }
bool operator> (const Room& r1, const Room& r2) { return r1.room_number > r2.room_number; }
bool operator> (int room_number, const Room& r2) { return room_number > r2.room_number; }
bool operator> (const Room& r1, int room_number) { return r1.room_number > room_number; }
bool operator< (const Room& r1, const Room& r2) { return r1.room_number < r2.room_number; }
bool operator< (int room_number, const Room& r2) { return room_number < r2.room_number; }
bool operator< (const Room& r1, int room_number) { return r1.room_number < room_number; }
bool operator!=(const Room& r1, const Room& r2) { return r1.room_number != r2.room_number; }
bool operator!=(int room_number, const Room& r2) { return room_number != r2.room_number; }
bool operator!=(const Room& r1, int room_number) { return r1.room_number != room_number; }
/// @}

/**
 * @brief Преобразование в строку
 */
Room::operator string() const {
    ostringstream oss;
    oss << "Цена за ночь:\t\t\t"      << price_per_night << " " << CURRENCY << endl
        << "Статус бронирования:\t\t" << (is_booked ? "да" : "нет");

    return oss.str();
}

/**
 * @brief Оператор вывода
 * @param os Поток вывода
 * @param r Комната для вывода
 * @return Поток вывода
 */
ostream& operator<<(ostream& os, const Room& r) {
    os << static_cast<string>(r);
    return os;
}

/**
 * @brief Оператор ввода
 * @param is Поток ввода
 * @param r Комната для ввода
 * @return Поток ввода
 */
istream& operator>>(istream& is, Room& r) {
    cout << "Введите информацию о комнате: " << endl << endl;
    if (r.input_room_number())     { is.setstate(ios::failbit); return is; }
    if (r.input_price_per_night()) { is.setstate(ios::failbit); return is; }
    if (r.input_is_booked())       { is.setstate(ios::failbit); return is; }
    return is;
}

/**
 * @brief Преобразование в строку
 * @return Строковое представление комнаты
 */
string Room::to_string() const {
    ostringstream oss;
    oss << *this;
    return oss.str();
}