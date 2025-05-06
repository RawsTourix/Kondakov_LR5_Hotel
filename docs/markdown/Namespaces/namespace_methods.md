---
title: Methods
summary: Пространство имён для операций с комнатами 

---

# Methods

Пространство имён для операций с комнатами 

## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[Methods::RoomInfo](Classes/struct_methods_1_1_room_info.md)** <br>Краткая информация о комнате для отображения  |

## Functions

|                | Name           |
| -------------- | -------------- |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, shared_ptr< [Room](Classes/class_room.md) > >, function< void()> > | **[show_rooms](Namespaces/namespace_methods.md#function-show-rooms)**(const Container & rooms)<br>Вывод списка комнат  |
| template <typename RoomType ,typename Container \> <br>enable_if_t< is_base_of_v< [Room](Classes/class_room.md), typename RoomType > &&is_same_v< typename Container::value_type, shared_ptr< [Room](Classes/class_room.md) > >, function< void()> > | **[add_room](Namespaces/namespace_methods.md#function-add-room)**(Container & rooms)<br>Добавление комнаты  |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, shared_ptr< [Room](Classes/class_room.md) > >, function< void()> > | **[edit_room](Namespaces/namespace_methods.md#function-edit-room)**(Container & rooms)<br>Изменение комнаты  |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, shared_ptr< [Room](Classes/class_room.md) > >, function< void()> > | **[delete_room](Namespaces/namespace_methods.md#function-delete-room)**(Container & rooms)<br>Удаление комнаты  |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, shared_ptr< [Room](Classes/class_room.md) > >, function< void()> > | **[sort_rooms](Namespaces/namespace_methods.md#function-sort-rooms)**(Container & rooms)<br>Сортировка комнат  |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, shared_ptr< [Room](Classes/class_room.md) > >, function< void()> > | **[calculate_total](Namespaces/namespace_methods.md#function-calculate-total)**(Container & rooms)<br>Расчёт стоимости проживания  |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, shared_ptr< [Room](Classes/class_room.md) > >, function< void()> > | **[validate_room](Namespaces/namespace_methods.md#function-validate-room)**(Container & rooms)<br>Проверка валидности комнаты  |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, shared_ptr< [Room](Classes/class_room.md) > >, function< void()> > | **[additional_room_methods](Namespaces/namespace_methods.md#function-additional-room-methods)**(Container & rooms)<br>Дополнительные методы комнат  |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, shared_ptr< [Room](Classes/class_room.md) > >, shared_ptr< [Room](Classes/class_room.md) > > | **[get_room_from_rooms_map](Namespaces/namespace_methods.md#function-get-room-from-rooms-map)**(string main_label, string message, Container & rooms)<br>Выбор комнаты из списка  |
| template <typename Container \> <br>enable_if_t< is_same_v< typename Container::value_type, shared_ptr< [Room](Classes/class_room.md) > >, vector< int > > | **[get_room_numbers](Namespaces/namespace_methods.md#function-get-room-numbers)**(const Container & rooms)<br>Получение списка номеров комнат  |
| template <typename RoomType ,typename Container \> <br>enable_if_t< is_base_of_v< [Room](Classes/class_room.md), typename RoomType > &&is_same_v< typename Container::value_type, shared_ptr< [Room](Classes/class_room.md) > >, bool > | **[room_in_rooms_by_room_number](Namespaces/namespace_methods.md#function-room-in-rooms-by-room-number)**(RoomType room, const Container & rooms)<br>Проверка существования комнаты  |


## Functions Documentation

### function show_rooms

```cpp
template <typename Container >
enable_if_t< is_same_v< typename Container::value_type, shared_ptr< Room > >, function< void()> > show_rooms(
    const Container & rooms
)
```

Вывод списка комнат 

**Parameters**: 

  * **rooms** Контейнер с комнатами 
  * **rooms** Контейнер с комнатами 


**Template Parameters**: 

  * **Container** Тип контейнера с комнатами 
  * **Container** Тип контейнера (должен содержать shared_ptr<Room>) 


**Return**: 

  * Функция для вывода списка
  * Функция для вывода списка



Первая функция меню. Выводит форматированный список комнат. 


### function add_room

```cpp
template <typename RoomType ,
typename Container >
enable_if_t< is_base_of_v< Room, typename RoomType > &&is_same_v< typename Container::value_type, shared_ptr< Room > >, function< void()> > add_room(
    Container & rooms
)
```

Добавление комнаты 

**Parameters**: 

  * **rooms** Контейнер для добавления 
  * **rooms** Контейнер с комнатами 


**Template Parameters**: 

  * **RoomType** Тип добавляемой комнаты 
  * **Container** Тип контейнера 
  * **RoomType** Тип добавляемой комнаты (StandardRoom/Suite/FamilyRoom) 
  * **Container** Тип контейнера для хранения комнат 


**Return**: 

  * Функция для добавления комнаты
  * Функция-обработчик добавления комнаты


Добавление новой комнаты в контейнер


Вторая функция меню. Создает комнату указанного типа, запрашивает параметры через меню и добавляет в контейнер. Проверяет уникальность номера комнаты. 


### function edit_room

```cpp
template <typename Container >
enable_if_t< is_same_v< typename Container::value_type, shared_ptr< Room > >, function< void()> > edit_room(
    Container & rooms
)
```

Изменение комнаты 

**Parameters**: 

  * **rooms** Контейнер с комнатами 
  * **rooms** Контейнер с комнатами 


**Template Parameters**: 

  * **Container** Тип контейнера 
  * **Container** Тип контейнера с комнатами 


**Return**: 

  * Функция для изменения комнаты
  * Функция-обработчик редактирования комнаты


Редактирование существующей комнаты


Третья функция меню. Создает динамическое меню для редактирования всех параметров выбранной комнаты с учетом ее конкретного типа 


### function delete_room

```cpp
template <typename Container >
enable_if_t< is_same_v< typename Container::value_type, shared_ptr< Room > >, function< void()> > delete_room(
    Container & rooms
)
```

Удаление комнаты 

**Parameters**: 

  * **rooms** Контейнер с комнатами 
  * **rooms** Контейнер с комнатами 


**Template Parameters**: 

  * **Container** Тип контейнера 
  * **Container** Тип контейнера с комнатами 


**Return**: 

  * Функция для удаления комнаты
  * Функция-обработчик удаления комнаты


Удаление комнаты из контейнера


Четвёртая функция меню. Запрашивает подтверждение перед удалением. При удалении сохраняет целостность нумерации в списке. 


### function sort_rooms

```cpp
template <typename Container >
enable_if_t< is_same_v< typename Container::value_type, shared_ptr< Room > >, function< void()> > sort_rooms(
    Container & rooms
)
```

Сортировка комнат 

**Parameters**: 

  * **rooms** Контейнер для сортировки 
  * **rooms** Контейнер с комнатами 


**Template Parameters**: 

  * **Container** Тип контейнера 
  * **Container** Тип контейнера с комнатами 


**Return**: 

  * Функция для сортировки
  * Функция-обработчик сортировки


Сортировка комнат по различным критериям


Пятая функция меню. Предоставляет подменю с вариантами сортировки:

* По номеру комнаты
* По типу комнаты
* По цене за ночь
* По статусу бронирования 


### function calculate_total

```cpp
template <typename Container >
enable_if_t< is_same_v< typename Container::value_type, shared_ptr< Room > >, function< void()> > calculate_total(
    Container & rooms
)
```

Расчёт стоимости проживания 

**Parameters**: 

  * **rooms** Контейнер с комнатами 
  * **rooms** Контейнер с комнатами 


**Template Parameters**: 

  * **Container** Тип контейнера 
  * **Container** Тип контейнера с комнатами 


**Return**: 

  * Функция для расчёта
  * Функция-обработчик расчета стоимости


Расчет стоимости проживания в выбранной комнате


Шестая функция меню. Запрашивает количество ночей и выводит детализированный расчет с учетом особенностей конкретного типа комнаты. 


### function validate_room

```cpp
template <typename Container >
enable_if_t< is_same_v< typename Container::value_type, shared_ptr< Room > >, function< void()> > validate_room(
    Container & rooms
)
```

Проверка валидности комнаты 

**Parameters**: 

  * **rooms** Контейнер с комнатами 
  * **rooms** Контейнер с комнатами 


**Template Parameters**: 

  * **Container** Тип контейнера 
  * **Container** Тип контейнера с комнатами 


**Return**: 

  * Функция для проверки
  * Функция-обработчик проверки валидности


Проверка валидности параметров комнаты


Седьмая функция меню. Проверяет соблюдение бизнес-правил для выбранной комнаты:

* Для [StandardRoom](Classes/class_standard_room.md): количество кроватей >= 1
* Для [Suite](Classes/class_suite.md): общая стоимость >= 10000
* Для [FamilyRoom](Classes/class_family_room.md): детских кроватей <= 4 


### function additional_room_methods

```cpp
template <typename Container >
enable_if_t< is_same_v< typename Container::value_type, shared_ptr< Room > >, function< void()> > additional_room_methods(
    Container & rooms
)
```

Дополнительные методы комнат 

**Parameters**: 

  * **rooms** Контейнер с комнатами 
  * **rooms** Контейнер с комнатами 


**Template Parameters**: 

  * **Container** Тип контейнера 
  * **Container** Тип контейнера с комнатами 


**Return**: 

  * Функция для работы с доп. методами
  * Функция-обработчик дополнительных операций


Дополнительные специфичные операции с комнатами


Восьмая функция меню. Предоставляет доступ к уникальным функциям каждого типа комнат:

* [StandardRoom](Classes/class_standard_room.md): добавление кровати (+20% к цене)
* [Suite](Classes/class_suite.md): заказ шампанского (+2000 к цене)
* [FamilyRoom](Classes/class_family_room.md): активация игровой зоны (+1500 к цене) 


### function get_room_from_rooms_map

```cpp
template <typename Container >
enable_if_t< is_same_v< typename Container::value_type, shared_ptr< Room > >, shared_ptr< Room > > get_room_from_rooms_map(
    string main_label,
    string message,
    Container & rooms
)
```

Выбор комнаты из списка 

**Parameters**: 

  * **main_label** Заголовок меню 
  * **message** Приглашение для ввода 
  * **rooms** Контейнер с комнатами 
  * **main_label** Заголовок меню выбора 
  * **message** Приглашение для ввода 
  * **rooms** Контейнер с комнатами 


**Template Parameters**: 

  * **Container** Тип контейнера 
  * **Container** Тип контейнера с комнатами 


**Return**: 

  * Указатель на выбранную комнату
  * Указатель на выбранную комнату или nullptr при отмене


Выбор комнаты из списка с нумерацией


Отображает пронумерованный список всех комнат и возвращает выбранный вариант 


### function get_room_numbers

```cpp
template <typename Container >
enable_if_t< is_same_v< typename Container::value_type, shared_ptr< Room > >, vector< int > > get_room_numbers(
    const Container & rooms
)
```

Получение списка номеров комнат 

**Parameters**: 

  * **rooms** Контейнер с комнатами 
  * **rooms** Контейнер с комнатами 


**Template Parameters**: 

  * **Container** Тип контейнера 
  * **Container** Тип контейнера с комнатами 


**Return**: 

  * Вектор номеров комнат
  * Вектор номеров комнат 


Получение списка номеров всех комнат


### function room_in_rooms_by_room_number

```cpp
template <typename RoomType ,
typename Container >
enable_if_t< is_base_of_v< Room, typename RoomType > &&is_same_v< typename Container::value_type, shared_ptr< Room > >, bool > room_in_rooms_by_room_number(
    RoomType room,
    const Container & rooms
)
```

Проверка существования комнаты 

**Parameters**: 

  * **room** Проверяемая комната 
  * **rooms** Контейнер для проверки 
  * **room** Комната для проверки 
  * **rooms** Контейнер с комнатами 


**Template Parameters**: 

  * **RoomType** Тип комнаты 
  * **Container** Тип контейнера 
  * **RoomType** Тип комнаты 
  * **Container** Тип контейнера с комнатами 


**Return**: 

  * true если комната существует
  * true если комната с таким номером уже существует 


Проверка существования комнаты с указанным номером


< Получение списка номеров комнат






-------------------------------

Updated on 2025-05-06 at 23:16:47 +0300