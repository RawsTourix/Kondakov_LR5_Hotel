---
title: Kondakov_LR5_Hotel/kondakov_lr5_family_room.hpp
summary: Реализация методов класса FamilyRoom. 

---

# Kondakov_LR5_Hotel/kondakov_lr5_family_room.hpp

Реализация методов класса [FamilyRoom](Classes/class_family_room.md).  [More...](#detailed-description)

## Detailed Description

Реализация методов класса [FamilyRoom](Classes/class_family_room.md). 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 



## Source code

```cpp


#ifndef KONDAKOV_LR5_FAMILY_ROOM_HPP
#define KONDAKOV_LR5_FAMILY_ROOM_HPP

#include "kondakov_lr5_family_room.h"

inline int FamilyRoom::get_child_beds() const {
    return child_beds;
}

inline bool FamilyRoom::get_toy_kit() const {
    return toy_kit;
}

inline const vector<string>& FamilyRoom::get_amenities() const {
    return amenities;
}

inline string FamilyRoom::get_full_name() const {
    ostringstream oss;
    oss << ROOM_TYPE << " №" << room_number;
    return oss.str();
}

inline void FamilyRoom::set_child_beds(int child_beds) {
    this->child_beds = child_beds;
}

inline void FamilyRoom::set_toy_kit(bool toy_kit) {
    this->toy_kit = toy_kit;
}

inline void FamilyRoom::set_amenities(vector<string> amenities) {
    this->amenities = move(amenities);
}

inline bool FamilyRoom::input_child_beds() {
    if (InputControl::input((*this).operator[]<int>(2), "Количество детских кроватей: ", 1, 5)) { 
        return true; 
    }
    return false;
}

inline bool FamilyRoom::input_toy_kit() {
    if (InputControl::input((*this).operator[]<bool>(3), "Наличие набора детских игрушек: (1/0): ")) { 
        return true; 
    }
    return false;
}

template <char Delim>
inline bool FamilyRoom::input_amenities() {
    cout << "Ввод удобств осуществляется в одну строку через разделитель '" << Delim << "'." << endl << endl;
    cout << "Удобства: ";
    InputControl::DelimitedContainer<Delim, vector<string>&> dc(amenities);
    if (cin >> dc) { return false; }
    else { cin.clear(); return true; }
}

inline const string& FamilyRoom::get_room_type() const {
    return ROOM_TYPE;
}

inline const string& FamilyRoom::get_json_type() const {
    return JSON_TYPE;
}

inline float FamilyRoom::calculate_total(int night_count) const {
    return price_per_night * night_count + static_cast<float>(child_beds * 1000);
}

inline bool FamilyRoom::validate() const {
    return child_beds <= 4;
}

inline void FamilyRoom::add_play_area() {
    toy_kit = !toy_kit;
    price_per_night += 1500.0f * (toy_kit ? 1 : -1);
}

inline void FamilyRoom::remove_play_area() {
    if (toy_kit) {
        toy_kit = false;
        price_per_night -= 1500.0f;
    }
}

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
```


-------------------------------

Updated on 2025-05-06 at 23:16:47 +0300
