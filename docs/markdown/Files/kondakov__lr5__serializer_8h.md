---
title: Kondakov_LR5_Hotel/kondakov_lr5_serializer.h
summary: Заголовочный файл для сериализации/десериализации комнат 

---

# Kondakov_LR5_Hotel/kondakov_lr5_serializer.h

Заголовочный файл для сериализации/десериализации комнат  [More...](#detailed-description)

## Namespaces

| Name           |
| -------------- |
| **[Serializer](Namespaces/namespace_serializer.md)** <br>Пространство имён для операций сериализации  |

## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[Serializer::RoomTypeRegistry](Classes/struct_serializer_1_1_room_type_registry.md)** <br>Регистратор типов комнат для фабричного создания  |

## Detailed Description

Заголовочный файл для сериализации/десериализации комнат 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 



## Source code

```cpp


#ifndef KONDAKOV_LR5_SERIALIZER_H
#define KONDAKOV_LR5_SERIALIZER_H


#include "kondakov_lr5_standard_room.h"
#include "kondakov_lr5_suite.h"
#include "kondakov_lr5_family_room.h"

namespace Serializer {

    struct RoomTypeRegistry {
        map<string, function<shared_ptr<Room>()>> creators; 

        RoomTypeRegistry();
    };

    static RoomTypeRegistry registry;

    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, json>
    serialize_rooms(const Container& rooms);

    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, Container>
    deserialize_rooms(const json& j);

    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, void>
    save_rooms_to_file(const Container& rooms, const string& filename);

    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, Container>
    load_rooms_from_file(const string& filename);
}

#include "kondakov_lr5_serializer.hpp"
 // Конец группы serialization

#endif // KONDAKOV_LR5_SERIALIZER_H
```


-------------------------------

Updated on 2025-05-09 at 18:16:45 +0300
