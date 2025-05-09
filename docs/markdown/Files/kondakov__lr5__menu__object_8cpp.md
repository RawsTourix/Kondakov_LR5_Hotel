---
title: Kondakov_LR5_Hotel/kondakov_lr5_menu_object.cpp
summary: Реализация конструкторов класса MenuObject. 

---

# Kondakov_LR5_Hotel/kondakov_lr5_menu_object.cpp

Реализация конструкторов класса [MenuObject](Classes/class_menu_object.md).  [More...](#detailed-description)

## Detailed Description

Реализация конструкторов класса [MenuObject](Classes/class_menu_object.md). 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 



## Source code

```cpp


#include "kondakov_lr5_menu_object.h"

// Конструкторы делегируют вызов полному конструктору
MenuObject::MenuObject(int number, string label, function<void()> action)
    : MenuObject(number, label, action, {}, false) {}

MenuObject::MenuObject(int number, string label, function<void()> action, bool one_off)
    : MenuObject(number, label, action, {}, one_off) {}

MenuObject::MenuObject(int number, string label, vector<MenuObject> submenu)
    : MenuObject(number, label, nullptr, submenu, false) {}

MenuObject::MenuObject(int number, string label, vector<MenuObject> submenu, bool one_off)
    : MenuObject(number, label, nullptr, submenu, one_off) {}

MenuObject::MenuObject(int number, string label, function<void()> action, vector<MenuObject> submenu)
    : MenuObject(number, label, action, submenu, false) {}

MenuObject::MenuObject(int number, string label, function<void()> action,
                       vector<MenuObject> submenu, bool one_off_menu_inclusion)
    : number(number), label(label), action(action),
      submenu(submenu), one_off_menu_inclusion(one_off_menu_inclusion) {}

MenuObject::MenuObject(MenuObject&& other) noexcept
    : number(exchange(other.number, 0)),
      label(move(other.label)),
      action(move(other.action)),
      submenu(move(other.submenu)),
      one_off_menu_inclusion(other.one_off_menu_inclusion) {}
```


-------------------------------

Updated on 2025-05-09 at 18:16:45 +0300
