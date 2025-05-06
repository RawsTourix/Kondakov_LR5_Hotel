---
title: Serializer
summary: Пространство имён для операций сериализации 

---

# Serializer

Пространство имён для операций сериализации 

## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[Serializer::RoomTypeRegistry](Classes/struct_serializer_1_1_room_type_registry.md)** <br>Регистратор типов комнат для фабричного создания  |

## Functions

|                | Name           |
| -------------- | -------------- |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, shared_ptr< [Room](Classes/class_room.md) > >, [json](Modules/group__core__definitions.md#using-json) > | **[serialize_rooms](Namespaces/namespace_serializer.md#function-serialize-rooms)**(const Container & rooms)<br>Сериализация контейнера комнат в JSON.  |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, shared_ptr< [Room](Classes/class_room.md) > >, Container > | **[deserialize_rooms](Namespaces/namespace_serializer.md#function-deserialize-rooms)**(const [json](Modules/group__core__definitions.md#using-json) & j)<br>Десериализация комнат из JSON.  |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, shared_ptr< [Room](Classes/class_room.md) > >, void > | **[save_rooms_to_file](Namespaces/namespace_serializer.md#function-save-rooms-to-file)**(const Container & rooms, const string & filename)<br>Сохранение комнат в файл  |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, shared_ptr< [Room](Classes/class_room.md) > >, Container > | **[load_rooms_from_file](Namespaces/namespace_serializer.md#function-load-rooms-from-file)**(const string & filename)<br>Загрузка комнат из файла  |

## Attributes

|                | Name           |
| -------------- | -------------- |
| [RoomTypeRegistry](Classes/struct_serializer_1_1_room_type_registry.md) | **[registry](Namespaces/namespace_serializer.md#variable-registry)** <br>Статический экземпляр регистратора типов  |


## Functions Documentation

### function serialize_rooms

```cpp
template <typename Container >
enable_if_t< is_same_v< typename Container::value_type, shared_ptr< Room > >, json > serialize_rooms(
    const Container & rooms
)
```

Сериализация контейнера комнат в JSON. 

**Parameters**: 

  * **rooms** Контейнер с комнатами 


**Template Parameters**: 

  * **Container** Тип контейнера (должен содержать shared_ptr<Room>) 


**Return**: JSON объект с данными комнат


Преобразует каждую комнату в JSON объект с добавлением типа 


### function deserialize_rooms

```cpp
template <typename Container >
enable_if_t< is_same_v< typename Container::value_type, shared_ptr< Room > >, Container > deserialize_rooms(
    const json & j
)
```

Десериализация комнат из JSON. 

**Parameters**: 

  * **j** JSON объект с данными 


**Exceptions**: 

  * **runtime_error** При неизвестном типе комнаты


**Template Parameters**: 

  * **Container** Тип контейнера для результатов 


**Return**: Контейнер с десериализованными комнатами 


Создает объекты комнат через фабрику на основе типа в JSON 


### function save_rooms_to_file

```cpp
template <typename Container >
enable_if_t< is_same_v< typename Container::value_type, shared_ptr< Room > >, void > save_rooms_to_file(
    const Container & rooms,
    const string & filename
)
```

Сохранение комнат в файл 

**Parameters**: 

  * **rooms** Контейнер для сохранения 
  * **filename** Имя файла для сохранения 


**Exceptions**: 

  * **runtime_error** При ошибке открытия файла


**Template Parameters**: 

  * **Container** Тип контейнера с комнатами 



Сохраняет JSON-представление в файл с отступами (pretty print) 


### function load_rooms_from_file

```cpp
template <typename Container >
enable_if_t< is_same_v< typename Container::value_type, shared_ptr< Room > >, Container > load_rooms_from_file(
    const string & filename
)
```

Загрузка комнат из файла 

**Parameters**: 

  * **filename** Имя файла для загрузки 


**Exceptions**: 

  * **runtime_error** При ошибке открытия файла


**Template Parameters**: 

  * **Container** Тип контейнера для результатов 


**Return**: Контейнер с загруженными комнатами 


Читает JSON из файла и десериализует в объекты комнат 



## Attributes Documentation

### variable registry

```cpp
static RoomTypeRegistry registry;
```

Статический экземпляр регистратора типов 




-------------------------------

Updated on 2025-05-06 at 23:16:47 +0300