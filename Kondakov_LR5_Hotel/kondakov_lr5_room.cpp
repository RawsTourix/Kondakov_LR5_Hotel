#include "kondakov_lr5_room.h"

// Конструктор по умолчанию
Room::Room()
	: Room(0, 0.0f, false) {
}

// Конструктор преобразования
Room::Room(int room_number)
	: Room(room_number, 0.0f, false) {
}

// Конструктор с параметрами
Room::Room(int room_number, float price_per_night, bool is_booked)
	: room_number(room_number),
	price_per_night(price_per_night),
	is_booked(is_booked) {
}

// Конструктор перемещения
Room::Room(Room&& other) noexcept
	: room_number(exchange(other.room_number, 0)),
	price_per_night(exchange(other.price_per_night, 0.0f)),
	is_booked(other.is_booked) {
}

// Сравнение по room_number
bool operator==(const Room& r1, const Room& r2) { return r1.room_number == r2.room_number; }
bool operator==(int room_number, const Room& r2) { return room_number == r2.room_number; }
bool operator==(const Room& r1, int room_number) { return r1.room_number == room_number; }
bool operator>=(const Room& r1, const Room& r2) { return r1.room_number >= r2.room_number; }
bool operator>=(int room_number, const Room& r2) { return room_number >= r2.room_number; }
bool operator>=(const Room& r1, int room_number) { return r1.room_number >= room_number; }
bool operator<=(const Room& r1, const Room& r2) { return r1.room_number <= r2.room_number; }
bool operator<=(int room_number, const Room& r2) { return room_number <= r2.room_number; }
bool operator<=(const Room& r1, int room_number) { return r1.room_number <= room_number; }
bool operator> (const Room& r1, const Room& r2) { return r1.room_number > r2.room_number; }
bool operator> (int room_number, const Room& r2) { return room_number > r2.room_number; }
bool operator> (const Room& r1, int room_number) { return r1.room_number > room_number; }
bool operator< (const Room& r1, const Room& r2) { return r1.room_number < r2.room_number; }
bool operator< (int room_number, const Room& r2) { return room_number < r2.room_number; }
bool operator< (const Room& r1, int room_number) { return r1.room_number < room_number; }
bool operator!=(const Room& r1, const Room& r2) { return r1.room_number != r2.room_number; }
bool operator!=(int room_number, const Room& r2) { return room_number != r2.room_number; }
bool operator!=(const Room& r1, int room_number) { return r1.room_number != room_number; }

// Красивый перевод в строку
Room::operator string() const {
	ostringstream oss;
	oss << "Цена за ночь:\t\t\t"	  << price_per_night << endl
		<< "Статус бронирования:\t\t" << (is_booked ? "да" : "нет");

	return oss.str();
}

// Переопределение операции вывода <<
ostream& operator<<(ostream& os, const Room& r) {
	os << static_cast<string>(r);

	return os;
}

// Переопределение операции ввода >>
istream& operator>>(istream& is, Room& r) {
	cout << "Введите информацию о комнате: " << endl << endl;
	if (r.input_room_number())     { is.setstate(ios::failbit); return is; }
	if (r.input_price_per_night()) { is.setstate(ios::failbit); return is; }
	if (r.input_is_booked())       { is.setstate(ios::failbit); return is; }

	return is;
}