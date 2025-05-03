#ifndef KONDAKOV_LR5_FAMILY_ROOM_HPP
#define KONDAKOV_LR5_FAMILY_ROOM_HPP

#include "kondakov_lr5_family_room.h"

// Геттер количества детских кроватей
inline int FamilyRoom::get_child_beds() const {
	return child_beds;
}

// Геттер наличия набора игрушек
inline int FamilyRoom::get_toy_kit() const {
	return toy_kit;
}

// Геттер удобств
inline const vector<string>& FamilyRoom::get_amenities() const {
	return amenities;
}

// Геттер полного названия комнаты
inline string FamilyRoom::get_full_name() const {
	ostringstream oss;
	oss << ROOM_TYPE << " №" << room_number;
	return oss.str();
}

// Сеттер количества детских кроватей
inline void FamilyRoom::set_child_beds(int child_beds) {
	this->child_beds = child_beds;
}

// Сеттер наличия набора игрушек
inline void FamilyRoom::set_toy_kit(bool toy_kit) {
	this->toy_kit = toy_kit;
}

// Сеттер удобств
inline void FamilyRoom::set_amenities(vector<string> amenities) {
	this->amenities = move(amenities);
}

// Инпуттер количества детских кроватей
inline bool FamilyRoom::input_child_beds() {
	// Реализация через [] по заданию
	if (InputControl::input((*this).operator[]<int>(2), "Количество детских кроватей: ", 0, 5)) { return true; }
	return false;
}

// Инпуттер наличия набора игрушек
inline bool FamilyRoom::input_toy_kit() {
	// Реализация через [] по заданию
	if (InputControl::input((*this).operator[]<bool>(3), "Наличие набора детских игрушек: (1/0): ")) { return true; }
	return false;
}

// Инпуттер удобств
template <char Delim>
inline bool FamilyRoom::input_amenities() {
	cout << "Ввод удобств осуществляется в одну строку через разделитель '" << Delim << "'." << endl << endl;
	cout << "Удобства: ";
	InputControl::DelimitedContainer<Delim, vector<string>&> dc(amenities);
	if (cin >> dc) { return false; }
	else { cin.clear(); return true; }
}

// Виртуальный геттер типа комнаты
inline const string& FamilyRoom::get_room_type() const {
	return ROOM_TYPE;
}

// Цена * ночи + 1000 руб./ребенок
inline float FamilyRoom::calculate_total(int night_count) const {
	return price_per_night * night_count + static_cast<float>(child_beds * 1000);
}

// Проверка child_beds <= 4
inline bool FamilyRoom::validate() const {
	return child_beds <= 4;
}

// Активация игровой зоны (+1500 руб.)
inline void FamilyRoom::add_play_area() {
	if (!toy_kit) {
		toy_kit = true;
		price_per_night += 1500.0f;
	}
}

// Активация игровой зоны (-1500 руб.)
inline void FamilyRoom::remove_play_area() {
	if (toy_kit) {
		toy_kit = false;
		price_per_night -= 1500.0f;
	}
}

// Получение параметров через []
template <typename T>
typename enable_if_t<is_same_v<T, float>, T>
FamilyRoom::operator[](int index) const {
	if (index == 0) return child_care_price;
	throw invalid_argument("Неверный индекс для float");
}

template <typename T>
typename enable_if_t<is_same_v<T, bool>, T>
FamilyRoom::operator[](int index) const {
	if (index == 1) return has_child_care;
	if (index == 3) return toy_kit;
	throw invalid_argument("Неверный индекс для bool");
}

template <typename T>
typename enable_if_t<is_same_v<T, int>, T>
FamilyRoom::operator[](int index) const {
	if (index == 2) return child_beds;
	throw invalid_argument("Неверный индекс для int");
}

template <typename T>
typename enable_if_t<is_same_v<T, string>, T>
FamilyRoom::operator[](int index) const {
	if (index == 4) return amenities;
	throw invalid_argument("Неверный индекс для string");
}

// Изменение параметров через []
template <typename T>
typename enable_if_t<is_same_v<T, float>, T&>
FamilyRoom::operator[](int index) {
	if (index == 0) return child_care_price;
	throw invalid_argument("Неверный индекс для float");
}

template <typename T>
typename enable_if_t<is_same_v<T, bool>, T&>
FamilyRoom::operator[](int index) {
	if (index == 1) return has_child_care;
	if (index == 3) return toy_kit;
	throw invalid_argument("Неверный индекс для bool");
}

template <typename T>
typename enable_if_t<is_same_v<T, int>, T&>
FamilyRoom::operator[](int index) {
	if (index == 2) return child_beds;
	throw invalid_argument("Неверный индекс для int");
}

template <typename T>
typename enable_if_t<is_same_v<T, string>, T&>
FamilyRoom::operator[](int index) {
	if (index == 4) return amenities;
	throw invalid_argument("Неверный индекс для string");
}

#endif // KONDAKOV_LR5_FAMILY_ROOM_HPP