#include "kondakov_lr5_menu_object.h"

// Конструктор с параметрами без подменю без one_off_menu_inclusion
MenuObject::MenuObject(int number,
    string label,
    function<void()> action)
    : MenuObject(number, label, action, {}, false) {
}

// Конструктор с параметрами без подменю с one_off_menu_inclusion
MenuObject::MenuObject(int number,
    string label,
    function<void()> action,
    bool one_off_menu_inclusion)
    : MenuObject(number, label, action, {}, one_off_menu_inclusion) {
}

// Конструктор с параметрами с подменю без one_off_menu_inclusion
MenuObject::MenuObject(int number,
    string label,
    vector<MenuObject> submenu)
    : MenuObject(number, label, nullptr, submenu, false) {
}

// Конструктор с параметрами с подменю с one_off_menu_inclusion
MenuObject::MenuObject(int number,
    string label,
    vector<MenuObject> submenu,
    bool one_off_menu_inclusion)
    : MenuObject(number, label, nullptr, submenu, one_off_menu_inclusion) {
}

// Конструктор с параметрами без one_off_menu_inclusion
MenuObject::MenuObject(int number,
    string label,
    function<void()> action,
    vector<MenuObject> submenu)
    : MenuObject(number, label, action, submenu, false) {
}

// Конструктор с параметрами полный
MenuObject::MenuObject(int number,
    string label,
    function<void()> action,
    vector<MenuObject> submenu,
    bool one_off_menu_inclusion)
    : number(number),
    label(label),
    action(action),
    submenu(submenu),
    one_off_menu_inclusion(one_off_menu_inclusion) {
}

// Конструктор перемещения
MenuObject::MenuObject(MenuObject&& other) noexcept
    : number(exchange(other.number, 0)),
    label(move(other.label)),
    action(move(other.action)),
    submenu(move(other.submenu)),
    one_off_menu_inclusion(other.one_off_menu_inclusion) {
}