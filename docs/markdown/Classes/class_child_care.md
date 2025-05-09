---
title: ChildCare
summary: Класс, представляющий услуги по уходу за детьми 

---

# ChildCare



Класс, представляющий услуги по уходу за детьми 


`#include <kondakov_lr5_child_care.h>`

Inherited by [FamilyRoom](Classes/class_family_room.md)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[ChildCare](Classes/class_child_care.md#function-childcare)**()<br>Конструктор по умолчанию  |
| | **[ChildCare](Classes/class_child_care.md#function-childcare)**(bool has_child_care)<br>Конструктор преобразования  |
| | **[ChildCare](Classes/class_child_care.md#function-childcare)**(float child_care_price, bool has_child_care)<br>Основной конструктор с параметрами  |
| | **[ChildCare](Classes/class_child_care.md#function-childcare)**(const [ChildCare](Classes/class_child_care.md) & ) =default<br>Конструктор копирования  |
| [ChildCare](Classes/class_child_care.md) & | **[operator=](Classes/class_child_care.md#function-operator=)**(const [ChildCare](Classes/class_child_care.md) & ) =default |
| | **[ChildCare](Classes/class_child_care.md#function-childcare)**([ChildCare](Classes/class_child_care.md) && other)<br>Конструктор перемещения  |
| [ChildCare](Classes/class_child_care.md) & | **[operator=](Classes/class_child_care.md#function-operator=)**([ChildCare](Classes/class_child_care.md) && ) =default |
| float | **[get_child_care_price](Classes/class_child_care.md#function-get-child-care-price)**() const<br>Получить стоимость услуг для детей  |
| bool | **[get_has_child_care](Classes/class_child_care.md#function-get-has-child-care)**() const<br>Получить наличие услуг для детей  |
| void | **[set_child_care_price](Classes/class_child_care.md#function-set-child-care-price)**(float child_care_price)<br>Установить стоимость услуг для детей  |
| void | **[set_has_child_care](Classes/class_child_care.md#function-set-has-child-care)**(bool has_child_care)<br>Установить наличие услуг для детей  |
| bool | **[input_child_care_price](Classes/class_child_care.md#function-input-child-care-price)**()<br>Ввод стоимости услуг для детей  |
| bool | **[input_has_child_care](Classes/class_child_care.md#function-input-has-child-care)**()<br>Ввод наличия услуг для детей  |
| | **[~ChildCare](Classes/class_child_care.md#function-~childcare)**() =default<br>Деструктор  |
| | **[operator string](Classes/class_child_care.md#function-operator-string)**() const<br>Преобразование в строку  |
| virtual string | **[to_string](Classes/class_child_care.md#function-to-string)**() const<br>Преобразование в строку  |

## Protected Functions

|                | Name           |
| -------------- | -------------- |
| void | **[print](Classes/class_child_care.md#function-print)**() const<br>Вывод информации об услугах  |
| bool | **[input](Classes/class_child_care.md#function-input)**()<br>Ввод информации об услугах  |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| const string | **[CURRENCY](Classes/class_child_care.md#variable-currency)** <br>Валюта для отображения цен  |

## Protected Attributes

|                | Name           |
| -------------- | -------------- |
| float | **[child_care_price](Classes/class_child_care.md#variable-child-care-price)** <br>Стоимость услуг для детей (в рублях)  |
| bool | **[has_child_care](Classes/class_child_care.md#variable-has-child-care)** <br>Флаг наличия услуг для детей  |

## Friends

|                | Name           |
| -------------- | -------------- |
| ostream & | **[operator<<](Classes/class_child_care.md#friend-operator<<)**(ostream & os, const [ChildCare](Classes/class_child_care.md) & cr) <br>Оператор вывода  |
| istream & | **[operator>>](Classes/class_child_care.md#friend-operator>>)**(istream & is, [ChildCare](Classes/class_child_care.md) & cr) <br>Оператор ввода  |

## Public Functions Documentation

### function ChildCare

```cpp
ChildCare()
```

Конструктор по умолчанию 

Создает услуги для детей с параметрами:

* Стоимость услуг: 1000.0
* Наличие услуг: нет 


### function ChildCare

```cpp
ChildCare(
    bool has_child_care
)
```

Конструктор преобразования 

**Parameters**: 

  * **has_child_care** Наличие услуг для детей
  * **has_child_care** Наличие услуг для детей 



Создает услуги для детей с указанным параметром:

* Стоимость услуг: 1000.0


### function ChildCare

```cpp
ChildCare(
    float child_care_price,
    bool has_child_care
)
```

Основной конструктор с параметрами 

**Parameters**: 

  * **child_care_price** Стоимость услуг 
  * **has_child_care** Наличие услуг 


Конструктор с параметрами


### function ChildCare

```cpp
ChildCare(
    const ChildCare & 
) =default
```

Конструктор копирования 

### function operator=

```cpp
ChildCare & operator=(
    const ChildCare & 
) =default
```


### function ChildCare

```cpp
ChildCare(
    ChildCare && other
)
```

Конструктор перемещения 

**Parameters**: 

  * **other** Другой объект [ChildCare](Classes/class_child_care.md)


### function operator=

```cpp
ChildCare & operator=(
    ChildCare && 
) =default
```


### function get_child_care_price

```cpp
inline float get_child_care_price() const
```

Получить стоимость услуг для детей 

**Return**: Стоимость услуг в рублях 

### function get_has_child_care

```cpp
inline bool get_has_child_care() const
```

Получить наличие услуг для детей 

**Return**: true если услуги доступны, false если нет 

### function set_child_care_price

```cpp
inline void set_child_care_price(
    float child_care_price
)
```

Установить стоимость услуг для детей 

**Parameters**: 

  * **child_care_price** Новая стоимость услуг 


### function set_has_child_care

```cpp
inline void set_has_child_care(
    bool has_child_care
)
```

Установить наличие услуг для детей 

**Parameters**: 

  * **has_child_care** Новое значение наличия услуг 


### function input_child_care_price

```cpp
inline bool input_child_care_price()
```

Ввод стоимости услуг для детей 

**Return**: true если ввод отменен, false если успешен 

### function input_has_child_care

```cpp
inline bool input_has_child_care()
```

Ввод наличия услуг для детей 

**Return**: true если ввод отменен, false если успешен 

### function ~ChildCare

```cpp
~ChildCare() =default
```

Деструктор 

### function operator string

```cpp
explicit operator string() const
```

Преобразование в строку 

**Return**: Строковое представление услуг 

### function to_string

```cpp
virtual string to_string() const
```

Преобразование в строку 

**Return**: Строковое представление объекта 

**Reimplemented by**: [FamilyRoom::to_string](Classes/class_family_room.md#function-to-string)


## Protected Functions Documentation

### function print

```cpp
inline void print() const
```

Вывод информации об услугах 

### function input

```cpp
inline bool input()
```

Ввод информации об услугах 

**Return**: true если ввод отменен, false если успешен 

## Public Attributes Documentation

### variable CURRENCY

```cpp
static const string CURRENCY = "руб.";
```

Валюта для отображения цен 

Инициализация статического поля 


## Protected Attributes Documentation

### variable child_care_price

```cpp
float child_care_price;
```

Стоимость услуг для детей (в рублях) 

### variable has_child_care

```cpp
bool has_child_care;
```

Флаг наличия услуг для детей 

## Friends

### friend operator<<

```cpp
friend ostream & operator<<(
    ostream & os,

    const ChildCare & cr
);
```

Оператор вывода 

**Parameters**: 

  * **os** Поток вывода 
  * **cr** Объект для вывода 


**Return**: Поток вывода 

### friend operator>>

```cpp
friend istream & operator>>(
    istream & is,

    ChildCare & cr
);
```

Оператор ввода 

**Parameters**: 

  * **is** Поток ввода 
  * **cr** Объект для ввода 


**Return**: Поток ввода 

-------------------------------

Updated on 2025-05-09 at 18:16:45 +0300