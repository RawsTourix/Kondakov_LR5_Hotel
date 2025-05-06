---
title: Kondakov_LR5_Hotel/kondakov_lr5_room.hpp
summary: Реализация методов класса Room. 

---

# Kondakov_LR5_Hotel/kondakov_lr5_room.hpp

Реализация методов класса [Room](Classes/class_room.md).  [More...](#detailed-description)

## Functions

|                | Name           |
| -------------- | -------------- |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, shared_ptr< [Room](Classes/class_room.md) > >, ostream & > | **[operator<<](Files/kondakov__lr5__room_8hpp.md#function-operator<<)**(ostream & os, const Container & rooms)<br>Вывод контейнера комнат  |

## Detailed Description

Реализация методов класса [Room](Classes/class_room.md). 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 

## Functions Documentation

### function operator<<

```cpp
template <typename Container >
enable_if_t< is_same_v< typename Container::value_type, shared_ptr< Room > >, ostream & > operator<<(
    ostream & os,
    const Container & rooms
)
```

Вывод контейнера комнат 

**Parameters**: 

  * **os** Поток вывода 
  * **rooms** Контейнер с комнатами 


**Template Parameters**: 

  * **Container** Тип контейнера (должен содержать shared_ptr<Room>) 


**Return**: Поток вывода 



## Source code

```cpp


#ifndef KONDAKOV_LR5_ROOM_HPP
#define KONDAKOV_LR5_ROOM_HPP

#include "kondakov_lr5_room.h"

inline int Room::get_room_number() const {
    return room_number;
}

inline float Room::get_price_per_night() const {
    return price_per_night;
}

inline bool Room::get_is_booked() const {
    return is_booked;
}

inline void Room::set_room_number(int room_number) {
    this->room_number = room_number;
}

inline void Room::set_price_per_night(float price_per_night) {
    this->price_per_night = price_per_night;
}

inline void Room::set_is_booked(bool is_booked) {
    this->is_booked = is_booked;
}

inline bool Room::input_room_number() {
    if (InputControl::input(room_number, "Номер комнаты: ", 1, 1000)) { return true; }
    return false;
}

template <typename Container>
inline typename enable_if_t<is_same_v<typename Container::value_type, int>, bool>
Room::input_room_number(const Container& room_numbers) {
    int room_number_temp = 0;
    if (InputControl::input(room_number_temp, "Номер комнаты: ", 1, 1000)) { return true; }

    while (find(room_numbers.begin(), room_numbers.end(), room_number_temp) != room_numbers.end()) {
        cout << endl << "Комната с номером \"" << room_number_temp << "\" уже существует!" << endl << endl;
        if (InputControl::input(room_number_temp, "Номер комнаты: ", 1, 1000)) { return true; }
    }

    room_number = room_number_temp;
    return false;
}

inline bool Room::input_price_per_night() {
    ostringstream message;
    message << "Цена за ночь (" << CURRENCY << "): ";
    if (InputControl::input(price_per_night, message.str(), 0.0f, 100000.0f)) { return true; }
    return false;
}

inline bool Room::input_is_booked() {
    if (InputControl::input(is_booked, "Стасус бронирования (1/0): ")) { return true; }
    return false;
}

template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, ostream&>
operator<<(ostream& os, const Container& rooms) {
    for (const auto& room : rooms) {
        room->print();
    }
    return os;
}

#endif // KONDAKOV_LR5_ROOM_HPP
```


-------------------------------

Updated on 2025-05-06 at 23:16:47 +0300
