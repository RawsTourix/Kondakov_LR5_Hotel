#include "kondakov_lr5_standard_room.h"

// Конструктор по умолчанию
StandardRoom::StandardRoom()
	: Room(),
	bed_count(1),
	has_tv(false),
	amenities({ "Wi-Fi", "Air conditioner" }) {
}

// Конструктор преобразования (создание по room_number и bed_count)
StandardRoom::StandardRoom(int room_number, int bed_count)
	: Room(room_number),
	bed_count(bed_count),
	has_tv(false),
	amenities({ "Wi-Fi", "Air conditioner" }) {
}

// Конструктор преобразования (с удобствами по умолчанию)
StandardRoom::StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv)
	: StandardRoom(room_number, price_per_night, is_booked, bed_count, has_tv, "Wi-Fi, air conditioner") {
}

// Конструктор с параметрами (удобства строка)
StandardRoom::StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv, string amenities)
	: Room(room_number, price_per_night, is_booked),
	bed_count(bed_count),
	has_tv(has_tv)
{
	InputControl::DelimitedContainer<',', vector<string>&> dc(this->amenities);
	dc >> amenities;
}

// Конструктор с параметрами (удобства вектор)
StandardRoom::StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv, vector<string> amenities)
	: Room(room_number, price_per_night, is_booked),
	bed_count(bed_count),
	has_tv(has_tv),
	amenities(amenities) {
}

// Конструктор перемещения
StandardRoom::StandardRoom(StandardRoom&& other) noexcept
	: Room(move(other)),
	bed_count(exchange(other.bed_count, 0)),
	has_tv(other.has_tv),
	amenities(move(other.amenities)) {
}

// Парсинг в json
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

// Парсинг из json
void StandardRoom::from_json(const json& j) {
	room_number = j["room_number"];
	price_per_night = j["price_per_night"];
	is_booked = j["is_booked"];
	bed_count = j["bed_count"];
	has_tv = j["has_tv"];
	amenities = j["amenities"];
}

// Сложение удобств
vector<string> operator+(const StandardRoom& sr1, const StandardRoom& sr2) {
	vector<string> a(sr1.amenities);
	a += sr2;  // Делегирование операции +=
	return a;
}
vector<string> operator+(const vector<string>& amenities, const StandardRoom& sr) {
	vector<string> a(amenities);
	a += sr;  // Делегирование операции +=
	return a;
}
vector<string> operator+(const StandardRoom& sr, const vector<string>& amenities) {
	vector<string> a(sr.amenities);  // Перегрузка += из kondakov_lr5_container_operations.hpp
	a += amenities;
	return a;
}
vector<string>& operator+=(vector<string>& amenities, const StandardRoom& sr) {
	amenities += sr.amenities;  // Перегрузка += из kondakov_lr5_container_operations.hpp
	return amenities;
}
StandardRoom& operator+=(StandardRoom& sr, const vector<string>& amenities) {
	sr.amenities += amenities;  // Перегрузка += из kondakov_lr5_container_operations.hpp
	return sr;
}
StandardRoom& operator+=(StandardRoom& sr, const string& amenities) {
	sr.amenities += amenities;  // Перегрузка += из kondakov_lr5_container_operations.hpp
	return sr;
}

// Красивый перевод в строку
StandardRoom::operator string() const {
	ostringstream oss;
	oss << "Количество кроватей:\t\t" << bed_count << endl
		<< "Наличие телевизора:\t\t"  << (has_tv ? "да" : "нет") << endl
		<< "Удобства:\t\t\t"		  << amenities;

	return oss.str();
}

// Переопределение операции вывода <<
ostream& operator<<(ostream& os, const StandardRoom& sr) {
	os << static_cast<string>(sr);

	return os;
}

// Переопределение операции ввода >>
istream& operator>>(istream& is, StandardRoom& sr) {
	if (sr.input_bed_count())      { is.setstate(ios::failbit); return is; }
	if (sr.input_has_tv())         { is.setstate(ios::failbit); return is; }
	if (sr.input_amenities<','>()) { is.setstate(ios::failbit); return is; }

	return is;
}

// Переопределённый вывод
void StandardRoom::print() const {
	cout << this->to_string() << endl << endl;  // Вывод информации наследника StandardRoom
}

// Переопределённый ввод
bool StandardRoom::input() {
	if (Room::input()) {     // Ввод информации родителя Room
		if (cin >> *this) {  // Ввод информации наследника StandardRoom
			return true;
		}
	}
	cin.clear();
	return false;
}

// Перевод в строку
string StandardRoom::to_string() const {
	ostringstream oss;
	oss << "[" << get_full_name() << "]" << endl;
	oss << Room::to_string() << endl;
	oss << *this;
	return oss.str();
}