#ifndef KONDAKOV_LR5_FAMILY_ROOM_H
#define KONDAKOV_LR5_FAMILY_ROOM_H

#include "kondakov_lr5_room.h"
#include "kondakov_lr5_child_care.h"

// Класс FamilyRoom (наследник Room и ChildCare)
class FamilyRoom final : virtual public Room, virtual public ChildCare {
private:
	int			   child_beds;  // Количество детских кроватей
	bool		   toy_kit;	    // Наличие набора игрушек
	vector<string> amenities;   // Удобства

	// Тип комнаты
	const string ROOM_TYPE = "Семейная комната";

public:
	// Конструктор по умолчанию
	FamilyRoom();

	// Конструктор преобразования (создание по room_number и child_beds)
	FamilyRoom(int room_number, int child_beds);

	// Конструктор преобразования (с удобствами по умолчанию)
	FamilyRoom(int room_number, float price_per_night, bool is_booked, float child_care_price,
		bool has_child_care, int child_beds, bool toy_kit);

	// Конструктор с параметрами
	FamilyRoom(int room_number, float price_per_night, bool is_booked, float child_care_price,
		bool has_child_care, int child_beds, bool toy_kit, string amenities);

	// Конструктор копирования
	FamilyRoom(const FamilyRoom&) = default;
	FamilyRoom& operator=(const FamilyRoom&) = default;

	// Конструктор перемещения
	FamilyRoom(FamilyRoom&& other) noexcept;
	FamilyRoom& operator=(FamilyRoom&&) noexcept = default;

	// Виртуальный деструктор
	virtual ~FamilyRoom() = default;

	// Геттер количества детских кроватей
	inline int get_child_beds() const;

	// Геттер наличия набора игрушек
	inline int get_toy_kit() const;

	// Геттер удобств
	virtual inline const vector<string>& get_amenities() const override;

	// Геттер полного названия комнаты
	virtual inline string get_full_name() const override;

	// Сеттер количества детских кроватей
	inline void set_child_beds(int child_beds);

	// Сеттер наличия набора игрушек
	inline void set_toy_kit(bool toy_kit);

	// Сеттер удобств
	inline void set_amenities(vector<string> amenities);

	// Инпуттер количества детских кроватей
	inline bool input_child_beds();

	// Инпуттер наличия набора игрушек
	inline bool input_toy_kit();

	// Инпуттер удобств
	template <char Delim = ','>
	inline bool input_amenities();

	// Виртуальный геттер типа комнаты
	virtual inline const string& get_room_type() const override;

	// Цена * ночи + 1000 руб./ребенок
	virtual inline float calculate_total(int night_count) const override;

	// Проверка child_beds <= 4
	virtual inline bool validate() const override;

	// Активация игровой зоны (+1500 руб.)
	inline void add_play_area();

	// Активация игровой зоны (-1500 руб.)
	inline void remove_play_area();

	// Получение параметров через []
	string operator[](int index) const;

	// Получение параметров через []
	template <typename T>
	typename enable_if_t<is_same_v<T, float>, T>
	operator[](int index) const;

	template <typename T>
	typename enable_if_t<is_same_v<T, bool>, T>
	operator[](int index) const;

	template <typename T>
	typename enable_if_t<is_same_v<T, int>, T>
	operator[](int index) const;

	template <typename T>
	typename enable_if_t<is_same_v<T, string>, T>
	operator[](int index) const;

	// Изменение параметров через []
	template <typename T>
	typename enable_if_t<is_same_v<T, float>, T&>
	operator[](int index);

	template <typename T>
	typename enable_if_t<is_same_v<T, bool>, T&>
	operator[](int index);

	template <typename T>
	typename enable_if_t<is_same_v<T, int>, T&>
	operator[](int index);

	template <typename T>
	typename enable_if_t<is_same_v<T, string>, T&>
	operator[](int index);

	// Сложение удобств
	friend vector<string>  operator+ (const FamilyRoom& fr1, const FamilyRoom& fr2);
	friend vector<string>  operator+ (const vector<string>& amenities, const FamilyRoom& fr);
	friend vector<string>  operator+ (const FamilyRoom& fr, const vector<string>& amenities);
	friend vector<string>& operator+=(vector<string>& amenities, const FamilyRoom& fr);
	friend FamilyRoom&	   operator+=(FamilyRoom& fr, const vector<string>& amenities);
	friend FamilyRoom&	   operator+=(FamilyRoom& fr, const string& amenities);

	// Красивый перевод в строку
	explicit operator string() const;

	// Переопределение операции вывода <<
	friend ostream& operator<<(ostream& os, const FamilyRoom& r);

	// Переопределение операции ввода >>
	friend istream& operator>>(istream& is, FamilyRoom& r);

	// Переопределённый вывод
	virtual void print() const override;

	// Переопределённый ввод
	virtual bool input() override;
};

#include "kondakov_lr5_family_room.hpp"

#endif // KONDAKOV_LR5_FAMILY_ROOM_H