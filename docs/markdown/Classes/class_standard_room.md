---
title: StandardRoom
summary: Класс стандартного номера (наследник Room) 

---

# StandardRoom



Класс стандартного номера (наследник [Room](Classes/class_room.md)) 


`#include <kondakov_lr5_standard_room.h>`

Inherits from [Room](Classes/class_room.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| int | **[get_bed_count](Classes/class_standard_room.md#function-get-bed-count)**() const<br>Получить количество кроватей  |
| bool | **[get_has_tv](Classes/class_standard_room.md#function-get-has-tv)**() const<br>Получить наличие телевизора  |
| virtual const vector< string > & | **[get_amenities](Classes/class_standard_room.md#function-get-amenities)**() const override<br>Получить список удобств  |
| virtual string | **[get_full_name](Classes/class_standard_room.md#function-get-full-name)**() const override<br>Получить полное название комнаты  |
| void | **[set_bed_count](Classes/class_standard_room.md#function-set-bed-count)**(int bed_count)<br>Установить количество кроватей  |
| void | **[set_has_tv](Classes/class_standard_room.md#function-set-has-tv)**(bool has_tv)<br>Установить наличие телевизора  |
| void | **[set_amenities](Classes/class_standard_room.md#function-set-amenities)**(vector< string > amenities)<br>Установить список удобств  |
| bool | **[input_bed_count](Classes/class_standard_room.md#function-input-bed-count)**()<br>Ввод количества кроватей  |
| bool | **[input_has_tv](Classes/class_standard_room.md#function-input-has-tv)**()<br>Ввод наличия телевизора  |
| template <char Delim\> <br>bool | **[input_amenities](Classes/class_standard_room.md#function-input-amenities)**()<br>Ввод удобств с разделителем  |
| virtual const string & | **[get_room_type](Classes/class_standard_room.md#function-get-room-type)**() const override<br>Получить тип комнаты  |
| virtual const string & | **[get_json_type](Classes/class_standard_room.md#function-get-json-type)**() const override<br>Получить тип для JSON.  |
| virtual float | **[calculate_total](Classes/class_standard_room.md#function-calculate-total)**(int night_count) const override<br>Расчет общей стоимости проживания  |
| virtual bool | **[validate](Classes/class_standard_room.md#function-validate)**() const override<br>Проверка валидности номера  |
| virtual [json](Modules/group__core__definitions.md#using-json) | **[to_json](Classes/class_standard_room.md#function-to-json)**() const override<br>Преобразование в JSON.  |
| virtual void | **[from_json](Classes/class_standard_room.md#function-from-json)**(const [json](Modules/group__core__definitions.md#using-json) & j) override<br>Загрузка из JSON.  |
| virtual void | **[print](Classes/class_standard_room.md#function-print)**() const override<br>Вывод информации о номере  |
| virtual bool | **[input](Classes/class_standard_room.md#function-input)**() override<br>Ввод информации о номере  |
| virtual string | **[to_string](Classes/class_standard_room.md#function-to-string)**() const override<br>Преобразование в строку  |
| | **[StandardRoom](Classes/class_standard_room.md#function-standardroom)**()<br>Конструктор по умолчанию  |
| | **[StandardRoom](Classes/class_standard_room.md#function-standardroom)**(int room_number, int bed_count)<br>Конструктор преобразования  |
| | **[StandardRoom](Classes/class_standard_room.md#function-standardroom)**(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv)<br>Конструктор с удобствами по умолчанию  |
| | **[StandardRoom](Classes/class_standard_room.md#function-standardroom)**(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv, string amenities)<br>Конструктор с параметрами (удобства строка)  |
| | **[StandardRoom](Classes/class_standard_room.md#function-standardroom)**(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv, vector< string > amenities)<br>Конструктор с параметрами (удобства вектор)  |
| | **[StandardRoom](Classes/class_standard_room.md#function-standardroom)**(const [StandardRoom](Classes/class_standard_room.md) & ) =default<br>Конструктор копирования  |
| [StandardRoom](Classes/class_standard_room.md) & | **[operator=](Classes/class_standard_room.md#function-operator=)**(const [StandardRoom](Classes/class_standard_room.md) & ) =default |
| | **[StandardRoom](Classes/class_standard_room.md#function-standardroom)**([StandardRoom](Classes/class_standard_room.md) && other)<br>Конструктор перемещения  |
| [StandardRoom](Classes/class_standard_room.md) & | **[operator=](Classes/class_standard_room.md#function-operator=)**([StandardRoom](Classes/class_standard_room.md) && ) =default |
| virtual | **[~StandardRoom](Classes/class_standard_room.md#function-~standardroom)**() =default<br>Деструктор  |
| void | **[exstra_bed](Classes/class_standard_room.md#function-exstra-bed)**()<br>Добавить дополнительную кровать (+20% к цене)  |
| | **[operator string](Classes/class_standard_room.md#function-operator-string)**() const<br>Преобразование в строку  |

## Friends

|                | Name           |
| -------------- | -------------- |
| vector< string > | **[operator+](Classes/class_standard_room.md#friend-operator+)**(const [StandardRoom](Classes/class_standard_room.md) & sr1, const [StandardRoom](Classes/class_standard_room.md) & sr2)  |
| vector< string > | **[operator+](Classes/class_standard_room.md#friend-operator+)**(const vector< string > & amenities, const [StandardRoom](Classes/class_standard_room.md) & sr)  |
| vector< string > | **[operator+](Classes/class_standard_room.md#friend-operator+)**(const [StandardRoom](Classes/class_standard_room.md) & sr, const vector< string > & amenities)  |
| vector< string > & | **[operator+=](Classes/class_standard_room.md#friend-operator+=)**(vector< string > & amenities, const [StandardRoom](Classes/class_standard_room.md) & sr)  |
| [StandardRoom](Classes/class_standard_room.md) & | **[operator+=](Classes/class_standard_room.md#friend-operator+=)**([StandardRoom](Classes/class_standard_room.md) & sr, const vector< string > & amenities)  |
| [StandardRoom](Classes/class_standard_room.md) & | **[operator+=](Classes/class_standard_room.md#friend-operator+=)**([StandardRoom](Classes/class_standard_room.md) & sr, const string & amenities)  |
| ostream & | **[operator<<](Classes/class_standard_room.md#friend-operator<<)**(ostream & os, const [StandardRoom](Classes/class_standard_room.md) & r) <br>Оператор вывода  |
| istream & | **[operator>>](Classes/class_standard_room.md#friend-operator>>)**(istream & is, [StandardRoom](Classes/class_standard_room.md) & r) <br>Оператор ввода  |

## Additional inherited members

**Public Functions inherited from [Room](Classes/class_room.md)**

|                | Name           |
| -------------- | -------------- |
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
| | **[Room](Classes/class_room.md#function-room)**()<br>Конструктор по умолчанию  |
| | **[Room](Classes/class_room.md#function-room)**(int room_number)<br>Конструктор преобразования (по номеру комнаты)  |
| | **[Room](Classes/class_room.md#function-room)**(int room_number, float price_per_night, bool is_booked)<br>Конструктор с параметрами  |
| | **[Room](Classes/class_room.md#function-room)**(const [Room](Classes/class_room.md) & ) =default<br>Конструктор копирования  |
| | **[Room](Classes/class_room.md#function-room)**([Room](Classes/class_room.md) && other)<br>Конструктор перемещения  |
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


## Public Functions Documentation

### function get_bed_count

```cpp
inline int get_bed_count() const
```

Получить количество кроватей 

**Return**: Количество кроватей 

### function get_has_tv

```cpp
inline bool get_has_tv() const
```

Получить наличие телевизора 

**Return**: true если есть телевизор, иначе false 

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

**Return**: Строка с полным названием комнаты 

**Reimplements**: [Room::get_full_name](Classes/class_room.md#function-get-full-name)


### function set_bed_count

```cpp
inline void set_bed_count(
    int bed_count
)
```

Установить количество кроватей 

**Parameters**: 

  * **bed_count** Новое количество кроватей 


### function set_has_tv

```cpp
inline void set_has_tv(
    bool has_tv
)
```

Установить наличие телевизора 

**Parameters**: 

  * **has_tv** Наличие телевизора 


### function set_amenities

```cpp
inline void set_amenities(
    vector< string > amenities
)
```

Установить список удобств 

**Parameters**: 

  * **amenities** Новый список удобств 


### function input_bed_count

```cpp
inline bool input_bed_count()
```

Ввод количества кроватей 

**Return**: true если операция отменена, иначе false 

### function input_has_tv

```cpp
inline bool input_has_tv()
```

Ввод наличия телевизора 

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

**Return**: Константная ссылка на строку с типом комнаты 

**Reimplements**: [Room::get_room_type](Classes/class_room.md#function-get-room-type)


### function get_json_type

```cpp
inline virtual const string & get_json_type() const override
```

Получить тип для JSON. 

**Return**: Константная ссылка на строку с типом для JSON 

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


**Return**: Общая стоимость 

**Reimplements**: [Room::calculate_total](Classes/class_room.md#function-calculate-total)


### function validate

```cpp
inline virtual bool validate() const override
```

Проверка валидности номера 

**Return**: true если номер валиден (количество кроватей >= 1), иначе false 

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


### function StandardRoom

```cpp
StandardRoom()
```

Конструктор по умолчанию 

### function StandardRoom

```cpp
StandardRoom(
    int room_number,
    int bed_count
)
```

Конструктор преобразования 

**Parameters**: 

  * **room_number** Номер комнаты 
  * **bed_count** Количество кроватей 


### function StandardRoom

```cpp
StandardRoom(
    int room_number,
    float price_per_night,
    bool is_booked,
    int bed_count,
    bool has_tv
)
```

Конструктор с удобствами по умолчанию 

**Parameters**: 

  * **room_number** Номер комнаты 
  * **price_per_night** Цена за ночь 
  * **is_booked** Статус бронирования 
  * **bed_count** Количество кроватей 
  * **has_tv** Наличие телевизора 


### function StandardRoom

```cpp
StandardRoom(
    int room_number,
    float price_per_night,
    bool is_booked,
    int bed_count,
    bool has_tv,
    string amenities
)
```

Конструктор с параметрами (удобства строка) 

**Parameters**: 

  * **room_number** Номер комнаты 
  * **price_per_night** Цена за ночь 
  * **is_booked** Статус бронирования 
  * **bed_count** Количество кроватей 
  * **has_tv** Наличие телевизора 
  * **amenities** Удобства (строка с разделителями) 


### function StandardRoom

```cpp
StandardRoom(
    int room_number,
    float price_per_night,
    bool is_booked,
    int bed_count,
    bool has_tv,
    vector< string > amenities
)
```

Конструктор с параметрами (удобства вектор) 

**Parameters**: 

  * **room_number** Номер комнаты 
  * **price_per_night** Цена за ночь 
  * **is_booked** Статус бронирования 
  * **bed_count** Количество кроватей 
  * **has_tv** Наличие телевизора 
  * **amenities** Удобства (вектор строк) 


### function StandardRoom

```cpp
StandardRoom(
    const StandardRoom & 
) =default
```

Конструктор копирования 

### function operator=

```cpp
StandardRoom & operator=(
    const StandardRoom & 
) =default
```


### function StandardRoom

```cpp
StandardRoom(
    StandardRoom && other
)
```

Конструктор перемещения 

**Parameters**: 

  * **other** Другой объект [StandardRoom](Classes/class_standard_room.md)


### function operator=

```cpp
StandardRoom & operator=(
    StandardRoom && 
) =default
```


### function ~StandardRoom

```cpp
virtual ~StandardRoom() =default
```

Деструктор 

### function exstra_bed

```cpp
inline void exstra_bed()
```

Добавить дополнительную кровать (+20% к цене) 

Добавить дополнительную кровать

Увеличивает цену на 20% и количество кроватей на 1 


### function operator string

```cpp
explicit operator string() const
```

Преобразование в строку 

## Friends

### friend operator+

```cpp
friend vector< string > operator+(
    const StandardRoom & sr1,

    const StandardRoom & sr2
);
```


### friend operator+

```cpp
friend vector< string > operator+(
    const vector< string > & amenities,

    const StandardRoom & sr
);
```


### friend operator+

```cpp
friend vector< string > operator+(
    const StandardRoom & sr,

    const vector< string > & amenities
);
```


### friend operator+=

```cpp
friend vector< string > & operator+=(
    vector< string > & amenities,

    const StandardRoom & sr
);
```


### friend operator+=

```cpp
friend StandardRoom & operator+=(
    StandardRoom & sr,

    const vector< string > & amenities
);
```


### friend operator+=

```cpp
friend StandardRoom & operator+=(
    StandardRoom & sr,

    const string & amenities
);
```


### friend operator<<

```cpp
friend ostream & operator<<(
    ostream & os,

    const StandardRoom & r
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

    StandardRoom & r
);
```

Оператор ввода 

**Parameters**: 

  * **is** Поток ввода 
  * **sr** Комната для ввода 


**Return**: Поток ввода 

-------------------------------

Updated on 2025-05-06 at 23:16:47 +0300