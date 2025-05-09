/**
 * @file kondakov_lr5_suite.hpp
 * @brief ���������� ������� ������ Suite
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#ifndef KONDAKOV_LR5_SUITE_HPP
#define KONDAKOV_LR5_SUITE_HPP

#include "kondakov_lr5_suite.h"

/**
 * @brief �������� ������� ������������
 * @return true ���� ���� ������������, ����� false
 */
inline bool Suite::get_room_service() const {
    return room_service;
}

/**
 * @brief �������� ������� �������
 * @return true ���� ���� �������, ����� false
 */
inline bool Suite::get_jacuzzi() const {
    return jacuzzi;
}

/**
 * @brief �������� ������ �������
 * @return ����������� ������ �� ������ �������
 */
inline const vector<string>& Suite::get_amenities() const {
    return amenities;
}

/**
 * @brief �������� ������ �������� �������
 * @return ������ � ��������� ������� "���� ������� �X"
 */
inline string Suite::get_full_name() const {
    ostringstream oss;
    oss << ROOM_TYPE << " �" << room_number;
    return oss.str();
}

/**
 * @brief ���������� ������� ������������
 * @param room_service ����� ��������
 */
inline void Suite::set_room_service(bool room_service) {
    this->room_service = room_service;
}

/**
 * @brief ���������� ������� �������
 * @param jacuzzi ����� ��������
 */
inline void Suite::set_jacuzzi(bool jacuzzi) {
    this->jacuzzi = jacuzzi;
}

/**
 * @brief ���������� ������ �������
 * @param amenities ����� ������ �������
 */
inline void Suite::set_amenities(vector<string> amenities) {
    this->amenities = move(amenities);
}

/**
 * @brief ���� ������� ������������
 * @return true ���� �������� ��������, ����� false
 */
inline bool Suite::input_room_service() {
    if (InputControl::input(room_service, "������� ������������ (1/0): ")) { return true; }
    return false;
}

/**
 * @brief ���� ������� �������
 * @return true ���� �������� ��������, ����� false
 */
inline bool Suite::input_jacuzzi() {
    if (InputControl::input(jacuzzi, "������� ������� (1/0): ")) { return true; }
    return false;
}

/**
 * @brief ���� ������� � ������������
 * @tparam Delim ����������� ��� �����
 * @return true ���� �������� ��������, ����� false
 */
template <char Delim>
inline bool Suite::input_amenities() {
    cout << "���� ������� �������������� � ���� ������ ����� ����������� '" << Delim << "'." << endl;
    cout << "��������: ";
    InputControl::DelimitedContainer<Delim, vector<string>&> dc(amenities);
    if (cin >> dc) { return false; }
    else { cin.clear(); return true; }
}

/**
 * @brief �������� ��� �������
 * @return ����������� ������ �� ������ � �����
 */
inline const string& Suite::get_room_type() const {
    return ROOM_TYPE;
}

/**
 * @brief �������� ��� ��� JSON
 * @return ����������� ������ �� ������ � �����
 */
inline const string& Suite::get_json_type() const {
    return JSON_TYPE;
}

/**
 * @brief ������ ����� ��������� ����������
 * @param night_count ���������� �����
 * @return ����� ��������� (���� * ���� + ������������� ����� �� ������)
 */
inline float Suite::calculate_total(int night_count) const {
    return price_per_night * static_cast<float>(night_count) + SERVICE_PRICE;
}

/**
 * @brief �������� ���������� ������
 * @return true ���� ����� ��������� �� 1 ���� >= 10000, ����� false
 */
inline bool Suite::validate() const {
    return calculate_total(1) >= 10000.0f;
}

/**
 * @brief �������� ������
 * @param amenity �������� ������
 * @details ����������� ���� �� 2000 ���. � ��������� ������ � ������
 */
inline void Suite::order_champagne(string amenity) {
    price_per_night += 2000.0f;
    InputControl::make_first_letter_uppercase(amenity);
    *this += amenity;
}

#endif // KONDAKOV_LR5_SUITE_HPP