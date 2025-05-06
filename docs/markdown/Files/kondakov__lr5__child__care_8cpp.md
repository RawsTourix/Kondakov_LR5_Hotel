---
title: Kondakov_LR5_Hotel/kondakov_lr5_child_care.cpp
summary: Реализация методов класса ChildCare. 

---

# Kondakov_LR5_Hotel/kondakov_lr5_child_care.cpp

Реализация методов класса [ChildCare](Classes/class_child_care.md).  [More...](#detailed-description)

## Functions

|                | Name           |
| -------------- | -------------- |
| ostream & | **[operator<<](Files/kondakov__lr5__child__care_8cpp.md#function-operator<<)**(ostream & os, const [ChildCare](Classes/class_child_care.md) & cr)<br>Оператор вывода  |
| istream & | **[operator>>](Files/kondakov__lr5__child__care_8cpp.md#function-operator>>)**(istream & is, [ChildCare](Classes/class_child_care.md) & cr)<br>Оператор ввода  |

## Detailed Description

Реализация методов класса [ChildCare](Classes/class_child_care.md). 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 

## Functions Documentation

### function operator<<

```cpp
ostream & operator<<(
    ostream & os,
    const ChildCare & cr
)
```

Оператор вывода 

**Parameters**: 

  * **os** Поток вывода 
  * **cr** Объект для вывода 


**Return**: Поток вывода 

### function operator>>

```cpp
istream & operator>>(
    istream & is,
    ChildCare & cr
)
```

Оператор ввода 

**Parameters**: 

  * **is** Поток ввода 
  * **cr** Объект для ввода 


**Return**: Поток ввода 



## Source code

```cpp


#include "kondakov_lr5_child_care.h"

const string ChildCare::CURRENCY = "руб.";  

ChildCare::ChildCare()
    : ChildCare(1000.0f, false) {
}

ChildCare::ChildCare(bool has_child_care)
    : ChildCare(1000.0f, has_child_care) {
}

ChildCare::ChildCare(float child_care_price, bool has_child_care)
    : child_care_price(child_care_price),
      has_child_care(has_child_care) {
}

ChildCare::ChildCare(ChildCare&& other) noexcept
    : child_care_price(other.child_care_price),
      has_child_care(other.has_child_care) {
}

ChildCare::operator string() const {
    ostringstream oss;
    oss << "Стоимость услуг для детей:\t" << child_care_price << " " << CURRENCY << endl
        << "Наличие услуг для детей:\t"   << (has_child_care ? "да" : "нет");
    return oss.str();
}

ostream& operator<<(ostream& os, const ChildCare& cr) {
    os << static_cast<string>(cr);
    return os;
}

istream& operator>>(istream& is, ChildCare& cr) {
    if (cr.input_child_care_price()) { is.setstate(ios::failbit); return is; }
    if (cr.input_has_child_care())   { is.setstate(ios::failbit); return is; }
    return is;
}

string ChildCare::to_string() const {
    ostringstream oss;
    oss << *this;
    return oss.str();
}
```


-------------------------------

Updated on 2025-05-06 at 23:16:47 +0300
