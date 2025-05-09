/**
 * @file kondakov_lr5_family_room.cpp
 * @brief ���������� ������� ������ FamilyRoom
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#include "kondakov_lr5_family_room.h"

/**
 * @brief ����������� �� ���������
 */
FamilyRoom::FamilyRoom()
    : Room(),
      ChildCare(),
      child_beds(1),
      toy_kit(false),
      amenities({ "Wi-Fi", "Air condition" }) {
}

/**
 * @brief ����������� ��������������
 * @param room_number ����� �������
 * @param child_beds ���������� ������� ��������
 */
FamilyRoom::FamilyRoom(int room_number, int child_beds)
    : Room(room_number),
      ChildCare(true),
      child_beds(child_beds),
      toy_kit(false),
      amenities({"Wi-Fi", "Air condition"}) {
}

/**
 * @brief ����������� � ���������� �� ���������
 * @param room_number ����� �������
 * @param price_per_night ���� �� ����
 * @param is_booked ������ ������������
 * @param child_care_price ��������� ����� ��� �����
 * @param has_child_care ������� ����� ��� �����
 * @param child_beds ���������� ������� ��������
 * @param toy_kit ������� ������ �������
 */
FamilyRoom::FamilyRoom(int room_number, float price_per_night, bool is_booked,
                     float child_care_price, bool has_child_care,
                     int child_beds, bool toy_kit)
    : FamilyRoom(room_number, price_per_night, is_booked, child_care_price,
                has_child_care, child_beds, toy_kit, "Wi-Fi, air condition") {
}

/**
 * @brief ����������� � ����������� (�������� ������)
 * @param room_number ����� �������
 * @param price_per_night ���� �� ����
 * @param is_booked ������ ������������
 * @param child_care_price ��������� ����� ��� �����
 * @param has_child_care ������� ����� ��� �����
 * @param child_beds ���������� ������� ��������
 * @param toy_kit ������� ������ �������
 * @param amenities ������ ������� (������, ����������� - �������)
 */
FamilyRoom::FamilyRoom(int room_number, float price_per_night, bool is_booked,
                     float child_care_price, bool has_child_care,
                     int child_beds, bool toy_kit, string amenities)
    : Room(room_number, price_per_night, is_booked),
      ChildCare(child_care_price, has_child_care),
      child_beds(child_beds),
      toy_kit(toy_kit) {
    InputControl::DelimitedContainer<',', vector<string>&> dc(this->amenities);
    dc >> amenities;
}

/**
 * @brief ����������� � ����������� (�������� ������)
 * @param room_number ����� �������
 * @param price_per_night ���� �� ����
 * @param is_booked ������ ������������
 * @param child_care_price ��������� ����� ��� �����
 * @param has_child_care ������� ����� ��� �����
 * @param child_beds ���������� ������� ��������
 * @param toy_kit ������� ������ �������
 * @param amenities ������ ������� (������ �����)
 */
FamilyRoom::FamilyRoom(int room_number, float price_per_night, bool is_booked,
    float child_care_price, bool has_child_care,
    int child_beds, bool toy_kit, vector<string> amenities)
    : Room(room_number, price_per_night, is_booked),
    ChildCare(child_care_price, has_child_care),
    child_beds(child_beds),
    toy_kit(toy_kit),
    amenities(amenities) {
}

/**
 * @brief ����������� �����������
 * @param other ������ ������ FamilyRoom
 */
FamilyRoom::FamilyRoom(FamilyRoom&& other) noexcept
    : Room(move(other)),
      ChildCare(move(other)),
      child_beds(other.child_beds),
      toy_kit(other.toy_kit) {
}

/**
 * @brief �������������� � JSON
 * @return JSON ������ � ������� ������
 */
json FamilyRoom::to_json() const {
    return {
        { "room_number", room_number },
        { "price_per_night", price_per_night },
        { "is_booked", is_booked },
        { "child_care_price", child_care_price },
        { "has_child_care", has_child_care },
        { "child_beds", child_beds },
        { "toy_kit", toy_kit },
        { "amenities", amenities }
    };
}

/**
 * @brief �������� �� JSON
 * @param j JSON ������ � ������� ������
 */
