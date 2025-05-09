---
title: Kondakov_LR5_Hotel/kondakov_lr5_family_room.cpp
summary: Реализация методов класса FamilyRoom. 

---

# Kondakov_LR5_Hotel/kondakov_lr5_family_room.cpp

Реализация методов класса [FamilyRoom](Classes/class_family_room.md).  [More...](#detailed-description)

## Functions

|                | Name           |
| -------------- | -------------- |
| vector< string > | **[operator+](Files/kondakov__lr5__family__room_8cpp.md#function-operator+)**(const [FamilyRoom](Classes/class_family_room.md) & fr1, const [FamilyRoom](Classes/class_family_room.md) & fr2) |
| vector< string > | **[operator+](Files/kondakov__lr5__family__room_8cpp.md#function-operator+)**(const vector< string > & amenities, const [FamilyRoom](Classes/class_family_room.md) & fr) |
| vector< string > | **[operator+](Files/kondakov__lr5__family__room_8cpp.md#function-operator+)**(const [FamilyRoom](Classes/class_family_room.md) & fr, const vector< string > & amenities) |
| vector< string > & | **[operator+=](Files/kondakov__lr5__family__room_8cpp.md#function-operator+=)**(vector< string > & amenities, const [FamilyRoom](Classes/class_family_room.md) & fr) |
| [FamilyRoom](Classes/class_family_room.md) & | **[operator+=](Files/kondakov__lr5__family__room_8cpp.md#function-operator+=)**([FamilyRoom](Classes/class_family_room.md) & fr, const vector< string > & amenities) |
| [FamilyRoom](Classes/class_family_room.md) & | **[operator+=](Files/kondakov__lr5__family__room_8cpp.md#function-operator+=)**([FamilyRoom](Classes/class_family_room.md) & fr, const string & amenities) |
| ostream & | **[operator<<](Files/kondakov__lr5__family__room_8cpp.md#function-operator<<)**(ostream & os, const [FamilyRoom](Classes/class_family_room.md) & fr)<br>Оператор вывода  |
| istream & | **[operator>>](Files/kondakov__lr5__family__room_8cpp.md#function-operator>>)**(istream & is, [FamilyRoom](Classes/class_family_room.md) & fr)<br>Оператор ввода  |

## Detailed Description

Реализация методов класса [FamilyRoom](Classes/class_family_room.md). 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 

## Functions Documentation

### function operator+

```cpp
vector< string > operator+(
    const FamilyRoom & fr1,
    const FamilyRoom & fr2
)
```


### function operator+

```cpp
vector< string > operator+(
    const vector< string > & amenities,
    const FamilyRoom & fr
)
```


### function operator+

```cpp
vector< string > operator+(
    const FamilyRoom & fr,
    const vector< string > & amenities
)
```


### function operator+=

```cpp
vector< string > & operator+=(
    vector< string > & amenities,
    const FamilyRoom & fr
)
```


### function operator+=

```cpp
FamilyRoom & operator+=(
    FamilyRoom & fr,
    const vector< string > & amenities
)
```


### function operator+=

```cpp
FamilyRoom & operator+=(
    FamilyRoom & fr,
    const string & amenities
)
```


### function operator<<

```cpp
ostream & operator<<(
    ostream & os,
    const FamilyRoom & fr
)
```

Оператор вывода 

**Parameters**: 

  * **os** Поток вывода 
  * **fr** Комната для вывода 


**Return**: Поток вывода 

### function operator>>

```cpp
istream & operator>>(
    istream & is,
    FamilyRoom & fr
)
```

Оператор ввода 

**Parameters**: 

  * **is** Поток ввода 
  * **fr** Комната для ввода 


**Return**: Поток ввода 



## Source code

```cpp


#include "kondakov_lr5_family_room.h"

FamilyRoom::FamilyRoom()
    : Room(),
      ChildCare(),
      child_beds(1),
      toy_kit(false),
      amenities({ "Wi-Fi", "Air condition" }) {
}

FamilyRoom::FamilyRoom(int room_number, int child_beds)
    : Room(room_number),
      ChildCare(true),
      child_beds(child_beds),
      toy_kit(false),
      amenities({"Wi-Fi", "Air condition"}) {
}

FamilyRoom::FamilyRoom(int room_number, float price_per_night, bool is_booked,
                     float child_care_price, bool has_child_care,
                     int child_beds, bool toy_kit)
    : FamilyRoom(room_number, price_per_night, is_booked, child_care_price,
                has_child_care, child_beds, toy_kit, "Wi-Fi, air condition") {
}

FamilyRoom::FamilyRoom(int room_number, float price_per_night, bool is_booked,
                     float child_care_price, bool has_child_care,
                     int child_beds, bool toy_kit, string amenities)
    : Room(room_number, price_per_night, is_booked),
      ChildCare(child_care_price, has_child_care),
      child_beds(child_beds),
      toy_kit(toy_kit) {
    InputControl::DelimitedContainer<',', vector<string>&> dc(this->amenities);
    dc >> amenities;
}

FamilyRoom::FamilyRoom(int room_number, float price_per_night, bool is_booked,
    float child_care_price, bool has_child_care,
    int child_beds, bool toy_kit, vector<string> amenities)
    : Room(room_number, price_per_night, is_booked),
    ChildCare(child_care_price, has_child_care),
    child_beds(child_beds),
    toy_kit(toy_kit),
    amenities(amenities) {
}

FamilyRoom::FamilyRoom(FamilyRoom&& other) noexcept
    : Room(move(other)),
      ChildCare(move(other)),
      child_beds(other.child_beds),
      toy_kit(other.toy_kit) {
}

json FamilyRoom::to_json() const {
    return {
        { "room_number", room_number },
        { "price_per_night", price_per_night },
        { "is_booked", is_booked },
        { "child_care_price", child_care_price },
        { "has_child_care", has_child_care },
        { "child_beds", child_beds },
        { "toy_kit", toy_kit },
        { "amenities", amenities }
    };
}

void FamilyRoom::from_json(const json& j) {
    room_number = j["room_number"];
    price_per_night = j["price_per_night"];
    is_booked = j["is_booked"];
    child_care_price = j["child_care_price"];
    has_child_care = j["has_child_care"];
    child_beds = j["child_beds"];
    toy_kit = j["toy_kit"];
    amenities = j["amenities"];
}

string FamilyRoom::operator[](int index) const {
    ostringstream oss;
    switch (index) {
        case 0: oss << "Стоимость услуг для детей: " << child_care_price; break;
        case 1: oss << "Наличие услуг для детей: " << has_child_care; break;
        case 2: oss << "Количество детских кроватей: " << child_beds; break;
        case 3: oss << "Наличие набора детских игрушек: " << toy_kit; break;
        case 4: oss << "Удобства: " << amenities; break;
        default: 
            ostringstream error;
            error << "Значение \"" << index << "\" вне допустимого диапазона (0-4)";
            throw out_of_range(error.str());
    }
    return oss.str();
}

vector<string> operator+(const FamilyRoom& fr1, const FamilyRoom& fr2) {
    vector<string> a(fr1.amenities);
    a += fr2;
    return a;
}

vector<string> operator+(const vector<string>& amenities, const FamilyRoom& fr) {
    vector<string> a(amenities);
    a += fr;
    return a;
}

vector<string> operator+(const FamilyRoom& fr, const vector<string>& amenities) {
    vector<string> a(fr.amenities);
    a += amenities;
    return a;
}

vector<string>& operator+=(vector<string>& amenities, const FamilyRoom& fr) {
    amenities += fr.amenities;
    return amenities;
}

FamilyRoom& operator+=(FamilyRoom& fr, const vector<string>& amenities) {
    fr.amenities += amenities;
    return fr;
}

FamilyRoom& operator+=(FamilyRoom& fr, const string& amenities) {
    fr.amenities += amenities;
    return fr;
}

FamilyRoom::operator string() const {
    ostringstream oss;
    oss << "Количество детских кроватей:\t"    << child_beds << endl
        << "Наличие набора детских игрушек:\t" << (toy_kit ? "да" : "нет") << endl
        << "Удобства:\t\t\t"                   << amenities;
    return oss.str();
}

ostream& operator<<(ostream& os, const FamilyRoom& fr) {
    os << static_cast<string>(fr);
    return os;
}

istream& operator>>(istream& is, FamilyRoom& fr) {
    if (fr.input_child_beds())      { is.setstate(ios::failbit); return is; }
    if (fr.input_toy_kit())         { is.setstate(ios::failbit); return is; }
    if (fr.input_amenities<','>())  { is.setstate(ios::failbit); return is; }
    return is;
}

void FamilyRoom::print() const {
    cout << this->to_string() << endl << endl;
}

bool FamilyRoom::input() {
    if (Room::input()) {          // Ввод базовой информации
        if (ChildCare::input()) { // Ввод информации об услугах
            if (cin >> *this) {   // Ввод специфичной информации
                return true;
            }
        }
    }
    cin.clear();
    return false;
}

string FamilyRoom::to_string() const {
    ostringstream oss;
    oss << "[" << get_full_name() << "]" << endl;
    oss << Room::to_string() << endl;
    oss << ChildCare::to_string() << endl;
    oss << *this;
    return oss.str();
}
```


-------------------------------

Updated on 2025-05-09 at 18:16:45 +0300
