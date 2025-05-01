#include "kondakov_lr5_family_room.h"

// Конструктор по умолчанию
FamilyRoom::FamilyRoom()
	: Room(),
	ChildCare(),
	child_beds(1),
	toy_kit(false),
	amenities({ "Wi-Fi", "Air condition" }) {
}

// Конструктор преобразования (создание по room_number и child_beds)
FamilyRoom::FamilyRoom(int room_number, int child_beds)
	: Room(room_number),
	ChildCare(true),
	child_beds(child_beds),
	toy_kit(false),
	amenities({"Wi-Fi", "Air condition"}) {
}

// Конструктор преобразования (с удобствами по умолчанию)
FamilyRoom::FamilyRoom(int room_number, float price_per_night, bool is_booked, float child_care_price,
	bool has_child_care, int child_beds, bool toy_kit)
	: FamilyRoom(room_number, price_per_night, is_booked, child_care_price,
		has_child_care, child_beds, toy_kit, "Wi-Fi, air condition") {
}

// Конструктор с параметрами
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

// Конструктор перемещения
FamilyRoom::FamilyRoom(FamilyRoom&& other) noexcept
	: Room(move(other)),
	ChildCare(move(other)),
	child_beds(other.child_beds),
	toy_kit(other.toy_kit) {
}

// Получение параметров через []
string FamilyRoom::operator[](int index) const {
	ostringstream oss;
	switch (index) {
		case 0: oss << "Стоимость услуг для детей: " << child_care_price;
		case 1: oss << "Наличие услуг для детей: " << has_child_care;
		case 2: oss << "Количество детских кроватей: " << child_beds;
		case 3: oss << "Наличие набора детских игрушек: " << toy_kit;
		case 4: oss << "Удобства: " << amenities;
		default: ostringstream oss; oss << "Значение \"" << index << "\" вне допустимого диапазона (0-4)"; throw out_of_range(oss.str());
	}
	return oss.str();
}

// Сложение удобств
vector<string> operator+(const FamilyRoom& fr1, const FamilyRoom& fr2) {
	vector<string> a(fr1.amenities);
	a += fr2;  // Делегирование операции +=
	return a;
}
vector<string> operator+(const vector<string>& amenities, const FamilyRoom& fr) {
	vector<string> a(amenities);
	a += fr;  // Делегирование операции +=
	return a;
}
vector<string> operator+(const FamilyRoom& fr, const vector<string>& amenities) {
	vector<string> a(fr.amenities);  // Перегрузка += из kondakov_lr5_container_operations.hpp
	a += amenities;
	return a;
}
vector<string>& operator+=(vector<string>& amenities, const FamilyRoom& fr) {
	amenities += fr.amenities;  // Перегрузка += из kondakov_lr5_container_operations.hpp
	return amenities;
}
FamilyRoom& operator+=(FamilyRoom& fr, const vector<string>& amenities) {
	fr.amenities += amenities;  // Перегрузка += из kondakov_lr5_container_operations.hpp
	return fr;
}
FamilyRoom& operator+=(FamilyRoom& fr, const string& amenities) {
	fr.amenities += amenities;  // Перегрузка += из kondakov_lr5_container_operations.hpp
	return fr;
}

// Красивый перевод в строку
FamilyRoom::operator string() const {
	ostringstream oss;
	oss << "Количество детских кроватей:\t"    << child_beds << endl
		<< "Наличие набора детских игрушек:\t" << (toy_kit ? "да" : "нет") << endl
		<< "Удобства:\t\t\t"				   << amenities;

	return oss.str();
}

// Переопределение операции вывода <<
ostream& operator<<(ostream& os, const FamilyRoom& fr) {
	os << static_cast<string>(fr);

	return os;
}

// Переопределение операции ввода >>
istream& operator>>(istream& is, FamilyRoom& fr) {
	if (fr.input_child_beds())	   { is.setstate(ios::failbit); return is; }
	if (fr.input_toy_kit())		   { is.setstate(ios::failbit); return is; }
	if (fr.input_amenities<','>()) { is.setstate(ios::failbit); return is; }

	return is;
}

// Переопределённый вывод
void FamilyRoom::print() const {
	cout << "[" << get_full_name() << "]" << endl;
	Room::print();					// Вывод информации первого родителя Room
	ChildCare::print();				// Вывод информации второго родителя ChildCare
	cout << *this << endl << endl;  // Вывод информации наследника FamilyRoom
}

// Переопределённый ввод
bool FamilyRoom::input() {
	if (Room::input()) {		   // Ввод информации первого родителя Room
		if (ChildCare::input()) {  // Ввод информации второго родителя ChildCare
			if (cin >> *this) {    // Ввод информации наследника FamilyRoom
				return true;
			}
		}
	}
	cin.clear();
	return false;
}