void FamilyRoom::from_json(const json& j) {
    room_number = j["room_number"];
    price_per_night = j["price_per_night"];
    is_booked = j["is_booked"];
    child_care_price = j["child_care_price"];
    has_child_care = j["has_child_care"];
    child_beds = j["child_beds"];
    toy_kit = j["toy_kit"];
    amenities = j["amenities"];
}

/**
 * @brief �������� ������� �� ������� (��������� ������)
 * @param index ������ ���� (0-4)
 * @return ��������� ������������� ������������ ����
 * @throw out_of_range ���� ������ ��� ���������
 */
string FamilyRoom::operator[](int index) const {
    ostringstream oss;
    switch (index) {
        case 0: oss << "��������� ����� ��� �����: " << child_care_price; break;
        case 1: oss << "������� ����� ��� �����: " << has_child_care; break;
        case 2: oss << "���������� ������� ��������: " << child_beds; break;
        case 3: oss << "������� ������ ������� �������: " << toy_kit; break;
        case 4: oss << "��������: " << amenities; break;
        default: 
            ostringstream error;
            error << "�������� \"" << index << "\" ��� ����������� ��������� (0-4)";
            throw out_of_range(error.str());
    }
    return oss.str();
}

/// @name ��������� �������� �������
/// @{
vector<string> operator+(const FamilyRoom& fr1, const FamilyRoom& fr2) {
    vector<string> a(fr1.amenities);
    a += fr2;
    return a;
}

vector<string> operator+(const vector<string>& amenities, const FamilyRoom& fr) {
    vector<string> a(amenities);
    a += fr;
    return a;
}

vector<string> operator+(const FamilyRoom& fr, const vector<string>& amenities) {
    vector<string> a(fr.amenities);
    a += amenities;
    return a;
}

vector<string>& operator+=(vector<string>& amenities, const FamilyRoom& fr) {
    amenities += fr.amenities;
    return amenities;
}

FamilyRoom& operator+=(FamilyRoom& fr, const vector<string>& amenities) {
    fr.amenities += amenities;
    return fr;
}

FamilyRoom& operator+=(FamilyRoom& fr, const string& amenities) {
    fr.amenities += amenities;
    return fr;
}
/// @}

/**
 * @brief �������������� � ������
 */
FamilyRoom::operator string() const {
    ostringstream oss;
    oss << "���������� ������� ��������:\t"    << child_beds << endl
        << "������� ������ ������� �������:\t" << (toy_kit ? "��" : "���") << endl
        << "��������:\t\t\t"                   << amenities;
    return oss.str();
}

/**
 * @brief �������� ������
 * @param os ����� ������
 * @param fr ������� ��� ������
 * @return ����� ������
 */
ostream& operator<<(ostream& os, const FamilyRoom& fr) {
    os << static_cast<string>(fr);
    return os;
}

/**
 * @brief �������� �����
 * @param is ����� �����
 * @param fr ������� ��� �����
 * @return ����� �����
 */
istream& operator>>(istream& is, FamilyRoom& fr) {
    if (fr.input_child_beds())      { is.setstate(ios::failbit); return is; }
    if (fr.input_toy_kit())         { is.setstate(ios::failbit); return is; }
    if (fr.input_amenities<','>())  { is.setstate(ios::failbit); return is; }
    return is;
}

/**
 * @brief ����� ���������� � ������
 */
void FamilyRoom::print() const {
    cout << this->to_string() << endl << endl;
}

/**
 * @brief ���� ���������� � ������
 * @return true ���� ���� �������, false ���� �������
 */
bool FamilyRoom::input() {
    if (Room::input()) {          // ���� ������� ����������
        if (ChildCare::input()) { // ���� ���������� �� �������
            if (cin >> *this) {   // ���� ����������� ����������
                return true;
            }
        }
    }
    cin.clear();
    return false;
}

/**
 * @brief �������������� � ������
 * @return ������ ��������� ������������� ������
 */
string FamilyRoom::to_string() const {
    ostringstream oss;
    oss << "[" << get_full_name() << "]" << endl;
    oss << Room::to_string() << endl;
    oss << ChildCare::to_string() << endl;
    oss << *this;
    return oss.str();
}