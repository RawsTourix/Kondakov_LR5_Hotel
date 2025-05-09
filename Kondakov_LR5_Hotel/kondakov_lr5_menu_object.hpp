/**
 * @file kondakov_lr5_menu_object.hpp
 * @brief ���������� ������� ������ MenuObject
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup menu_system
 */

#ifndef KONDAKOV_LR5_MENU_OBJECT_HPP
#define KONDAKOV_LR5_MENU_OBJECT_HPP

#include "kondakov_lr5_menu_object.h"

/**
 * @brief ����������� ��� ������� � ��������������
 * @details ������� ����� ���� � ���������� ������������� ��������
 */
template <typename RoomPtr, typename Action, typename>
MenuObject::MenuObject(int number, string label, RoomPtr room, Action action,
                       string main_message, string success_message) :
    MenuObject(number, label, [=] {
        cout << endl << endl << main_message << endl << endl;
        if (!action()) {
            cout << endl;
            room->print();
            cout << success_message;
        }
        cout << endl;
    }) {
}

/**
 * @brief ����� ������ ����
 * @param indentation ������ ��� ��������� �������
 */
inline void MenuObject::show(const string& indentation) const {
    cout << indentation << number << ". " << label << endl;
}

/**
 * @brief ���������� �������� ������ ����
 */
inline void MenuObject::act() const {
    if (action)
        action();
    else
        cout << "������� �� ������ ��� ����� ������..." << endl << endl;
}

/**
 * @brief ��������� �������� ������
 * @return �������� ������ ����
 */
inline string MenuObject::get_label() const {
    return label;
}

/**
 * @brief ��������� ������ ������
 * @return ����� ������ ����
 */
inline int MenuObject::get_number() const {
    return number;
}

/**
 * @brief ��������� ������� ��������
 * @return ������ ���� "�����. ��������"
 */
inline string MenuObject::get_full_name() const {
    ostringstream oss;
    oss << number << ". " << label;
    return oss.str();
}

/**
 * @brief ��������� �������
 * @return ����������� ������ �� ������ �������
 */
inline const vector<MenuObject>& MenuObject::get_submenu() const {
    return submenu;
}

/**
 * @brief �������� ����� ������������ ����
 * @return true ���� ���� �����������
 */
inline bool MenuObject::get_one_off_menu_inclusion() const {
    return one_off_menu_inclusion;
}

/**
 * @brief ����� ����
 * @tparam Container ��� ���������� � �������� ����
 * @param menu ��������� � ����
 * @param indent ������� �����������
 */
template <typename Container>
enable_if_t<is_same_v<typename Container::value_type, MenuObject>, void>
MenuObject::show_menu(const Container& menu, int indent) {
    string indentation(indent, '\t');
    for (const auto& item : menu) {
        item.show(indentation);
        if (!item.get_submenu().empty())
            show_menu(item.get_submenu(), indent + 1);
    }
}

/**
 * @brief ��������� �������������� � ����
 * @tparam Container ��� ���������� � �������� ����
 * @param menu ��������� � ����
 * @param main_label ��������� ����
 * @param exit_label �������� ������ ������
 * @param indent ������� �����������
 * @param one_off ���� ������������ ����������
 */
template <typename Container>
enable_if_t<is_same_v<typename Container::value_type, MenuObject>, void>
MenuObject::process(const Container& menu, const string main_label, 
                    const string exit_label, int indent, bool one_off) {
    int number = 0;
    bool one_off_menu_inclusion = false;
    do {
        if (!main_label.empty()) cout << main_label << endl << endl;
        show_menu(menu, indent);
        cout << "0. " << exit_label << endl << endl << endl;
        
        if (InputControl::input(number, "����� ����: ", 0, static_cast<int>(menu.size()))) {
            if (one_off) { cout << endl; break; }
            else { cout << endl << endl << endl; }
            continue;
        }

        if (!one_off) cout << endl << endl;
        if (number == 0) break;

        try {
            auto it = find_if(menu.begin(), menu.end(), 
                [number](MenuObject m) { return m.get_number() == number; });
            
            if (it != menu.end()) {
                one_off_menu_inclusion = it->get_one_off_menu_inclusion();
                if (it->get_submenu().empty()) {
                    (*it).act();
                    if (one_off) break;
                }
                else {
                    process(it->get_submenu(), it->get_label(), "�����.", indent, one_off);
                    if (one_off) break;
                    continue;
                }
            }
        }
        catch (const exception& e) {
            cout << "������: " << e.what();
        }

        if (one_off) break;
        cout << (one_off_menu_inclusion ? "\n\n" : "\n\n\n");
        one_off_menu_inclusion = false;
    } while (number != 0);
}

#endif // KONDAKOV_LR5_MENU_OBJECT_HPP