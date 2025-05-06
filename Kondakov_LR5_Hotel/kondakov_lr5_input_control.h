/**
 * @file kondakov_lr5_input_control.h
 * @brief ������������ ���� ��� ���������� ������ ������
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup input_control
 */

#ifndef KONDAKOV_LR5_INPUT_CONTROL_H
#define KONDAKOV_LR5_INPUT_CONTROL_H

#include "kondakov_lr5_def.h"

/**
 * @namespace InputControl
 * @brief ������������ ��� ��� ������� ���������� ������ ������
 */
namespace InputControl {
    /**
     * @brief ��������� ����� ��� ������ � ������������� (������� ������)
     * @tparam Delim �����������
     * @tparam Container ��� ����������
     * @tparam SFINAE ��������������� �������� ��� SFINAE
     */
    template <char Delim, typename Container, typename = void>
    struct DelimitedContainer;

    /**
     * @brief ������������� DelimitedContainer ��� ������ �� ��������
     * @tparam Delim �����������
     * @tparam Container ��� ���������� (������ ��������� ������)
     */
    template <char Delim, typename Container>
    struct DelimitedContainer<Delim, Container&, enable_if_t<is_same_v<typename Container::value_type, string>, void>>;

    /**
     * @brief ������� ������� � ������ � ����� ������
     * @param str ������ ��� ���������
     */
    void trim(string& str);

    /**
     * @brief ��������� ������ �� ��������� �� �����������
     * @tparam Delim �����������
     * @tparam Container ��� ���������� ��� �����������
     * @param input_line ������� ������
     * @param dc ��������� � ������������
     */
    template <char Delim, typename Container>
    void split(const string& input_line, DelimitedContainer<Delim, Container&>& dc);

    /**
     * @brief ����������� ������ � ������ �������
     * @param str ������� ������
     * @return ������ � ������ ��������
     */
    string get_lowercase(const string str);

    /**
     * @brief ������ ������ ����� ������ ���������
     * @param str ������ ��� ���������
     */
    void make_first_letter_uppercase(string& str);

    /**
     * @brief ���������, �������� �� ���� ������ (��� ������ ��������)
     * @param input ������� ������
     * @return true ���� ���� ������, ����� false
     */
    bool is_input_empty(const string& input);

    /**
     * @brief ��������� ����� �� ��������� � ��������
     * @tparam T ��� �����
     * @param number ����������� �����
     * @param min ����������� ��������
     * @param max ������������ ��������
     * @return true ���� ����� � ���������, ����� false
     */
    template <typename T>
    bool check_min_max(const T& number, T min, T max);

    /**
     * @brief ������� ����� ��� �����
     * @param varLink ������ �� ���������� ��� ���������� ����������
     * @param label ������� ��� �����
     * @return true ���� �������� ��������, ����� false
     */
    bool input(string& varLink, const string& label);
    
    /**
     * @brief ������� ����� ��� bool
     * @param varLink ������ �� ���������� ��� ���������� ����������
     * @param label ������� ��� �����
     * @return true ���� �������� ��������, ����� false
     */
    bool input(bool& varLink, const string& label);

    /**
     * @brief ������� ����� ��� �����
     * @tparam T �������������� ��� ������
     * @param varLink ������ �� ���������� ��� ���������� ����������
     * @param label ������� ��� �����
     * @param min ����������� ��������
     * @param max ������������ ��������
     * @return true ���� �������� ��������, ����� false
     */
    template <typename T>
    enable_if_t<is_arithmetic_v<T>, bool>
    input(T& varLink, const string& label, T min = 0, T max = numeric_limits<T>::max());

    /**
     * @brief �������� ���� ������ �� �����
     * @return �������� ������
     */
    char get_char();

    /**
     * @brief ����������� ������������� (y/n)
     * @param label ������� ��� �������
     * @return true ���� ������� 'y' ��� 'Y', false ���� 'n' ��� 'N'
     */
    bool yes_or_no(const string& label);
}

#include "kondakov_lr5_input_control.hpp"
#include "kondakov_lr5_container_operations.hpp"  ///< ���������� ��� ������ � ������������

#endif // KONDAKOV_LR5_INPUT_CONTROL_H