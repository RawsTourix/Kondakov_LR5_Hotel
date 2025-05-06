/**
 * @file kondakov_lr5_standard_room.h
 * @brief ������������ ���� ������ StandardRoom
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#ifndef KONDAKOV_LR5_STANDARD_ROOM_H
#define KONDAKOV_LR5_STANDARD_ROOM_H

#include "kondakov_lr5_room.h"

/**
 * @class StandardRoom
 * @brief ����� ������������ ������ (��������� Room)
 */
class StandardRoom final : virtual public Room {
private:
    int             bed_count;  ///< ���������� ��������
    bool            has_tv;     ///< ������� ����������
    vector<string>  amenities;  ///< ��������

    const string ROOM_TYPE = "����������� �������";  ///< ��� �������
    const string JSON_TYPE = "Standard";             ///< ��� ��� JSON

public:
    /// ����������� �� ���������
    StandardRoom();

    /**
     * @brief ����������� ��������������
     * @param room_number ����� �������
     * @param bed_count ���������� ��������
     */
    StandardRoom(int room_number, int bed_count);

    /**
     * @brief ����������� � ���������� �� ���������
     * @param room_number ����� �������
     * @param price_per_night ���� �� ����
     * @param is_booked ������ ������������
     * @param bed_count ���������� ��������
     * @param has_tv ������� ����������
     */
    StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv);

    /**
     * @brief ����������� � ����������� (�������� ������)
     * @param room_number ����� �������
     * @param price_per_night ���� �� ����
     * @param is_booked ������ ������������
     * @param bed_count ���������� ��������
     * @param has_tv ������� ����������
     * @param amenities �������� (������ � �������������)
     */
    StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv, string amenities);

    /**
     * @brief ����������� � ����������� (�������� ������)
     * @param room_number ����� �������
     * @param price_per_night ���� �� ����
     * @param is_booked ������ ������������
     * @param bed_count ���������� ��������
     * @param has_tv ������� ����������
     * @param amenities �������� (������ �����)
     */
    StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv, vector<string> amenities);

    /// ����������� �����������
    StandardRoom(const StandardRoom&) = default;
    StandardRoom& operator=(const StandardRoom&) = default;

    /// ����������� �����������
    StandardRoom(StandardRoom&& other) noexcept;
    StandardRoom& operator=(StandardRoom&&) noexcept = default;

    /// ����������
    virtual ~StandardRoom() = default;

    /// @name �������
    /// @{
    inline int get_bed_count() const;
    inline bool get_has_tv() const;
    virtual inline const vector<string>& get_amenities() const override;
    virtual inline string get_full_name() const override;
    /// @}

    /// @name �������
    /// @{
    inline void set_bed_count(int bed_count);
    inline void set_has_tv(bool has_tv);
    inline void set_amenities(vector<string> amenities);
    /// @}

    /// @name ������ �����
    /// @{
    inline bool input_bed_count();
    inline bool input_has_tv();
    template <char Delim>
    inline bool input_amenities();
    /// @}

    /// @name ���������������� ������
    /// @{
    virtual inline const string& get_room_type() const override;
    virtual inline const string& get_json_type() const override;
    virtual inline float calculate_total(int night_count) const override;
    virtual inline bool validate() const override;
    /// @}

    /// �������� �������������� ������� (+20% � ����)
    inline void exstra_bed();

    /// @name JSON ������
    /// @{
    virtual json to_json() const override;
    virtual void from_json(const json& j) override;
    /// @}

    /// @name ��������� �������� �������
    /// @{
    friend vector<string>  operator+ (const StandardRoom& sr1, const StandardRoom& sr2);
    friend vector<string>  operator+ (const vector<string>& amenities, const StandardRoom& sr);
    friend vector<string>  operator+ (const StandardRoom& sr, const vector<string>& amenities);
    friend vector<string>& operator+=(vector<string>& amenities, const StandardRoom& sr);
    friend StandardRoom&   operator+=(StandardRoom& sr, const vector<string>& amenities);
    friend StandardRoom&   operator+=(StandardRoom& sr, const string& amenities);
    /// @}

    /// �������������� � ������
    explicit operator string() const;

    /// @name ��������� �����/������
    /// @{
    friend ostream& operator<<(ostream& os, const StandardRoom& r);
    friend istream& operator>>(istream& is, StandardRoom& r);
    /// @}

    /// @name ���������������� ������ ������/�����
    /// @{
    virtual void print() const override;
    virtual bool input() override;
    virtual string to_string() const override;
    /// @}
};

#include "kondakov_lr5_standard_room.hpp"

#endif // KONDAKOV_LR5_STANDARD_ROOM_H