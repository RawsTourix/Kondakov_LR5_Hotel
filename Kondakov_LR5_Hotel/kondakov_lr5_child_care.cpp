/**
 * @file kondakov_lr5_child_care.cpp
 * @brief ���������� ������� ������ ChildCare
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#include "kondakov_lr5_child_care.h"

const string ChildCare::CURRENCY = "���.";  ///< ������������� ������������ ����

/**
 * @brief ����������� �� ���������
 */
ChildCare::ChildCare()
    : ChildCare(1000.0f, false) {
}

/**
 * @brief ����������� ��������������
 * @param has_child_care ������� ����� ��� �����
 */
ChildCare::ChildCare(bool has_child_care)
    : ChildCare(1000.0f, has_child_care) {
}

/**
 * @brief ����������� � �����������
 * @param child_care_price ��������� �����
 * @param has_child_care ������� �����
 */
ChildCare::ChildCare(float child_care_price, bool has_child_care)
    : child_care_price(child_care_price),
      has_child_care(has_child_care) {
}

/**
 * @brief ����������� �����������
 * @param other ������ ������ ChildCare
 */
ChildCare::ChildCare(ChildCare&& other) noexcept
    : child_care_price(other.child_care_price),
      has_child_care(other.has_child_care) {
}

/**
 * @brief �������������� � ������
 */
ChildCare::operator string() const {
    ostringstream oss;
    oss << "��������� ����� ��� �����:\t" << child_care_price << " " << CURRENCY << endl
        << "������� ����� ��� �����:\t"   << (has_child_care ? "��" : "���");
    return oss.str();
}

/**
 * @brief �������� ������
 * @param os ����� ������
 * @param cr ������ ��� ������
 * @return ����� ������
 */
ostream& operator<<(ostream& os, const ChildCare& cr) {
    os << static_cast<string>(cr);
    return os;
}

/**
 * @brief �������� �����
 * @param is ����� �����
 * @param cr ������ ��� �����
 * @return ����� �����
 */
istream& operator>>(istream& is, ChildCare& cr) {
    if (cr.input_child_care_price()) { is.setstate(ios::failbit); return is; }
    if (cr.input_has_child_care())   { is.setstate(ios::failbit); return is; }
    return is;
}

/**
 * @brief �������������� � ������
 * @return ��������� ������������� �������
 */
string ChildCare::to_string() const {
    ostringstream oss;
    oss << *this;
    return oss.str();
}