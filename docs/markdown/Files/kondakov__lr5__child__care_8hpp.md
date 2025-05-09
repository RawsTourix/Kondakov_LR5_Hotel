---
title: Kondakov_LR5_Hotel/kondakov_lr5_child_care.hpp
summary: Реализация методов класса ChildCare. 

---

# Kondakov_LR5_Hotel/kondakov_lr5_child_care.hpp

Реализация методов класса [ChildCare](Classes/class_child_care.md).  [More...](#detailed-description)

## Detailed Description

Реализация методов класса [ChildCare](Classes/class_child_care.md). 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 



## Source code

```cpp


#ifndef KONDAKOV_LR5_CHILD_CARE_HPP
#define KONDAKOV_LR5_CHILD_CARE_HPP

#include "kondakov_lr5_child_care.h"

inline float ChildCare::get_child_care_price() const {
    return child_care_price;
}

inline bool ChildCare::get_has_child_care() const {
    return has_child_care;
}

inline void ChildCare::set_child_care_price(float child_care_price) {
    this->child_care_price = child_care_price;
}

inline void ChildCare::set_has_child_care(bool has_child_care) {
    this->has_child_care = has_child_care;
}

inline bool ChildCare::input_child_care_price() {
    ostringstream message;
    message << "Стоимость услуг для детей (" << CURRENCY << "): ";
    if (InputControl::input(child_care_price, message.str(), 0.0f, 10000.0f)) { 
        return true; 
    }
    return false;
}

inline bool ChildCare::input_has_child_care() {
    if (InputControl::input(has_child_care, "Наличие услуг для детей (1/0): ")) { 
        return true; 
    }
    return false;
}

#endif // KONDAKOV_LR5_CHILD_CARE_HPP
```


-------------------------------

Updated on 2025-05-09 at 18:16:45 +0300
