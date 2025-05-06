---
title: Kondakov_LR5_Hotel/kondakov_lr5_container_operations.hpp
summary: Операции с контейнерами строк 

---

# Kondakov_LR5_Hotel/kondakov_lr5_container_operations.hpp

Операции с контейнерами строк  [More...](#detailed-description)

## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[InputControl::DelimitedContainer< Delim, Container &, enable_if_t< is_same_v< typename Container::value_type, string >, void > >](Classes/struct_input_control_1_1_delimited_container_3_01_delim_00_01_container_01_6_00_01enable__if__t_e12e72f0c289026bc10ec07e7fe406c5.md)** <br>Специализация [DelimitedContainer](Classes/struct_input_control_1_1_delimited_container.md) для работы со строками  |

## Functions

|                | Name           |
| -------------- | -------------- |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, string >, ostream & > | **[operator<<](Files/kondakov__lr5__container__operations_8hpp.md#function-operator<<)**(ostream & os, const Container & strings)<br>Перегрузка оператора вывода для контейнера строк  |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, string >, Container > | **[operator+](Files/kondakov__lr5__container__operations_8hpp.md#function-operator+)**(const Container & lhs, const Container & rhs)<br>Перегрузка оператора сложения для контейнеров строк  |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, string >, Container & > | **[operator+=](Files/kondakov__lr5__container__operations_8hpp.md#function-operator+=)**(Container & lhs, const Container & rhs)<br>Перегрузка оператора += для контейнеров строк  |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, string >, Container & > | **[operator+=](Files/kondakov__lr5__container__operations_8hpp.md#function-operator+=)**(Container & lhs, const string & str)<br>Перегрузка оператора += для контейнера и строки  |
| template <char Delim,typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, string >, istream & > | **[operator>>](Files/kondakov__lr5__container__operations_8hpp.md#function-operator>>)**(istream & is, [InputControl::DelimitedContainer](Classes/struct_input_control_1_1_delimited_container.md)< Delim, Container & > & dc)<br>Перегрузка оператора ввода для DelimitedContainer.  |
| template <char Delim,typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, string >, Container & > | **[operator>>](Files/kondakov__lr5__container__operations_8hpp.md#function-operator>>)**([InputControl::DelimitedContainer](Classes/struct_input_control_1_1_delimited_container.md)< Delim, Container & > & dc, const string & input_line)<br>Перегрузка оператора >> для разделения строки в контейнер  |

## Detailed Description

Операции с контейнерами строк 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 

## Functions Documentation

### function operator<<

```cpp
template <typename Container >
enable_if_t< is_same_v< typename Container::value_type, string >, ostream & > operator<<(
    ostream & os,
    const Container & strings
)
```

Перегрузка оператора вывода для контейнера строк 

**Parameters**: 

  * **os** Поток вывода 
  * **strings** Контейнер строк 


**Template Parameters**: 

  * **Container** Тип контейнера (должен содержать строки) 


**Return**: Поток вывода


Выводит элементы контейнера через запятую 


### function operator+

```cpp
template <typename Container >
enable_if_t< is_same_v< typename Container::value_type, string >, Container > operator+(
    const Container & lhs,
    const Container & rhs
)
```

Перегрузка оператора сложения для контейнеров строк 

**Parameters**: 

  * **lhs** Левый операнд 
  * **rhs** Правый операнд 


**Template Parameters**: 

  * **Container** Тип контейнера (должен содержать строки) 


**Return**: Новый контейнер с объединёнными элементами


Объединяет контейнеры, исключая дубликаты 


### function operator+=

```cpp
template <typename Container >
enable_if_t< is_same_v< typename Container::value_type, string >, Container & > operator+=(
    Container & lhs,
    const Container & rhs
)
```

Перегрузка оператора += для контейнеров строк 

**Parameters**: 

  * **lhs** Левый операнд (изменяемый) 
  * **rhs** Правый операнд 


**Template Parameters**: 

  * **Container** Тип контейнера (должен содержать строки) 


**Return**: Ссылка на изменённый контейнер


Добавляет элементы из правого операнда, исключая дубликаты 


### function operator+=

```cpp
template <typename Container >
enable_if_t< is_same_v< typename Container::value_type, string >, Container & > operator+=(
    Container & lhs,
    const string & str
)
```

Перегрузка оператора += для контейнера и строки 

**Parameters**: 

  * **lhs** Левый операнд (изменяемый) 
  * **str** Добавляемая строка 


**Template Parameters**: 

  * **Container** Тип контейнера (должен содержать строки) 


**Return**: Ссылка на изменённый контейнер


Добавляет строку если её ещё нет в контейнере 


### function operator>>

```cpp
template <char Delim,
typename Container >
enable_if_t< is_same_v< typename Container::value_type, string >, istream & > operator>>(
    istream & is,
    InputControl::DelimitedContainer< Delim, Container & > & dc
)
```

Перегрузка оператора ввода для DelimitedContainer. 

**Parameters**: 

  * **is** Поток ввода 
  * **dc** Контейнер с разделителем 


**Template Parameters**: 

  * **Delim** Разделитель 
  * **Container** Тип контейнера (должен содержать строки) 


**Return**: Поток ввода


Считывает строку и разделяет её по разделителю в контейнер 


### function operator>>

```cpp
template <char Delim,
typename Container >
enable_if_t< is_same_v< typename Container::value_type, string >, Container & > operator>>(
    InputControl::DelimitedContainer< Delim, Container & > & dc,
    const string & input_line
)
```

Перегрузка оператора >> для разделения строки в контейнер 

**Parameters**: 

  * **dc** Контейнер с разделителем 
  * **input_line** Входная строка 


**Template Parameters**: 

  * **Delim** Разделитель 
  * **Container** Тип контейнера (должен содержать строки) 


**Return**: Ссылка на изменённый контейнер 



## Source code

```cpp


#ifndef KONDAKOV_LR5_CONTAINER_OPERATIONS_HPP
#define KONDAKOV_LR5_CONTAINER_OPERATIONS_HPP

#include "kondakov_lr5_input_control.h"

template <char Delim, typename Container>
struct InputControl::DelimitedContainer<Delim, Container&, enable_if_t<is_same_v<typename Container::value_type, string>, void>> {
    Container& ref; 
    explicit DelimitedContainer(Container& r) : ref(r) {} 
};

template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, ostream&>
operator<<(ostream& os, const Container& strings) {
    if (!strings.empty()) {
        auto it = strings.begin();
        os << *it;

        for (++it; it != strings.end(); ++it) {
            os << ", " << *it;
        }
    }
    return os;
}

template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, Container>
operator+(const Container& lhs, const Container& rhs) {
    Container result = lhs;
    for (const auto& str : rhs) {
        if (find(result.begin(), result.end(), str) == result.end()) {
            result.push_back(str);
        }
    }
    return result;
}

template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, Container&>
operator+=(Container& lhs, const Container& rhs) {
    for (const auto& str : rhs) {
        if (find(lhs.begin(), lhs.end(), str) == lhs.end()) {
            lhs.push_back(str);
        }
    }
    return lhs;
}

template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, Container&>
operator+=(Container& lhs, const string& str) {
    if (find(lhs.begin(), lhs.end(), str) == lhs.end()) {
        lhs.push_back(str);
    }
    return lhs;
}

template <char Delim, typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, istream&>
operator>>(istream& is, InputControl::DelimitedContainer<Delim, Container&>& dc) {
    string input_line;

    if (!getline(is, input_line)) {
        is.setstate(ios::failbit);
        return is;
    }

    InputControl::trim(input_line);
    if (InputControl::is_input_empty(input_line)) {
        is.setstate(ios::failbit);
        return is;
    }

    InputControl::split(input_line, dc);
    return is;
}

template <char Delim, typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, Container&>
operator>>(InputControl::DelimitedContainer<Delim, Container&>& dc, const string& input_line) {
    InputControl::split(input_line, dc);
    return dc.ref;
}

#endif // KONDAKOV_LR5_CONTAINER_OPERATIONS_HPP
```


-------------------------------

Updated on 2025-05-06 at 23:16:47 +0300
