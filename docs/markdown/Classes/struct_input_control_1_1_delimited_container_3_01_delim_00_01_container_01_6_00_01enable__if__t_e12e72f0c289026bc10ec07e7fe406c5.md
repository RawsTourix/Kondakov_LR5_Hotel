---
title: InputControl::DelimitedContainer< Delim, Container &, enable_if_t< is_same_v< typename Container::value_type, string >, void > >
summary: Специализация DelimitedContainer для работы со строками 

---

# InputControl::DelimitedContainer< Delim, Container &, enable_if_t< is_same_v< typename Container::value_type, string >, void > >



Специализация [DelimitedContainer](Classes/struct_input_control_1_1_delimited_container.md) для работы со строками  [More...](#detailed-description)


`#include <kondakov_lr5_container_operations.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[DelimitedContainer](Classes/struct_input_control_1_1_delimited_container_3_01_delim_00_01_container_01_6_00_01enable__if__t_e12e72f0c289026bc10ec07e7fe406c5.md#function-delimitedcontainer)**(Container & r)<br>Конструктор  |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| Container & | **[ref](Classes/struct_input_control_1_1_delimited_container_3_01_delim_00_01_container_01_6_00_01enable__if__t_e12e72f0c289026bc10ec07e7fe406c5.md#variable-ref)** <br>Ссылка на целевой контейнер  |

## Detailed Description

```cpp
template <char Delim,
typename Container >
struct InputControl::DelimitedContainer< Delim, Container &, enable_if_t< is_same_v< typename Container::value_type, string >, void > >;
```

Специализация [DelimitedContainer](Classes/struct_input_control_1_1_delimited_container.md) для работы со строками 

**Template Parameters**: 

  * **Delim** Разделитель 
  * **Container** Тип контейнера (должен содержать строки)



Хранит ссылку на контейнер строк для последующей обработки 

## Public Functions Documentation

### function DelimitedContainer

```cpp
inline explicit DelimitedContainer(
    Container & r
)
```

Конструктор 

## Public Attributes Documentation

### variable ref

```cpp
Container & ref;
```

Ссылка на целевой контейнер 

-------------------------------

Updated on 2025-05-09 at 18:16:45 +0300