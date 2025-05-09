---
title: Kondakov_LR5_Hotel/kondakov_lr5_standard_room.hpp
summary: Реализация методов класса StandardRoom. 

---

# Kondakov_LR5_Hotel/kondakov_lr5_standard_room.hpp

Реализация методов класса [StandardRoom](Classes/class_standard_room.md).  [More...](#detailed-description)

## Detailed Description

Реализация методов класса [StandardRoom](Classes/class_standard_room.md). 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 



## Source code

```cpp


#ifndef KONDAKOV_LR5_STANDARD_ROOM_HPP
#define KONDAKOV_LR5_STANDARD_ROOM_HPP

#include "kondakov_lr5_standard_room.h"

inline int StandardRoom::get_bed_count() const {
    return bed_count;
}

inline bool StandardRoom::get_has_tv() const {
    return has_tv;
}

inline const vector<string>& StandardRoom::get_amenities() const {
    return amenities;
}

inline string StandardRoom::get_full_name() const {
    ostringstream oss;
    oss << ROOM_TYPE << " №" << room_number;
    return oss.str();
}

inline void StandardRoom::set_bed_count(int bed_count) {
    this->bed_count = bed_count;
}

inline void StandardRoom::set_has_tv(bool has_tv) {
    this->has_tv = has_tv;
}

inline void StandardRoom::set_amenities(vector<string> amenities) {
    this->amenities = move(amenities);
}

inline bool StandardRoom::input_bed_count() {
    if (InputControl::input(bed_count, "Количество кроватей: ", 1, 5)) { return true; }
    return false;
}

inline bool StandardRoom::input_has_tv() {
    if (InputControl::input(has_tv, "Наличие телевизора (1/0): ")) { return true; }
    return false;
}

template <char Delim>
inline bool StandardRoom::input_amenities() {
    cout << "Ввод удобств осуществляется в одну строку через разделитель '" << Delim << "'." << endl;
    cout << "Удобства: ";
    InputControl::DelimitedContainer<Delim, vector<string>&> dc(amenities);
    if (cin >> dc) { return false; }
    else { cin.clear(); return true; }
}

inline const string& StandardRoom::get_room_type() const {
    return ROOM_TYPE;
}

inline const string& StandardRoom::get_json_type() const {
    return JSON_TYPE;
}

inline float StandardRoom::calculate_total(int night_count) const {
    return price_per_night * static_cast<float>(night_count);
}

inline bool StandardRoom::validate() const {
    return bed_count >= 1;
}

inline void StandardRoom::exstra_bed() {
    price_per_night += price_per_night * 0.2f;
    bed_count++;
}

#endif // KONDAKOV_LR5_STANDARD_ROOM_HPP
```


-------------------------------

Updated on 2025-05-09 at 18:16:45 +0300
