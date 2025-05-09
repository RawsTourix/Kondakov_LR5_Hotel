---
title: Kondakov_LR5_Hotel/kondakov_lr5_room.cpp
summary: Реализация методов класса Room. 

---

# Kondakov_LR5_Hotel/kondakov_lr5_room.cpp

Реализация методов класса [Room](Classes/class_room.md).  [More...](#detailed-description)

## Functions

|                | Name           |
| -------------- | -------------- |
| bool | **[operator==](Files/kondakov__lr5__room_8cpp.md#function-operator==)**(const [Room](Classes/class_room.md) & r1, const [Room](Classes/class_room.md) & r2) |
| bool | **[operator==](Files/kondakov__lr5__room_8cpp.md#function-operator==)**(int room_number, const [Room](Classes/class_room.md) & r2) |
| bool | **[operator==](Files/kondakov__lr5__room_8cpp.md#function-operator==)**(const [Room](Classes/class_room.md) & r1, int room_number) |
| bool | **[operator>=](Files/kondakov__lr5__room_8cpp.md#function-operator>=)**(const [Room](Classes/class_room.md) & r1, const [Room](Classes/class_room.md) & r2) |
| bool | **[operator>=](Files/kondakov__lr5__room_8cpp.md#function-operator>=)**(int room_number, const [Room](Classes/class_room.md) & r2) |
| bool | **[operator>=](Files/kondakov__lr5__room_8cpp.md#function-operator>=)**(const [Room](Classes/class_room.md) & r1, int room_number) |
| bool | **[operator<=](Files/kondakov__lr5__room_8cpp.md#function-operator<=)**(const [Room](Classes/class_room.md) & r1, const [Room](Classes/class_room.md) & r2) |
| bool | **[operator<=](Files/kondakov__lr5__room_8cpp.md#function-operator<=)**(int room_number, const [Room](Classes/class_room.md) & r2) |
| bool | **[operator<=](Files/kondakov__lr5__room_8cpp.md#function-operator<=)**(const [Room](Classes/class_room.md) & r1, int room_number) |
| bool | **[operator>](Files/kondakov__lr5__room_8cpp.md#function-operator>)**(const [Room](Classes/class_room.md) & r1, const [Room](Classes/class_room.md) & r2) |
| bool | **[operator>](Files/kondakov__lr5__room_8cpp.md#function-operator>)**(int room_number, const [Room](Classes/class_room.md) & r2) |
| bool | **[operator>](Files/kondakov__lr5__room_8cpp.md#function-operator>)**(const [Room](Classes/class_room.md) & r1, int room_number) |
| bool | **[operator<](Files/kondakov__lr5__room_8cpp.md#function-operator<)**(const [Room](Classes/class_room.md) & r1, const [Room](Classes/class_room.md) & r2) |
| bool | **[operator<](Files/kondakov__lr5__room_8cpp.md#function-operator<)**(int room_number, const [Room](Classes/class_room.md) & r2) |
| bool | **[operator<](Files/kondakov__lr5__room_8cpp.md#function-operator<)**(const [Room](Classes/class_room.md) & r1, int room_number) |
| bool | **[operator!=](Files/kondakov__lr5__room_8cpp.md#function-operator!=)**(const [Room](Classes/class_room.md) & r1, const [Room](Classes/class_room.md) & r2) |
| bool | **[operator!=](Files/kondakov__lr5__room_8cpp.md#function-operator!=)**(int room_number, const [Room](Classes/class_room.md) & r2) |
| bool | **[operator!=](Files/kondakov__lr5__room_8cpp.md#function-operator!=)**(const [Room](Classes/class_room.md) & r1, int room_number) |
| ostream & | **[operator<<](Files/kondakov__lr5__room_8cpp.md#function-operator<<)**(ostream & os, const [Room](Classes/class_room.md) & r)<br>Оператор вывода  |
| istream & | **[operator>>](Files/kondakov__lr5__room_8cpp.md#function-operator>>)**(istream & is, [Room](Classes/class_room.md) & r)<br>Оператор ввода  |

## Detailed Description

Реализация методов класса [Room](Classes/class_room.md). 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 

## Functions Documentation

### function operator==

```cpp
bool operator==(
    const Room & r1,
    const Room & r2
)
```


### function operator==

```cpp
bool operator==(
    int room_number,
    const Room & r2
)
```


### function operator==

```cpp
bool operator==(
    const Room & r1,
    int room_number
)
```


### function operator>=

```cpp
bool operator>=(
    const Room & r1,
    const Room & r2
)
```


### function operator>=

```cpp
bool operator>=(
    int room_number,
    const Room & r2
)
```


### function operator>=

```cpp
bool operator>=(
    const Room & r1,
    int room_number
)
```


### function operator<=

```cpp
bool operator<=(
    const Room & r1,
    const Room & r2
)
```


### function operator<=

```cpp
bool operator<=(
    int room_number,
    const Room & r2
)
```


### function operator<=

```cpp
bool operator<=(
    const Room & r1,
    int room_number
)
```


### function operator>

```cpp
bool operator>(
    const Room & r1,
    const Room & r2
)
```


### function operator>

```cpp
bool operator>(
    int room_number,
    const Room & r2
)
```


### function operator>

```cpp
bool operator>(
    const Room & r1,
    int room_number
)
```


### function operator<

```cpp
bool operator<(
    const Room & r1,
    const Room & r2
)
```


### function operator<

```cpp
bool operator<(
    int room_number,
    const Room & r2
)
```


### function operator<

```cpp
bool operator<(
    const Room & r1,
    int room_number
)
```


### function operator!=

```cpp
bool operator!=(
    const Room & r1,
    const Room & r2
)
```


### function operator!=

```cpp
bool operator!=(
    int room_number,
    const Room & r2
)
```


### function operator!=

```cpp
bool operator!=(
    const Room & r1,
    int room_number
)
```


### function operator<<

```cpp
ostream & operator<<(
    ostream & os,
    const Room & r
)
```

Оператор вывода 

**Parameters**: 

  * **os** Поток вывода 
  * **r** Комната для вывода 


**Return**: Поток вывода 

### function operator>>

```cpp
istream & operator>>(
    istream & is,
    Room & r
)
```

Оператор ввода 

**Parameters**: 

  * **is** Поток ввода 
  * **r** Комната для ввода 


**Return**: Поток ввода 



## Source code

```cpp


#include "kondakov_lr5_room.h"

const string Room::CURRENCY = "руб.";

Room::Room()
    : Room(0, 0.0f, false) {
}

Room::Room(int room_number)
    : Room(room_number, 0.0f, false) {
}

Room::Room(int room_number, float price_per_night, bool is_booked)
    : room_number(room_number),
    price_per_night(price_per_night),
    is_booked(is_booked) {
}

Room::Room(Room&& other) noexcept
    : room_number(exchange(other.room_number, 0)),
    price_per_night(exchange(other.price_per_night, 0.0f)),
    is_booked(other.is_booked) {
}

bool operator==(const Room& r1, const Room& r2) { return r1.room_number == r2.room_number; }
bool operator==(int room_number, const Room& r2) { return room_number == r2.room_number; }
bool operator==(const Room& r1, int room_number) { return r1.room_number == room_number; }
bool operator>=(const Room& r1, const Room& r2) { return r1.room_number >= r2.room_number; }
bool operator>=(int room_number, const Room& r2) { return room_number >= r2.room_number; }
bool operator>=(const Room& r1, int room_number) { return r1.room_number >= room_number; }
bool operator<=(const Room& r1, const Room& r2) { return r1.room_number <= r2.room_number; }
bool operator<=(int room_number, const Room& r2) { return room_number <= r2.room_number; }
bool operator<=(const Room& r1, int room_number) { return r1.room_number <= room_number; }
bool operator> (const Room& r1, const Room& r2) { return r1.room_number > r2.room_number; }
bool operator> (int room_number, const Room& r2) { return room_number > r2.room_number; }
bool operator> (const Room& r1, int room_number) { return r1.room_number > room_number; }
bool operator< (const Room& r1, const Room& r2) { return r1.room_number < r2.room_number; }
bool operator< (int room_number, const Room& r2) { return room_number < r2.room_number; }
bool operator< (const Room& r1, int room_number) { return r1.room_number < room_number; }
bool operator!=(const Room& r1, const Room& r2) { return r1.room_number != r2.room_number; }
bool operator!=(int room_number, const Room& r2) { return room_number != r2.room_number; }
bool operator!=(const Room& r1, int room_number) { return r1.room_number != room_number; }

Room::operator string() const {
    ostringstream oss;
    oss << "Цена за ночь:\t\t\t"      << price_per_night << " " << CURRENCY << endl
        << "Статус бронирования:\t\t" << (is_booked ? "да" : "нет");

    return oss.str();
}

ostream& operator<<(ostream& os, const Room& r) {
    os << static_cast<string>(r);
    return os;
}

istream& operator>>(istream& is, Room& r) {
    cout << "Введите информацию о комнате: " << endl << endl;
    if (r.input_room_number())     { is.setstate(ios::failbit); return is; }
    if (r.input_price_per_night()) { is.setstate(ios::failbit); return is; }
    if (r.input_is_booked())       { is.setstate(ios::failbit); return is; }
    return is;
}

string Room::to_string() const {
    ostringstream oss;
    oss << *this;
    return oss.str();
}
```


-------------------------------

Updated on 2025-05-09 at 18:16:45 +0300
