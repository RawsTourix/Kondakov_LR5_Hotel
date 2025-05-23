/**
 * @file kondakov_lr5_room.hpp
 * @brief ���������� ������� ������ Room
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#ifndef KONDAKOV_LR5_ROOM_HPP
#define KONDAKOV_LR5_ROOM_HPP

#include "kondakov_lr5_room.h"

/**
 * @brief �������� ����� �������
 * @return ����� �������
 */
inline int Room::get_room_number() const {
    return room_number;
}

/**
 * @brief �������� ���� �� ����
 * @return ���� �� ����
 */
inline float Room::get_price_per_night() const {
    return price_per_night;
}

/**
 * @brief �������� ������ ������������
 * @return true ���� ����� ������������, ����� false
 */
inline bool Room::get_is_booked() const {
    return is_booked;
}

/**
 * @brief ���������� ����� �������
 * @param room_number ����� ����� �������
 */
inline void Room::set_room_number(int room_number) {
    this->room_number = room_number;
}

/**
 * @brief ���������� ���� �� ����
 * @param price_per_night ����� ���� �� ����
 */
inline void Room::set_price_per_night(float price_per_night) {
    this->price_per_night = price_per_night;
}

/**
 * @brief ���������� ������ ������������
 * @param is_booked ����� ������ ������������
 */
inline void Room::set_is_booked(bool is_booked) {
    this->is_booked = is_booked;
}

/**
 * @brief ���� ������ �������
 * @return true ���� �������� ��������, ����� false
 */
inline bool Room::input_room_number() {
    if (InputControl::input(room_number, "����� �������: ", 1, 1000)) { return true; }
    return false;
}

/**
 * @brief ���� ������ ������� � ��������� ������������
 * @tparam Container ��� ���������� � �������� ������
 * @param room_numbers ��������� � ������������� �������� ������
 * @return true ���� �������� ��������, ����� false
 */
template <typename Container>
inline typename enable_if_t<is_same_v<typename Container::value_type, int>, bool>
Room::input_room_number(const Container& room_numbers) {
    int room_number_temp = 0;
    if (InputControl::input(room_number_temp, "����� �������: ", 1, 1000)) { return true; }

    while (find(room_numbers.begin(), room_numbers.end(), room_number_temp) != room_numbers.end()) {
        cout << endl << "������� � ������� \"" << room_number_temp << "\" ��� ����������!" << endl << endl;
        if (InputControl::input(room_number_temp, "����� �������: ", 1, 1000)) { return true; }
    }

    room_number = room_number_temp;
    return false;
}

/**
 * @brief ���� ���� �� ����
 * @return true ���� �������� ��������, ����� false
 */
inline bool Room::input_price_per_night() {
    ostringstream message;
    message << "���� �� ���� (" << CURRENCY << "): ";
    if (InputControl::input(price_per_night, message.str(), 0.0f, 100000.0f)) { return true; }
    return false;
}

/**
 * @brief ���� ������� ������������
 * @return true ���� �������� ��������, ����� false
 */
inline bool Room::input_is_booked() {
    if (InputControl::input(is_booked, "������ ������������ (1/0): ")) { return true; }
    return false;
}

/**
 * @brief ����� ���������� ������
 * @tparam Container ��� ���������� (������ ��������� shared_ptr<Room>)
 * @param os ����� ������
 * @param rooms ��������� � ���������
 * @return ����� ������
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