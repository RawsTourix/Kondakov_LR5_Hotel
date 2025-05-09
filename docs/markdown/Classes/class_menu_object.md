---
title: MenuObject
summary: Класс для представления пункта меню 

---

# MenuObject

**Module:** **[Система меню](Modules/group__menu__system.md)**



Класс для представления пункта меню  [More...](#detailed-description)


`#include <kondakov_lr5_menu_object.h>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[MenuObject](Classes/class_menu_object.md#function-menuobject)**(int number, string label, function< void()> action)<br>Конструктор пункта меню без подменю  |
| | **[MenuObject](Classes/class_menu_object.md#function-menuobject)**(int number, string label, function< void()> action, bool one_off_menu_inclusion)<br>Конструктор с флагом одноразового меню  |
| | **[MenuObject](Classes/class_menu_object.md#function-menuobject)**(int number, string label, vector< [MenuObject](Classes/class_menu_object.md) > submenu)<br>Конструктор с подменю  |
| | **[MenuObject](Classes/class_menu_object.md#function-menuobject)**(int number, string label, vector< [MenuObject](Classes/class_menu_object.md) > submenu, bool one_off_menu_inclusion)<br>Конструктор с подменю и флагом  |
| | **[MenuObject](Classes/class_menu_object.md#function-menuobject)**(int number, string label, function< void()> action, vector< [MenuObject](Classes/class_menu_object.md) > submenu)<br>Конструктор с действием и подменю  |
| | **[MenuObject](Classes/class_menu_object.md#function-menuobject)**(int number, string label, function< void()> action, vector< [MenuObject](Classes/class_menu_object.md) > submenu, bool one_off_menu_inclusion)<br>Полный конструктор  |
| template <typename RoomPtr ,typename Action ,typename  =enable_if_t<is_base_of_v<Room, typename RoomPtr::element_type> &&                               is_same_v<bool, decltype(declval<Action>()())>\> <br>| **[MenuObject](Classes/class_menu_object.md#function-menuobject)**(int number, string label, RoomPtr room, Action action, string main_message, string success_message)<br>Конструктор для комнаты с подтверждением  |
| | **[MenuObject](Classes/class_menu_object.md#function-menuobject)**(const [MenuObject](Classes/class_menu_object.md) & ) =default<br>Конструктор копирования  |
| [MenuObject](Classes/class_menu_object.md) & | **[operator=](Classes/class_menu_object.md#function-operator=)**(const [MenuObject](Classes/class_menu_object.md) & ) =default |
| | **[MenuObject](Classes/class_menu_object.md#function-menuobject)**([MenuObject](Classes/class_menu_object.md) && other)<br>Конструктор перемещения  |
| [MenuObject](Classes/class_menu_object.md) & | **[operator=](Classes/class_menu_object.md#function-operator=)**([MenuObject](Classes/class_menu_object.md) && ) =default |
| void | **[show](Classes/class_menu_object.md#function-show)**(const string & indentation ="") const<br>Вывод пункта меню  |
| void | **[act](Classes/class_menu_object.md#function-act)**() const<br>Выполнение действия пункта меню  |
| string | **[get_label](Classes/class_menu_object.md#function-get-label)**() const<br>Получение названия пункта  |
| int | **[get_number](Classes/class_menu_object.md#function-get-number)**() const<br>Получение номера пункта  |
| string | **[get_full_name](Classes/class_menu_object.md#function-get-full-name)**() const<br>Получение полного названия  |
| const vector< [MenuObject](Classes/class_menu_object.md) > & | **[get_submenu](Classes/class_menu_object.md#function-get-submenu)**() const<br>Получение подменю  |
| bool | **[get_one_off_menu_inclusion](Classes/class_menu_object.md#function-get-one-off-menu-inclusion)**() const<br>Проверка флага одноразового меню  |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, [MenuObject](Classes/class_menu_object.md) >, void > | **[show_menu](Classes/class_menu_object.md#function-show-menu)**(const Container & menu, int indent)<br>Вывод меню  |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, [MenuObject](Classes/class_menu_object.md) >, void > | **[process](Classes/class_menu_object.md#function-process)**(const Container & menu, const string main_label ="", const string exit_label ="", int indent =0, bool one_off =false)<br>Обработка взаимодействия с меню  |
| | **[MenuObject](Classes/class_menu_object.md#function-menuobject)**() =delete<br>Удаленный конструктор по умолчанию  |
| | **[~MenuObject](Classes/class_menu_object.md#function-~menuobject)**() =default<br>Деструктор  |

## Detailed Description

```cpp
class MenuObject;
```

Класс для представления пункта меню 

Реализует древовидную структуру меню с поддержкой подменю и действий 

## Public Functions Documentation

### function MenuObject

```cpp
MenuObject(
    int number,
    string label,
    function< void()> action
)
```

Конструктор пункта меню без подменю 

**Parameters**: 

  * **number** Номер пункта 
  * **label** Название пункта 
  * **action** Действие при выборе 


### function MenuObject

```cpp
MenuObject(
    int number,
    string label,
    function< void()> action,
    bool one_off_menu_inclusion
)
```

Конструктор с флагом одноразового меню 

**Parameters**: 

  * **number** Номер пункта 
  * **label** Название пункта 
  * **action** Действие при выборе 
  * **one_off_menu_inclusion** Флаг одноразового меню 


### function MenuObject

```cpp
MenuObject(
    int number,
    string label,
    vector< MenuObject > submenu
)
```

Конструктор с подменю 

**Parameters**: 

  * **number** Номер пункта 
  * **label** Название пункта 
  * **submenu** Вектор подменю 


### function MenuObject

```cpp
MenuObject(
    int number,
    string label,
    vector< MenuObject > submenu,
    bool one_off_menu_inclusion
)
```

Конструктор с подменю и флагом 

**Parameters**: 

  * **number** Номер пункта 
  * **label** Название пункта 
  * **submenu** Вектор подменю 
  * **one_off_menu_inclusion** Флаг одноразового меню 


### function MenuObject

```cpp
MenuObject(
    int number,
    string label,
    function< void()> action,
    vector< MenuObject > submenu
)
```

Конструктор с действием и подменю 

**Parameters**: 

  * **number** Номер пункта 
  * **label** Название пункта 
  * **action** Действие при выборе 
  * **submenu** Вектор подменю 


### function MenuObject

```cpp
MenuObject(
    int number,
    string label,
    function< void()> action,
    vector< MenuObject > submenu,
    bool one_off_menu_inclusion
)
```

Полный конструктор 

**Parameters**: 

  * **number** Номер пункта 
  * **label** Название пункта 
  * **action** Действие при выборе 
  * **submenu** Вектор подменю 
  * **one_off_menu_inclusion** Флаг одноразового меню



Инициализирует все поля класса 


### function MenuObject

```cpp
template <typename RoomPtr ,
typename Action ,
typename  =enable_if_t<is_base_of_v<Room, typename RoomPtr::element_type> &&                               is_same_v<bool, decltype(declval<Action>()())>>
MenuObject(
    int number,
    string label,
    RoomPtr room,
    Action action,
    string main_message,
    string success_message
)
```

Конструктор для комнаты с подтверждением 

**Parameters**: 

  * **number** Номер пункта 
  * **label** Название пункта 
  * **room** Указатель на комнату 
  * **action** Действие с подтверждением 
  * **main_message** Сообщение перед действием 
  * **success_message** Сообщение после успеха


**Template Parameters**: 

  * **RoomPtr** Тип умного указателя на [Room](Classes/class_room.md)
  * **Action** Тип действия (должен возвращать bool) 



Создает пункт меню с обработкой подтверждения операции 


### function MenuObject

```cpp
MenuObject(
    const MenuObject & 
) =default
```

Конструктор копирования 

### function operator=

```cpp
MenuObject & operator=(
    const MenuObject & 
) =default
```


### function MenuObject

```cpp
MenuObject(
    MenuObject && other
)
```

Конструктор перемещения 

Эффективно переносит ресурсы из другого объекта 


### function operator=

```cpp
MenuObject & operator=(
    MenuObject && 
) =default
```


### function show

```cpp
inline void show(
    const string & indentation =""
) const
```

Вывод пункта меню 

**Parameters**: 

  * **indentation** Отступ для вложенных пунктов 


### function act

```cpp
inline void act() const
```

Выполнение действия пункта меню 

### function get_label

```cpp
inline string get_label() const
```

Получение названия пункта 

**Return**: Название пункта меню 

### function get_number

```cpp
inline int get_number() const
```

Получение номера пункта 

**Return**: Номер пункта меню 

### function get_full_name

```cpp
inline string get_full_name() const
```

Получение полного названия 

**Return**: Строка вида "номер. название" 

### function get_submenu

```cpp
inline const vector< MenuObject > & get_submenu() const
```

Получение подменю 

**Return**: Константная ссылка на вектор подменю 

### function get_one_off_menu_inclusion

```cpp
inline bool get_one_off_menu_inclusion() const
```

Проверка флага одноразового меню 

**Return**: true если меню одноразовое 

### function show_menu

```cpp
template <typename Container >
static enable_if_t< is_same_v< typename Container::value_type, MenuObject >, void > show_menu(
    const Container & menu,
    int indent
)
```

Вывод меню 

**Parameters**: 

  * **menu** Контейнер с меню 
  * **indent** Уровень вложенности 


**Template Parameters**: 

  * **Container** Тип контейнера с пунктами меню 


### function process

```cpp
template <typename Container >
static enable_if_t< is_same_v< typename Container::value_type, MenuObject >, void > process(
    const Container & menu,
    const string main_label ="",
    const string exit_label ="",
    int indent =0,
    bool one_off =false
)
```

Обработка взаимодействия с меню 

**Parameters**: 

  * **menu** Контейнер с меню 
  * **main_label** Заголовок меню 
  * **exit_label** Название пункта выхода 
  * **indent** Уровень вложенности 
  * **one_off** Флаг одноразового выполнения 


**Template Parameters**: 

  * **Container** Тип контейнера с пунктами меню 


### function MenuObject

```cpp
MenuObject() =delete
```

Удаленный конструктор по умолчанию 

### function ~MenuObject

```cpp
~MenuObject() =default
```

Деструктор 

-------------------------------

Updated on 2025-05-09 at 18:16:45 +0300