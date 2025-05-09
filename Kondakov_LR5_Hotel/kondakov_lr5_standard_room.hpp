/**
 * @file kondakov_lr5_standard_room.hpp
 * @brief ���������� ������� ������ StandardRoom
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#ifndef KONDAKOV_LR5_STANDARD_ROOM_HPP
#define KONDAKOV_LR5_STANDARD_ROOM_HPP

#include "kondakov_lr5_standard_room.h"

/**
 * @brief �������� ���������� ��������
 * @return ���������� ��������
 */
inline int StandardRoom::get_bed_count() const {
    return bed_count;
}

/**
 * @brief �������� ������� ����������
 * @return true ���� ���� ���������, ����� false
 */
inline bool StandardRoom::get_has_tv() const {
    return has_tv;
}

/**
 * @brief �������� ������ �������
 * @return ����������� ������ �� ������ �������
 */
inline const vector<string>& StandardRoom::get_amenities() const {
    return amenities;
}

/**
 * @brief �������� ������ �������� �������
 * @return ������ � ������ ��������� �������
 */
inline string StandardRoom::get_full_name() const {
    ostringstream oss;
    oss << ROOM_TYPE << " �" << room_number;
    return oss.str();
}

/**
 * @brief ���������� ���������� ��������
 * @param bed_count ����� ���������� ��������
 */
inline void StandardRoom::set_bed_count(int bed_count) {
    this->bed_count = bed_count;
}

/**
 * @brief ���������� ������� ����������
 * @param has_tv ������� ����������
 */
inline void StandardRoom::set_has_tv(bool has_tv) {
    this->has_tv = has_tv;
}

/**
 * @brief ���������� ������ �������
 * @param amenities ����� ������ �������
 */
inline void StandardRoom::set_amenities(vector<string> amenities) {
    this->amenities = move(amenities);
}

/**
 * @brief ���� ���������� ��������
 * @return true ���� �������� ��������, ����� false
 */
inline bool StandardRoom::input_bed_count() {
    if (InputControl::input(bed_count, "���������� ��������: ", 1, 5)) { return true; }
    return false;
}

/**
 * @brief ���� ������� ����������
 * @return true ���� �������� ��������, ����� false
 */
inline bool StandardRoom::input_has_tv() {
    if (InputControl::input(has_tv, "������� ���������� (1/0): ")) { return true; }
    return false;
}

/**
 * @brief ���� ������� � ������������
 * @tparam Delim ����������� ��� �����
 * @return true ���� �������� ��������, ����� false
 */
template <char Delim>
inline bool StandardRoom::input_amenities() {
    cout << "���� ������� �������������� � ���� ������ ����� ����������� '" << Delim << "'." << endl;
    cout << "��������: ";
    InputControl::DelimitedContainer<Delim, vector<string>&> dc(amenities);
    if (cin >> dc) { return false; }
    else { cin.clear(); return true; }
}

/**
 * @brief �������� ��� �������
 * @return ����������� ������ �� ������ � ����� �������
 */
inline const string& StandardRoom::get_room_type() const {
    return ROOM_TYPE;
}

/**
 * @brief �������� ��� ��� JSON
 * @return ����������� ������ �� ������ � ����� ��� JSON
 */
inline const string& StandardRoom::get_json_type() const {
    return JSON_TYPE;
}

/**
 * @brief ������ ����� ��������� ����������
 * @param night_count ���������� �����
 * @return ����� ���������
 */
inline float StandardRoom::calculate_total(int night_count) const {
    return price_per_night * static_cast<float>(night_count);
}

/**
 * @brief �������� ���������� ������
 * @return true ���� ����� ������� (���������� �������� >= 1), ����� false
 */
inline bool StandardRoom::validate() const {
    return bed_count >= 1;
}

/**
 * @brief �������� �������������� �������
 * @details ����������� ���� �� 20% � ���������� �������� �� 1
 */
inline void StandardRoom::exstra_bed() {
    price_per_night += price_per_night * 0.2f;
    bed_count++;
}

#endif // KONDAKOV_LR5_STANDARD_ROOM_HPP