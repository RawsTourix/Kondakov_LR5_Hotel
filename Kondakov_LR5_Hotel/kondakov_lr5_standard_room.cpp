/**
 * @file kondakov_lr5_standard_room.cpp
 * @brief Реализация методов класса StandardRoom
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#include "kondakov_lr5_standard_room.h"

/**
 * @brief Конструктор по умолчанию
 */
StandardRoom::StandardRoom()
    : Room(),
    bed_count(1),
    has_tv(false),
    amenities({ "Wi-Fi", "Air conditioner" }) {
}

/**
 * @brief Конструктор преобразования
 * @param room_number Номер комнаты
 * @param bed_count Количество кроватей
 */
StandardRoom::StandardRoom(int room_number, int bed_count)
    : Room(room_number),
    bed_count(bed_count),
    has_tv(false),
    amenities({ "Wi-Fi", "Air conditioner" }) {
}

/**
 * @brief Конструктор с удобствами по умолчанию
 * @param room_number Номер комнаты
 * @param price_per_night Цена за ночь
 * @param is_booked Статус бронирования
 * @param bed_count Количество кроватей
 * @param has_tv Наличие телевизора
 */
StandardRoom::StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv)
    : StandardRoom(room_number, price_per_night, is_booked, bed_count, has_tv, "Wi-Fi, air conditioner") {
}

/**
 * @brief Конструктор с параметрами (удобства строка)
 * @param room_number Номер комнаты
 * @param price_per_night Цена за ночь
 * @param is_booked Статус бронирования
 * @param bed_count Количество кроватей
 * @param has_tv Наличие телевизора
 * @param amenities Удобства (строка с разделителями)
 */
StandardRoom::StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv, string amenities)
    : Room(room_number, price_per_night, is_booked),
    bed_count(bed_count),
    has_tv(has_tv)
{
    InputControl::DelimitedContainer<',', vector<string>&> dc(this->amenities);
    dc >> amenities;
}

/**
 * @brief Конструктор с параметрами (удобства вектор)
 * @param room_number Номер комнаты
 * @param price_per_night Цена за ночь
 * @param is_booked Статус бронирования
 * @param bed_count Количество кроватей
 * @param has_tv Наличие телевизора
 * @param amenities Удобства (вектор строк)
 */
StandardRoom::StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv, vector<string> amenities)
    : Room(room_number, price_per_night, is_booked),
    bed_count(bed_count),
    has_tv(has_tv),
    amenities(amenities) {
}

/**
 * @brief Конструктор перемещения
 * @param other Другой объект StandardRoom
 */
StandardRoom::StandardRoom(StandardRoom&& other) noexcept
    : Room(move(other)),
    bed_count(exchange(other.bed_count, 0)),
    has_tv(other.has_tv),
    amenities(move(other.amenities)) {
}

/**
 * @brief Преобразование в JSON
 * @return JSON объект с данными номера
 */
json StandardRoom::to_json() const {
    return {
        { "room_number", room_number },
        { "price_per_night", price_per_night },
        { "is_booked", is_booked },
        { "bed_count", bed_count },
        { "has_tv", has_tv },
        { "amenities", amenities }
    };
}

/**
 * @brief Загрузка из JSON
 * @param j JSON объект с данными номера
 */
void StandardRoom::from_json(const json& j) {
    room_number = j["room_number"];
    price_per_night = j["price_per_night"];
    is_booked = j["is_booked"];
    bed_count = j["bed_count"];
    has_tv = j["has_tv"];
    amenities = j["amenities"];
}

/// @name Операторы сложения удобств
/// @{
vector<string> operator+(const StandardRoom& sr1, const StandardRoom& sr2) {
    vector<string> a(sr1.amenities);
    a += sr2;
    return a;
}
vector<string> operator+(const vector<string>& amenities, const StandardRoom& sr) {
    vector<string> a(amenities);
    a += sr;
    return a;
}
vector<string> operator+(const StandardRoom& sr, const vector<string>& amenities) {
    vector<string> a(sr.amenities);
    a += amenities;
    return a;
}
vector<string>& operator+=(vector<string>& amenities, const StandardRoom& sr) {
    amenities += sr.amenities;
    return amenities;
}
StandardRoom& operator+=(StandardRoom& sr, const vector<string>& amenities) {
    sr.amenities += amenities;
    return sr;
}
StandardRoom& operator+=(StandardRoom& sr, const string& amenities) {
    sr.amenities += amenities;
    return sr;
}
/// @}

/**
 * @brief Преобразование в строку
 */
StandardRoom::operator string() const {
    ostringstream oss;
    oss << "Количество кроватей:\t\t" << bed_count << endl
        << "Наличие телевизора:\t\t"  << (has_tv ? "да" : "нет") << endl
        << "Удобства:\t\t\t"          << amenities;
    return oss.str();
}

/**
 * @brief Оператор вывода
 * @param os Поток вывода
 * @param sr Комната для вывода
 * @return Поток вывода
 */
ostream& operator<<(ostream& os, const StandardRoom& sr) {
    os << static_cast<string>(sr);
    return os;
}

/**
 * @brief Оператор ввода
 * @param is Поток ввода
 * @param sr Комната для ввода
 * @return Поток ввода
 */
istream& operator>>(istream& is, StandardRoom& sr) {
    if (sr.input_bed_count())      { is.setstate(ios::failbit); return is; }
    if (sr.input_has_tv())         { is.setstate(ios::failbit); return is; }
    if (sr.input_amenities<','>()) { is.setstate(ios::failbit); return is; }
    return is;
}

/**
 * @brief Вывод информации о номере
 */
void StandardRoom::print() const {
    cout << this->to_string() << endl << endl;
}

/**
 * @brief Ввод информации о номере
 * @return true если операция отменена, иначе false
 */
bool StandardRoom::input() {
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
string StandardRoom::to_string() const {
    ostringstream oss;
    oss << "[" << get_full_name() << "]" << endl;
    oss << Room::to_string() << endl;
    oss << *this;
    return oss.str();
}