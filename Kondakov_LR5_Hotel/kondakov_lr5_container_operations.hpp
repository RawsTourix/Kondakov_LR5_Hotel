/**
 * @file kondakov_lr5_container_operations.hpp
 * @brief �������� � ������������ �����
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup container_operations
 */

#ifndef KONDAKOV_LR5_CONTAINER_OPERATIONS_HPP
#define KONDAKOV_LR5_CONTAINER_OPERATIONS_HPP

#include "kondakov_lr5_input_control.h"

 /**
  * @brief ������������� DelimitedContainer ��� ������ �� ��������
  * @tparam Delim �����������
  * @tparam Container ��� ���������� (������ ��������� ������)
  * @details ������ ������ �� ��������� ����� ��� ����������� ���������
  */
template <char Delim, typename Container>
struct InputControl::DelimitedContainer<Delim, Container&, enable_if_t<is_same_v<typename Container::value_type, string>, void>> {
    Container& ref; ///< ������ �� ������� ���������
    explicit DelimitedContainer(Container& r) : ref(r) {} ///< �����������
};

/**
 * @brief ���������� ��������� ������ ��� ���������� �����
 * @tparam Container ��� ���������� (������ ��������� ������)
 * @param os ����� ������
 * @param strings ��������� �����
 * @return ����� ������
 * @details ������� �������� ���������� ����� �������
 */
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, ostream&>
operator<<(ostream& os, const Container& strings) {
    if (!strings.empty()) {
        auto it = strings.begin();
        os << *it;

        for (++it; it != strings.end(); ++it) {
            os << ", " << *it;
        }
    }
    return os;
}

/**
 * @brief ���������� ��������� �������� ��� ����������� �����
 * @tparam Container ��� ���������� (������ ��������� ������)
 * @param lhs ����� �������
 * @param rhs ������ �������
 * @return ����� ��������� � ������������ ����������
 * @details ���������� ����������, �������� ���������
 */
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, Container>
operator+(const Container& lhs, const Container& rhs) {
    Container result = lhs;
    for (const auto& str : rhs) {
        if (find(result.begin(), result.end(), str) == result.end()) {
            result.push_back(str);
        }
    }
    return result;
}

/**
 * @brief ���������� ��������� += ��� ����������� �����
 * @tparam Container ��� ���������� (������ ��������� ������)
 * @param lhs ����� ������� (����������)
 * @param rhs ������ �������
 * @return ������ �� ��������� ���������
 * @details ��������� �������� �� ������� ��������, �������� ���������
 */
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, Container&>
operator+=(Container& lhs, const Container& rhs) {
    for (const auto& str : rhs) {
        if (find(lhs.begin(), lhs.end(), str) == lhs.end()) {
            lhs.push_back(str);
        }
    }
    return lhs;
}

/**
 * @brief ���������� ��������� += ��� ���������� � ������
 * @tparam Container ��� ���������� (������ ��������� ������)
 * @param lhs ����� ������� (����������)
 * @param str ����������� ������
 * @return ������ �� ��������� ���������
 * @details ��������� ������ ���� � ��� ��� � ����������
 */
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, Container&>
operator+=(Container& lhs, const string& str) {
    if (find(lhs.begin(), lhs.end(), str) == lhs.end()) {
        lhs.push_back(str);
    }
    return lhs;
}

/**
 * @brief ���������� ��������� ����� ��� DelimitedContainer
 * @tparam Delim �����������
 * @tparam Container ��� ���������� (������ ��������� ������)
 * @param is ����� �����
 * @param dc ��������� � ������������
 * @return ����� �����
 * @details ��������� ������ � ��������� � �� ����������� � ���������
 */
template <char Delim, typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, istream&>
operator>>(istream& is, InputControl::DelimitedContainer<Delim, Container&>& dc) {
    string input_line;

    if (!getline(is, input_line)) {
        is.setstate(ios::failbit);
        return is;
    }

    InputControl::trim(input_line);
    if (InputControl::is_input_empty(input_line)) {
        is.setstate(ios::failbit);
        return is;
    }

    InputControl::split(input_line, dc);
    return is;
}

/**
 * @brief ���������� ��������� >> ��� ���������� ������ � ���������
 * @tparam Delim �����������
 * @tparam Container ��� ���������� (������ ��������� ������)
 * @param dc ��������� � ������������
 * @param input_line ������� ������
 * @return ������ �� ��������� ���������
 */
template <char Delim, typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, Container&>
operator>>(InputControl::DelimitedContainer<Delim, Container&>& dc, const string& input_line) {
    InputControl::split(input_line, dc);
    return dc.ref;
}

#endif // KONDAKOV_LR5_CONTAINER_OPERATIONS_HPP