#ifndef KONDAKOV_LR5_STANDARD_ROOM_H
#define KONDAKOV_LR5_STANDARD_ROOM_H

#include "kondakov_lr5_room.h"

// Наследник Room
class StandardRoom final : virtual public Room {
private:
	int			   bed_count;  // Количество кроватей
	bool		   has_tv;	   // Наличие телевизора
	vector<string> amenities;  // Удобства

	// Тип комнаты
	const string ROOM_TYPE = "Стандартная комната";

	// Тип сохранения в json
	const string JSON_TYPE = "Standard";

public:
	// Конструктор по умолчанию
	StandardRoom();

	// Конструктор преобразования (создание по room_number и bed_count)
	StandardRoom(int room_number, int bed_count);

	// Конструктор преобразования (с удобствами по умолчанию)
	StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv);

	// Конструктор с параметрами (удобства строка)
	StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv, string amenities);

	// Конструктор с параметрами (удобства вектор)
	StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv, vector<string> amenities);

	// Конструктор копирования
	StandardRoom(const StandardRoom&) = default;
	StandardRoom& operator=(const StandardRoom&) = default;

	// Конструктор перемещения
	StandardRoom(StandardRoom&& other) noexcept;
	StandardRoom& operator=(StandardRoom&&) noexcept = default;

	// Виртуальный деструктор
	virtual ~StandardRoom() = default;

	// Геттер количества кроватей
	inline int get_bed_count() const;

	// Геттер наличия телевизора
	inline bool get_has_tv() const;

	// Геттер списка удобств
	virtual inline const vector<string>& get_amenities() const override;

	// Геттер полного названия комнаты
	virtual inline string get_full_name() const override;

	// Сеттер количества кроватей
	inline void set_bed_count(int bed_count);

	// Сеттер наличия телевизора
	inline void set_has_tv(bool has_tv);

	// Сеттер удобств
	inline void set_amenities(vector<string> amenities);

	// Инпуттер количества кроватей
	inline bool input_bed_count();

	// Инпуттер наличия телевизора
	inline bool input_has_tv();

	// Инпуттер удобств
	template <char Delim>
	inline bool input_amenities();

	// Виртуальный геттер типа комнаты
	virtual inline const string& get_room_type() const override;

	// Виртуальный геттер типа сохранения комнаты в json
	virtual inline const string& get_json_type() const override;

	// Расчет стоимости проживания (зависит от типа номера)
	virtual inline float calculate_total(int night_count) const override;

	// Проверка bed_count >= 1
	virtual inline bool validate() const override;

	// Добавление кровати (+20% к цене)
	inline void exstra_bed();

	// Парсинг в json
	virtual json to_json() const override;

	// Парсинг из json
	virtual void from_json(const json& j) override;

	// Сложение удобств
	friend vector<string>  operator+ (const StandardRoom& sr1, const StandardRoom& sr2);
	friend vector<string>  operator+ (const vector<string>& amenities, const StandardRoom& sr);
	friend vector<string>  operator+ (const StandardRoom& sr, const vector<string>& amenities);
	friend vector<string>& operator+=(vector<string>& amenities, const StandardRoom& sr);
	friend StandardRoom&   operator+=(StandardRoom& sr, const vector<string>& amenities);
	friend StandardRoom&   operator+=(StandardRoom& sr, const string& amenities);

	// Красивый перевод в строку
	explicit operator string() const;

	// Переопределение операции вывода <<
	friend ostream& operator<<(ostream& os, const StandardRoom& r);

	// Переопределение операции ввода >>
	friend istream& operator>>(istream& is, StandardRoom& r);

	// Переопределённый вывод
	virtual void print() const override;

	// Переопределённый ввод
	virtual bool input() override;

	// Перевод в строку
	virtual string to_string() const override;
};

#include "kondakov_lr5_standard_room.hpp"

#endif // KONDAKOV_LR5_STANDARD_ROOM_H