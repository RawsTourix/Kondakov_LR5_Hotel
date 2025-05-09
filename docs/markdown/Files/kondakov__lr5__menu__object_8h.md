---
title: Kondakov_LR5_Hotel/kondakov_lr5_menu_object.h
summary: Заголовочный файл класса MenuObject. 

---

# Kondakov_LR5_Hotel/kondakov_lr5_menu_object.h

Заголовочный файл класса [MenuObject](Classes/class_menu_object.md).  [More...](#detailed-description)

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[MenuObject](Classes/class_menu_object.md)** <br>Класс для представления пункта меню  |

## Detailed Description

Заголовочный файл класса [MenuObject](Classes/class_menu_object.md). 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 



## Source code

```cpp


#ifndef KONDAKOV_LR5_MENU_OBJECT_H
#define KONDAKOV_LR5_MENU_OBJECT_H


#include "kondakov_lr5_serializer.h"

class MenuObject {
private:
    int number;                     
    string label;                   
    function<void()> action;        
    vector<MenuObject> submenu {};  
    bool one_off_menu_inclusion;    

public:
    MenuObject() = delete;


    MenuObject(int number, string label, function<void()> action);

    MenuObject(int number, string label, function<void()> action, bool one_off_menu_inclusion);

    MenuObject(int number, string label, vector<MenuObject> submenu);

    MenuObject(int number, string label, vector<MenuObject> submenu, bool one_off_menu_inclusion);

    MenuObject(int number, string label, function<void()> action, vector<MenuObject> submenu);

    MenuObject(int number, string label, function<void()> action, 
               vector<MenuObject> submenu, bool one_off_menu_inclusion);

    template <typename RoomPtr, typename Action,
        typename = enable_if_t<is_base_of_v<Room, typename RoomPtr::element_type> &&
                               is_same_v<bool, decltype(declval<Action>()())>, void>>
    MenuObject(int number, string label, RoomPtr room, Action action,
               string main_message, string success_message);

    MenuObject(const MenuObject&) = default;
    MenuObject& operator=(const MenuObject&) = default;

    MenuObject(MenuObject&&) noexcept;
    MenuObject& operator=(MenuObject&&) = default;

    ~MenuObject() = default;  

    inline void show(const string& indentation = "") const;
    inline void act() const;
    inline string get_label() const;
    inline int get_number() const;
    inline string get_full_name() const;
    inline const vector<MenuObject>& get_submenu() const;
    inline bool get_one_off_menu_inclusion() const;

    template <typename Container>
    static enable_if_t<is_same_v<typename Container::value_type, MenuObject>, void>
    show_menu(const Container& menu, int indent);

    template <typename Container>
    static enable_if_t<is_same_v<typename Container::value_type, MenuObject>, void>
    process(const Container& menu, const string main_label = "", 
            const string exit_label = "", int indent = 0, bool one_off = false);
};

#include "kondakov_lr5_menu_object.hpp"
 // Конец группы input_control

#endif // KONDAKOV_LR5_MENU_OBJECT_H
```


-------------------------------

Updated on 2025-05-09 at 18:16:45 +0300
