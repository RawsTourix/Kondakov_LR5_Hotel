/**
 * @file kondakov_lr5_menu_object.cpp
 * @brief Реализация конструкторов класса MenuObject
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup menu_system
 */

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

/**
 * @brief Полный конструктор
 * @details Инициализирует все поля класса
 */
MenuObject::MenuObject(int number, string label, function<void()> action,
                       vector<MenuObject> submenu, bool one_off_menu_inclusion)
    : number(number), label(label), action(action),
      submenu(submenu), one_off_menu_inclusion(one_off_menu_inclusion) {}

/**
 * @brief Конструктор перемещения
 * @details Эффективно переносит ресурсы из другого объекта
 */
MenuObject::MenuObject(MenuObject&& other) noexcept
    : number(exchange(other.number, 0)),
      label(move(other.label)),
      action(move(other.action)),
      submenu(move(other.submenu)),
      one_off_menu_inclusion(other.one_off_menu_inclusion) {}