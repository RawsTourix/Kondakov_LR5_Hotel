---
title: Kondakov_LR5_Hotel/kondakov_lr5_suite.cpp
summary: Реализация методов класса Suite. 

---

# Kondakov_LR5_Hotel/kondakov_lr5_suite.cpp

Реализация методов класса [Suite](Classes/class_suite.md).  [More...](#detailed-description)

## Functions

|                | Name           |
| -------------- | -------------- |
| vector< string > | **[operator+](Files/kondakov__lr5__suite_8cpp.md#function-operator+)**(const [Suite](Classes/class_suite.md) & s1, const [Suite](Classes/class_suite.md) & s2) |
| vector< string > | **[operator+](Files/kondakov__lr5__suite_8cpp.md#function-operator+)**(const vector< string > & amenities, const [Suite](Classes/class_suite.md) & s) |
| vector< string > | **[operator+](Files/kondakov__lr5__suite_8cpp.md#function-operator+)**(const [Suite](Classes/class_suite.md) & s, const vector< string > & amenities) |
| vector< string > & | **[operator+=](Files/kondakov__lr5__suite_8cpp.md#function-operator+=)**(vector< string > & amenities, const [Suite](Classes/class_suite.md) & s) |
| [Suite](Classes/class_suite.md) & | **[operator+=](Files/kondakov__lr5__suite_8cpp.md#function-operator+=)**([Suite](Classes/class_suite.md) & s, const vector< string > & amenities) |
| [Suite](Classes/class_suite.md) & | **[operator+=](Files/kondakov__lr5__suite_8cpp.md#function-operator+=)**([Suite](Classes/class_suite.md) & s, const string & amenities) |
| ostream & | **[operator<<](Files/kondakov__lr5__suite_8cpp.md#function-operator<<)**(ostream & os, const [Suite](Classes/class_suite.md) & sr)<br>Оператор вывода  |
| istream & | **[operator>>](Files/kondakov__lr5__suite_8cpp.md#function-operator>>)**(istream & is, [Suite](Classes/class_suite.md) & s)<br>Оператор ввода  |

## Detailed Description

Реализация методов класса [Suite](Classes/class_suite.md). 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 

## Functions Documentation

### function operator+

```cpp
vector< string > operator+(
    const Suite & s1,
    const Suite & s2
)
```


### function operator+

```cpp
vector< string > operator+(
    const vector< string > & amenities,
    const Suite & s
)
```


### function operator+

```cpp
vector< string > operator+(
    const Suite & s,
    const vector< string > & amenities
)
```


### function operator+=

```cpp
vector< string > & operator+=(
    vector< string > & amenities,
    const Suite & s
)
```


### function operator+=

```cpp
Suite & operator+=(
    Suite & s,
    const vector< string > & amenities
)
```


### function operator+=

```cpp
Suite & operator+=(
    Suite & s,
    const string & amenities
)
```


### function operator<<

```cpp
ostream & operator<<(
    ostream & os,
    const Suite & sr
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
    Suite & s
)
```

Оператор ввода 

**Parameters**: 

  * **is** Поток ввода 
  * **s** Комната для ввода 


**Return**: Поток ввода 



## Source code

```cpp


#include "kondakov_lr5_suite.h"

Suite::Suite()
    : Room(),
    room_service(true),
    jacuzzi(false),
    amenities({ "Lux", "Room service" }) {
}

Suite::Suite(int room_number, bool room_service)
    : Room(room_number),
    room_service(room_service),
    jacuzzi(false),
    amenities({ "Lux", "Room service" }) {
}

Suite::Suite(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi)
    : Suite(room_number, price_per_night, is_booked, room_service, jacuzzi, "Lux, room service") {
}

Suite::Suite(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi, string amenities)
    : Room(room_number, price_per_night, is_booked),
    room_service(room_service),
    jacuzzi(jacuzzi)
{
    InputControl::DelimitedContainer<',', vector<string>&> dc(this->amenities);
    dc >> amenities;
}

Suite::Suite(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi, vector<string> amenities)
    : Room(room_number, price_per_night, is_booked),
    room_service(room_service),
    jacuzzi(jacuzzi),
    amenities(amenities) {
}

Suite::Suite(Suite&& other) noexcept
    : Room(move(other)),
    room_service(other.room_service),
    jacuzzi(other.jacuzzi),
    amenities(move(other.amenities)) {
}

json Suite::to_json() const {
    return {
        { "room_number", room_number },
        { "price_per_night", price_per_night },
        { "is_booked", is_booked },
        { "room_service", room_service },
        { "jacuzzi", jacuzzi },
        { "amenities", amenities }
    };
}

void Suite::from_json(const json& j) {
    room_number = j["room_number"];
    price_per_night = j["price_per_night"];
    is_booked = j["is_booked"];
    room_service = j["room_service"];
    jacuzzi = j["jacuzzi"];
    amenities = j["amenities"];
}

vector<string> operator+(const Suite& s1, const Suite& s2) {
    vector<string> a(s1.amenities);
    a += s2;
    return a;
}
vector<string> operator+(const vector<string>& amenities, const Suite& s) {
    vector<string> a(amenities);
    a += s;
    return a;
}
vector<string> operator+(const Suite& s, const vector<string>& amenities) {
    vector<string> a(s.amenities);
    a += amenities;
    return a;
}
vector<string>& operator+=(vector<string>& amenities, const Suite& s) {
    amenities += s.amenities;
    return amenities;
}
Suite& operator+=(Suite& s, const vector<string>& amenities) {
    s.amenities += amenities;
    return s;
}
Suite& operator+=(Suite& s, const string& amenities) {
    s.amenities += amenities;
    return s;
}

Suite::operator string() const {
    ostringstream oss;
    oss << "Наличие обслуживания:\t\t" << (room_service ? "да" : "нет") << endl
        << "Наличие джакузи:\t\t"   << (jacuzzi ? "да" : "нет") << endl
        << "Удобства:\t\t\t"       << amenities;
    return oss.str();
}

ostream& operator<<(ostream& os, const Suite& sr) {
    os << static_cast<string>(sr);
    return os;
}

istream& operator>>(istream& is, Suite& s) {
    if (s.input_room_service())   { is.setstate(ios::failbit); return is; }
    if (s.input_jacuzzi())        { is.setstate(ios::failbit); return is; }
    if (s.input_amenities<','>()) { is.setstate(ios::failbit); return is; }
    return is;
}

void Suite::print() const {
    cout << this->to_string() << endl << endl;
}

bool Suite::input() {
    if (Room::input()) {
        if (cin >> *this) {
            return true;
        }
    }
    cin.clear();
    return false;
}

string Suite::to_string() const {
    ostringstream oss;
    oss << "[" << get_full_name() << "]" << endl;
    oss << Room::to_string() << endl;
    oss << *this;
    return oss.str();
}
```


-------------------------------

Updated on 2025-05-06 at 23:16:47 +0300
