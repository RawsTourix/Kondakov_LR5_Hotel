---
title: Kondakov_LR5_Hotel/kondakov_lr5_input_control.h
summary: Заголовочный файл для управления вводом данных 

---

# Kondakov_LR5_Hotel/kondakov_lr5_input_control.h

Заголовочный файл для управления вводом данных  [More...](#detailed-description)

## Namespaces

| Name           |
| -------------- |
| **[InputControl](Namespaces/namespace_input_control.md)** <br>Пространство имён для функций управления вводом данных  |

## Detailed Description

Заголовочный файл для управления вводом данных 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 



## Source code

```cpp


#ifndef KONDAKOV_LR5_INPUT_CONTROL_H
#define KONDAKOV_LR5_INPUT_CONTROL_H


#include "kondakov_lr5_def.h"

namespace InputControl {
    template <char Delim, typename Container, typename = void>
    struct DelimitedContainer;

    template <char Delim, typename Container>
    struct DelimitedContainer<Delim, Container&, enable_if_t<is_same_v<typename Container::value_type, string>, void>>;

    void trim(string& str);

    template <char Delim, typename Container>
    void split(const string& input_line, DelimitedContainer<Delim, Container&>& dc);

    string get_lowercase(const string str);

    void make_first_letter_uppercase(string& str);

    bool is_input_empty(const string& input);

    template <typename T>
    bool check_min_max(const T& number, T min, T max);

    bool input(string& varLink, const string& label);
    
    bool input(bool& varLink, const string& label);

    template <typename T>
    enable_if_t<is_arithmetic_v<T>, bool>
    input(T& varLink, const string& label, T min = 0, T max = numeric_limits<T>::max());

    char get_char();

    bool yes_or_no(const string& label);
}

#include "kondakov_lr5_input_control.hpp"
#include "kondakov_lr5_container_operations.hpp"  
 // Конец группы input_control

#endif // KONDAKOV_LR5_INPUT_CONTROL_H
```


-------------------------------

Updated on 2025-05-09 at 18:16:45 +0300
