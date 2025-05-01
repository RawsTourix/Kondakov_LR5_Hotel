#ifndef KONDAKOV_LR5_STANDARD_ROOM_HPP
#define KONDAKOV_LR5_STANDARD_ROOM_HPP

#include "kondakov_lr5_standard_room.h"

// ������ ���������� ��������
inline int StandardRoom::get_bed_count() const {
	return bed_count;
}

// ������ ������� ����������
inline bool StandardRoom::get_has_tv() const {
	return has_tv;
}

// ������ �������
inline const vector<string>& StandardRoom::get_amenities() const {
	return amenities;
}

// ������ ������� �������� �������
inline string StandardRoom::get_full_name() const {
	ostringstream oss;
	oss << ROOM_TYPE << " �" << room_number;
	return oss.str();
}

// ������ ���������� ��������
inline void StandardRoom::set_bed_count(int bed_count) {
	this->bed_count = bed_count;
}

// ������ ������� ����������
inline void StandardRoom::set_has_tv(bool has_tv) {
	this->has_tv = has_tv;
}

// ������ �������
inline void StandardRoom::set_amenities(vector<string> amenities) {
	this->amenities = move(amenities);
}

// �������� ���������� ��������
inline bool StandardRoom::input_bed_count() {
	int bed_count;
	if (InputControl::input(bed_count, "���������� ��������: ")) { return true; }
	set_bed_count(bed_count);
	return false;
}

// �������� ������� ����������
inline bool StandardRoom::input_has_tv() {
	int has_tv;
	if (InputControl::input(has_tv, "������� ���������� (1/0): ", 0, 1)) { return true; }
	set_has_tv(static_cast<bool>(has_tv));
	return false;
}

// �������� �������
template <char Delim>
inline bool StandardRoom::input_amenities() {
	cout << "���� ������� �������������� � ���� ������ ����� ����������� '" << Delim << "'." << endl << endl;
	cout << "��������: ";
	InputControl::DelimitedContainer<Delim, vector<string>&> dc(amenities);
	if (cin >> dc) { return false; }
	else { cin.clear(); return true; }
}

// ����������� ������ ���� �������
inline const string& StandardRoom::get_room_type() const {
	return ROOM_TYPE;
}

// ������ ��������� ���������� (������� �� ���� ������)
inline float StandardRoom::calculate_total(int night_count) const {
	return price_per_night * static_cast<float>(night_count);
}

// �������� bed_count >= 1
inline bool StandardRoom::validate() const {
	return bed_count >= 1;
}

// ���������� ������� (+20% � ����)
inline void StandardRoom::exstra_bed() {
	price_per_night += price_per_night * 0.2f;
	bed_count++;
}

#endif // KONDAKOV_LR5_STANDARD_ROOM_HPP