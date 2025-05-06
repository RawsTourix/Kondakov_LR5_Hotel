---
title: Room
summary: Абстрактный базовый класс для представления гостиничного номера 

---

# Room



Абстрактный базовый класс для представления гостиничного номера 


`#include <kondakov_lr5_room.h>`

Inherited by [FamilyRoom](Classes/class_family_room.md), [StandardRoom](Classes/class_standard_room.md), [Suite](Classes/class_suite.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| int | **[get_room_number](Classes/class_room.md#function-get-room-number)**() const<br>Получить номер комнаты  |
| float | **[get_price_per_night](Classes/class_room.md#function-get-price-per-night)**() const<br>Получить цену за ночь  |
| bool | **[get_is_booked](Classes/class_room.md#function-get-is-booked)**() const<br>Получить статус бронирования  |
| virtual const vector< string > & | **[get_amenities](Classes/class_room.md#function-get-amenities)**() const =0 |
| virtual string | **[get_full_name](Classes/class_room.md#function-get-full-name)**() const =0 |
| void | **[set_room_number](Classes/class_room.md#function-set-room-number)**(int room_number)<br>Установить номер комнаты  |
| void | **[set_price_per_night](Classes/class_room.md#function-set-price-per-night)**(float price_per_night)<br>Установить цену за ночь  |
| void | **[set_is_booked](Classes/class_room.md#function-set-is-booked)**(bool is_booked)<br>Установить статус бронирования  |
| bool | **[input_room_number](Classes/class_room.md#function-input-room-number)**()<br>Ввод номера комнаты  |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, int >, bool > | **[input_room_number](Classes/class_room.md#function-input-room-number)**(const Container & room_numbers)<br>Ввод номера комнаты с проверкой уникальности  |
| bool | **[input_price_per_night](Classes/class_room.md#function-input-price-per-night)**()<br>Ввод цены за ночь  |
| bool | **[input_is_booked](Classes/class_room.md#function-input-is-booked)**()<br>Ввод статуса бронирования  |
| virtual const string & | **[get_room_type](Classes/class_room.md#function-get-room-type)**() const =0 |
| virtual const string & | **[get_json_type](Classes/class_room.md#function-get-json-type)**() const =0 |
| virtual float | **[calculate_total](Classes/class_room.md#function-calculate-total)**(int night_count) const =0 |
| virtual bool | **[validate](Classes/class_room.md#function-validate)**() const =0 |
| virtual [json](Modules/group__core__definitions.md#using-json) | **[to_json](Classes/class_room.md#function-to-json)**() const =0 |
| virtual void | **[from_json](Classes/class_room.md#function-from-json)**(const [json](Modules/group__core__definitions.md#using-json) & j) =0 |
| | **[Room](Classes/class_room.md#function-room)**()<br>Конструктор по умолчанию  |
| | **[Room](Classes/class_room.md#function-room)**(int room_number)<br>Конструктор преобразования (по номеру комнаты)  |
| | **[Room](Classes/class_room.md#function-room)**(int room_number, float price_per_night, bool is_booked)<br>Конструктор с параметрами  |
| | **[Room](Classes/class_room.md#function-room)**(const [Room](Classes/class_room.md) & ) =default<br>Конструктор копирования  |
| [Room](Classes/class_room.md) & | **[operator=](Classes/class_room.md#function-operator=)**(const [Room](Classes/class_room.md) & ) =default |
| | **[Room](Classes/class_room.md#function-room)**([Room](Classes/class_room.md) && other)<br>Конструктор перемещения  |
| [Room](Classes/class_room.md) & | **[operator=](Classes/class_room.md#function-operator=)**([Room](Classes/class_room.md) && ) =default |
| virtual | **[~Room](Classes/class_room.md#function-~room)**() =default<br>Виртуальный деструктор  |
| | **[operator string](Classes/class_room.md#function-operator-string)**() const<br>Преобразование в строку  |
| virtual string | **[to_string](Classes/class_room.md#function-to-string)**() const<br>Виртуальный метод преобразования в строку  |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, shared_ptr< [Room](Classes/class_room.md) > >, ostream & > friend | **[operator<<](Classes/class_room.md#function-operator<<)**(ostream & os, const Container & rooms)<br>Перегрузка вывода для контейнера комнат  |

## Protected Functions

|                | Name           |
| -------------- | -------------- |
| virtual void | **[print](Classes/class_room.md#function-print)**() const<br>Виртуальный метод вывода информации о комнате  |
| virtual bool | **[input](Classes/class_room.md#function-input)**()<br>Виртуальный метод ввода информации о комнате  |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| const string | **[CURRENCY](Classes/class_room.md#variable-currency)** <br>Валюта для отображения цен  |

## Protected Attributes

|                | Name           |
| -------------- | -------------- |
| int | **[room_number](Classes/class_room.md#variable-room-number)** <br>Номер комнаты  |
| float | **[price_per_night](Classes/class_room.md#variable-price-per-night)** <br>Цена за ночь  |
| bool | **[is_booked](Classes/class_room.md#variable-is-booked)** <br>Статус бронирования  |

## Friends

|                | Name           |
| -------------- | -------------- |
| bool | **[operator==](Classes/class_room.md#friend-operator==)**(const [Room](Classes/class_room.md) & r1, const [Room](Classes/class_room.md) & r2)  |
| bool | **[operator==](Classes/class_room.md#friend-operator==)**(int room_number, const [Room](Classes/class_room.md) & r2)  |
| bool | **[operator==](Classes/class_room.md#friend-operator==)**(const [Room](Classes/class_room.md) & r1, int room_number)  |
| bool | **[operator>=](Classes/class_room.md#friend-operator>=)**(const [Room](Classes/class_room.md) & r1, const [Room](Classes/class_room.md) & r2)  |
| bool | **[operator>=](Classes/class_room.md#friend-operator>=)**(int room_number, const [Room](Classes/class_room.md) & r2)  |
| bool | **[operator>=](Classes/class_room.md#friend-operator>=)**(const [Room](Classes/class_room.md) & r1, int room_number)  |
| bool | **[operator<=](Classes/class_room.md#friend-operator<=)**(const [Room](Classes/class_room.md) & r1, const [Room](Classes/class_room.md) & r2)  |
| bool | **[operator<=](Classes/class_room.md#friend-operator<=)**(int room_number, const [Room](Classes/class_room.md) & r2)  |
| bool | **[operator<=](Classes/class_room.md#friend-operator<=)**(const [Room](Classes/class_room.md) & r1, int room_number)  |
| bool | **[operator>](Classes/class_room.md#friend-operator>)**(const [Room](Classes/class_room.md) & r1, const [Room](Classes/class_room.md) & r2)  |
| bool | **[operator>](Classes/class_room.md#friend-operator>)**(int room_number, const [Room](Classes/class_room.md) & r2)  |
| bool | **[operator>](Classes/class_room.md#friend-operator>)**(const [Room](Classes/class_room.md) & r1, int room_number)  |
| bool | **[operator<](Classes/class_room.md#friend-operator<)**(const [Room](Classes/class_room.md) & r1, const [Room](Classes/class_room.md) & r2)  |
| bool | **[operator<](Classes/class_room.md#friend-operator<)**(int room_number, const [Room](Classes/class_room.md) & r2)  |
| bool | **[operator<](Classes/class_room.md#friend-operator<)**(const [Room](Classes/class_room.md) & r1, int room_number)  |
| bool | **[operator!=](Classes/class_room.md#friend-operator!=)**(const [Room](Classes/class_room.md) & r1, const [Room](Classes/class_room.md) & r2)  |
| bool | **[operator!=](Classes/class_room.md#friend-operator!=)**(int room_number, const [Room](Classes/class_room.md) & r2)  |
| bool | **[operator!=](Classes/class_room.md#friend-operator!=)**(const [Room](Classes/class_room.md) & r1, int room_number)  |
| ostream & | **[operator<<](Classes/class_room.md#friend-operator<<)**(ostream & os, const [Room](Classes/class_room.md) & r) <br>Оператор вывода  |
| istream & | **[operator>>](Classes/class_room.md#friend-operator>>)**(istream & is, [Room](Classes/class_room.md) & r) <br>Оператор ввода  |

## Public Functions Documentation

### function get_room_number

```cpp
inline int get_room_number() const
```

Получить номер комнаты 

**Return**: Номер комнаты 

### function get_price_per_night

```cpp
inline float get_price_per_night() const
```

Получить цену за ночь 

**Return**: Цена за ночь 

### function get_is_booked

```cpp
inline bool get_is_booked() const
```

Получить статус бронирования 

**Return**: true если номер забронирован, иначе false 

### function get_amenities

```cpp
inline virtual const vector< string > & get_amenities() const =0
```


**Reimplemented by**: [FamilyRoom::get_amenities](Classes/class_family_room.md#function-get-amenities), [StandardRoom::get_amenities](Classes/class_standard_room.md#function-get-amenities), [Suite::get_amenities](Classes/class_suite.md#function-get-amenities)


### function get_full_name

```cpp
inline virtual string get_full_name() const =0
```


**Reimplemented by**: [FamilyRoom::get_full_name](Classes/class_family_room.md#function-get-full-name), [StandardRoom::get_full_name](Classes/class_standard_room.md#function-get-full-name), [Suite::get_full_name](Classes/class_suite.md#function-get-full-name)


### function set_room_number

```cpp
inline void set_room_number(
    int room_number
)
```

Установить номер комнаты 

**Parameters**: 

  * **room_number** Новый номер комнаты 


### function set_price_per_night

```cpp
inline void set_price_per_night(
    float price_per_night
)
```

Установить цену за ночь 

**Parameters**: 

  * **price_per_night** Новая цена за ночь 


### function set_is_booked

```cpp
inline void set_is_booked(
    bool is_booked
)
```

Установить статус бронирования 

**Parameters**: 

  * **is_booked** Новый статус бронирования 


### function input_room_number

```cpp
inline bool input_room_number()
```

Ввод номера комнаты 

**Return**: true если операция отменена, иначе false 

### function input_room_number

```cpp
template <typename Container >
inline enable_if_t< is_same_v< typename Container::value_type, int >, bool > input_room_number(
    const Container & room_numbers
)
```

Ввод номера комнаты с проверкой уникальности 

**Parameters**: 

  * **room_numbers** Контейнер с существующими номерами комнат 


**Template Parameters**: 

  * **Container** Тип контейнера с номерами комнат 


**Return**: true если операция отменена, иначе false 

### function input_price_per_night

```cpp
inline bool input_price_per_night()
```

Ввод цены за ночь 

**Return**: true если операция отменена, иначе false 

### function input_is_booked

```cpp
inline bool input_is_booked()
```

Ввод статуса бронирования 

**Return**: true если операция отменена, иначе false 

### function get_room_type

```cpp
inline virtual const string & get_room_type() const =0
```


**Reimplemented by**: [FamilyRoom::get_room_type](Classes/class_family_room.md#function-get-room-type), [StandardRoom::get_room_type](Classes/class_standard_room.md#function-get-room-type), [Suite::get_room_type](Classes/class_suite.md#function-get-room-type)


### function get_json_type

```cpp
inline virtual const string & get_json_type() const =0
```


**Reimplemented by**: [FamilyRoom::get_json_type](Classes/class_family_room.md#function-get-json-type), [StandardRoom::get_json_type](Classes/class_standard_room.md#function-get-json-type), [Suite::get_json_type](Classes/class_suite.md#function-get-json-type)


### function calculate_total

```cpp
inline virtual float calculate_total(
    int night_count
) const =0
```


**Reimplemented by**: [FamilyRoom::calculate_total](Classes/class_family_room.md#function-calculate-total), [StandardRoom::calculate_total](Classes/class_standard_room.md#function-calculate-total), [Suite::calculate_total](Classes/class_suite.md#function-calculate-total)


### function validate

```cpp
inline virtual bool validate() const =0
```


**Reimplemented by**: [FamilyRoom::validate](Classes/class_family_room.md#function-validate), [StandardRoom::validate](Classes/class_standard_room.md#function-validate), [Suite::validate](Classes/class_suite.md#function-validate)


### function to_json

```cpp
virtual json to_json() const =0
```


**Reimplemented by**: [FamilyRoom::to_json](Classes/class_family_room.md#function-to-json), [StandardRoom::to_json](Classes/class_standard_room.md#function-to-json), [Suite::to_json](Classes/class_suite.md#function-to-json)


### function from_json

```cpp
virtual void from_json(
    const json & j
) =0
```


**Reimplemented by**: [FamilyRoom::from_json](Classes/class_family_room.md#function-from-json), [StandardRoom::from_json](Classes/class_standard_room.md#function-from-json), [Suite::from_json](Classes/class_suite.md#function-from-json)


### function Room

```cpp
Room()
```

Конструктор по умолчанию 

### function Room

```cpp
Room(
    int room_number
)
```

Конструктор преобразования (по номеру комнаты) 

**Parameters**: 

  * **room_number** Номер комнаты 


Конструктор преобразования


### function Room

```cpp
Room(
    int room_number,
    float price_per_night,
    bool is_booked
)
```

Конструктор с параметрами 

**Parameters**: 

  * **room_number** Номер комнаты 
  * **price_per_night** Цена за ночь 
  * **is_booked** Статус бронирования 


### function Room

```cpp
Room(
    const Room & 
) =default
```

Конструктор копирования 

### function operator=

```cpp
Room & operator=(
    const Room & 
) =default
```


### function Room

```cpp
Room(
    Room && other
)
```

Конструктор перемещения 

**Parameters**: 

  * **other** Другой объект [Room](Classes/class_room.md)


### function operator=

```cpp
Room & operator=(
    Room && 
) =default
```


### function ~Room

```cpp
virtual ~Room() =default
```

Виртуальный деструктор 

### function operator string

```cpp
explicit operator string() const
```

Преобразование в строку 

### function to_string

```cpp
virtual string to_string() const
```

Виртуальный метод преобразования в строку 

**Return**: Строковое представление комнаты 

**Reimplemented by**: [FamilyRoom::to_string](Classes/class_family_room.md#function-to-string), [StandardRoom::to_string](Classes/class_standard_room.md#function-to-string), [Suite::to_string](Classes/class_suite.md#function-to-string)


Преобразование в строку


### function operator<<

```cpp
template <typename Container >
enable_if_t< is_same_v< typename Container::value_type, shared_ptr< Room > >, ostream & > friend operator<<(
    ostream & os,
    const Container & rooms
)
```

Перегрузка вывода для контейнера комнат 

**Template Parameters**: 

  * **Container** Тип контейнера (должен содержать shared_ptr<Room>) 


## Protected Functions Documentation

### function print

```cpp
inline virtual void print() const
```

Виртуальный метод вывода информации о комнате 

**Reimplemented by**: [FamilyRoom::print](Classes/class_family_room.md#function-print), [StandardRoom::print](Classes/class_standard_room.md#function-print), [Suite::print](Classes/class_suite.md#function-print)


### function input

```cpp
inline virtual bool input()
```

Виртуальный метод ввода информации о комнате 

**Return**: true если операция отменена, false если успешно 

**Reimplemented by**: [FamilyRoom::input](Classes/class_family_room.md#function-input), [StandardRoom::input](Classes/class_standard_room.md#function-input), [Suite::input](Classes/class_suite.md#function-input)


## Public Attributes Documentation

### variable CURRENCY

```cpp
static const string CURRENCY = "руб.";
```

Валюта для отображения цен 

Валюта по умолчанию 


## Protected Attributes Documentation

### variable room_number

```cpp
int room_number;
```

Номер комнаты 

### variable price_per_night

```cpp
float price_per_night;
```

Цена за ночь 

### variable is_booked

```cpp
bool is_booked;
```

Статус бронирования 

## Friends

### friend operator==

```cpp
friend bool operator==(
    const Room & r1,

    const Room & r2
);
```


### friend operator==

```cpp
friend bool operator==(
    int room_number,

    const Room & r2
);
```


### friend operator==

```cpp
friend bool operator==(
    const Room & r1,

    int room_number
);
```


### friend operator>=

```cpp
friend bool operator>=(
    const Room & r1,

    const Room & r2
);
```


### friend operator>=

```cpp
friend bool operator>=(
    int room_number,

    const Room & r2
);
```


### friend operator>=

```cpp
friend bool operator>=(
    const Room & r1,

    int room_number
);
```


### friend operator<=

```cpp
friend bool operator<=(
    const Room & r1,

    const Room & r2
);
```


### friend operator<=

```cpp
friend bool operator<=(
    int room_number,

    const Room & r2
);
```


### friend operator<=

```cpp
friend bool operator<=(
    const Room & r1,

    int room_number
);
```


### friend operator>

```cpp
friend bool operator>(
    const Room & r1,

    const Room & r2
);
```


### friend operator>

```cpp
friend bool operator>(
    int room_number,

    const Room & r2
);
```


### friend operator>

```cpp
friend bool operator>(
    const Room & r1,

    int room_number
);
```


### friend operator<

```cpp
friend bool operator<(
    const Room & r1,

    const Room & r2
);
```


### friend operator<

```cpp
friend bool operator<(
    int room_number,

    const Room & r2
);
```


### friend operator<

```cpp
friend bool operator<(
    const Room & r1,

    int room_number
);
```


### friend operator!=

```cpp
friend bool operator!=(
    const Room & r1,

    const Room & r2
);
```


### friend operator!=

```cpp
friend bool operator!=(
    int room_number,

    const Room & r2
);
```


### friend operator!=

```cpp
friend bool operator!=(
    const Room & r1,

    int room_number
);
```


### friend operator<<

```cpp
friend ostream & operator<<(
    ostream & os,

    const Room & r
);
```

Оператор вывода 

**Parameters**: 

  * **os** Поток вывода 
  * **r** Комната для вывода 


**Return**: Поток вывода 

### friend operator>>

```cpp
friend istream & operator>>(
    istream & is,

    Room & r
);
```

Оператор ввода 

**Parameters**: 

  * **is** Поток ввода 
  * **r** Комната для ввода 


**Return**: Поток ввода 

-------------------------------

Updated on 2025-05-06 at 23:16:47 +0300