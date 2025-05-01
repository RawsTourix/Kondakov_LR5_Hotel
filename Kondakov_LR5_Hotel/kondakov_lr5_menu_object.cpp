#include "kondakov_lr5_menu_object.h"

// ����������� � ����������� ��� ������� ��� one_off_menu_inclusion
MenuObject::MenuObject(int number,
    string label,
    function<void()> action)
    : MenuObject(number, label, action, {}, false) {
}

// ����������� � ����������� ��� ������� � one_off_menu_inclusion
MenuObject::MenuObject(int number,
    string label,
    function<void()> action,
    bool one_off_menu_inclusion)
    : MenuObject(number, label, action, {}, one_off_menu_inclusion) {
}

// ����������� � ����������� � ������� ��� one_off_menu_inclusion
MenuObject::MenuObject(int number,
    string label,
    vector<MenuObject> submenu)
    : MenuObject(number, label, nullptr, submenu, false) {
}

// ����������� � ����������� � ������� � one_off_menu_inclusion
MenuObject::MenuObject(int number,
    string label,
    vector<MenuObject> submenu,
    bool one_off_menu_inclusion)
    : MenuObject(number, label, nullptr, submenu, one_off_menu_inclusion) {
}

// ����������� � ����������� ��� one_off_menu_inclusion
MenuObject::MenuObject(int number,
    string label,
    function<void()> action,
    vector<MenuObject> submenu)
    : MenuObject(number, label, action, submenu, false) {
}

// ����������� � ����������� ������
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

// ����������� �����������
MenuObject::MenuObject(MenuObject&& other) noexcept
    : number(exchange(other.number, 0)),
    label(move(other.label)),
    action(move(other.action)),
    submenu(move(other.submenu)),
    one_off_menu_inclusion(other.one_off_menu_inclusion) {
}