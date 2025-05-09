/**
 * @file kondakov_lr5_family_room.cpp
 * @brief Реализация методов класса FamilyRoom
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#include "kondakov_lr5_family_room.h"

/**
 * @brief Конструктор по умолчанию
 */
FamilyRoom::FamilyRoom()
    : Room(),
      ChildCare(),
      child_beds(1),
      toy_kit(false),
      amenities({ "Wi-Fi", "Air condition" }) {
}

/**
 * @brief Конструктор преобразования
 * @param room_number Номер комнаты
 * @param child_beds Количество детских кроватей
 */
FamilyRoom::FamilyRoom(int room_number, int child_beds)
    : Room(room_number),
      ChildCare(true),
      child_beds(child_beds),
      toy_kit(false),
      amenities({"Wi-Fi", "Air condition"}) {
}

/**
 * @brief Конструктор с удобствами по умолчанию
 * @param room_number Номер комнаты
 * @param price_per_night Цена за ночь
 * @param is_booked Статус бронирования
 * @param child_care_price Стоимость услуг для детей
 * @param has_child_care Наличие услуг для детей
 * @param child_beds Количество детских кроватей
 * @param toy_kit Наличие набора игрушек
 */
FamilyRoom::FamilyRoom(int room_number, float price_per_night, bool is_booked,
                     float child_care_price, bool has_child_care,
                     int child_beds, bool toy_kit)
    : FamilyRoom(room_number, price_per_night, is_booked, child_care_price,
                has_child_care, child_beds, toy_kit, "Wi-Fi, air condition") {
}

/**
 * @brief Конструктор с параметрами (удобства строка)
 * @param room_number Номер комнаты
 * @param price_per_night Цена за ночь
 * @param is_booked Статус бронирования
 * @param child_care_price Стоимость услуг для детей
 * @param has_child_care Наличие услуг для детей
 * @param child_beds Количество детских кроватей
 * @param toy_kit Наличие набора игрушек
 * @param amenities Список удобств (строка, разделитель - запятая)
 */
FamilyRoom::FamilyRoom(int room_number, float price_per_night, bool is_booked,
                     float child_care_price, bool has_child_care,
                     int child_beds, bool toy_kit, string amenities)
    : Room(room_number, price_per_night, is_booked),
      ChildCare(child_care_price, has_child_care),
      child_beds(child_beds),
      toy_kit(toy_kit) {
    InputControl::DelimitedContainer<',', vector<string>&> dc(this->amenities);
    dc >> amenities;
}

/**
 * @brief Конструктор с параметрами (удобства вектор)
 * @param room_number Номер комнаты
 * @param price_per_night Цена за ночь
 * @param is_booked Статус бронирования
 * @param child_care_price Стоимость услуг для детей
 * @param has_child_care Наличие услуг для детей
 * @param child_beds Количество детских кроватей
 * @param toy_kit Наличие набора игрушек
 * @param amenities Список удобств (вектор строк)
 */
FamilyRoom::FamilyRoom(int room_number, float price_per_night, bool is_booked,
    float child_care_price, bool has_child_care,
    int child_beds, bool toy_kit, vector<string> amenities)
    : Room(room_number, price_per_night, is_booked),
    ChildCare(child_care_price, has_child_care),
    child_beds(child_beds),
    toy_kit(toy_kit),
    amenities(amenities) {
}

/**
 * @brief Конструктор перемещения
 * @param other Другой объект FamilyRoom
 */
FamilyRoom::FamilyRoom(FamilyRoom&& other) noexcept
    : Room(move(other)),
      ChildCare(move(other)),
      child_beds(other.child_beds),
      toy_kit(other.toy_kit) {
}

/**
 * @brief Преобразование в JSON
 * @return JSON объект с данными номера
 */
json FamilyRoom::to_json() const {
    return {
        { "room_number", room_number },
        { "price_per_night", price_per_night },
        { "is_booked", is_booked },
        { "child_care_price", child_care_price },
        { "has_child_care", has_child_care },
        { "child_beds", child_beds },
        { "toy_kit", toy_kit },
        { "amenities", amenities }
    };
}

/**
 * @brief Загрузка из JSON
 * @param j JSON объект с данными номера
 */
