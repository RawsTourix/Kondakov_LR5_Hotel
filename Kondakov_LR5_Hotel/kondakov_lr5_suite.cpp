/**
 * @file kondakov_lr5_suite.cpp
 * @brief Реализация методов класса Suite
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#include "kondakov_lr5_suite.h"

/**
 * @brief Конструктор по умолчанию
 */
Suite::Suite()
    : Room(),
    room_service(true),
    jacuzzi(false),
    amenities({ "Lux", "Room service" }) {
}

/**
 * @brief Конструктор преобразования
 * @param room_number Номер комнаты
 * @param room_service Наличие обслуживания
 */
Suite::Suite(int room_number, bool room_service)
    : Room(room_number),
    room_service(room_service),
    jacuzzi(false),
    amenities({ "Lux", "Room service" }) {
}

/**
 * @brief Конструктор с удобствами по умолчанию
 * @param room_number Номер комнаты
 * @param price_per_night Цена за ночь
 * @param is_booked Статус бронирования
 * @param room_service Наличие обслуживания
 * @param jacuzzi Наличие джакузи
 */
Suite::Suite(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi)
    : Suite(room_number, price_per_night, is_booked, room_service, jacuzzi, "Lux, room service") {
}

/**
 * @brief Конструктор с параметрами (удобства строка)
 * @param room_number Номер комнаты
 * @param price_per_night Цена за ночь
 * @param is_booked Статус бронирования
 * @param room_service Наличие обслуживания
 * @param jacuzzi Наличие джакузи
 * @param amenities Удобства (строка с разделителями)
 */
Suite::Suite(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi, string amenities)
    : Room(room_number, price_per_night, is_booked),
    room_service(room_service),
    jacuzzi(jacuzzi)
{
    InputControl::DelimitedContainer<',', vector<string>&> dc(this->amenities);
    dc >> amenities;
}

/**
 * @brief Конструктор с параметрами (удобства вектор)
 * @param room_number Номер комнаты
 * @param price_per_night Цена за ночь
 * @param is_booked Статус бронирования
 * @param room_service Наличие обслуживания
 * @param jacuzzi Наличие джакузи
 * @param amenities Удобства (вектор строк)
 */
Suite::Suite(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi, vector<string> amenities)
    : Room(room_number, price_per_night, is_booked),
    room_service(room_service),
    jacuzzi(jacuzzi),
    amenities(amenities) {
}

/**
 * @brief Конструктор перемещения
 * @param other Другой объект Suite
 */
Suite::Suite(Suite&& other) noexcept
    : Room(move(other)),
    room_service(other.room_service),
    jacuzzi(other.jacuzzi),
    amenities(move(other.amenities)) {
}

/**
 * @brief Преобразование в JSON
 * @return JSON объект с данными номера
 */
json Suite::to_json() const {
    return {
        { "room_number", room_number },
        { "price_per_night", price_per_night },
        { "is_booked", is_booked },
        { "room_service", room_service },
        { "jacuzzi", jacuzzi },
        { "amenities", amenities }
    };
}

/**
 * @brief Загрузка из JSON
 * @param j JSON объект с данными номера
 */
void Suite::from_json(const json& j) {
    room_number = j["room_number"];
    price_per_night = j["price_per_night"];
    is_booked = j["is_booked"];
    room_service = j["room_service"];
    jacuzzi = j["jacuzzi"];
    amenities = j["amenities"];
}

/// @name Операторы сложения удобств
/// @{
vector<string> operator+(const Suite& s1, const Suite& s2) {
    vector<string> a(s1.amenities);
    a += s2;
    return a;
}
vector<string> operator+(const vector<string>& amenities, const Suite& s) {
    vector<string> a(amenities);
    a += s;
    return a;
}
vector<string> operator+(const Suite& s, const vector<string>& amenities) {
    vector<string> a(s.amenities);
    a += amenities;
    return a;
}
vector<string>& operator+=(vector<string>& amenities, const Suite& s) {
    amenities += s.amenities;
    return amenities;
}
Suite& operator+=(Suite& s, const vector<string>& amenities) {
    s.amenities += amenities;
    return s;
}
Suite& operator+=(Suite& s, const string& amenities) {
    s.amenities += amenities;
    return s;
}
/// @}

/**
 * @brief Преобразование в строку
 */
Suite::operator string() const {
    ostringstream oss;
    oss << "Наличие обслуживания:\t\t" << (room_service ? "да" : "нет") << endl
        << "Наличие джакузи:\t\t"   << (jacuzzi ? "да" : "нет") << endl
        << "Удобства:\t\t\t"       << amenities;
    return oss.str();
}

/**
 * @brief Оператор вывода
 * @param os Поток вывода
 * @param sr Комната для вывода
 * @return Поток вывода
 */
ostream& operator<<(ostream& os, const Suite& sr) {
    os << static_cast<string>(sr);
    return os;
}

/**
 * @brief Оператор ввода
 * @param is Поток ввода
 * @param s Комната для ввода
 * @return Поток ввода
 */
istream& operator>>(istream& is, Suite& s) {
    if (s.input_room_service())   { is.setstate(ios::failbit); return is; }
    if (s.input_jacuzzi())        { is.setstate(ios::failbit); return is; }
    if (s.input_amenities<','>()) { is.setstate(ios::failbit); return is; }
    return is;
}

/**
 * @brief Вывод информации о номере
 */
void Suite::print() const {
    cout << this->to_string() << endl << endl;
}

/**
 * @brief Ввод информации о номере
 * @return true если операция отменена, иначе false
 */
bool Suite::input() {
    if (Room::input()) {
        if (cin >> *this) {
            return true;
        }
    }
    cin.clear();
    return false;
}

/**
 * @brief Преобразование в строку
 * @return Строковое представление номера
 */
string Suite::to_string() const {
    ostringstream oss;
    oss << "[" << get_full_name() << "]" << endl;
    oss << Room::to_string() << endl;
    oss << *this;
    return oss.str();
}