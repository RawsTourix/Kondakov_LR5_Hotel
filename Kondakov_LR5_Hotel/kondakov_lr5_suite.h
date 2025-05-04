#ifndef KONDAKOV_LR5_SUITE_H
#define KONDAKOV_LR5_SUITE_H

#include "kondakov_lr5_room.h"

// Наследник Room, final
class Suite final : virtual public Room {
private:
	bool		   room_service;  // Наличие обслуживания
	bool		   jacuzzi;		  // Наличие джакузи
	vector<string> amenities;	  // Удобства

	// Стоимость услуг
	const float SERVICE_PRICE = 5000.0f;

	// Тип комнаты
	const string ROOM_TYPE = "Люкс комната";

public:
	// Конструктор по умолчанию
	Suite();

	// Конструктор преобразования (создание по room_number и room_service)
	Suite(int room_number, bool room_service);

	// Конструктор преобразования (с удобствами по умолчанию)
	Suite(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi);

	// Конструктор с параметрами (удобства строка)
	Suite(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi, string amenities);

	// Конструктор с параметрами (удобства вектор)
	Suite(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi, vector<string> amenities);

	// Конструктор копирования
	Suite(const Suite&) = default;
	Suite& operator=(const Suite&) = default;

	// Конструктор перемещения
	Suite(Suite&& other) noexcept;
	Suite& operator=(Suite&&) noexcept = default;

	// Виртуальный деструктор
	virtual ~Suite() = default;

	// Геттер наличия обслуживания
	inline int get_room_service() const;

	// Геттер наличия джакузи
	inline bool get_jacuzzi() const;

	// Геттер удобств
	virtual inline const vector<string>& get_amenities() const override;

	// Геттер полного названия комнаты
	virtual inline string get_full_name() const override;

	// Сеттер наличия обслуживания
	inline void set_room_service(int room_service);

	// Сеттер наличия джакузи
	inline void set_jacuzzi(bool jacuzzi);

	// Сеттер удобств
	inline void set_amenities(vector<string> amenities);

	// Инпуттер наличия обслуживания
	inline bool input_room_service();

	// Инпуттер наличия джакузи
	inline bool input_jacuzzi();

	// Инпуттер удобств
	template <char Delim>
	inline bool input_amenities();

	// Виртуальный геттер типа комнаты
	virtual inline const string& get_room_type() const override;

	// Расчет стоимости проживания (цена * ночи + 5000 руб. за услуги)
	virtual inline float calculate_total(int night_count) const override;

	// Проверка calculate_total >= 10000
	virtual inline bool validate() const override;

	// Добавление услуги (+2000 руб. к стоимости)
	inline void order_champagne(string amenity);

	// Парсинг в json
	virtual json to_json() const override;

	// Парсинг из json
	virtual void from_json(const json& j) override;

	// Сложение удобств
	friend vector<string>  operator+ (const Suite& s1, const Suite& s2);
	friend vector<string>  operator+ (const vector<string>& amenities, const Suite& s);
	friend vector<string>  operator+ (const Suite& s, const vector<string>& amenities);
	friend vector<string>& operator+=(vector<string>& amenities, const Suite& s);
	friend Suite&		   operator+=(Suite& s, const vector<string>& amenities);
	friend Suite&		   operator+=(Suite& s, const string& amenities);

	// Красивый перевод в строку
	explicit operator string() const;

	// Переопределение операции вывода <<
	friend ostream& operator<<(ostream& os, const Suite& r);

	// Переопределение операции ввода >>
	friend istream& operator>>(istream& is, Suite& r);

	// Переопределённый вывод
	virtual void print() const override;

	// Переопределённый ввод
	virtual bool input() override;

	// Перевод в строку
	virtual string to_string() const override;
};

#include "kondakov_lr5_suite.hpp"

#endif // KONDAKOV_LR5_SUITE_H