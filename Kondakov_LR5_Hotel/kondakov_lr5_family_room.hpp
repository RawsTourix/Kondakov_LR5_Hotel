/**
 * @file kondakov_lr5_family_room.hpp
 * @brief ���������� ������� ������ FamilyRoom
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#ifndef KONDAKOV_LR5_FAMILY_ROOM_HPP
#define KONDAKOV_LR5_FAMILY_ROOM_HPP

#include "kondakov_lr5_family_room.h"

/**
 * @brief �������� ���������� ������� ��������
 * @return ���������� ������� ��������
 */
inline int FamilyRoom::get_child_beds() const {
    return child_beds;
}

/**
 * @brief �������� ������� ������ �������
 * @return true ���� ����� ����, false ���� ���
 */
inline bool FamilyRoom::get_toy_kit() const {
    return toy_kit;
}

/**
 * @brief �������� ������ �������
 * @return ����������� ������ �� ������ �������
 */
inline const vector<string>& FamilyRoom::get_amenities() const {
    return amenities;
}

/**
 * @brief �������� ������ �������� �������
 * @return ������ ���� "�������� ������� �X"
 */
inline string FamilyRoom::get_full_name() const {
    ostringstream oss;
    oss << ROOM_TYPE << " �" << room_number;
    return oss.str();
}

/**
 * @brief ���������� ���������� ������� ��������
 * @param child_beds ����� ���������� ��������
 */
inline void FamilyRoom::set_child_beds(int child_beds) {
    this->child_beds = child_beds;
}

/**
 * @brief ���������� ������� ������ �������
 * @param toy_kit ����� �������� ������� ������
 */
inline void FamilyRoom::set_toy_kit(bool toy_kit) {
    this->toy_kit = toy_kit;
}

/**
 * @brief ���������� ������ �������
 * @param amenities ����� ������ �������
 */
inline void FamilyRoom::set_amenities(vector<string> amenities) {
    this->amenities = move(amenities);
}

/**
 * @brief ���� ���������� ������� ��������
 * @return true ���� ���� �������, false ���� �������
 * @note ���������� �������� [] ��� ������� � ����
 */
inline bool FamilyRoom::input_child_beds() {
    if (InputControl::input((*this).operator[]<int>(2), "���������� ������� ��������: ", 1, 5)) { 
        return true; 
    }
    return false;
}

/**
 * @brief ���� ������� ������ �������
 * @return true ���� ���� �������, false ���� �������
 * @note ���������� �������� [] ��� ������� � ����
 */
inline bool FamilyRoom::input_toy_kit() {
    if (InputControl::input((*this).operator[]<bool>(3), "������� ������ ������� �������: (1/0): ")) { 
        return true; 
    }
    return false;
}

/**
 * @brief ���� ������� � ������������
 * @tparam Delim ����������� (�� ��������� ',')
 * @return true ���� ���� �������, false ���� �������
 */
template <char Delim>
inline bool FamilyRoom::input_amenities() {
    cout << "���� ������� �������������� � ���� ������ ����� ����������� '" << Delim << "'." << endl << endl;
    cout << "��������: ";
    InputControl::DelimitedContainer<Delim, vector<string>&> dc(amenities);
    if (cin >> dc) { return false; }
    else { cin.clear(); return true; }
}

/**
 * @brief �������� ��� �������
 * @return ����������� ������ �� ������ � �����
 */
inline const string& FamilyRoom::get_room_type() const {
    return ROOM_TYPE;
}

/**
 * @brief �������� ��� ��� JSON
 * @return ����������� ������ �� ������ � �����
 */
inline const string& FamilyRoom::get_json_type() const {
    return JSON_TYPE;
}

/**
 * @brief ������ ����� ��������� ����������
 * @param night_count ���������� �����
 * @return ����� ��������� (���� * ���� + 1000 ���./�������)
 */
inline float FamilyRoom::calculate_total(int night_count) const {
    return price_per_night * night_count + static_cast<float>(child_beds * 1000);
}

/**
 * @brief �������� ���������� ������
 * @return true ���� ���������� ������� �������� <= 4, ����� false
 */
inline bool FamilyRoom::validate() const {
    return child_beds <= 4;
}

/**
 * @brief ������������ ������� ����
 * @details ��������� 1500 ���. � ��������� � ������������� ���� ������� �������
 */
inline void FamilyRoom::add_play_area() {
    toy_kit = !toy_kit;
    price_per_night += 1500.0f * (toy_kit ? 1 : -1);
}

/**
 * @brief �������������� ������� ����
 * @details ������� 1500 ���. �� ���������, ���� ������� ���� ���� �������
 */
inline void FamilyRoom::remove_play_area() {
    if (toy_kit) {
        toy_kit = false;
        price_per_night -= 1500.0f;
    }
}

/**
 * @brief ��������� �������� ������� �� ������� (const)
 * @tparam T ��� ������������� ��������
 * @param index ������ ���� (0-4)
 * @return �������� ������������ ����
 * @throw invalid_argument ���� ������ �� ������������� ����
 */
template <typename T>
typename enable_if_t<is_same_v<T, float>, T>
FamilyRoom::operator[](int index) const {
    if (index == 0) return child_care_price;
    throw invalid_argument("�������� ������ ��� float");
}

template <typename T>
typename enable_if_t<is_same_v<T, bool>, T>
FamilyRoom::operator[](int index) const {
    if (index == 1) return has_child_care;
    if (index == 3) return toy_kit;
    throw invalid_argument("�������� ������ ��� bool");
}

template <typename T>
typename enable_if_t<is_same_v<T, int>, T>
FamilyRoom::operator[](int index) const {
    if (index == 2) return child_beds;
    throw invalid_argument("�������� ������ ��� int");
}

template <typename T>
typename enable_if_t<is_same_v<T, string>, T>
FamilyRoom::operator[](int index) const {
    if (index == 4) return amenities;
    throw invalid_argument("�������� ������ ��� string");
}

/**
 * @brief ��������� �������� ������� �� ������� (non-const)
 * @tparam T ��� ������������� ��������
 * @param index ������ ���� (0-4)
 * @return ������ �� ����������� ����
 * @throw invalid_argument ���� ������ �� ������������� ����
 */
template <typename T>
typename enable_if_t<is_same_v<T, float>, T&>
FamilyRoom::operator[](int index) {
    if (index == 0) return child_care_price;
    throw invalid_argument("�������� ������ ��� float");
}

template <typename T>
typename enable_if_t<is_same_v<T, bool>, T&>
FamilyRoom::operator[](int index) {
    if (index == 1) return has_child_care;
    if (index == 3) return toy_kit;
    throw invalid_argument("�������� ������ ��� bool");
}

template <typename T>
typename enable_if_t<is_same_v<T, int>, T&>
FamilyRoom::operator[](int index) {
    if (index == 2) return child_beds;
    throw invalid_argument("�������� ������ ��� int");
}

template <typename T>
typename enable_if_t<is_same_v<T, string>, T&>
FamilyRoom::operator[](int index) {
    if (index == 4) return amenities;
    throw invalid_argument("�������� ������ ��� string");
}

#endif // KONDAKOV_LR5_FAMILY_ROOM_HPP