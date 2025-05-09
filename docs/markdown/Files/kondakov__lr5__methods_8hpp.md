---
title: Kondakov_LR5_Hotel/kondakov_lr5_methods.hpp
summary: Реализация методов работы с комнатами 

---

# Kondakov_LR5_Hotel/kondakov_lr5_methods.hpp

Реализация методов работы с комнатами  [More...](#detailed-description)

## Functions

|                | Name           |
| -------------- | -------------- |
| template <typename RoomPtr ,typename Container \> <br>enable_if_t< is_base_of_v< [Room](Classes/class_room.md), typename RoomPtr::element_type > &&is_same_v< typename Container::value_type, shared_ptr< [Room](Classes/class_room.md) > >, vector< function< bool()> > > | **[get_room_edit_methods](Files/kondakov__lr5__methods_8hpp.md#function-get-room-edit-methods)**(RoomPtr room, const Container & rooms)<br>Получение методов редактирования комнаты  |
| template <typename RoomPtr ,typename Container \> <br>enable_if_t< is_base_of_v< [Room](Classes/class_room.md), typename RoomPtr::element_type > &&is_same_v< typename Container::value_type, shared_ptr< [Room](Classes/class_room.md) > >, void > | **[add_edit_menu_items](Files/kondakov__lr5__methods_8hpp.md#function-add-edit-menu-items)**(vector< [MenuObject](Classes/class_menu_object.md) > & menu, RoomPtr room, const Container & rooms)<br>Добавление пунктов меню для редактирования комнаты  |

## Detailed Description

Реализация методов работы с комнатами 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 

## Functions Documentation

### function get_room_edit_methods

```cpp
template <typename RoomPtr ,
typename Container >
enable_if_t< is_base_of_v< Room, typename RoomPtr::element_type > &&is_same_v< typename Container::value_type, shared_ptr< Room > >, vector< function< bool()> > > get_room_edit_methods(
    RoomPtr room,
    const Container & rooms
)
```

Получение методов редактирования комнаты 

**Parameters**: 

  * **room** Комната для редактирования 
  * **rooms** Контейнер с комнатами 


**Template Parameters**: 

  * **RoomPtr** Тип указателя на комнату 
  * **Container** Тип контейнера с комнатами 


**Return**: Вектор функций редактирования 

### function add_edit_menu_items

```cpp
template <typename RoomPtr ,
typename Container >
enable_if_t< is_base_of_v< Room, typename RoomPtr::element_type > &&is_same_v< typename Container::value_type, shared_ptr< Room > >, void > add_edit_menu_items(
    vector< MenuObject > & menu,
    RoomPtr room,
    const Container & rooms
)
```

Добавление пунктов меню для редактирования комнаты 

**Parameters**: 

  * **menu** Вектор меню для заполнения 
  * **room** Комната для редактирования 
  * **rooms** Контейнер с комнатами 


**Template Parameters**: 

  * **RoomPtr** Тип указателя на комнату 
  * **Container** Тип контейнера с комнатами 




## Source code

```cpp


#ifndef KONDAKOV_LR5_METHODS_HPP
#define KONDAKOV_LR5_METHODS_HPP

#include "kondakov_lr5_methods.h"

Methods::RoomInfo::RoomInfo(int number, string full_name, shared_ptr<Room> room) :
    number(number), full_name(full_name), room(room) {
}

ostream& Methods::operator<<(ostream& os, const RoomInfo& ri) {
    os << ri.number << ". " << ri.full_name;
    return os;
}

template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
Methods::show_rooms(const Container& rooms) {
    return [&rooms]() {
        cout << rooms << "Список комнат успешно выведен.";  // Вывод контейнера комнат с помощью перегрузки << из Room
    };
}

template <typename RoomPtr, typename Container>
typename enable_if_t<is_base_of_v<Room, typename RoomPtr::element_type>&&
                     is_same_v<typename Container::value_type, shared_ptr<Room>>, vector<function<bool()>>>
get_room_edit_methods(RoomPtr room, const Container& rooms) {
    // Получение списка номеров комнат
    vector<int> room_numbers(Methods::get_room_numbers(rooms));

    // Составление вектора функций для изменения комнаты
    vector<function<bool()>> room_edit_methods{};

    room_edit_methods.push_back([room, room_numbers]() -> bool {
        // Ввод номера комнаты с проверкой на уникальность
        return room->input_room_number(room_numbers);
    });
    room_edit_methods.push_back([room]() -> bool { return room->input_price_per_night(); });
    room_edit_methods.push_back([room]() -> bool { return room->input_is_booked(); });

    if (auto sr = dynamic_pointer_cast<StandardRoom>(room)) {
        room_edit_methods.push_back([sr]() -> bool { return sr->input_bed_count(); });
        room_edit_methods.push_back([sr]() -> bool { return sr->input_has_tv(); });
        room_edit_methods.push_back([sr]() -> bool { return sr->input_amenities<','>(); });
    }
    else if (auto s = dynamic_pointer_cast<Suite>(room)) {
        room_edit_methods.push_back([s]() -> bool { return s->input_room_service(); });
        room_edit_methods.push_back([s]() -> bool { return s->input_jacuzzi(); });
        room_edit_methods.push_back([s]() -> bool { return s->input_amenities<','>(); });
    }
    else if (auto fr = dynamic_pointer_cast<FamilyRoom>(room)) {
        room_edit_methods.push_back([fr]() -> bool { return fr->input_child_care_price(); });
        room_edit_methods.push_back([fr]() -> bool { return fr->input_has_child_care(); });
        room_edit_methods.push_back([fr]() -> bool { return fr->input_child_beds(); });
        room_edit_methods.push_back([fr]() -> bool { return fr->input_toy_kit(); });
        room_edit_methods.push_back([fr]() -> bool { return fr->input_amenities<','>(); });
    }

    return room_edit_methods;
}

template <typename RoomType, typename Container>
typename enable_if_t<is_base_of_v<Room, typename RoomType> &&
                     is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
Methods::add_room(Container& rooms) {
    return [&rooms]() {
        // Создание комнаты по умолчанию
        shared_ptr<RoomType> room = make_shared<RoomType>();

        // Получение методов для изменения комнаты
        vector<function<bool()>> edit_methods(get_room_edit_methods(room, rooms));

        // Вывод типа комнаты
        cout << "[" << room->get_room_type() << "]" << endl << endl;

        // Изменение параметров комнаты
        for (const auto& action : edit_methods) {
            if (action()) { return; }
        }

        cout << endl;
        room->print();
        rooms.push_back(move(room));
        cout << "Комната успешно добавлена.";
    };
}

template <typename RoomPtr, typename Container>
typename enable_if_t<is_base_of_v<Room, typename RoomPtr::element_type> &&
                     is_same_v<typename Container::value_type, shared_ptr<Room>>, void>
add_edit_menu_items(vector<MenuObject>& menu, RoomPtr room, const Container& rooms) {
    // Получение методов для изменения комнаты
    vector<function<bool()>> edit_methods(get_room_edit_methods(room, rooms));

    // Общие пункты для всех комнат
    menu.emplace_back(
        1, "Изменить номер комнаты;",
        room,
        edit_methods.at(0),
        "Изменение номера комнаты.",
        "Номер комнаты успешно изменён."
    );
    menu.emplace_back(
        2, "Изменить цену за ночь;",
        room,
        edit_methods.at(1),
        "Изменение цены за ночь.",
        "Цена за ночь успешно изменена."
    );
    menu.emplace_back(
        3, "Изменить статус бронирования;",
        room,
        edit_methods.at(2),
        "Изменение статуса бронирования.",
        "Статус бронирования успешно изменён."
    );

    if (auto sr = dynamic_pointer_cast<StandardRoom>(room)) {
        menu.emplace_back(
            4, "Изменить количество кроватей;",
            sr,
            edit_methods.at(3),
            "Изменение количества кроватей.",
            "Количество кроватей успешно изменено."
        );
        menu.emplace_back(
            5, "Изменить наличие телевизора;",
            sr,
            edit_methods.at(4),
            "Изменение наличия телевизора.",
            "Наличие телевизора успешно изменено."
        );
        menu.emplace_back(
            6, "Изменить удобства;",
            sr,
            edit_methods.at(5),
            "Изменение удобств.",
            "Удобства успешно изменены."
        );
    }
    else if (auto s = dynamic_pointer_cast<Suite>(room)) {
        menu.emplace_back(
            4, "Изменить наличие обслуживания;",
            s,
            edit_methods.at(3),
            "Изменение наличия обслуживания.",
            "Наличие обслуживания успешно изменено."
        );
        menu.emplace_back(
            5, "Изменить наличие джакузи;",
            s,
            edit_methods.at(4),
            "Изменение наличия джакузи.",
            "Наличие джакузи успешно изменено."
        );
        menu.emplace_back(
            6, "Изменить удобства;",
            s,
            edit_methods.at(5),
            "Изменение удобств.",
            "Удобства успешно изменены."
        );
    }
    else if (auto fr = dynamic_pointer_cast<FamilyRoom>(room)) {
        menu.emplace_back(
            4, "Изменить стоимость услуг для детей;",
            fr,
            edit_methods.at(3),
            "Изменение стоимости услуг для детей.",
            "Стоимость услуг для детей успешно изменена."
        );
        menu.emplace_back(
            5, "Изменить наличие услуг для детей;",
            fr,
            edit_methods.at(4),
            "Изменение наличия услуг для детей.",
            "Наличие услуг для детей успешно изменено."
        );
        menu.emplace_back(
            6, "Изменить количество детских кроватей;",
            fr,
            edit_methods.at(5),
            "Изменение количества детских кроватей.",
            "Количество детских кроватей успешно изменено."
        );
        menu.emplace_back(
            7, "Изменить наличие набора детских игрушек;",
            fr,
            edit_methods.at(6),
            "Изменение наличия набора детских игрушек.",
            "Наличие набора детских игрушек успешно изменено."
        );
        menu.emplace_back(
            8, "Изменить удобства;",
            fr,
            edit_methods.at(7),
            "Изменение удобств.",
            "Удобства успешно изменены."
        );
    }
}

template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
Methods::edit_room(Container& rooms) {
    return [&rooms]() {
        // Получение комнаты из списка
        shared_ptr<Room> room = get_room_from_rooms_map("Изменение комнаты:", "Пункт меню: ", rooms);
        if (room == nullptr) { return; }

        // Создание динамического меню для конкретной комнаты
        vector<MenuObject> edit_room_menu {};

        if (auto sr = dynamic_pointer_cast<StandardRoom>(room)) {
            add_edit_menu_items(edit_room_menu, sr, rooms);
            MenuObject::process(edit_room_menu, sr->to_string(), "Назад.", 0, true);
        }
        else if (auto s = dynamic_pointer_cast<Suite>(room)) {
            add_edit_menu_items(edit_room_menu, s, rooms);
            MenuObject::process(edit_room_menu, s->to_string(), "Назад.", 0, true);
        }
        else if (auto fr = dynamic_pointer_cast<FamilyRoom>(room)) {
            add_edit_menu_items(edit_room_menu, fr, rooms);
            MenuObject::process(edit_room_menu, fr->to_string(), "Назад.", 0, true);
        }
    };
}

template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
Methods::delete_room(Container& rooms) {
    return [&rooms]() {
        // Получение комнаты из списка
        shared_ptr<Room> room = get_room_from_rooms_map("Удаление комнаты:", "Пункт меню: ", rooms);
        if (room == nullptr) { return; }

        // Подтверждение операции и удаление или рекурсивный возврат к меню
        ostringstream message;
        message << "Вы точно хотите удалить [" << room->get_full_name() << "]?";
        if (InputControl::yes_or_no(message.str())) {

            auto it = remove_if(rooms.begin(), rooms.end(), [&room](shared_ptr<Room> r) { return room->get_room_number() == r->get_room_number(); });

            if (it == rooms.end()) {
                cout << "Комнаты с таким номером нет в списке.";
            }
            else {
                rooms.erase(it, rooms.end());
                cout << "Комната успешно удалена.";
            }
        }
        else {
            cout << "[Отмена операции]";
        }

        cout << endl;
    };
}

template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
Methods::sort_rooms(Container& rooms) {
    return [&rooms]() {
        // Создание меню для сортировки
        vector<MenuObject> sort_menu {
            { 1, "Отсортировать по номеру комнаты;",
                [&rooms]() {
                    vector<MenuObject> sort_by_room_number_menu {
                        { 1, "По возрастанию;", [&rooms]() {
                                sort(rooms.begin(), rooms.end(), [](shared_ptr<Room> r1, shared_ptr<Room> r2) {
                                    return *r1 < *r2; }
                                );
                                cout << endl << endl << "Список комнат успешно отсортирован по возрастанию номеров комнат." << endl;
                            }
                        },
                        { 2, "По убыванию;", [&rooms]() {
                                sort(rooms.begin(), rooms.end(), [](shared_ptr<Room> r1, shared_ptr<Room> r2) {
                                    return *r1 > *r2; }
                                );
                                cout << endl << endl << "Список комнат успешно отсортирован по убыванию номеров комнат." << endl;
                            }
                        }
                    };

                    MenuObject::process(sort_by_room_number_menu, "\n\nОтсортировать по номеру комнаты:", "Назад.", 0, true);
                }
            },
            { 2, "Отсортировать по типу комнаты;",
                [&rooms]() {
                    vector<MenuObject> sort_by_room_type_menu {
                        { 1, "По возрастанию;", [&rooms]() {
                                sort(rooms.begin(), rooms.end(), [](shared_ptr<Room> r1, shared_ptr<Room> r2) {
                                    return make_tuple(r1->get_room_type(), r1->get_room_number()) <
                                        make_tuple(r2->get_room_type(), r2->get_room_number()); }
                                );
                                cout << endl << endl << "Список комнат успешно отсортирован по возрастанию типов комнат." << endl;
                            }
                        },
                        { 2, "По убыванию;", [&rooms]() {
                                sort(rooms.begin(), rooms.end(), [](shared_ptr<Room> r1, shared_ptr<Room> r2) {
                                    return make_tuple(r1->get_room_type(), r1->get_room_number()) >
                                        make_tuple(r2->get_room_type(), r2->get_room_number()); }
                                );
                                cout << endl << endl << "Список комнат успешно отсортирован по убыванию типов комнат." << endl;
                            }
                        },
                    };

                    MenuObject::process(sort_by_room_type_menu, "\n\nОтсортировать по типу комнаты:", "Назад.", 0, true);
                }
            },
            { 3, "Отсортировать по цене за ночь;",
                [&rooms]() {
                    vector<MenuObject> sort_by_price_per_night_menu {
                        { 1, "По возрастанию;", [&rooms]() {
                                sort(rooms.begin(), rooms.end(), [](shared_ptr<Room> r1, shared_ptr<Room> r2) {
                                    return make_tuple(r1->get_price_per_night(), r1->get_room_number()) <
                                        make_tuple(r2->get_price_per_night(), r2->get_room_number()); }
                                );
                                cout << endl << endl << "Список комнат успешно отсортирован по возрастанию цен за ночь." << endl;
                            }
                        },
                        { 2, "По убыванию;", [&rooms]() {
                                sort(rooms.begin(), rooms.end(), [](shared_ptr<Room> r1, shared_ptr<Room> r2) {
                                    return make_tuple(r1->get_price_per_night(), r1->get_room_number()) >
                                        make_tuple(r2->get_price_per_night(), r2->get_room_number()); }
                                );
                                cout << endl << endl << "Список комнат успешно отсортирован по убыванию цен за ночь." << endl;
                            }
                        },
                    };

                    MenuObject::process(sort_by_price_per_night_menu, "\n\nОтсортировать по цене за ночь:", "Назад.", 0, true);
                }
            },
            { 4, "Отсортировать по статусу бронирования;",
                [&rooms]() {
                    vector<MenuObject> sort_by_is_booked_menu {
                        { 1, "По возрастанию;", [&rooms]() {
                                sort(rooms.begin(), rooms.end(), [](shared_ptr<Room> r1, shared_ptr<Room> r2) {
                                    return make_tuple(r1->get_is_booked(), r1->get_room_number()) <
                                        make_tuple(r2->get_is_booked(), r2->get_room_number()); }
                                );
                                cout << endl << endl << "Список комнат успешно отсортирован по возрастанию статусов бронирования." << endl;
                            }
                        },
                        { 2, "По убыванию;", [&rooms]() {
                                sort(rooms.begin(), rooms.end(), [](shared_ptr<Room> r1, shared_ptr<Room> r2) {
                                    return make_tuple(r1->get_is_booked(), r1->get_room_number()) >
                                        make_tuple(r2->get_is_booked(), r2->get_room_number()); }
                                );
                                cout << endl << endl << "Список комнат успешно отсортирован по убыванию статусов бронирования." << endl;
                            }
                        },
                    };

                    MenuObject::process(sort_by_is_booked_menu, "\n\nОтсортировать по статусу бронирования:", "Назад.", 0, true);
                }
            }
        };

        // Обработка одноразового меню для сортировки списка комнат
        MenuObject::process(sort_menu, "Отсортировать список комнат:", "Назад.", 0, true);
    };
}

template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
Methods::calculate_total(Container& rooms) {
    return [&rooms]() {
        // Получение комнаты из списка
        shared_ptr<Room> room = get_room_from_rooms_map("Рассчитать стоимость проживания:", "Пункт меню: ", rooms);
        if (room == nullptr) { return; }

        // Ввод количества ночей и вычисление стоимости проживания
        int night_count;
        if (InputControl::input(night_count, "Количество ночей: ", 1, 365)) { return; }
        cout << endl << endl << 
            "Стоимость проживания в [" << room->get_full_name() << "]." << endl << endl <<
            "Количество ночей: " << night_count << endl << endl <<
            "Стоимость: " << room->calculate_total(night_count) << " " << Room::CURRENCY;
    };
}

template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
Methods::validate_room(Container& rooms) {
    return [&rooms]() {
        // Получение комнаты из списка
        shared_ptr<Room> room = get_room_from_rooms_map("Проверить комнату на валидность:", "Пункт меню: ", rooms);
        if (room == nullptr) { return; }

        cout << "[" << room->get_full_name() << "] — " << (room->validate() ? "" : "не") << "валидна.";
    };
}

template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
Methods::additional_room_methods(Container& rooms) {
    return [&rooms]() {
        // Получение комнаты из списка
        shared_ptr<Room> room = get_room_from_rooms_map("Дополнительные методы комнат:", "Пункт меню: ", rooms);
        if (room == nullptr) { return; }

        // Различные методы комнат
        vector<MenuObject> edit_room_menu{};
        if (room->get_room_type() == "Стандартная комната") {
            shared_ptr<StandardRoom> sr = dynamic_pointer_cast<StandardRoom>(room);

            cout << "Добавление дополнительной кровати (+20% к стоимости)." << endl << endl;

            cout << "Текущее количество кроватей: " << sr->get_bed_count() << endl << endl;
            cout << "Текущая стоимость за ночь: " << sr->get_price_per_night() << " " << Room::CURRENCY << endl << endl;

            if (InputControl::yes_or_no("Добавить кровать?")) {
                sr->exstra_bed();
                cout << "Кровать добавлена." << endl << endl;

                cout << "Изменившееся количество кроватей: " << sr->get_bed_count() << endl << endl;
                cout << "Изменившаяся стоимость за ночь: " << sr->get_price_per_night() << " " << Room::CURRENCY;
            }
            else {
                cout << "[Отмена операции]";
            }
        }
        else if (room->get_room_type() == "Люкс комната") {
            shared_ptr<Suite> s = dynamic_pointer_cast<Suite>(room);

            cout << "Добавление услуги (+2000 руб. к стоимости)." << endl << endl;

            cout << "Текущие услуги: " << s->get_amenities() << endl << endl;
            cout << "Текущая стоимость за ночь: " << s->get_price_per_night() << " " << Room::CURRENCY << endl << endl;

            if (InputControl::yes_or_no("Добавить услугу?")) {
                string amenity;
                if (InputControl::input(amenity, "Услуга: ")) { return; }
                s->order_champagne(amenity);
                cout << endl << "Услуга добавлена." << endl << endl;

                cout << "Изменившиеся услуги: " << s->get_amenities() << endl << endl;
                cout << "Изменившаяся стоимость за ночь: " << s->get_price_per_night() << " " << Room::CURRENCY;
            }
            else {
                cout << "[Отмена операции]";
            }
        }
        else if (room->get_room_type() == "Семейная комната") {
            shared_ptr<FamilyRoom> fr = dynamic_pointer_cast<FamilyRoom>(room);

            cout << "Активация/деактивация игровой зоны (+/- 1500 руб.)." << endl << endl;

            cout << "Текущая стоимость за ночь: " <<fr->get_price_per_night() << " " << Room::CURRENCY << endl << endl;

            if (InputControl::yes_or_no(fr->get_toy_kit() ? "Игровая зона активирована. Деакивировать?" :
                "Игровая зона не активирована. Акивировать?"))
            {
                fr->add_play_area();
            }
            else {
                cout << "[Отмена операции]"; return;
            }

            cout << "Игровая зона " << (fr->get_toy_kit() ? "" : "де") << "активирована." << endl << endl;
            cout << "Изменившаяся стоимость за ночь: " << fr->get_price_per_night() << " " << Room::CURRENCY;
        }
    };
}


/* Вспомогательные методы */

template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, shared_ptr<Room>>
Methods::get_room_from_rooms_map(string main_label, string message, Container& rooms) {
    vector<RoomInfo> edit_room_info{};
    int key = 1;
    cout << main_label << endl << endl;
    for (const auto& room : rooms) {
        edit_room_info.emplace_back(key++, room->get_full_name(), room);
        edit_room_info.back().print();
    }
    edit_room_info.emplace_back(0, "Назад", nullptr);
    edit_room_info.back().print();
    cout << endl << endl;

    int room_choice = 0;
    if (InputControl::input(room_choice, message, 0, static_cast<int>(edit_room_info.size() - 1))) { cout << endl; return nullptr; }
    if (room_choice == 0) { return nullptr; }
    auto it = find_if(edit_room_info.begin(), edit_room_info.end(), [room_choice](RoomInfo ri) { return ri.number == room_choice; });
    if (it == edit_room_info.end()) {
        cout << endl << "Ошибка при выборе комнаты!";
        return nullptr;
    }
    cout << endl << endl;

    return it->room;
}

template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, vector<int>>
Methods::get_room_numbers(const Container& rooms) {
    vector<int> room_numbers {};
    for (const auto& room : rooms) {
        room_numbers.push_back(room->get_room_number());
    }
    return room_numbers;
}

template <typename RoomType, typename Container>
typename enable_if_t<is_base_of_v<Room, typename RoomType> &&
                     is_same_v<typename Container::value_type, shared_ptr<Room>>, bool>
Methods::room_in_rooms_by_room_number(RoomType room, const Container& rooms) {
    
    vector<int> room_numbers(get_room_numbers(rooms));  

    return find(room_numbers.begin(), room_numbers.end(), room.get_room_number()) != room_numbers.end();
}

#endif // KONDAKOV_LR5_METHODS_HPP
```


-------------------------------

Updated on 2025-05-09 at 18:16:45 +0300
