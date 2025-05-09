---
title: Kondakov_LR5_Hotel/kondakov_lr5_methods.h
summary: Заголовочный файл с методами работы с комнатами 

---

# Kondakov_LR5_Hotel/kondakov_lr5_methods.h

Заголовочный файл с методами работы с комнатами  [More...](#detailed-description)

## Namespaces

| Name           |
| -------------- |
| **[Methods](Namespaces/namespace_methods.md)** <br>Пространство имён для операций с комнатами  |

## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[Methods::RoomInfo](Classes/struct_methods_1_1_room_info.md)** <br>Краткая информация о комнате для отображения  |

## Detailed Description

Заголовочный файл с методами работы с комнатами 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 



## Source code

```cpp


#ifndef KONDAKOV_LR5_METHODS_H
#define KONDAKOV_LR5_METHODS_H


#include "kondakov_lr5_menu_object.h"

namespace Methods {
    using ::operator<<;

    struct RoomInfo {
        int number;             
        string full_name;       
        shared_ptr<Room> room;  

        RoomInfo() = delete;
        
        RoomInfo(int number, string full_name, shared_ptr<Room> room);

        inline void print() const {
            cout << *this << endl;
        }

        friend ostream& operator<<(ostream& os, const RoomInfo& ri);
    };


    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    show_rooms(const Container& rooms);

    template <typename RoomType, typename Container>
    typename enable_if_t<is_base_of_v<Room, typename RoomType>&&
                         is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    add_room(Container& rooms);

    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    edit_room(Container& rooms);

    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    delete_room(Container& rooms);

    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    sort_rooms(Container& rooms);

    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    calculate_total(Container& rooms);

    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    validate_room(Container& rooms);

    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    additional_room_methods(Container& rooms);


    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, shared_ptr<Room>>
    get_room_from_rooms_map(string main_label, string message, Container& rooms);

    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, vector<int>>
    get_room_numbers(const Container& rooms);

    template <typename RoomType, typename Container>
    typename enable_if_t<is_base_of_v<Room, typename RoomType>&&
                         is_same_v<typename Container::value_type, shared_ptr<Room>>, bool>
    room_in_rooms_by_room_number(RoomType room, const Container& rooms);
};

#include "kondakov_lr5_methods.hpp"
 // Конец группы room_operations

#endif // KONDAKOV_LR5_METHODS_H
```


-------------------------------

Updated on 2025-05-09 at 18:16:45 +0300
