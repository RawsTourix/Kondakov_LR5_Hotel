#ifndef KONDAKOV_LR5_ROOM_HPP
#define KONDAKOV_LR5_ROOM_HPP

#include "kondakov_lr5_room.h"

// Геттер уникального идентификатора
inline int Room::get_room_number() const {
	return room_number;
}

// Геттер цены за ночь
inline float Room::get_price_per_night() const {
	return price_per_night;
}

// Геттер статуса бронирования
inline bool Room::get_is_booked() const {
	return is_booked;
}

// Сеттер уникального идентификатора
inline void Room::set_room_number(int room_number) {
	this->room_number = room_number;
}

// Сеттер цены за ночь
inline void Room::set_price_per_night(float price_per_night) {
	this->price_per_night = price_per_night;
}

// Сеттер статуса бронирования
inline void Room::set_is_booked(bool is_booked) {
	this->is_booked = is_booked;
}

// Инпуттер номера комнаты
inline bool Room::input_room_number() {
	if (InputControl::input(room_number, "Номер комнаты: ", 0, 1000)) { return true; }
	return false;
}

// Инпуттер номера комнаты с проверкой на уникальность номера комнаты
template <typename Container>
inline typename enable_if_t<is_same_v<typename Container::value_type, int>, bool>
Room::input_room_number(const Container& room_numbers) {
	int room_number_temp = 0;
	if (InputControl::input(room_number_temp, "Номер комнаты: ", 0, 1000)) { return true; }

	// Проверка на уникальность номера комнаты
	while (find(room_numbers.begin(), room_numbers.end(), room_number_temp) != room_numbers.end()) {
		cout << endl << "Комната с номером \"" << room_number_temp << "\" уже существует!" << endl << endl;
		if (InputControl::input(room_number_temp, "Номер комнаты: ", 0, 1000)) { return true; }
	}

	room_number = room_number_temp;
	return false;
}

// Инпуттер цены за ночь
inline bool Room::input_price_per_night() {
	ostringstream message;
	message << "Цена за ночь (" << CURRENCY << "): ";
	if (InputControl::input(price_per_night, message.str(), 0.0f, 100000.0f)) { return true; }
	return false;
}

// Инпуттер статуса бронирования
inline bool Room::input_is_booked() {
	if (InputControl::input(is_booked, "Стасус бронирования (1/0): ")) { return true; }
	return false;
}

// Перегрузка вывода контейнера комнат
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, ostream&>
operator<<(ostream& os, const Container& rooms) {
	for (const auto& room : rooms) {
		room->print();
	}
	return os;
}

#endif // KONDAKOV_LR5_ROOM_HPP