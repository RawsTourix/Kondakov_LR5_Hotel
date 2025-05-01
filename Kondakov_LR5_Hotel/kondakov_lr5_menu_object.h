#ifndef KONDAKOV_LR5_MENU_OBJECT_H
#define KONDAKOV_LR5_MENU_OBJECT_H

#include "kondakov_lr5_standard_room.h"
#include "kondakov_lr5_suite.h"
#include "kondakov_lr5_family_room.h"

class MenuObject {
private:
    // Структура меню
    int number;                     // Номер пункта
    string label;                   // Название пункта
    function<void()> action;        // Событие при выборе пункта
    vector<MenuObject> submenu {};  // Подменю
    bool one_off_menu_inclusion;    // Включение динамического одноразового меню (опционально: влияет только на отступ после меню)
    /* Динамическое одноразовое меню запускается отдельно, а не в основном меню, поэтому при выходе из него (выброре пункта "0. Назад")
       выполняется отступ в самом динамическом меню, а после выхода из него и в основном меню. Для избежания этого в MenuObject::process
       была введена переменная one_off — одноразовае выполнение — которая убирает лишние отступы в самом динамическом меню. Но так как
       динамическое меню вызывается из основного — в основном меню тоже нужно убрать лишние отступы. Из динамического меню нет доступа к
       основному, так как динамическое запущено в основном. Тут и была введена переменная one_off_menu_inclusion, которая даёт понять
       функции MenuObject::process, что из этого пункта меню будет вызываться одноразовое динамическое меню, и MenuObject::process
       уменьшает отступ после работы с этим пунктом меню. */

public:
    // Конструктор по умолчанию
    MenuObject() = delete;

    // Конструктор с параметрами без подменю без one_off_menu_inclusion
    MenuObject(int number,
        string label,
        function<void()> action);

    // Конструктор с параметрами без подменю с one_off_menu_inclusion
    MenuObject(int number,
        string label,
        function<void()> action,
        bool one_off_menu_inclusion);

    // Конструктор с параметрами с подменю без one_off_menu_inclusion
    MenuObject(int number,
        string label,
        vector<MenuObject> submenu);

    // Конструктор с параметрами с подменю с one_off_menu_inclusion
    MenuObject(int number,
        string label,
        vector<MenuObject> submenu,
        bool one_off_menu_inclusion);

    // Конструктор с параметрами без one_off_menu_inclusion
    MenuObject(int number,
        string label,
        function<void()> action,
        vector<MenuObject> submenu);

    // Конструктор с параметрами полный
    MenuObject(int number,
        string label,
        function<void()> action,
        vector<MenuObject> submenu,
        bool one_off_menu_inclusion);

    // Конструктор пункта меню для конкретной комнаты с подтверждением выполнения операции
    template <typename RoomPtr, typename Action,
        typename = enable_if_t<is_base_of_v<Room, typename RoomPtr::element_type> &&
                               is_same_v<bool, decltype(declval<Action>()())>, void>>
    MenuObject(int number,
        string label,
        RoomPtr room,
        Action action,
        string main_message,
        string success_message);

    // Конструктор копирования
    MenuObject(const MenuObject&) = default;
    MenuObject& operator=(const MenuObject&) = default;

    // Конструктор пепремещения
    MenuObject(MenuObject&& menu_object) noexcept;
    MenuObject& operator=(MenuObject&&) = default;

    // Деструктор
    ~MenuObject() = default;

    // Вывод пункта меню
    inline void show(const string& indentation = "") const;

    // Выполнить функцию
    inline void act() const;

    // Геттер названия пункта
    inline string get_label() const;

    // Геттер номера пункта
    inline int get_number() const;

    // Геттер полного названия пункта
    inline string get_full_name() const;

    // Геттер подменю
    inline const vector<MenuObject>& get_submenu() const;

    // Геттер отступа после меню
    inline bool get_one_off_menu_inclusion() const;

    // Вывод меню
    template <typename Container>
    static enable_if_t<is_same_v<typename Container::value_type, MenuObject>, void>
    show_menu(const Container& menu, int indent);

    // Обработка взаимодействия с меню
    template <typename Container>
    static enable_if_t<is_same_v<typename Container::value_type, MenuObject>, void>
    process(const Container& menu, const string main_label = "", const string exit_label = "", int indent = 0, bool one_off = false);
};

#include "kondakov_lr5_menu_object.hpp"

#endif // KONDAKOV_LR5_MENU_OBJECT_H