void FamilyRoom::from_json(const json& j) {
    room_number = j["room_number"];
    price_per_night = j["price_per_night"];
    is_booked = j["is_booked"];
    child_care_price = j["child_care_price"];
    has_child_care = j["has_child_care"];
    child_beds = j["child_beds"];
    toy_kit = j["toy_kit"];
    amenities = j["amenities"];
}

/**
 * @brief Оператор доступа по индексу (строковая версия)
 * @param index Индекс поля (0-4)
 * @return Строковое представление запрошенного поля
 * @throw out_of_range Если индекс вне диапазона
 */
string FamilyRoom::operator[](int index) const {
    ostringstream oss;
    switch (index) {
        case 0: oss << "Стоимость услуг для детей: " << child_care_price; break;
        case 1: oss << "Наличие услуг для детей: " << has_child_care; break;
        case 2: oss << "Количество детских кроватей: " << child_beds; break;
        case 3: oss << "Наличие набора детских игрушек: " << toy_kit; break;
        case 4: oss << "Удобства: " << amenities; break;
        default: 
            ostringstream error;
            error << "Значение \"" << index << "\" вне допустимого диапазона (0-4)";
            throw out_of_range(error.str());
    }
    return oss.str();
}

/// @name Операторы сложения удобств
/// @{
vector<string> operator+(const FamilyRoom& fr1, const FamilyRoom& fr2) {
    vector<string> a(fr1.amenities);
    a += fr2;
    return a;
}

vector<string> operator+(const vector<string>& amenities, const FamilyRoom& fr) {
    vector<string> a(amenities);
    a += fr;
    return a;
}

vector<string> operator+(const FamilyRoom& fr, const vector<string>& amenities) {
    vector<string> a(fr.amenities);
    a += amenities;
    return a;
}

vector<string>& operator+=(vector<string>& amenities, const FamilyRoom& fr) {
    amenities += fr.amenities;
    return amenities;
}

FamilyRoom& operator+=(FamilyRoom& fr, const vector<string>& amenities) {
    fr.amenities += amenities;
    return fr;
}

FamilyRoom& operator+=(FamilyRoom& fr, const string& amenities) {
    fr.amenities += amenities;
    return fr;
}
/// @}

/**
 * @brief Преобразование в строку
 */
FamilyRoom::operator string() const {
    ostringstream oss;
    oss << "Количество детских кроватей:\t"    << child_beds << endl
        << "Наличие набора детских игрушек:\t" << (toy_kit ? "да" : "нет") << endl
        << "Удобства:\t\t\t"                   << amenities;
    return oss.str();
}

/**
 * @brief Оператор вывода
 * @param os Поток вывода
 * @param fr Комната для вывода
 * @return Поток вывода
 */
ostream& operator<<(ostream& os, const FamilyRoom& fr) {
    os << static_cast<string>(fr);
    return os;
}

/**
 * @brief Оператор ввода
 * @param is Поток ввода
 * @param fr Комната для ввода
 * @return Поток ввода
 */
istream& operator>>(istream& is, FamilyRoom& fr) {
    if (fr.input_child_beds())      { is.setstate(ios::failbit); return is; }
    if (fr.input_toy_kit())         { is.setstate(ios::failbit); return is; }
    if (fr.input_amenities<','>())  { is.setstate(ios::failbit); return is; }
    return is;
}

/**
 * @brief Вывод информации о номере
 */
void FamilyRoom::print() const {
    cout << this->to_string() << endl << endl;
}

/**
 * @brief Ввод информации о номере
 * @return true если ввод отменен, false если успешен
 */
bool FamilyRoom::input() {
    if (Room::input()) {          // Ввод базовой информации
        if (ChildCare::input()) { // Ввод информации об услугах
            if (cin >> *this) {   // Ввод специфичной информации
                return true;
            }
        }
    }
    cin.clear();
    return false;
}

/**
 * @brief Преобразование в строку
 * @return Полное строковое представление номера
 */
string FamilyRoom::to_string() const {
    ostringstream oss;
    oss << "[" << get_full_name() << "]" << endl;
    oss << Room::to_string() << endl;
    oss << ChildCare::to_string() << endl;
    oss << *this;
    return oss.str();
}