/**
 * @file kondakov_lr5_child_care.hpp
 * @brief ���������� ������� ������ ChildCare
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#ifndef KONDAKOV_LR5_CHILD_CARE_HPP
#define KONDAKOV_LR5_CHILD_CARE_HPP

#include "kondakov_lr5_child_care.h"

/**
 * @brief �������� ��������� ����� ��� �����
 * @return ��������� ����� � ������
 */
inline float ChildCare::get_child_care_price() const {
    return child_care_price;
}

/**
 * @brief �������� ������� ����� ��� �����
 * @return true ���� ������ ��������, false ���� ���
 */
inline bool ChildCare::get_has_child_care() const {
    return has_child_care;
}

/**
 * @brief ���������� ��������� ����� ��� �����
 * @param child_care_price ����� ��������� �����
 */
inline void ChildCare::set_child_care_price(float child_care_price) {
    this->child_care_price = child_care_price;
}

/**
 * @brief ���������� ������� ����� ��� �����
 * @param has_child_care ����� �������� ������� �����
 */
inline void ChildCare::set_has_child_care(bool has_child_care) {
    this->has_child_care = has_child_care;
}

/**
 * @brief ���� ��������� ����� ��� �����
 * @return true ���� ���� �������, false ���� �������
 */
inline bool ChildCare::input_child_care_price() {
    ostringstream message;
    message << "��������� ����� ��� ����� (" << CURRENCY << "): ";
    if (InputControl::input(child_care_price, message.str(), 0.0f, 10000.0f)) { 
        return true; 
    }
    return false;
}

/**
 * @brief ���� ������� ����� ��� �����
 * @return true ���� ���� �������, false ���� �������
 */
inline bool ChildCare::input_has_child_care() {
    if (InputControl::input(has_child_care, "������� ����� ��� ����� (1/0): ")) { 
        return true; 
    }
    return false;
}

#endif // KONDAKOV_LR5_CHILD_CARE_HPP