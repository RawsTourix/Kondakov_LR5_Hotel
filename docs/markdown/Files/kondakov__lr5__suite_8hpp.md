---
title: Kondakov_LR5_Hotel/kondakov_lr5_suite.hpp
summary: Реализация методов класса Suite. 

---

# Kondakov_LR5_Hotel/kondakov_lr5_suite.hpp

Реализация методов класса [Suite](Classes/class_suite.md).  [More...](#detailed-description)

## Detailed Description

Реализация методов класса [Suite](Classes/class_suite.md). 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 



## Source code

```cpp


#ifndef KONDAKOV_LR5_SUITE_HPP
#define KONDAKOV_LR5_SUITE_HPP

#include "kondakov_lr5_suite.h"

inline bool Suite::get_room_service() const {
    return room_service;
}

inline bool Suite::get_jacuzzi() const {
    return jacuzzi;
}

inline const vector<string>& Suite::get_amenities() const {
    return amenities;
}

inline string Suite::get_full_name() const {
    ostringstream oss;
    oss << ROOM_TYPE << " №" << room_number;
    return oss.str();
}

inline void Suite::set_room_service(bool room_service) {
    this->room_service = room_service;
}

inline void Suite::set_jacuzzi(bool jacuzzi) {
    this->jacuzzi = jacuzzi;
}

inline void Suite::set_amenities(vector<string> amenities) {
    this->amenities = move(amenities);
}

inline bool Suite::input_room_service() {
    if (InputControl::input(room_service, "Наличие обслуживания (1/0): ")) { return true; }
    return false;
}

inline bool Suite::input_jacuzzi() {
    if (InputControl::input(jacuzzi, "Наличие джакузи (1/0): ")) { return true; }
    return false;
}

template <char Delim>
inline bool Suite::input_amenities() {
    cout << "Ввод удобств осуществляется в одну строку через разделитель '" << Delim << "'." << endl << endl;
    cout << "Удобства: ";
    InputControl::DelimitedContainer<Delim, vector<string>&> dc(amenities);
    if (cin >> dc) { return false; }
    else { cin.clear(); return true; }
}

inline const string& Suite::get_room_type() const {
    return ROOM_TYPE;
}

inline const string& Suite::get_json_type() const {
    return JSON_TYPE;
}

inline float Suite::calculate_total(int night_count) const {
    return price_per_night * static_cast<float>(night_count) + SERVICE_PRICE;
}

inline bool Suite::validate() const {
    return calculate_total(1) >= 10000.0f;
}

inline void Suite::order_champagne(string amenity) {
    price_per_night += 2000.0f;
    InputControl::make_first_letter_uppercase(amenity);
    *this += amenity;
}

#endif // KONDAKOV_LR5_SUITE_HPP
```


-------------------------------

Updated on 2025-05-06 at 23:16:47 +0300
