#ifndef KONDAKOV_LR5_CHILD_CARE_H
#define KONDAKOV_LR5_CHILD_CARE_H

#include "kondakov_lr5_input_control.h"

// Класс ChildCare (услуги для детей)
class ChildCare {
protected:
	float child_care_price;  // Стоимость услуг для детей
	bool  has_child_care;	 // Наличие услуг для детей

	// Переопределённый вывод
	void print() const {
		cout << *this << endl;
	}

	// Переопределённый ввод
	bool input() {
		return static_cast<bool>(cin >> *this);
	}

public:
	// Валюта
	static const string CURRENCY;

	// Конструктор по умолчанию
	ChildCare();

	// Конструктор преобразования
	ChildCare(bool has_child_care);

	// Конструктор с параметрами
	ChildCare(float child_care_price, bool has_child_care);

	// Конструктор копирования
	ChildCare(const ChildCare&) = default;
	ChildCare& operator=(const ChildCare&) = default;

	// Конструктор перемещения
	ChildCare(ChildCare&& other) noexcept;
	ChildCare& operator=(ChildCare&&) noexcept = default;

	// Виртуальный деструктор
	~ChildCare() = default;

	// Геттер стоимости услуг для детей
	inline float get_child_care_price() const;

	// Геттер стоимости услуг для детей
	inline bool get_has_child_care() const;

	// Сеттер стоимости услуг для детей
	inline void set_child_care_price(float child_care_price);

	// Сеттер стоимости услуг для детей
	inline void set_has_child_care(bool has_child_care);

	// Инпуттер стоимости услуг для детей
	inline bool input_child_care_price();

	// Инпуттер стоимости услуг для детей
	inline bool input_has_child_care();

	// Красивый перевод в строку
	explicit operator string() const;

	// Переопределение операции вывода <<
	friend ostream& operator<<(ostream& os, const ChildCare& cr);

	// Переопределение операции ввода >>
	friend istream& operator>>(istream& is, ChildCare& cr);

};

#include "kondakov_lr5_child_care.hpp"

#endif // KONDAKOV_LR5_CHILD_CARE_H