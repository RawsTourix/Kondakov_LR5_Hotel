#include "kondakov_lr5_family_room.h"

// ����������� �� ���������
FamilyRoom::FamilyRoom()
	: Room(),
	ChildCare(),
	child_beds(1),
	toy_kit(false),
	amenities({ "Wi-Fi", "Air condition" }) {
}

// ����������� �������������� (�������� �� room_number � child_beds)
FamilyRoom::FamilyRoom(int room_number, int child_beds)
	: Room(room_number),
	ChildCare(true),
	child_beds(child_beds),
	toy_kit(false),
	amenities({"Wi-Fi", "Air condition"}) {
}

// ����������� �������������� (� ���������� �� ���������)
FamilyRoom::FamilyRoom(int room_number, float price_per_night, bool is_booked, float child_care_price,
	bool has_child_care, int child_beds, bool toy_kit)
	: FamilyRoom(room_number, price_per_night, is_booked, child_care_price,
		has_child_care, child_beds, toy_kit, "Wi-Fi, air condition") {
}

// ����������� � �����������
FamilyRoom::FamilyRoom(int room_number, float price_per_night, bool is_booked, float child_care_price,
	bool has_child_care, int child_beds, bool toy_kit, string amenities)
	: Room(room_number, price_per_night, is_booked),
	ChildCare(child_care_price, has_child_care),
	child_beds(child_beds),
	toy_kit(toy_kit)
{
	InputControl::DelimitedContainer<',', vector<string>&> dc(this->amenities);
	dc >> amenities;
}

// ����������� �����������
FamilyRoom::FamilyRoom(FamilyRoom&& other) noexcept
	: Room(move(other)),
	ChildCare(move(other)),
	child_beds(other.child_beds),
	toy_kit(other.toy_kit) {
}

// ��������� ���������� ����� []
string FamilyRoom::operator[](int index) const {
	ostringstream oss;
	switch (index) {
		case 0: oss << "��������� ����� ��� �����: " << child_care_price;
		case 1: oss << "������� ����� ��� �����: " << has_child_care;
		case 2: oss << "���������� ������� ��������: " << child_beds;
		case 3: oss << "������� ������ ������� �������: " << toy_kit;
		case 4: oss << "��������: " << amenities;
		default: ostringstream oss; oss << "�������� \"" << index << "\" ��� ����������� ��������� (0-4)"; throw out_of_range(oss.str());
	}
	return oss.str();
}

// �������� �������
vector<string> operator+(const FamilyRoom& fr1, const FamilyRoom& fr2) {
	vector<string> a(fr1.amenities);
	a += fr2;  // ������������� �������� +=
	return a;
}
vector<string> operator+(const vector<string>& amenities, const FamilyRoom& fr) {
	vector<string> a(amenities);
	a += fr;  // ������������� �������� +=
	return a;
}
vector<string> operator+(const FamilyRoom& fr, const vector<string>& amenities) {
	vector<string> a(fr.amenities);  // ���������� += �� kondakov_lr5_container_operations.hpp
	a += amenities;
	return a;
}
vector<string>& operator+=(vector<string>& amenities, const FamilyRoom& fr) {
	amenities += fr.amenities;  // ���������� += �� kondakov_lr5_container_operations.hpp
	return amenities;
}
FamilyRoom& operator+=(FamilyRoom& fr, const vector<string>& amenities) {
	fr.amenities += amenities;  // ���������� += �� kondakov_lr5_container_operations.hpp
	return fr;
}
FamilyRoom& operator+=(FamilyRoom& fr, const string& amenities) {
	fr.amenities += amenities;  // ���������� += �� kondakov_lr5_container_operations.hpp
	return fr;
}

// �������� ������� � ������
FamilyRoom::operator string() const {
	ostringstream oss;
	oss << "���������� ������� ��������:\t"    << child_beds << endl
		<< "������� ������ ������� �������:\t" << (toy_kit ? "��" : "���") << endl
		<< "��������:\t\t\t"				   << amenities;

	return oss.str();
}

// ��������������� �������� ������ <<
ostream& operator<<(ostream& os, const FamilyRoom& fr) {
	os << static_cast<string>(fr);

	return os;
}

// ��������������� �������� ����� >>
istream& operator>>(istream& is, FamilyRoom& fr) {
	if (fr.input_child_beds())	   { is.setstate(ios::failbit); return is; }
	if (fr.input_toy_kit())		   { is.setstate(ios::failbit); return is; }
	if (fr.input_amenities<','>()) { is.setstate(ios::failbit); return is; }

	return is;
}

// ��������������� �����
void FamilyRoom::print() const {
	cout << "[" << get_full_name() << "]" << endl;
	Room::print();					// ����� ���������� ������� �������� Room
	ChildCare::print();				// ����� ���������� ������� �������� ChildCare
	cout << *this << endl << endl;  // ����� ���������� ���������� FamilyRoom
}

// ��������������� ����
bool FamilyRoom::input() {
	if (Room::input()) {		   // ���� ���������� ������� �������� Room
		if (ChildCare::input()) {  // ���� ���������� ������� �������� ChildCare
			if (cin >> *this) {    // ���� ���������� ���������� FamilyRoom
				return true;
			}
		}
	}
	cin.clear();
	return false;
}