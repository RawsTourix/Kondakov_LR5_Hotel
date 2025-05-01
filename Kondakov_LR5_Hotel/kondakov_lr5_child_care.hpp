#ifndef KONDAKOV_LR5_CHILD_CARE_HPP
#define KONDAKOV_LR5_CHILD_CARE_HPP

#include "kondakov_lr5_child_care.h"

// Геттер стоимости услуг для детей
inline float ChildCare::get_child_care_price() const {
	return child_care_price;
}

// Геттер наличия услуг для детей
inline bool ChildCare::get_has_child_care() const {
	return has_child_care;
}

// Сеттер стоимости услуг для детей
inline void ChildCare::set_child_care_price(float child_care_price) {
	this->child_care_price = child_care_price;
}

// Сеттер наличия услуг для детей
inline void ChildCare::set_has_child_care(bool has_child_care) {
	this->has_child_care = has_child_care;
}

// Инпуттер стоимости услуг для детей
inline bool ChildCare::input_child_care_price() {
	if (InputControl::input(child_care_price, "Стоимость услуг для детей: ")) { return true; }
	return false;
}

// Инпуттер наличия услуг для детей
inline bool ChildCare::input_has_child_care() {
	if (InputControl::input(has_child_care, "Наличие услуг для детей (1/0): ")) { return true; }
	return false;
}

#endif // KONDAKOV_LR5_CHILD_CARE_HPP