/**
 * @file kondakov_lr5_menu_object.h
 * @brief ������������ ���� ������ MenuObject
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup menu_system
 */

#ifndef KONDAKOV_LR5_MENU_OBJECT_H
#define KONDAKOV_LR5_MENU_OBJECT_H

/**
 * @defgroup menu_system ������� ����
 * @brief �������� � �������������� � ����
 * @{
 */

#include "kondakov_lr5_serializer.h"

/**
 * @class MenuObject
 * @brief ����� ��� ������������� ������ ����
 * @details ��������� ����������� ��������� ���� � ���������� ������� � ��������
 */
class MenuObject {
private:
    int number;                     ///< ����� ������ ����
    string label;                   ///< �������� ������ ����
    function<void()> action;        ///< �������� ��� ������ ������
    vector<MenuObject> submenu {};  ///< ������ �������
    bool one_off_menu_inclusion;    ///< ���� ������������ ���� (��������� ���������)

public:
    /**
     * @brief ��������� ����������� �� ���������
     */
    MenuObject() = delete;

    /// @name ������������
    /// @{
    /**
     * @brief ����������� ������ ���� ��� �������
     * @param number ����� ������
     * @param label �������� ������
     * @param action �������� ��� ������
     */
    MenuObject(int number, string label, function<void()> action);

    /**
     * @brief ����������� � ������ ������������ ����
     * @param number ����� ������
     * @param label �������� ������
     * @param action �������� ��� ������
     * @param one_off_menu_inclusion ���� ������������ ����
     */
    MenuObject(int number, string label, function<void()> action, bool one_off_menu_inclusion);

    /**
     * @brief ����������� � �������
     * @param number ����� ������
     * @param label �������� ������
     * @param submenu ������ �������
     */
    MenuObject(int number, string label, vector<MenuObject> submenu);

    /**
     * @brief ����������� � ������� � ������
     * @param number ����� ������
     * @param label �������� ������
     * @param submenu ������ �������
     * @param one_off_menu_inclusion ���� ������������ ����
     */
    MenuObject(int number, string label, vector<MenuObject> submenu, bool one_off_menu_inclusion);

    /**
     * @brief ����������� � ��������� � �������
     * @param number ����� ������
     * @param label �������� ������
     * @param action �������� ��� ������
     * @param submenu ������ �������
     */
    MenuObject(int number, string label, function<void()> action, vector<MenuObject> submenu);

    /**
     * @brief ������ �����������
     * @param number ����� ������
     * @param label �������� ������
     * @param action �������� ��� ������
     * @param submenu ������ �������
     * @param one_off_menu_inclusion ���� ������������ ����
     */
    MenuObject(int number, string label, function<void()> action, 
               vector<MenuObject> submenu, bool one_off_menu_inclusion);

    /**
     * @brief ����������� ��� ������� � ��������������
     * @tparam RoomPtr ��� ������ ��������� �� Room
     * @tparam Action ��� �������� (������ ���������� bool)
     * @param number ����� ������
     * @param label �������� ������
     * @param room ��������� �� �������
     * @param action �������� � ��������������
     * @param main_message ��������� ����� ���������
     * @param success_message ��������� ����� ������
     */
    template <typename RoomPtr, typename Action,
        typename = enable_if_t<is_base_of_v<Room, typename RoomPtr::element_type> &&
                               is_same_v<bool, decltype(declval<Action>()())>, void>>
    MenuObject(int number, string label, RoomPtr room, Action action,
               string main_message, string success_message);

    /// ����������� �����������
    MenuObject(const MenuObject&) = default;
    MenuObject& operator=(const MenuObject&) = default;

    /// ����������� �����������
    MenuObject(MenuObject&&) noexcept;
    MenuObject& operator=(MenuObject&&) = default;
    /// @}

    ~MenuObject() = default;  ///< ����������

    /// @name ������ ������ � ����
    /// @{
    inline void show(const string& indentation = "") const;
    inline void act() const;
    inline string get_label() const;
    inline int get_number() const;
    inline string get_full_name() const;
    inline const vector<MenuObject>& get_submenu() const;
    inline bool get_one_off_menu_inclusion() const;
    /// @}

    /// @name ����������� ������
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

/** @} */ // ����� ������ input_control

#endif // KONDAKOV_LR5_MENU_OBJECT_H