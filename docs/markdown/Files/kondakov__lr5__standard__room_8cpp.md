---
title: Kondakov_LR5_Hotel/kondakov_lr5_standard_room.cpp
summary: Реализация методов класса StandardRoom. 

---

# Kondakov_LR5_Hotel/kondakov_lr5_standard_room.cpp

Реализация методов класса [StandardRoom](Classes/class_standard_room.md).  [More...](#detailed-description)

## Functions

|                | Name           |
| -------------- | -------------- |
| vector< string > | **[operator+](Files/kondakov__lr5__standard__room_8cpp.md#function-operator+)**(const [StandardRoom](Classes/class_standard_room.md) & sr1, const [StandardRoom](Classes/class_standard_room.md) & sr2) |
| vector< string > | **[operator+](Files/kondakov__lr5__standard__room_8cpp.md#function-operator+)**(const vector< string > & amenities, const [StandardRoom](Classes/class_standard_room.md) & sr) |
| vector< string > | **[operator+](Files/kondakov__lr5__standard__room_8cpp.md#function-operator+)**(const [StandardRoom](Classes/class_standard_room.md) & sr, const vector< string > & amenities) |
| vector< string > & | **[operator+=](Files/kondakov__lr5__standard__room_8cpp.md#function-operator+=)**(vector< string > & amenities, const [StandardRoom](Classes/class_standard_room.md) & sr) |
| [StandardRoom](Classes/class_standard_room.md) & | **[operator+=](Files/kondakov__lr5__standard__room_8cpp.md#function-operator+=)**([StandardRoom](Classes/class_standard_room.md) & sr, const vector< string > & amenities) |
| [StandardRoom](Classes/class_standard_room.md) & | **[operator+=](Files/kondakov__lr5__standard__room_8cpp.md#function-operator+=)**([StandardRoom](Classes/class_standard_room.md) & sr, const string & amenities) |
| ostream & | **[operator<<](Files/kondakov__lr5__standard__room_8cpp.md#function-operator<<)**(ostream & os, const [StandardRoom](Classes/class_standard_room.md) & sr)<br>Оператор вывода  |
| istream & | **[operator>>](Files/kondakov__lr5__standard__room_8cpp.md#function-operator>>)**(istream & is, [StandardRoom](Classes/class_standard_room.md) & sr)<br>Оператор ввода  |

## Detailed Description

Реализация методов класса [StandardRoom](Classes/class_standard_room.md). 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 

## Functions Documentation

### function operator+

```cpp
vector< string > operator+(
    const StandardRoom & sr1,
    const StandardRoom & sr2
)
```


### function operator+

```cpp
vector< string > operator+(
    const vector< string > & amenities,
    const StandardRoom & sr
)
```


### function operator+

```cpp
vector< string > operator+(
    const StandardRoom & sr,
    const vector< string > & amenities
)
```


### function operator+=

```cpp
vector< string > & operator+=(
    vector< string > & amenities,
    const StandardRoom & sr
)
```


### function operator+=

```cpp
StandardRoom & operator+=(
    StandardRoom & sr,
    const vector< string > & amenities
)
```


### function operator+=

```cpp
StandardRoom & operator+=(
    StandardRoom & sr,
    const string & amenities
)
```


### function operator<<

```cpp
ostream & operator<<(
    ostream & os,
    const StandardRoom & sr
)
```

Оператор вывода 

**Parameters**: 

  * **os** Поток вывода 
  * **sr** Комната для вывода 


**Return**: Поток вывода 

### function operator>>

```cpp
istream & operator>>(
    istream & is,
    StandardRoom & sr
)
```

Оператор ввода 

**Parameters**: 

  * **is** Поток ввода 
  * **sr** Комната для ввода 


**Return**: Поток ввода 



## Source code

```cpp


#include "kondakov_lr5_standard_room.h"

StandardRoom::StandardRoom()
    : Room(),
    bed_count(1),
    has_tv(false),
    amenities({ "Wi-Fi", "Air conditioner" }) {
}

StandardRoom::StandardRoom(int room_number, int bed_count)
    : Room(room_number),
    bed_count(bed_count),
    has_tv(false),
    amenities({ "Wi-Fi", "Air conditioner" }) {
}

StandardRoom::StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv)
    : StandardRoom(room_number, price_per_night, is_booked, bed_count, has_tv, "Wi-Fi, air conditioner") {
}

StandardRoom::StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv, string amenities)
    : Room(room_number, price_per_night, is_booked),
    bed_count(bed_count),
    has_tv(has_tv)
{
    InputControl::DelimitedContainer<',', vector<string>&> dc(this->amenities);
    dc >> amenities;
}

StandardRoom::StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv, vector<string> amenities)
    : Room(room_number, price_per_night, is_booked),
    bed_count(bed_count),
    has_tv(has_tv),
    amenities(amenities) {
}

StandardRoom::StandardRoom(StandardRoom&& other) noexcept
    : Room(move(other)),
    bed_count(exchange(other.bed_count, 0)),
    has_tv(other.has_tv),
    amenities(move(other.amenities)) {
}

json StandardRoom::to_json() const {
    return {
        { "room_number", room_number },
        { "price_per_night", price_per_night },
        { "is_booked", is_booked },
        { "bed_count", bed_count },
        { "has_tv", has_tv },
        { "amenities", amenities }
    };
}

void StandardRoom::from_json(const json& j) {
    room_number = j["room_number"];
    price_per_night = j["price_per_night"];
    is_booked = j["is_booked"];
    bed_count = j["bed_count"];
    has_tv = j["has_tv"];
    amenities = j["amenities"];
}

vector<string> operator+(const StandardRoom& sr1, const StandardRoom& sr2) {
    vector<string> a(sr1.amenities);
    a += sr2;
    return a;
}
vector<string> operator+(const vector<string>& amenities, const StandardRoom& sr) {
    vector<string> a(amenities);
    a += sr;
    return a;
}
vector<string> operator+(const StandardRoom& sr, const vector<string>& amenities) {
    vector<string> a(sr.amenities);
    a += amenities;
    return a;
}
vector<string>& operator+=(vector<string>& amenities, const StandardRoom& sr) {
    amenities += sr.amenities;
    return amenities;
}
StandardRoom& operator+=(StandardRoom& sr, const vector<string>& amenities) {
    sr.amenities += amenities;
    return sr;
}
StandardRoom& operator+=(StandardRoom& sr, const string& amenities) {
    sr.amenities += amenities;
    return sr;
}

StandardRoom::operator string() const {
    ostringstream oss;
    oss << "Количество кроватей:\t\t" << bed_count << endl
        << "Наличие телевизора:\t\t"  << (has_tv ? "да" : "нет") << endl
        << "Удобства:\t\t\t"          << amenities;
    return oss.str();
}

ostream& operator<<(ostream& os, const StandardRoom& sr) {
    os << static_cast<string>(sr);
    return os;
}

istream& operator>>(istream& is, StandardRoom& sr) {
    if (sr.input_bed_count())      { is.setstate(ios::failbit); return is; }
    if (sr.input_has_tv())         { is.setstate(ios::failbit); return is; }
    if (sr.input_amenities<','>()) { is.setstate(ios::failbit); return is; }
    return is;
}

void StandardRoom::print() const {
    cout << this->to_string() << endl << endl;
}

bool StandardRoom::input() {
    if (Room::input()) {
        if (cin >> *this) {
            return true;
        }
    }
    cin.clear();
    return false;
}

string StandardRoom::to_string() const {
    ostringstream oss;
    oss << "[" << get_full_name() << "]" << endl;
    oss << Room::to_string() << endl;
    oss << *this;
    return oss.str();
}
```


-------------------------------

Updated on 2025-05-06 at 23:16:47 +0300
