---
title: Serializer::RoomTypeRegistry
summary: Регистратор типов комнат для фабричного создания 

---

# Serializer::RoomTypeRegistry



Регистратор типов комнат для фабричного создания 


`#include <kondakov_lr5_serializer.h>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[RoomTypeRegistry](Classes/struct_serializer_1_1_room_type_registry.md#function-roomtyperegistry)**()<br>Конструктор регистратора типов  |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| map< string, function< shared_ptr< [Room](Classes/class_room.md) >()> > | **[creators](Classes/struct_serializer_1_1_room_type_registry.md#variable-creators)** <br>Карта создателей объектов  |

## Public Functions Documentation

### function RoomTypeRegistry

```cpp
RoomTypeRegistry()
```

Конструктор регистратора типов 

Конструктор регистратора типов комнат

Инициализирует карту creators для всех типов комнат

Инициализирует фабрику для создания [StandardRoom](Classes/class_standard_room.md), [Suite](Classes/class_suite.md) и [FamilyRoom](Classes/class_family_room.md)


## Public Attributes Documentation

### variable creators

```cpp
map< string, function< shared_ptr< Room >()> > creators;
```

Карта создателей объектов 

-------------------------------

Updated on 2025-05-06 at 23:16:47 +0300