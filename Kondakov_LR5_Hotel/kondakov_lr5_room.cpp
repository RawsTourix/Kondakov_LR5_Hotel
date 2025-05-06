/**
 * @file kondakov_lr5_room.cpp
 * @brief ���������� ������� ������ Room
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#include "kondakov_lr5_room.h"

/// ������ �� ���������
const string Room::CURRENCY = "���.";

/**
 * @brief ����������� �� ���������
 */
Room::Room()
    : Room(0, 0.0f, false) {
}

/**
 * @brief ����������� ��������������
 * @param room_number ����� �������
 */
Room::Room(int room_number)
    : Room(room_number, 0.0f, false) {
}

/**
 * @brief ����������� � �����������
 * @param room_number ����� �������
 * @param price_per_night ���� �� ����
 * @param is_booked ������ ������������
 */
Room::Room(int room_number, float price_per_night, bool is_booked)
    : room_number(room_number),
    price_per_night(price_per_night),
    is_booked(is_booked) {
}

/**
 * @brief ����������� �����������
 * @param other ������ ������ Room
 */
Room::Room(Room&& other) noexcept
    : room_number(exchange(other.room_number, 0)),
    price_per_night(exchange(other.price_per_night, 0.0f)),
    is_booked(other.is_booked) {
}

/// @name ��������� ���������
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
 * @brief �������������� � ������
 */
Room::operator string() const {
    ostringstream oss;
    oss << "���� �� ����:\t\t\t"      << price_per_night << " " << CURRENCY << endl
        << "������ ������������:\t\t" << (is_booked ? "��" : "���");

    return oss.str();
}

/**
 * @brief �������� ������
 * @param os ����� ������
 * @param r ������� ��� ������
 * @return ����� ������
 */
ostream& operator<<(ostream& os, const Room& r) {
    os << static_cast<string>(r);
    return os;
}

/**
 * @brief �������� �����
 * @param is ����� �����
 * @param r ������� ��� �����
 * @return ����� �����
 */
istream& operator>>(istream& is, Room& r) {
    cout << "������� ���������� � �������: " << endl << endl;
    if (r.input_room_number())     { is.setstate(ios::failbit); return is; }
    if (r.input_price_per_night()) { is.setstate(ios::failbit); return is; }
    if (r.input_is_booked())       { is.setstate(ios::failbit); return is; }
    return is;
}

/**
 * @brief �������������� � ������
 * @return ��������� ������������� �������
 */
string Room::to_string() const {
    ostringstream oss;
    oss << *this;
    return oss.str();
}