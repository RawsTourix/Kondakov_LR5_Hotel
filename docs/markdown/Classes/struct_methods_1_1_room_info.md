---
title: Methods::RoomInfo
summary: Краткая информация о комнате для отображения 

---

# Methods::RoomInfo



Краткая информация о комнате для отображения 


`#include <kondakov_lr5_methods.h>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[RoomInfo](Classes/struct_methods_1_1_room_info.md#function-roominfo)**() =delete |
| | **[RoomInfo](Classes/struct_methods_1_1_room_info.md#function-roominfo)**(int number, string full_name, shared_ptr< [Room](Classes/class_room.md) > room)<br>Конструктор с параметрами  |
| void | **[print](Classes/struct_methods_1_1_room_info.md#function-print)**() const<br>Вывод информации о комнате  |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| int | **[number](Classes/struct_methods_1_1_room_info.md#variable-number)** <br>Порядковый номер в списке  |
| string | **[full_name](Classes/struct_methods_1_1_room_info.md#variable-full-name)** <br>Полное название комнаты  |
| shared_ptr< [Room](Classes/class_room.md) > | **[room](Classes/struct_methods_1_1_room_info.md#variable-room)** <br>Указатель на объект комнаты  |

## Friends

|                | Name           |
| -------------- | -------------- |
| ostream & | **[operator<<](Classes/struct_methods_1_1_room_info.md#friend-operator<<)**(ostream & os, const [RoomInfo](Classes/struct_methods_1_1_room_info.md) & ri)  |

## Public Functions Documentation

### function RoomInfo

```cpp
RoomInfo() =delete
```


### function RoomInfo

```cpp
RoomInfo(
    int number,
    string full_name,
    shared_ptr< Room > room
)
```

Конструктор с параметрами 

**Parameters**: 

  * **number** Порядковый номер 
  * **full_name** Название комнаты 
  * **room** Указатель на комнату
  * **number** Порядковый номер комнаты 
  * **full_name** Полное название комнаты 
  * **room** Указатель на объект комнаты 


Конструктор структуры [RoomInfo](Classes/struct_methods_1_1_room_info.md).


### function print

```cpp
inline void print() const
```

Вывод информации о комнате 

## Public Attributes Documentation

### variable number

```cpp
int number;
```

Порядковый номер в списке 

### variable full_name

```cpp
string full_name;
```

Полное название комнаты 

### variable room

```cpp
shared_ptr< Room > room;
```

Указатель на объект комнаты 

## Friends

### friend operator<<

```cpp
friend ostream & operator<<(
    ostream & os,

    const RoomInfo & ri
);
```


-------------------------------

Updated on 2025-05-09 at 18:16:45 +0300