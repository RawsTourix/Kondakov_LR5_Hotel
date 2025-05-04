#include "kondakov_lr5_suite.h"

// Конструктор по умолчанию
Suite::Suite()
	: Room(),
	room_service(true),
	jacuzzi(false),
	amenities({ "Lux", "Room service" }) {
}

// Конструктор преобразования (создание по room_number и room_service)
Suite::Suite(int room_number, bool room_service)
	: Room(room_number),
	room_service(room_service),
	jacuzzi(false),
	amenities({ "Lux", "Room service" }) {
}

// Конструктор преобразования (с удобствами по умолчанию)
Suite::Suite(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi)
	: Suite(room_number, price_per_night, is_booked, room_service, jacuzzi, "Lux, room service") {
}

// Конструктор с параметрами (удобства строка)
Suite::Suite(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi, string amenities)
	: Room(room_number, price_per_night, is_booked),
	room_service(room_service),
	jacuzzi(jacuzzi)
{
	InputControl::DelimitedContainer<',', vector<string>&> dc(this->amenities);
	dc >> amenities;  // Разделение строки на вектор подстрок по ','
}

// Конструктор с параметрами (удобства вектор)
Suite::Suite(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi, vector<string> amenities)
	: Room(room_number, price_per_night, is_booked),
	room_service(room_service),
	jacuzzi(jacuzzi),
	amenities(amenities) {
}

// Конструктор перемещения
Suite::Suite(Suite&& other) noexcept
	: Room(move(other)),
	room_service(other.room_service),
	jacuzzi(other.jacuzzi),
	amenities(move(other.amenities)) {
}

// Парсинг в json
json Suite::to_json() const {
	return {
		{ "room_number", room_number },
		{ "price_per_night", price_per_night },
		{ "is_booked", is_booked },
		{ "room_service", room_service },
		{ "jacuzzi", jacuzzi },
		{ "amenities", amenities }
	};
}

// Парсинг из json
void Suite::from_json(const json& j) {
	room_number = j["room_number"];
	price_per_night = j["price_per_night"];
	is_booked = j["is_booked"];
	room_service = j["room_service"];
	jacuzzi = j["jacuzzi"];
	amenities = j["amenities"];
}

// Сложение удобств
vector<string> operator+(const Suite& s1, const Suite& s2) {
	vector<string> a(s1.amenities);
	a += s2;  // Делегирование операции +=
	return a;
}
vector<string> operator+(const vector<string>& amenities, const Suite& s) {
	vector<string> a(amenities);
	a += s;  // Делегирование операции +=
	return a;
}
vector<string> operator+(const Suite& s, const vector<string>& amenities) {
	vector<string> a(s.amenities);
	a += amenities;  // Перегрузка += из kondakov_lr5_container_operations.hpp
	return a;
}
vector<string>& operator+=(vector<string>& amenities, const Suite& s) {
	amenities += s.amenities;  // Перегрузка += из kondakov_lr5_container_operations.hpp
	return amenities;
}
Suite& operator+=(Suite& s, const vector<string>& amenities) {
	s.amenities += amenities;  // Перегрузка += из kondakov_lr5_container_operations.hpp
	return s;
}
Suite& operator+=(Suite& s, const string& amenities) {
	s.amenities += amenities;  // Перегрузка += из kondakov_lr5_container_operations.hpp
	return s;
}

// Красивый перевод в строку
Suite::operator string() const {
	ostringstream oss;
	oss << "Наличие обслуживания:\t\t" << (room_service ? "да" : "нет") << endl
		<< "Наличие джакузи:\t\t"	   << (jacuzzi ? "да" : "нет") << endl
		<< "Удобства:\t\t\t"		   << amenities;

	return oss.str();
}

// Переопределение операции вывода <<
ostream& operator<<(ostream& os, const Suite& sr) {
	os << static_cast<string>(sr);

	return os;
}

// Переопределение операции ввода >>
istream& operator>>(istream& is, Suite& s) {
	if (s.input_room_service())   { is.setstate(ios::failbit); return is; }
	if (s.input_jacuzzi())        { is.setstate(ios::failbit); return is; }
	if (s.input_amenities<','>()) { is.setstate(ios::failbit); return is; }

	return is;
}

// Переопределённый вывод
void Suite::print() const {
	cout << this->to_string() << endl << endl;
}

// Переопределённый ввод
bool Suite::input() {
	if (Room::input()) {	 // Ввод информации родителя Room
		if (cin >> *this) {  // Ввод информации наследника Suite
			return true;
		}
	}
	cin.clear();
	return false;
}

// Перевод в строку
string Suite::to_string() const {
	ostringstream oss;
	oss << "[" << get_full_name() << "]" << endl;
	oss << Room::to_string() << endl;
	oss << *this;
	return oss.str();
}