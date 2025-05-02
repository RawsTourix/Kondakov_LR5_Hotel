#ifndef KONDAKOV_LR5_ROOM_H
#define KONDAKOV_LR5_ROOM_H

#include "kondakov_lr5_input_control.h"

// Абстрактный базовый класс Room
class Room {
protected:
	int		room_number;	  // Номер комнаты
	float	price_per_night;  // Цена за ночь
	bool	is_booked;		  // Статус бронирования

	// Переопределённый вывод
	virtual void print() const {
		cout << *this << endl;
	}

	// Переопределённый ввод
	virtual bool input() {
		return static_cast<bool>(cin >> *this);
	}

public:
	// Конструктор по умолчанию
	Room();

	// Конструктор преобразования
	Room(int room_number);

	// Конструктор с параметрами
	Room(int room_number, float price_per_night, bool is_booked);

	// Конструктор копирования
	Room(const Room&) = default;
	Room& operator=(const Room&) = default;

	// Конструктор перемещения
	Room(Room&& other) noexcept;
	Room& operator=(Room&&) noexcept = default;

	// Виртуальный деструктор
	virtual ~Room() = default;

	// Геттер номера комнаты
	inline int get_room_number() const;

	// Геттер цены за ночь
	inline float get_price_per_night() const;

	// Геттер статуса бронирования
	inline bool get_is_booked() const;

	// Чисто виртуальный геттер удобств
	virtual inline const vector<string>& get_amenities() const = 0;

	// Геттер полного названия комнаты
	virtual inline string get_full_name() const = 0;

	// Геттер методов для изменения комнаты

	// Сеттер номера комнаты
	inline void set_room_number(int room_number);

	// Сеттер цены за ночь
	inline void set_price_per_night(float price_per_night);

	// Сеттер статуса бронирования
	inline void set_is_booked(bool is_booked);

	// Инпуттер номера комнаты
	inline bool input_room_number();

	// Инпуттер номера комнаты с проверкой на уникальность номера комнаты
	template <typename Container>
	inline typename enable_if_t<is_same_v<typename Container::value_type, int>, bool>
	input_room_number(const Container& room_numbers);

	// Инпуттер цены за ночь
	inline bool input_price_per_night();

	// Инпуттер статуса бронирования
	inline bool input_is_booked();

	// Виртуальный геттер типа комнаты
	virtual inline const string& get_room_type() const = 0;

	// Расчет стоимости проживания (зависит от типа номера)
	virtual inline float calculate_total(int night_count) const = 0;

	// Проверка price_per_night > 0
	virtual inline bool validate() const;

	// Сравнение по room_number
	friend bool operator==(const Room& r1, const Room& r2);
	friend bool operator==(int room_number, const Room& r2);
	friend bool operator==(const Room& r1, int room_number);
	friend bool operator>=(const Room& r1, const Room& r2);
	friend bool operator>=(int room_number, const Room& r2);
	friend bool operator>=(const Room& r1, int room_number);
	friend bool operator<=(const Room& r1, const Room& r2);
	friend bool operator<=(int room_number, const Room& r2);
	friend bool operator<=(const Room& r1, int room_number);
	friend bool operator> (const Room& r1, const Room& r2);
	friend bool operator> (int room_number, const Room& r2);
	friend bool operator> (const Room& r1, int room_number);
	friend bool operator< (const Room& r1, const Room& r2);
	friend bool operator< (int room_number, const Room& r2);
	friend bool operator< (const Room& r1, int room_number);
	friend bool operator!=(const Room& r1, const Room& r2);
	friend bool operator!=(int room_number, const Room& r2);
	friend bool operator!=(const Room& r1, int room_number);
	
	// Красивый перевод в строку
	explicit operator string() const;

	// Переопределение операции вывода <<
	friend ostream& operator<<(ostream& os, const Room& r);

	// Переопределение операции ввода >>
	friend istream& operator>>(istream& is, Room& r);

	// Перегрузка вывода контейнера комнат
	template <typename Container>
	typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, ostream&>
	friend operator<<(ostream& os, const Container& rooms);
};

#include "kondakov_lr5_room.hpp"

#endif // KONDAKOV_LR5_ROOM_H