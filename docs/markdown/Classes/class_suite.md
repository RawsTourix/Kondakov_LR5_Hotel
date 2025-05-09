---
title: Suite
summary: Класс номера люкс, наследующий от Room. 

---

# Suite



Класс номера люкс, наследующий от [Room](Classes/class_room.md).  [More...](#detailed-description)


`#include <kondakov_lr5_suite.h>`

Inherits from [Room](Classes/class_room.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Suite](Classes/class_suite.md#function-suite)**()<br>Конструктор по умолчанию  |
| | **[Suite](Classes/class_suite.md#function-suite)**(int room_number, bool room_service)<br>Конструктор преобразования  |
| | **[Suite](Classes/class_suite.md#function-suite)**(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi)<br>Конструктор с удобствами по умолчанию  |
| | **[Suite](Classes/class_suite.md#function-suite)**(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi, string amenities)<br>Конструктор с параметрами (удобства строка)  |
| | **[Suite](Classes/class_suite.md#function-suite)**(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi, vector< string > amenities)<br>Конструктор с параметрами (удобства вектор)  |
| | **[Suite](Classes/class_suite.md#function-suite)**(const [Suite](Classes/class_suite.md) & ) =default<br>Конструктор копирования  |
| [Suite](Classes/class_suite.md) & | **[operator=](Classes/class_suite.md#function-operator=)**(const [Suite](Classes/class_suite.md) & ) =default |
| | **[Suite](Classes/class_suite.md#function-suite)**([Suite](Classes/class_suite.md) && other)<br>Конструктор перемещения  |
| [Suite](Classes/class_suite.md) & | **[operator=](Classes/class_suite.md#function-operator=)**([Suite](Classes/class_suite.md) && ) =default |
| bool | **[get_room_service](Classes/class_suite.md#function-get-room-service)**() const<br>Получить наличие обслуживания  |
| bool | **[get_jacuzzi](Classes/class_suite.md#function-get-jacuzzi)**() const<br>Получить наличие джакузи  |
| virtual const vector< string > & | **[get_amenities](Classes/class_suite.md#function-get-amenities)**() const override<br>Получить список удобств  |
| virtual string | **[get_full_name](Classes/class_suite.md#function-get-full-name)**() const override<br>Получить полное название комнаты  |
| void | **[set_room_service](Classes/class_suite.md#function-set-room-service)**(bool room_service)<br>Установить наличие обслуживания  |
| void | **[set_jacuzzi](Classes/class_suite.md#function-set-jacuzzi)**(bool jacuzzi)<br>Установить наличие джакузи  |
| void | **[set_amenities](Classes/class_suite.md#function-set-amenities)**(vector< string > amenities)<br>Установить список удобств  |
| bool | **[input_room_service](Classes/class_suite.md#function-input-room-service)**()<br>Ввод наличия обслуживания  |
| bool | **[input_jacuzzi](Classes/class_suite.md#function-input-jacuzzi)**()<br>Ввод наличия джакузи  |
| template <char Delim\> <br>bool | **[input_amenities](Classes/class_suite.md#function-input-amenities)**()<br>Ввод удобств с разделителем  |
| virtual const string & | **[get_room_type](Classes/class_suite.md#function-get-room-type)**() const override<br>Получить тип комнаты  |
| virtual const string & | **[get_json_type](Classes/class_suite.md#function-get-json-type)**() const override<br>Получить тип для JSON.  |
| virtual float | **[calculate_total](Classes/class_suite.md#function-calculate-total)**(int night_count) const override<br>Расчет общей стоимости проживания  |
| virtual bool | **[validate](Classes/class_suite.md#function-validate)**() const override<br>Проверка валидности номера  |
| virtual [json](Modules/group__core__definitions.md#using-json) | **[to_json](Classes/class_suite.md#function-to-json)**() const override<br>Преобразование в JSON.  |
| virtual void | **[from_json](Classes/class_suite.md#function-from-json)**(const [json](Modules/group__core__definitions.md#using-json) & j) override<br>Загрузка из JSON.  |
| virtual void | **[print](Classes/class_suite.md#function-print)**() const override<br>Вывод информации о номере  |
| virtual bool | **[input](Classes/class_suite.md#function-input)**() override<br>Ввод информации о номере  |
| virtual string | **[to_string](Classes/class_suite.md#function-to-string)**() const override<br>Преобразование в строку  |
| virtual | **[~Suite](Classes/class_suite.md#function-~suite)**() =default<br>Деструктор  |
| void | **[order_champagne](Classes/class_suite.md#function-order-champagne)**(string amenity)<br>Заказать шампанское (добавляет услугу)  |
| | **[operator string](Classes/class_suite.md#function-operator-string)**() const<br>Преобразование в строку  |

## Friends

|                | Name           |
| -------------- | -------------- |
| vector< string > | **[operator+](Classes/class_suite.md#friend-operator+)**(const [Suite](Classes/class_suite.md) & s1, const [Suite](Classes/class_suite.md) & s2)  |
| vector< string > | **[operator+](Classes/class_suite.md#friend-operator+)**(const vector< string > & amenities, const [Suite](Classes/class_suite.md) & s)  |
| vector< string > | **[operator+](Classes/class_suite.md#friend-operator+)**(const [Suite](Classes/class_suite.md) & s, const vector< string > & amenities)  |
| vector< string > & | **[operator+=](Classes/class_suite.md#friend-operator+=)**(vector< string > & amenities, const [Suite](Classes/class_suite.md) & s)  |
| [Suite](Classes/class_suite.md) & | **[operator+=](Classes/class_suite.md#friend-operator+=)**([Suite](Classes/class_suite.md) & s, const vector< string > & amenities)  |
| [Suite](Classes/class_suite.md) & | **[operator+=](Classes/class_suite.md#friend-operator+=)**([Suite](Classes/class_suite.md) & s, const string & amenities)  |
| ostream & | **[operator<<](Classes/class_suite.md#friend-operator<<)**(ostream & os, const [Suite](Classes/class_suite.md) & r) <br>Оператор вывода  |
| istream & | **[operator>>](Classes/class_suite.md#friend-operator>>)**(istream & is, [Suite](Classes/class_suite.md) & r) <br>Оператор ввода  |

## Additional inherited members

**Public Functions inherited from [Room](Classes/class_room.md)**

|                | Name           |
| -------------- | -------------- |
| | **[Room](Classes/class_room.md#function-room)**()<br>Конструктор по умолчанию  |
| | **[Room](Classes/class_room.md#function-room)**(int room_number)<br>Конструктор преобразования  |
| | **[Room](Classes/class_room.md#function-room)**(int room_number, float price_per_night, bool is_booked)<br>Основной конструктор с параметрами  |
| | **[Room](Classes/class_room.md#function-room)**(const [Room](Classes/class_room.md) & ) =default<br>Конструктор копирования  |
| | **[Room](Classes/class_room.md#function-room)**([Room](Classes/class_room.md) && other)<br>Конструктор перемещения  |
| int | **[get_room_number](Classes/class_room.md#function-get-room-number)**() const<br>Получить номер комнаты  |
| float | **[get_price_per_night](Classes/class_room.md#function-get-price-per-night)**() const<br>Получить цену за ночь  |
| bool | **[get_is_booked](Classes/class_room.md#function-get-is-booked)**() const<br>Получить статус бронирования  |
| void | **[set_room_number](Classes/class_room.md#function-set-room-number)**(int room_number)<br>Установить номер комнаты  |
| void | **[set_price_per_night](Classes/class_room.md#function-set-price-per-night)**(float price_per_night)<br>Установить цену за ночь  |
| void | **[set_is_booked](Classes/class_room.md#function-set-is-booked)**(bool is_booked)<br>Установить статус бронирования  |
| bool | **[input_room_number](Classes/class_room.md#function-input-room-number)**()<br>Ввод номера комнаты  |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, int >, bool > | **[input_room_number](Classes/class_room.md#function-input-room-number)**(const Container & room_numbers)<br>Ввод номера комнаты с проверкой уникальности  |
| bool | **[input_price_per_night](Classes/class_room.md#function-input-price-per-night)**()<br>Ввод цены за ночь  |
| bool | **[input_is_booked](Classes/class_room.md#function-input-is-booked)**()<br>Ввод статуса бронирования  |
| virtual | **[~Room](Classes/class_room.md#function-~room)**() =default<br>Виртуальный деструктор  |

**Public Attributes inherited from [Room](Classes/class_room.md)**

|                | Name           |
| -------------- | -------------- |
| const string | **[CURRENCY](Classes/class_room.md#variable-currency)** <br>Валюта для отображения цен  |

**Protected Attributes inherited from [Room](Classes/class_room.md)**

|                | Name           |
| -------------- | -------------- |
| int | **[room_number](Classes/class_room.md#variable-room-number)** <br>Номер комнаты  |
| float | **[price_per_night](Classes/class_room.md#variable-price-per-night)** <br>Цена за ночь  |
| bool | **[is_booked](Classes/class_room.md#variable-is-booked)** <br>Статус бронирования  |

**Friends inherited from [Room](Classes/class_room.md)**

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


## Detailed Description

```cpp
class Suite;
```

Класс номера люкс, наследующий от [Room](Classes/class_room.md). 

Представляет номер повышенной комфортности с дополнительными услугами 

## Public Functions Documentation

### function Suite

```cpp
Suite()
```

Конструктор по умолчанию 

Создает номер люкс с параметрами:

* Номер комнаты: 0
* Цена за ночь: 0.0
* Статус бронирования: нет
* Обслуживание в номере: нет
* Наличие джакузи: нет
* Список удобств: "Lux", "Room service" 


### function Suite

```cpp
Suite(
    int room_number,
    bool room_service
)
```

Конструктор преобразования 

**Parameters**: 

  * **room_number** Номер комнаты 
  * **room_service** Обслуживание в номере
  * **room_number** Номер комнаты 
  * **room_service** Наличие обслуживания 



Создает номер люкс с указанными параметрами и значениями по умолчанию:

* Цена за ночь: 0.0
* Статус бронирования: нет
* Наличие джакузи: нет
* Список удобств: "Lux", "Room service"


### function Suite

```cpp
Suite(
    int room_number,
    float price_per_night,
    bool is_booked,
    bool room_service,
    bool jacuzzi
)
```

Конструктор с удобствами по умолчанию 

**Parameters**: 

  * **room_number** Номер комнаты 
  * **price_per_night** Цена за ночь 
  * **is_booked** Статус бронирования 
  * **room_service** Обслуживание в номере 
  * **jacuzzi** Наличие джакузи
  * **room_number** Номер комнаты 
  * **price_per_night** Цена за ночь 
  * **is_booked** Статус бронирования 
  * **room_service** Наличие обслуживания 
  * **jacuzzi** Наличие джакузи 



Создает номер люкс с указанными параметрами и удобствами по умолчанию: "Lux", "Room service"


### function Suite

```cpp
Suite(
    int room_number,
    float price_per_night,
    bool is_booked,
    bool room_service,
    bool jacuzzi,
    string amenities
)
```

Конструктор с параметрами (удобства строка) 

**Parameters**: 

  * **room_number** Номер комнаты 
  * **price_per_night** Цена за ночь 
  * **is_booked** Статус бронирования 
  * **room_service** Обслуживание в номере 
  * **jacuzzi** Наличие джакузи 
  * **amenities** Удобства (строка, разделитель - запятая)
  * **room_number** Номер комнаты 
  * **price_per_night** Цена за ночь 
  * **is_booked** Статус бронирования 
  * **room_service** Наличие обслуживания 
  * **jacuzzi** Наличие джакузи 
  * **amenities** Удобства (строка с разделителями) 


### function Suite

```cpp
Suite(
    int room_number,
    float price_per_night,
    bool is_booked,
    bool room_service,
    bool jacuzzi,
    vector< string > amenities
)
```

Конструктор с параметрами (удобства вектор) 

**Parameters**: 

  * **room_number** Номер комнаты 
  * **price_per_night** Цена за ночь 
  * **is_booked** Статус бронирования 
  * **room_service** Обслуживание в номере 
  * **jacuzzi** Наличие джакузи 
  * **amenities** Удобства (вектор строк)
  * **room_number** Номер комнаты 
  * **price_per_night** Цена за ночь 
  * **is_booked** Статус бронирования 
  * **room_service** Наличие обслуживания 
  * **jacuzzi** Наличие джакузи 
  * **amenities** Удобства (вектор строк) 


### function Suite

```cpp
Suite(
    const Suite & 
) =default
```

Конструктор копирования 

### function operator=

```cpp
Suite & operator=(
    const Suite & 
) =default
```


### function Suite

```cpp
Suite(
    Suite && other
)
```

Конструктор перемещения 

**Parameters**: 

  * **other** Другой объект [Suite](Classes/class_suite.md)


### function operator=

```cpp
Suite & operator=(
    Suite && 
) =default
```


### function get_room_service

```cpp
inline bool get_room_service() const
```

Получить наличие обслуживания 

**Return**: true если есть обслуживание, иначе false 

### function get_jacuzzi

```cpp
inline bool get_jacuzzi() const
```

Получить наличие джакузи 

**Return**: true если есть джакузи, иначе false 

### function get_amenities

```cpp
inline virtual const vector< string > & get_amenities() const override
```

Получить список удобств 

**Return**: Константная ссылка на вектор удобств 

**Reimplements**: [Room::get_amenities](Classes/class_room.md#function-get-amenities)


### function get_full_name

```cpp
inline virtual string get_full_name() const override
```

Получить полное название комнаты 

**Return**: Строка с названием формата "Люкс комната №X" 

**Reimplements**: [Room::get_full_name](Classes/class_room.md#function-get-full-name)


### function set_room_service

```cpp
inline void set_room_service(
    bool room_service
)
```

Установить наличие обслуживания 

**Parameters**: 

  * **room_service** Новое значение 


### function set_jacuzzi

```cpp
inline void set_jacuzzi(
    bool jacuzzi
)
```

Установить наличие джакузи 

**Parameters**: 

  * **jacuzzi** Новое значение 


### function set_amenities

```cpp
inline void set_amenities(
    vector< string > amenities
)
```

Установить список удобств 

**Parameters**: 

  * **amenities** Новый список удобств 


### function input_room_service

```cpp
inline bool input_room_service()
```

Ввод наличия обслуживания 

**Return**: true если операция отменена, иначе false 

### function input_jacuzzi

```cpp
inline bool input_jacuzzi()
```

Ввод наличия джакузи 

**Return**: true если операция отменена, иначе false 

### function input_amenities

```cpp
template <char Delim>
inline bool input_amenities()
```

Ввод удобств с разделителем 

**Template Parameters**: 

  * **Delim** Разделитель для ввода 


**Return**: true если операция отменена, иначе false 

### function get_room_type

```cpp
inline virtual const string & get_room_type() const override
```

Получить тип комнаты 

**Return**: Константная ссылка на строку с типом 

**Reimplements**: [Room::get_room_type](Classes/class_room.md#function-get-room-type)


### function get_json_type

```cpp
inline virtual const string & get_json_type() const override
```

Получить тип для JSON. 

**Return**: Константная ссылка на строку с типом 

**Reimplements**: [Room::get_json_type](Classes/class_room.md#function-get-json-type)


### function calculate_total

```cpp
inline virtual float calculate_total(
    int night_count
) const override
```

Расчет общей стоимости проживания 

**Parameters**: 

  * **night_count** Количество ночей 


**Return**: Общая стоимость (цена * ночи + фиксированная плата за услуги) 

**Reimplements**: [Room::calculate_total](Classes/class_room.md#function-calculate-total)


### function validate

```cpp
inline virtual bool validate() const override
```

Проверка валидности номера 

**Return**: true если общая стоимость за 1 ночь >= 10000, иначе false 

**Reimplements**: [Room::validate](Classes/class_room.md#function-validate)


### function to_json

```cpp
virtual json to_json() const override
```

Преобразование в JSON. 

**Return**: JSON объект с данными номера 

**Reimplements**: [Room::to_json](Classes/class_room.md#function-to-json)


### function from_json

```cpp
virtual void from_json(
    const json & j
) override
```

Загрузка из JSON. 

**Parameters**: 

  * **j** JSON объект с данными номера 


**Reimplements**: [Room::from_json](Classes/class_room.md#function-from-json)


### function print

```cpp
virtual void print() const override
```

Вывод информации о номере 

**Reimplements**: [Room::print](Classes/class_room.md#function-print)


### function input

```cpp
virtual bool input() override
```

Ввод информации о номере 

**Return**: true если операция отменена, иначе false 

**Reimplements**: [Room::input](Classes/class_room.md#function-input)


### function to_string

```cpp
virtual string to_string() const override
```

Преобразование в строку 

**Return**: Строковое представление номера 

**Reimplements**: [Room::to_string](Classes/class_room.md#function-to-string)


### function ~Suite

```cpp
virtual ~Suite() =default
```

Деструктор 

### function order_champagne

```cpp
inline void order_champagne(
    string amenity
)
```

Заказать шампанское (добавляет услугу) 

**Parameters**: 

  * **amenity** Название услуги


Добавить услугу


Увеличивает цену на 2000 руб. и добавляет услугу в список 


### function operator string

```cpp
explicit operator string() const
```

Преобразование в строку 

## Friends

### friend operator+

```cpp
friend vector< string > operator+(
    const Suite & s1,

    const Suite & s2
);
```


### friend operator+

```cpp
friend vector< string > operator+(
    const vector< string > & amenities,

    const Suite & s
);
```


### friend operator+

```cpp
friend vector< string > operator+(
    const Suite & s,

    const vector< string > & amenities
);
```


### friend operator+=

```cpp
friend vector< string > & operator+=(
    vector< string > & amenities,

    const Suite & s
);
```


### friend operator+=

```cpp
friend Suite & operator+=(
    Suite & s,

    const vector< string > & amenities
);
```


### friend operator+=

```cpp
friend Suite & operator+=(
    Suite & s,

    const string & amenities
);
```


### friend operator<<

```cpp
friend ostream & operator<<(
    ostream & os,

    const Suite & r
);
```

Оператор вывода 

**Parameters**: 

  * **os** Поток вывода 
  * **sr** Комната для вывода 


**Return**: Поток вывода 

### friend operator>>

```cpp
friend istream & operator>>(
    istream & is,

    Suite & r
);
```

Оператор ввода 

**Parameters**: 

  * **is** Поток ввода 
  * **s** Комната для ввода 


**Return**: Поток ввода 

-------------------------------

Updated on 2025-05-09 at 18:16:45 +0300