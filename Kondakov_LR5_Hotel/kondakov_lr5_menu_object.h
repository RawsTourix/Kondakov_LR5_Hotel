/**
 * @file kondakov_lr5_menu_object.h
 * @brief Заголовочный файл класса MenuObject
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup menu_system
 */

#ifndef KONDAKOV_LR5_MENU_OBJECT_H
#define KONDAKOV_LR5_MENU_OBJECT_H

/**
 * @defgroup menu_system Система меню
 * @brief Создание и взаимодействие с меню
 * @{
 */

#include "kondakov_lr5_serializer.h"

/**
 * @class MenuObject
 * @brief Класс для представления пункта меню
 * @details Реализует древовидную структуру меню с поддержкой подменю и действий
 */
class MenuObject {
private:
    int number;                     ///< Номер пункта меню
    string label;                   ///< Название пункта меню
    function<void()> action;        ///< Действие при выборе пункта
    vector<MenuObject> submenu {};  ///< Вектор подменю
    bool one_off_menu_inclusion;    ///< Флаг одноразового меню (управляет отступами)

public:
    /**
     * @brief Удаленный конструктор по умолчанию
     */
    MenuObject() = delete;

    /// @name Конструкторы
    /// @{
    /**
     * @brief Конструктор пункта меню без подменю
     * @param number Номер пункта
     * @param label Название пункта
     * @param action Действие при выборе
     */
    MenuObject(int number, string label, function<void()> action);

    /**
     * @brief Конструктор с флагом одноразового меню
     * @param number Номер пункта
     * @param label Название пункта
     * @param action Действие при выборе
     * @param one_off_menu_inclusion Флаг одноразового меню
     */
    MenuObject(int number, string label, function<void()> action, bool one_off_menu_inclusion);

    /**
     * @brief Конструктор с подменю
     * @param number Номер пункта
     * @param label Название пункта
     * @param submenu Вектор подменю
     */
    MenuObject(int number, string label, vector<MenuObject> submenu);

    /**
     * @brief Конструктор с подменю и флагом
     * @param number Номер пункта
     * @param label Название пункта
     * @param submenu Вектор подменю
     * @param one_off_menu_inclusion Флаг одноразового меню
     */
    MenuObject(int number, string label, vector<MenuObject> submenu, bool one_off_menu_inclusion);

    /**
     * @brief Конструктор с действием и подменю
     * @param number Номер пункта
     * @param label Название пункта
     * @param action Действие при выборе
     * @param submenu Вектор подменю
     */
    MenuObject(int number, string label, function<void()> action, vector<MenuObject> submenu);

    /**
     * @brief Полный конструктор
     * @param number Номер пункта
     * @param label Название пункта
     * @param action Действие при выборе
     * @param submenu Вектор подменю
     * @param one_off_menu_inclusion Флаг одноразового меню
     */
    MenuObject(int number, string label, function<void()> action, 
               vector<MenuObject> submenu, bool one_off_menu_inclusion);

    /**
     * @brief Конструктор для комнаты с подтверждением
     * @tparam RoomPtr Тип умного указателя на Room
     * @tparam Action Тип действия (должен возвращать bool)
     * @param number Номер пункта
     * @param label Название пункта
     * @param room Указатель на комнату
     * @param action Действие с подтверждением
     * @param main_message Сообщение перед действием
     * @param success_message Сообщение после успеха
     */
    template <typename RoomPtr, typename Action,
        typename = enable_if_t<is_base_of_v<Room, typename RoomPtr::element_type> &&
                               is_same_v<bool, decltype(declval<Action>()())>, void>>
    MenuObject(int number, string label, RoomPtr room, Action action,
               string main_message, string success_message);

    /// Конструктор копирования
    MenuObject(const MenuObject&) = default;
    MenuObject& operator=(const MenuObject&) = default;

    /// Конструктор перемещения
    MenuObject(MenuObject&&) noexcept;
    MenuObject& operator=(MenuObject&&) = default;
    /// @}

    ~MenuObject() = default;  ///< Деструктор

    /// @name Методы работы с меню
    /// @{
    inline void show(const string& indentation = "") const;
    inline void act() const;
    inline string get_label() const;
    inline int get_number() const;
    inline string get_full_name() const;
    inline const vector<MenuObject>& get_submenu() const;
    inline bool get_one_off_menu_inclusion() const;
    /// @}

    /// @name Статические методы
    /// @{
    template <typename Container>
    static enable_if_t<is_same_v<typename Container::value_type, MenuObject>, void>
    show_menu(const Container& menu, int indent);

    template <typename Container>
    static enable_if_t<is_same_v<typename Container::value_type, MenuObject>, void>
    process(const Container& menu, const string main_label = "", 
            const string exit_label = "", int indent = 0, bool one_off = false);
    /// @}
};

#include "kondakov_lr5_menu_object.hpp"

/** @} */ // Конец группы input_control

#endif // KONDAKOV_LR5_MENU_OBJECT_H