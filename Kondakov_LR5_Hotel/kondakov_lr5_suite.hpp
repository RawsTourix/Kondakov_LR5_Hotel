#ifndef KONDAKOV_LR5_SUITE_HPP
#define KONDAKOV_LR5_SUITE_HPP

#include "kondakov_lr5_suite.h"

// ������ ������� ������������
inline int Suite::get_room_service() const {
	return room_service;
}

// ������ ������� �������
inline bool Suite::get_jacuzzi() const {
	return jacuzzi;
}

// ������ �������
inline const vector<string>& Suite::get_amenities() const {
	return amenities;
}

// ������ ������� �������� �������
inline string Suite::get_full_name() const {
	ostringstream oss;
	oss << ROOM_TYPE << " �" << room_number;
	return oss.str();
}

// ������ ������� ������������
inline void Suite::set_room_service(int room_service) {
	this->room_service = room_service;
}

// ������ ������� �������
inline void Suite::set_jacuzzi(bool jacuzzi) {
	this->jacuzzi = jacuzzi;
}

// ������ �������
inline void Suite::set_amenities(vector<string> amenities) {
	this->amenities = move(amenities);
}

// �������� ������� ������������
inline bool Suite::input_room_service() {
	if (InputControl::input(room_service, "������� ������������ (1/0): ")) { return true; }
	return false;
}

// �������� ������� �������
inline bool Suite::input_jacuzzi() {
	if (InputControl::input(jacuzzi, "������� ������� (1/0): ")) { return true; }
	return false;
}

// �������� �������
template <char Delim>
inline bool Suite::input_amenities() {
	cout << "���� ������� �������������� � ���� ������ ����� ����������� '" << Delim << "'." << endl << endl;
	cout << "��������: ";
	InputControl::DelimitedContainer<Delim, vector<string>&> dc(amenities);
	if (cin >> dc) { return false; }
	else { cin.clear(); return true; }
}

// ����������� ������ ���� �������
inline const string& Suite::get_room_type() const {
	return ROOM_TYPE;
}

// ����������� ������ ���� ���������� ������� � json
inline const string& Suite::get_json_type() const {
	return JSON_TYPE;
}

// ������ ��������� ���������� (���� * ���� + 5000 ���. �� ������)
inline float Suite::calculate_total(int night_count) const {
	return price_per_night * static_cast<float>(night_count) + SERVICE_PRICE;
}

// �������� calculate_total >= 10000
inline bool Suite::validate() const {
	return calculate_total(1) >= 10000.0f;
}

// ���������� ������ (+2000 ���. � ���������)
inline void Suite::order_champagne(string amenity) {
	price_per_night += 2000.0f;
	InputControl::make_first_letter_uppercase(amenity);
	*this += amenity;
}

#endif // KONDAKOV_LR5_SUITE_HPP