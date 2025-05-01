#ifndef KONDAKOV_LR5_MENU_OBJECT_H
#define KONDAKOV_LR5_MENU_OBJECT_H

#include "kondakov_lr5_standard_room.h"
#include "kondakov_lr5_suite.h"
#include "kondakov_lr5_family_room.h"

class MenuObject {
private:
    // ��������� ����
    int number;                     // ����� ������
    string label;                   // �������� ������
    function<void()> action;        // ������� ��� ������ ������
    vector<MenuObject> submenu {};  // �������
    bool one_off_menu_inclusion;    // ��������� ������������� ������������ ���� (�����������: ������ ������ �� ������ ����� ����)
    /* ������������ ����������� ���� ����������� ��������, � �� � �������� ����, ������� ��� ������ �� ���� (������� ������ "0. �����")
       ����������� ������ � ����� ������������ ����, � ����� ������ �� ���� � � �������� ����. ��� ��������� ����� � MenuObject::process
       ���� ������� ���������� one_off � ����������� ���������� � ������� ������� ������ ������� � ����� ������������ ����. �� ��� ���
       ������������ ���� ���������� �� ��������� � � �������� ���� ���� ����� ������ ������ �������. �� ������������� ���� ��� ������� �
       ���������, ��� ��� ������������ �������� � ��������. ��� � ���� ������� ���������� one_off_menu_inclusion, ������� ��� ������
       ������� MenuObject::process, ��� �� ����� ������ ���� ����� ���������� ����������� ������������ ����, � MenuObject::process
       ��������� ������ ����� ������ � ���� ������� ����. */

public:
    // ����������� �� ���������
    MenuObject() = delete;

    // ����������� � ����������� ��� ������� ��� one_off_menu_inclusion
    MenuObject(int number,
        string label,
        function<void()> action);

    // ����������� � ����������� ��� ������� � one_off_menu_inclusion
    MenuObject(int number,
        string label,
        function<void()> action,
        bool one_off_menu_inclusion);

    // ����������� � ����������� � ������� ��� one_off_menu_inclusion
    MenuObject(int number,
        string label,
        vector<MenuObject> submenu);

    // ����������� � ����������� � ������� � one_off_menu_inclusion
    MenuObject(int number,
        string label,
        vector<MenuObject> submenu,
        bool one_off_menu_inclusion);

    // ����������� � ����������� ��� one_off_menu_inclusion
    MenuObject(int number,
        string label,
        function<void()> action,
        vector<MenuObject> submenu);

    // ����������� � ����������� ������
    MenuObject(int number,
        string label,
        function<void()> action,
        vector<MenuObject> submenu,
        bool one_off_menu_inclusion);

    // ����������� ������ ���� ��� ���������� ������� � �������������� ���������� ��������
    template <typename RoomPtr, typename Action,
        typename = enable_if_t<is_base_of_v<Room, typename RoomPtr::element_type> &&
                               is_same_v<bool, decltype(declval<Action>()())>, void>>
    MenuObject(int number,
        string label,
        RoomPtr room,
        Action action,
        string main_message,
        string success_message);

    // ����������� �����������
    MenuObject(const MenuObject&) = default;
    MenuObject& operator=(const MenuObject&) = default;

    // ����������� ������������
    MenuObject(MenuObject&& menu_object) noexcept;
    MenuObject& operator=(MenuObject&&) = default;

    // ����������
    ~MenuObject() = default;

    // ����� ������ ����
    inline void show(const string& indentation = "") const;

    // ��������� �������
    inline void act() const;

    // ������ �������� ������
    inline string get_label() const;

    // ������ ������ ������
    inline int get_number() const;

    // ������ ������� �������� ������
    inline string get_full_name() const;

    // ������ �������
    inline const vector<MenuObject>& get_submenu() const;

    // ������ ������� ����� ����
    inline bool get_one_off_menu_inclusion() const;

    // ����� ����
    template <typename Container>
    static enable_if_t<is_same_v<typename Container::value_type, MenuObject>, void>
    show_menu(const Container& menu, int indent);

    // ��������� �������������� � ����
    template <typename Container>
    static enable_if_t<is_same_v<typename Container::value_type, MenuObject>, void>
    process(const Container& menu, const string main_label = "", const string exit_label = "", int indent = 0, bool one_off = false);
};

#include "kondakov_lr5_menu_object.hpp"

#endif // KONDAKOV_LR5_MENU_OBJECT_H