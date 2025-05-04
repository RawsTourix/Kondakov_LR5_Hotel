#include "kondakov_lr5_standard_room.h"

// ����������� �� ���������
StandardRoom::StandardRoom()
	: Room(),
	bed_count(1),
	has_tv(false),
	amenities({ "Wi-Fi", "Air conditioner" }) {
}

// ����������� �������������� (�������� �� room_number � bed_count)
StandardRoom::StandardRoom(int room_number, int bed_count)
	: Room(room_number),
	bed_count(bed_count),
	has_tv(false),
	amenities({ "Wi-Fi", "Air conditioner" }) {
}

// ����������� �������������� (� ���������� �� ���������)
StandardRoom::StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv)
	: StandardRoom(room_number, price_per_night, is_booked, bed_count, has_tv, "Wi-Fi, air conditioner") {
}

// ����������� � ����������� (�������� ������)
StandardRoom::StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv, string amenities)
	: Room(room_number, price_per_night, is_booked),
	bed_count(bed_count),
	has_tv(has_tv)
{
	InputControl::DelimitedContainer<',', vector<string>&> dc(this->amenities);
	dc >> amenities;
}

// ����������� � ����������� (�������� ������)
StandardRoom::StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv, vector<string> amenities)
	: Room(room_number, price_per_night, is_booked),
	bed_count(bed_count),
	has_tv(has_tv),
	amenities(amenities) {
}

// ����������� �����������
StandardRoom::StandardRoom(StandardRoom&& other) noexcept
	: Room(move(other)),
	bed_count(exchange(other.bed_count, 0)),
	has_tv(other.has_tv),
	amenities(move(other.amenities)) {
}

// ������� � json
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

// ������� �� json
void StandardRoom::from_json(const json& j) {
	room_number = j["room_number"];
	price_per_night = j["price_per_night"];
	is_booked = j["is_booked"];
	bed_count = j["bed_count"];
	has_tv = j["has_tv"];
	amenities = j["amenities"];
}

// �������� �������
vector<string> operator+(const StandardRoom& sr1, const StandardRoom& sr2) {
	vector<string> a(sr1.amenities);
	a += sr2;  // ������������� �������� +=
	return a;
}
vector<string> operator+(const vector<string>& amenities, const StandardRoom& sr) {
	vector<string> a(amenities);
	a += sr;  // ������������� �������� +=
	return a;
}
vector<string> operator+(const StandardRoom& sr, const vector<string>& amenities) {
	vector<string> a(sr.amenities);  // ���������� += �� kondakov_lr5_container_operations.hpp
	a += amenities;
	return a;
}
vector<string>& operator+=(vector<string>& amenities, const StandardRoom& sr) {
	amenities += sr.amenities;  // ���������� += �� kondakov_lr5_container_operations.hpp
	return amenities;
}
StandardRoom& operator+=(StandardRoom& sr, const vector<string>& amenities) {
	sr.amenities += amenities;  // ���������� += �� kondakov_lr5_container_operations.hpp
	return sr;
}
StandardRoom& operator+=(StandardRoom& sr, const string& amenities) {
	sr.amenities += amenities;  // ���������� += �� kondakov_lr5_container_operations.hpp
	return sr;
}

// �������� ������� � ������
StandardRoom::operator string() const {
	ostringstream oss;
	oss << "���������� ��������:\t\t" << bed_count << endl
		<< "������� ����������:\t\t"  << (has_tv ? "��" : "���") << endl
		<< "��������:\t\t\t"		  << amenities;

	return oss.str();
}

// ��������������� �������� ������ <<
ostream& operator<<(ostream& os, const StandardRoom& sr) {
	os << static_cast<string>(sr);

	return os;
}

// ��������������� �������� ����� >>
istream& operator>>(istream& is, StandardRoom& sr) {
	if (sr.input_bed_count())      { is.setstate(ios::failbit); return is; }
	if (sr.input_has_tv())         { is.setstate(ios::failbit); return is; }
	if (sr.input_amenities<','>()) { is.setstate(ios::failbit); return is; }

	return is;
}

// ��������������� �����
void StandardRoom::print() const {
	cout << this->to_string() << endl << endl;  // ����� ���������� ���������� StandardRoom
}

// ��������������� ����
bool StandardRoom::input() {
	if (Room::input()) {     // ���� ���������� �������� Room
		if (cin >> *this) {  // ���� ���������� ���������� StandardRoom
			return true;
		}
	}
	cin.clear();
	return false;
}

// ������� � ������
string StandardRoom::to_string() const {
	ostringstream oss;
	oss << "[" << get_full_name() << "]" << endl;
	oss << Room::to_string() << endl;
	oss << *this;
	return oss.str();
}