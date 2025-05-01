#ifndef KONDAKOV_LR5_ROOM_HPP
#define KONDAKOV_LR5_ROOM_HPP

#include "kondakov_lr5_room.h"

// ������ ����������� ��������������
inline int Room::get_room_number() const {
	return room_number;
}

// ������ ���� �� ����
inline float Room::get_price_per_night() const {
	return price_per_night;
}

// ������ ������� ������������
inline bool Room::get_is_booked() const {
	return is_booked;
}

// ������ ����������� ��������������
inline void Room::set_room_number(int room_number) {
	this->room_number = room_number;
}

// ������ ���� �� ����
inline void Room::set_price_per_night(float price_per_night) {
	this->price_per_night = price_per_night;
}

// ������ ������� ������������
inline void Room::set_is_booked(bool is_booked) {
	this->is_booked = is_booked;
}

// �������� ������ �������
inline bool Room::input_room_number() {
	int room_number;
	if (InputControl::input(room_number, "����� �������: ")) { return true; }
	set_room_number(room_number);
	return false;
}

// �������� ���� �� ����
inline bool Room::input_price_per_night() {
	float price_per_night;
	if (InputControl::input(price_per_night, "���� �� ����: ")) { return true; }
	set_price_per_night(price_per_night);
	return false;
}

// �������� ������� ������������
inline bool Room::input_is_booked() {
	int is_booked;
	if (InputControl::input(is_booked, "������ ������������ (1/0): ", 0, 1)) { return true; }
	set_is_booked(static_cast<bool>(is_booked));
	return false;
}

// �������� price_per_night > 0
inline bool Room::validate() const {
	return price_per_night > 0;
}

// ���������� ������ ���������� ������
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, ostream&>
operator<<(ostream& os, const Container& rooms) {
	for (const auto& room : rooms) {
		room->print();
	}
	return os;
}

#endif // KONDAKOV_LR5_ROOM_HPP