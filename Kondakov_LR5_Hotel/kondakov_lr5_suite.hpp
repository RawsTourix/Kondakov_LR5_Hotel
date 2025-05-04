#ifndef KONDAKOV_LR5_SUITE_HPP
#define KONDAKOV_LR5_SUITE_HPP

#include "kondakov_lr5_suite.h"

// Геттер наличия обслуживания
inline int Suite::get_room_service() const {
	return room_service;
}

// Геттер наличия джакузи
inline bool Suite::get_jacuzzi() const {
	return jacuzzi;
}

// Геттер удобств
inline const vector<string>& Suite::get_amenities() const {
	return amenities;
}

// Геттер полного названия комнаты
inline string Suite::get_full_name() const {
	ostringstream oss;
	oss << ROOM_TYPE << " №" << room_number;
	return oss.str();
}

// Сеттер наличия обслуживания
inline void Suite::set_room_service(int room_service) {
	this->room_service = room_service;
}

// Сеттер наличия джакузи
inline void Suite::set_jacuzzi(bool jacuzzi) {
	this->jacuzzi = jacuzzi;
}

// Сеттер удобств
inline void Suite::set_amenities(vector<string> amenities) {
	this->amenities = move(amenities);
}

// Инпуттер наличия обслуживания
inline bool Suite::input_room_service() {
	if (InputControl::input(room_service, "Наличие обслуживания (1/0): ")) { return true; }
	return false;
}

// Инпуттер наличия джакузи
inline bool Suite::input_jacuzzi() {
	if (InputControl::input(jacuzzi, "Наличие джакузи (1/0): ")) { return true; }
	return false;
}

// Инпуттер удобств
template <char Delim>
inline bool Suite::input_amenities() {
	cout << "Ввод удобств осуществляется в одну строку через разделитель '" << Delim << "'." << endl << endl;
	cout << "Удобства: ";
	InputControl::DelimitedContainer<Delim, vector<string>&> dc(amenities);
	if (cin >> dc) { return false; }
	else { cin.clear(); return true; }
}

// Виртуальный геттер типа комнаты
inline const string& Suite::get_room_type() const {
	return ROOM_TYPE;
}

// Виртуальный геттер типа сохранения комнаты в json
inline const string& Suite::get_json_type() const {
	return JSON_TYPE;
}

// Расчет стоимости проживания (цена * ночи + 5000 руб. за услуги)
inline float Suite::calculate_total(int night_count) const {
	return price_per_night * static_cast<float>(night_count) + SERVICE_PRICE;
}

// Проверка calculate_total >= 10000
inline bool Suite::validate() const {
	return calculate_total(1) >= 10000.0f;
}

// Добавление услуги (+2000 руб. к стоимости)
inline void Suite::order_champagne(string amenity) {
	price_per_night += 2000.0f;
	InputControl::make_first_letter_uppercase(amenity);
	*this += amenity;
}

#endif // KONDAKOV_LR5_SUITE_HPP