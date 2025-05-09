---
title: FamilyRoom
summary: Класс семейного номера, наследует Room и ChildCare. 

---

# FamilyRoom



Класс семейного номера, наследует [Room]() и [ChildCare](Classes/class_child_care.md). 


`#include <kondakov_lr5_family_room.h>`

Inherits from [Room](Classes/class_room.md), [ChildCare](Classes/class_child_care.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[FamilyRoom](Classes/class_family_room.md#function-familyroom)**()<br>Конструктор по умолчанию  |
| | **[FamilyRoom](Classes/class_family_room.md#function-familyroom)**(int room_number, int child_beds)<br>Базовый конструктор  |
| | **[FamilyRoom](Classes/class_family_room.md#function-familyroom)**(int room_number, float price_per_night, bool is_booked, float child_care_price, bool has_child_care, int child_beds, bool toy_kit)<br>Конструктор с удобствами по умолчанию  |
| | **[FamilyRoom](Classes/class_family_room.md#function-familyroom)**(int room_number, float price_per_night, bool is_booked, float child_care_price, bool has_child_care, int child_beds, bool toy_kit, string amenities)<br>Конструктор с параметрами (удобства в строке)  |
| | **[FamilyRoom](Classes/class_family_room.md#function-familyroom)**(int room_number, float price_per_night, bool is_booked, float child_care_price, bool has_child_care, int child_beds, bool toy_kit, vector< string > amenities)<br>Конструктор с параметрами (удобства в векторе)  |
| | **[FamilyRoom](Classes/class_family_room.md#function-familyroom)**(const [FamilyRoom](Classes/class_family_room.md) & ) =default<br>Конструктор копирования  |
| [FamilyRoom](Classes/class_family_room.md) & | **[operator=](Classes/class_family_room.md#function-operator=)**(const [FamilyRoom](Classes/class_family_room.md) & ) =default |
| | **[FamilyRoom](Classes/class_family_room.md#function-familyroom)**([FamilyRoom](Classes/class_family_room.md) && other)<br>Конструктор перемещения  |
| [FamilyRoom](Classes/class_family_room.md) & | **[operator=](Classes/class_family_room.md#function-operator=)**([FamilyRoom](Classes/class_family_room.md) && ) =default |
| int | **[get_child_beds](Classes/class_family_room.md#function-get-child-beds)**() const<br>Получить количество детских кроватей  |
| bool | **[get_toy_kit](Classes/class_family_room.md#function-get-toy-kit)**() const<br>Получить наличие набора игрушек  |
| virtual const vector< string > & | **[get_amenities](Classes/class_family_room.md#function-get-amenities)**() const override<br>Получить список удобств  |
| virtual string | **[get_full_name](Classes/class_family_room.md#function-get-full-name)**() const override<br>Получить полное название комнаты  |
| void | **[set_child_beds](Classes/class_family_room.md#function-set-child-beds)**(int child_beds)<br>Установить количество детских кроватей  |
| void | **[set_toy_kit](Classes/class_family_room.md#function-set-toy-kit)**(bool toy_kit)<br>Установить наличие набора игрушек  |
| void | **[set_amenities](Classes/class_family_room.md#function-set-amenities)**(vector< string > amenities)<br>Установить список удобств  |
| bool | **[input_child_beds](Classes/class_family_room.md#function-input-child-beds)**()<br>Ввод количества детских кроватей  |
| bool | **[input_toy_kit](Classes/class_family_room.md#function-input-toy-kit)**()<br>Ввод наличия набора игрушек  |
| template <char Delim =','\> <br>bool | **[input_amenities](Classes/class_family_room.md#function-input-amenities)**()<br>Ввод удобств с разделителем  |
| virtual const string & | **[get_room_type](Classes/class_family_room.md#function-get-room-type)**() const override<br>Получить тип комнаты  |
| virtual const string & | **[get_json_type](Classes/class_family_room.md#function-get-json-type)**() const override<br>Получить тип для JSON.  |
| virtual float | **[calculate_total](Classes/class_family_room.md#function-calculate-total)**(int night_count) const override<br>Расчет общей стоимости проживания  |
| virtual bool | **[validate](Classes/class_family_room.md#function-validate)**() const override<br>Проверка валидности номера  |
| void | **[add_play_area](Classes/class_family_room.md#function-add-play-area)**()<br>Активировать игровую зону  |
| void | **[remove_play_area](Classes/class_family_room.md#function-remove-play-area)**()<br>Деактивировать игровую зону  |
| virtual [json](Modules/group__core__definitions.md#using-json) | **[to_json](Classes/class_family_room.md#function-to-json)**() const override<br>Преобразование в JSON.  |
| virtual void | **[from_json](Classes/class_family_room.md#function-from-json)**(const [json](Modules/group__core__definitions.md#using-json) & j) override<br>Загрузка из JSON.  |
| string | **[operator[]](Classes/class_family_room.md#function-operator[])**(int index) const<br>Оператор доступа по индексу (строковая версия)  |
| template <typename T \> <br>enable_if_t< is_same_v< T, float >, T > | **[operator[]](Classes/class_family_room.md#function-operator[])**(int index) const<br>Шаблонный оператор доступа по индексу (const)  |
| template <typename T \> <br>enable_if_t< is_same_v< T, bool >, T > | **[operator[]](Classes/class_family_room.md#function-operator[])**(int index) const |
| template <typename T \> <br>enable_if_t< is_same_v< T, int >, T > | **[operator[]](Classes/class_family_room.md#function-operator[])**(int index) const |
| template <typename T \> <br>enable_if_t< is_same_v< T, string >, T > | **[operator[]](Classes/class_family_room.md#function-operator[])**(int index) const |
| template <typename T \> <br>enable_if_t< is_same_v< T, float >, T & > | **[operator[]](Classes/class_family_room.md#function-operator[])**(int index)<br>Шаблонный оператор доступа по индексу (non-const)  |
| template <typename T \> <br>enable_if_t< is_same_v< T, bool >, T & > | **[operator[]](Classes/class_family_room.md#function-operator[])**(int index) |
| template <typename T \> <br>enable_if_t< is_same_v< T, int >, T & > | **[operator[]](Classes/class_family_room.md#function-operator[])**(int index) |
| template <typename T \> <br>enable_if_t< is_same_v< T, string >, T & > | **[operator[]](Classes/class_family_room.md#function-operator[])**(int index) |
| | **[operator string](Classes/class_family_room.md#function-operator-string)**() const<br>Преобразование в строку  |
| virtual void | **[print](Classes/class_family_room.md#function-print)**() const override<br>Вывод информации о номере  |
| virtual bool | **[input](Classes/class_family_room.md#function-input)**() override<br>Ввод информации о номере  |
| virtual string | **[to_string](Classes/class_family_room.md#function-to-string)**() const override<br>Преобразование в строку  |
| virtual | **[~FamilyRoom](Classes/class_family_room.md#function-~familyroom)**() =default<br>Деструктор  |

## Friends

|                | Name           |
| -------------- | -------------- |
| ostream & | **[operator<<](Classes/class_family_room.md#friend-operator<<)**(ostream & os, const [FamilyRoom](Classes/class_family_room.md) & r) <br>Оператор вывода  |
| istream & | **[operator>>](Classes/class_family_room.md#friend-operator>>)**(istream & is, [FamilyRoom](Classes/class_family_room.md) & r) <br>Оператор ввода  |
| vector< string > | **[operator+](Classes/class_family_room.md#friend-operator+)**(const [FamilyRoom](Classes/class_family_room.md) & fr1, const [FamilyRoom](Classes/class_family_room.md) & fr2)  |
| vector< string > | **[operator+](Classes/class_family_room.md#friend-operator+)**(const vector< string > & amenities, const [FamilyRoom](Classes/class_family_room.md) & fr)  |
| vector< string > | **[operator+](Classes/class_family_room.md#friend-operator+)**(const [FamilyRoom](Classes/class_family_room.md) & fr, const vector< string > & amenities)  |
| vector< string > & | **[operator+=](Classes/class_family_room.md#friend-operator+=)**(vector< string > & amenities, const [FamilyRoom](Classes/class_family_room.md) & fr)  |
| [FamilyRoom](Classes/class_family_room.md) & | **[operator+=](Classes/class_family_room.md#friend-operator+=)**([FamilyRoom](Classes/class_family_room.md) & fr, const vector< string > & amenities)  |
| [FamilyRoom](Classes/class_family_room.md) & | **[operator+=](Classes/class_family_room.md#friend-operator+=)**([FamilyRoom](Classes/class_family_room.md) & fr, const string & amenities)  |

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

**Public Functions inherited from [ChildCare](Classes/class_child_care.md)**

|                | Name           |
| -------------- | -------------- |
| | **[ChildCare](Classes/class_child_care.md#function-childcare)**()<br>Конструктор по умолчанию  |
| | **[ChildCare](Classes/class_child_care.md#function-childcare)**(bool has_child_care)<br>Конструктор преобразования  |
| | **[ChildCare](Classes/class_child_care.md#function-childcare)**(float child_care_price, bool has_child_care)<br>Основной конструктор с параметрами  |
| | **[ChildCare](Classes/class_child_care.md#function-childcare)**(const [ChildCare](Classes/class_child_care.md) & ) =default<br>Конструктор копирования  |
| | **[ChildCare](Classes/class_child_care.md#function-childcare)**([ChildCare](Classes/class_child_care.md) && other)<br>Конструктор перемещения  |
| float | **[get_child_care_price](Classes/class_child_care.md#function-get-child-care-price)**() const<br>Получить стоимость услуг для детей  |
| bool | **[get_has_child_care](Classes/class_child_care.md#function-get-has-child-care)**() const<br>Получить наличие услуг для детей  |
| void | **[set_child_care_price](Classes/class_child_care.md#function-set-child-care-price)**(float child_care_price)<br>Установить стоимость услуг для детей  |
| void | **[set_has_child_care](Classes/class_child_care.md#function-set-has-child-care)**(bool has_child_care)<br>Установить наличие услуг для детей  |
| bool | **[input_child_care_price](Classes/class_child_care.md#function-input-child-care-price)**()<br>Ввод стоимости услуг для детей  |
| bool | **[input_has_child_care](Classes/class_child_care.md#function-input-has-child-care)**()<br>Ввод наличия услуг для детей  |
| | **[~ChildCare](Classes/class_child_care.md#function-~childcare)**() =default<br>Деструктор  |

**Public Attributes inherited from [ChildCare](Classes/class_child_care.md)**

|                | Name           |
| -------------- | -------------- |
| const string | **[CURRENCY](Classes/class_child_care.md#variable-currency)** <br>Валюта для отображения цен  |

**Protected Attributes inherited from [ChildCare](Classes/class_child_care.md)**

|                | Name           |
| -------------- | -------------- |
| float | **[child_care_price](Classes/class_child_care.md#variable-child-care-price)** <br>Стоимость услуг для детей (в рублях)  |
| bool | **[has_child_care](Classes/class_child_care.md#variable-has-child-care)** <br>Флаг наличия услуг для детей  |


## Public Functions Documentation

### function FamilyRoom

```cpp
FamilyRoom()
```

Конструктор по умолчанию 

Создает семейный номер с параметрами:

* Номер комнаты: 0
* Цена за ночь: 0.0
* Статус бронирования: нет
* Стоимость услуг для детей: 0.0
* Наличие услуг для детей: нет
* Детских кроватей: 0
* Набор игрушек: нет
* Список удобств: "Wi-Fi", "Air condition" 


### function FamilyRoom

```cpp
FamilyRoom(
    int room_number,
    int child_beds
)
```

Базовый конструктор 

**Parameters**: 

  * **room_number** Номер комнаты 
  * **child_beds** Количество детских кроватей
  * **room_number** Номер комнаты 
  * **child_beds** Количество детских кроватей 


Конструктор преобразования


Создает семейный номер с указанными параметрами:

* Цена за ночь: 0.0
* Статус бронирования: нет
* Стоимость услуг для детей: 0.0
* Наличие услуг для детей: нет
* Набор игрушек: нет
* Список удобств: "Wi-Fi", "Air condition"


### function FamilyRoom

```cpp
FamilyRoom(
    int room_number,
    float price_per_night,
    bool is_booked,
    float child_care_price,
    bool has_child_care,
    int child_beds,
    bool toy_kit
)
```

Конструктор с удобствами по умолчанию 

**Parameters**: 

  * **room_number** Номер комнаты 
  * **price_per_night** Цена за ночь 
  * **is_booked** Статус бронирования 
  * **child_care_price** Стоимость услуг для детей 
  * **has_child_care** Наличие услуг для детей 
  * **child_beds** Количество детских кроватей 
  * **toy_kit** Набор игрушек
  * **room_number** Номер комнаты 
  * **price_per_night** Цена за ночь 
  * **is_booked** Статус бронирования 
  * **child_care_price** Стоимость услуг для детей 
  * **has_child_care** Наличие услуг для детей 
  * **child_beds** Количество детских кроватей 
  * **toy_kit** Наличие набора игрушек 



Создает семейный номер с указанными параметрамис и удобствами по умолчанию: "Wi-Fi", "Air condition"


### function FamilyRoom

```cpp
FamilyRoom(
    int room_number,
    float price_per_night,
    bool is_booked,
    float child_care_price,
    bool has_child_care,
    int child_beds,
    bool toy_kit,
    string amenities
)
```

Конструктор с параметрами (удобства в строке) 

**Parameters**: 

  * **room_number** Номер комнаты 
  * **price_per_night** Цена за ночь 
  * **is_booked** Статус бронирования 
  * **child_care_price** Стоимость услуг для детей 
  * **has_child_care** Наличие услуг для детей 
  * **child_beds** Количество детских кроватей 
  * **toy_kit** Набор игрушек 
  * **amenities** Удобства (строка, разделитель - запятая)
  * **room_number** Номер комнаты 
  * **price_per_night** Цена за ночь 
  * **is_booked** Статус бронирования 
  * **child_care_price** Стоимость услуг для детей 
  * **has_child_care** Наличие услуг для детей 
  * **child_beds** Количество детских кроватей 
  * **toy_kit** Наличие набора игрушек 
  * **amenities** Список удобств (строка, разделитель - запятая) 


Конструктор с параметрами (удобства строка)


### function FamilyRoom

```cpp
FamilyRoom(
    int room_number,
    float price_per_night,
    bool is_booked,
    float child_care_price,
    bool has_child_care,
    int child_beds,
    bool toy_kit,
    vector< string > amenities
)
```

Конструктор с параметрами (удобства в векторе) 

**Parameters**: 

  * **room_number** Номер комнаты 
  * **price_per_night** Цена за ночь 
  * **is_booked** Статус бронирования 
  * **child_care_price** Стоимость услуг для детей 
  * **has_child_care** Наличие услуг для детей 
  * **child_beds** Количество детских кроватей 
  * **toy_kit** Набор игрушек 
  * **amenities** Удобства (вектор строк)
  * **room_number** Номер комнаты 
  * **price_per_night** Цена за ночь 
  * **is_booked** Статус бронирования 
  * **child_care_price** Стоимость услуг для детей 
  * **has_child_care** Наличие услуг для детей 
  * **child_beds** Количество детских кроватей 
  * **toy_kit** Наличие набора игрушек 
  * **amenities** Список удобств (вектор строк) 


Конструктор с параметрами (удобства вектор)


### function FamilyRoom

```cpp
FamilyRoom(
    const FamilyRoom & 
) =default
```

Конструктор копирования 

### function operator=

```cpp
FamilyRoom & operator=(
    const FamilyRoom & 
) =default
```


### function FamilyRoom

```cpp
FamilyRoom(
    FamilyRoom && other
)
```

Конструктор перемещения 

**Parameters**: 

  * **other** Другой объект [FamilyRoom](Classes/class_family_room.md)


### function operator=

```cpp
FamilyRoom & operator=(
    FamilyRoom && 
) =default
```


### function get_child_beds

```cpp
inline int get_child_beds() const
```

Получить количество детских кроватей 

**Return**: Количество детских кроватей 

### function get_toy_kit

```cpp
inline bool get_toy_kit() const
```

Получить наличие набора игрушек 

**Return**: true если набор есть, false если нет 

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

**Return**: Строка вида "Семейная комната №X" 

**Reimplements**: [Room::get_full_name](Classes/class_room.md#function-get-full-name)


### function set_child_beds

```cpp
inline void set_child_beds(
    int child_beds
)
```

Установить количество детских кроватей 

**Parameters**: 

  * **child_beds** Новое количество кроватей 


### function set_toy_kit

```cpp
inline void set_toy_kit(
    bool toy_kit
)
```

Установить наличие набора игрушек 

**Parameters**: 

  * **toy_kit** Новое значение наличия набора 


### function set_amenities

```cpp
inline void set_amenities(
    vector< string > amenities
)
```

Установить список удобств 

**Parameters**: 

  * **amenities** Новый список удобств 


### function input_child_beds

```cpp
inline bool input_child_beds()
```

Ввод количества детских кроватей 

**Return**: true если ввод отменен, false если успешен 

**Note**: Использует оператор [] для доступа к полю 

### function input_toy_kit

```cpp
inline bool input_toy_kit()
```

Ввод наличия набора игрушек 

**Return**: true если ввод отменен, false если успешен 

**Note**: Использует оператор [] для доступа к полю 

### function input_amenities

```cpp
template <char Delim =','>
inline bool input_amenities()
```

Ввод удобств с разделителем 

**Template Parameters**: 

  * **Delim** Разделитель (по умолчанию ',') 


**Return**: true если ввод отменен, false если успешен 

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


**Return**: Общая стоимость (цена * ночи + 1000 руб./ребенок) 

**Reimplements**: [Room::calculate_total](Classes/class_room.md#function-calculate-total)


### function validate

```cpp
inline virtual bool validate() const override
```

Проверка валидности номера 

**Return**: true если количество детских кроватей <= 4, иначе false 

**Reimplements**: [Room::validate](Classes/class_room.md#function-validate)


### function add_play_area

```cpp
inline void add_play_area()
```

Активировать игровую зону 

Добавляет 1500 руб. к стоимости и устанавливает флаг наличия игрушек 


### function remove_play_area

```cpp
inline void remove_play_area()
```

Деактивировать игровую зону 

Убирает 1500 руб. из стоимости, если игровая зона была активна 


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


### function operator[]

```cpp
string operator[](
    int index
) const
```

Оператор доступа по индексу (строковая версия) 

**Parameters**: 

  * **index** Индекс поля (0-4) 


**Exceptions**: 

  * **out_of_range** Если индекс вне диапазона 


**Return**: Строковое представление запрошенного поля 

### function operator[]

```cpp
template <typename T >
enable_if_t< is_same_v< T, float >, T > operator[](
    int index
) const
```

Шаблонный оператор доступа по индексу (const) 

**Parameters**: 

  * **index** Индекс поля (0-4) 


**Exceptions**: 

  * **invalid_argument** Если индекс не соответствует типу 


**Template Parameters**: 

  * **T** Тип возвращаемого значения 


**Return**: Значение запрошенного поля 

### function operator[]

```cpp
template <typename T >
enable_if_t< is_same_v< T, bool >, T > operator[](
    int index
) const
```


### function operator[]

```cpp
template <typename T >
enable_if_t< is_same_v< T, int >, T > operator[](
    int index
) const
```


### function operator[]

```cpp
template <typename T >
enable_if_t< is_same_v< T, string >, T > operator[](
    int index
) const
```


### function operator[]

```cpp
template <typename T >
enable_if_t< is_same_v< T, float >, T & > operator[](
    int index
)
```

Шаблонный оператор доступа по индексу (non-const) 

**Parameters**: 

  * **index** Индекс поля (0-4) 


**Exceptions**: 

  * **invalid_argument** Если индекс не соответствует типу 


**Template Parameters**: 

  * **T** Тип возвращаемого значения 


**Return**: Ссылка на запрошенное поле 

### function operator[]

```cpp
template <typename T >
enable_if_t< is_same_v< T, bool >, T & > operator[](
    int index
)
```


### function operator[]

```cpp
template <typename T >
enable_if_t< is_same_v< T, int >, T & > operator[](
    int index
)
```


### function operator[]

```cpp
template <typename T >
enable_if_t< is_same_v< T, string >, T & > operator[](
    int index
)
```


### function operator string

```cpp
explicit operator string() const
```

Преобразование в строку 

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

**Return**: true если ввод отменен, false если успешен 

**Reimplements**: [Room::input](Classes/class_room.md#function-input)


### function to_string

```cpp
virtual string to_string() const override
```

Преобразование в строку 

**Return**: Полное строковое представление номера 

**Reimplements**: [Room::to_string](Classes/class_room.md#function-to-string)


### function ~FamilyRoom

```cpp
virtual ~FamilyRoom() =default
```

Деструктор 

## Friends

### friend operator<<

```cpp
friend ostream & operator<<(
    ostream & os,

    const FamilyRoom & r
);
```

Оператор вывода 

**Parameters**: 

  * **os** Поток вывода 
  * **fr** Комната для вывода 


**Return**: Поток вывода 

### friend operator>>

```cpp
friend istream & operator>>(
    istream & is,

    FamilyRoom & r
);
```

Оператор ввода 

**Parameters**: 

  * **is** Поток ввода 
  * **fr** Комната для ввода 


**Return**: Поток ввода 

### friend operator+

```cpp
friend vector< string > operator+(
    const FamilyRoom & fr1,

    const FamilyRoom & fr2
);
```


### friend operator+

```cpp
friend vector< string > operator+(
    const vector< string > & amenities,

    const FamilyRoom & fr
);
```


### friend operator+

```cpp
friend vector< string > operator+(
    const FamilyRoom & fr,

    const vector< string > & amenities
);
```


### friend operator+=

```cpp
friend vector< string > & operator+=(
    vector< string > & amenities,

    const FamilyRoom & fr
);
```


### friend operator+=

```cpp
friend FamilyRoom & operator+=(
    FamilyRoom & fr,

    const vector< string > & amenities
);
```


### friend operator+=

```cpp
friend FamilyRoom & operator+=(
    FamilyRoom & fr,

    const string & amenities
);
```


-------------------------------

Updated on 2025-05-09 at 18:16:45 +0300