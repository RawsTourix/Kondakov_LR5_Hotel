/**
 * @file kondakov_lr5_suite.cpp
 * @brief ���������� ������� ������ Suite
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#include "kondakov_lr5_suite.h"

/**
 * @brief ����������� �� ���������
 */
Suite::Suite()
    : Room(),
    room_service(true),
    jacuzzi(false),
    amenities({ "Lux", "Room service" }) {
}

/**
 * @brief ����������� ��������������
 * @param room_number ����� �������
 * @param room_service ������� ������������
 */
Suite::Suite(int room_number, bool room_service)
    : Room(room_number),
    room_service(room_service),
    jacuzzi(false),
    amenities({ "Lux", "Room service" }) {
}

/**
 * @brief ����������� � ���������� �� ���������
 * @param room_number ����� �������
 * @param price_per_night ���� �� ����
 * @param is_booked ������ ������������
 * @param room_service ������� ������������
 * @param jacuzzi ������� �������
 */
Suite::Suite(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi)
    : Suite(room_number, price_per_night, is_booked, room_service, jacuzzi, "Lux, room service") {
}

/**
 * @brief ����������� � ����������� (�������� ������)
 * @param room_number ����� �������
 * @param price_per_night ���� �� ����
 * @param is_booked ������ ������������
 * @param room_service ������� ������������
 * @param jacuzzi ������� �������
 * @param amenities �������� (������ � �������������)
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
 * @brief ����������� � ����������� (�������� ������)
 * @param room_number ����� �������
 * @param price_per_night ���� �� ����
 * @param is_booked ������ ������������
 * @param room_service ������� ������������
 * @param jacuzzi ������� �������
 * @param amenities �������� (������ �����)
 */
Suite::Suite(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi, vector<string> amenities)
    : Room(room_number, price_per_night, is_booked),
    room_service(room_service),
    jacuzzi(jacuzzi),
    amenities(amenities) {
}

/**
 * @brief ����������� �����������
 * @param other ������ ������ Suite
 */
Suite::Suite(Suite&& other) noexcept
    : Room(move(other)),
    room_service(other.room_service),
    jacuzzi(other.jacuzzi),
    amenities(move(other.amenities)) {
}

/**
 * @brief �������������� � JSON
 * @return JSON ������ � ������� ������
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
 * @brief �������� �� JSON
 * @param j JSON ������ � ������� ������
 */
void Suite::from_json(const json& j) {
    room_number = j["room_number"];
    price_per_night = j["price_per_night"];
    is_booked = j["is_booked"];
    room_service = j["room_service"];
    jacuzzi = j["jacuzzi"];
    amenities = j["amenities"];
}

/// @name ��������� �������� �������
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
 * @brief �������������� � ������
 */
Suite::operator string() const {
    ostringstream oss;
    oss << "������� ������������:\t\t" << (room_service ? "��" : "���") << endl
        << "������� �������:\t\t"   << (jacuzzi ? "��" : "���") << endl
        << "��������:\t\t\t"       << amenities;
    return oss.str();
}

/**
 * @brief �������� ������
 * @param os ����� ������
 * @param sr ������� ��� ������
 * @return ����� ������
 */
ostream& operator<<(ostream& os, const Suite& sr) {
    os << static_cast<string>(sr);
    return os;
}

/**
 * @brief �������� �����
 * @param is ����� �����
 * @param s ������� ��� �����
 * @return ����� �����
 */
istream& operator>>(istream& is, Suite& s) {
    if (s.input_room_service())   { is.setstate(ios::failbit); return is; }
    if (s.input_jacuzzi())        { is.setstate(ios::failbit); return is; }
    if (s.input_amenities<','>()) { is.setstate(ios::failbit); return is; }
    return is;
}

/**
 * @brief ����� ���������� � ������
 */
void Suite::print() const {
    cout << this->to_string() << endl << endl;
}

/**
 * @brief ���� ���������� � ������
 * @return true ���� �������� ��������, ����� false
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
 * @brief �������������� � ������
 * @return ��������� ������������� ������
 */
string Suite::to_string() const {
    ostringstream oss;
    oss << "[" << get_full_name() << "]" << endl;
    oss << Room::to_string() << endl;
    oss << *this;
    return oss.str();
}