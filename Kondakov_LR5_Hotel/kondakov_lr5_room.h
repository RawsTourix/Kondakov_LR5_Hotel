/**
 * @file kondakov_lr5_room.h
 * @brief ������������ ���� ������������ ������ Room
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#ifndef KONDAKOV_LR5_ROOM_H
#define KONDAKOV_LR5_ROOM_H

#include "kondakov_lr5_input_control.h"

/**
 * @class Room
 * @brief ����������� ������� ����� ��� ������������� ������������ ������
 */
class Room {
protected:
    int     room_number;      ///< ����� �������
    float   price_per_night;  ///< ���� �� ����
    bool    is_booked;        ///< ������ ������������

    /**
     * @brief ����������� ����� ������ ���������� � �������
     */
    virtual void print() const {
        cout << *this << endl;
    }

    /**
     * @brief ����������� ����� ����� ���������� � �������
     * @return true ���� �������� ��������, false ���� �������
     */
    virtual bool input() {
        return static_cast<bool>(cin >> *this);
    }

public:
    /// ������ ��� ����������� ���
    static const string CURRENCY;

    /// ����������� �� ���������
    Room();

    /// ����������� �������������� (�� ������ �������)
    Room(int room_number);

    /**
     * @brief ����������� � �����������
     * @param room_number ����� �������
     * @param price_per_night ���� �� ����
     * @param is_booked ������ ������������
     */
    Room(int room_number, float price_per_night, bool is_booked);

    /// ����������� �����������
    Room(const Room&) = default;
    Room& operator=(const Room&) = default;

    /// ����������� �����������
    Room(Room&& other) noexcept;
    Room& operator=(Room&&) noexcept = default;

    /// ����������� ����������
    virtual ~Room() = default;

    /// @name �������
    /// @{
    inline int get_room_number() const;
    inline float get_price_per_night() const;
    inline bool get_is_booked() const;
    virtual inline const vector<string>& get_amenities() const = 0;
    virtual inline string get_full_name() const = 0;
    /// @}

    /// @name �������
    /// @{
    inline void set_room_number(int room_number);
    inline void set_price_per_night(float price_per_night);
    inline void set_is_booked(bool is_booked);
    /// @}

    /// @name ������ �����
    /// @{
    inline bool input_room_number();
    template <typename Container>
    inline typename enable_if_t<is_same_v<typename Container::value_type, int>, bool>
    input_room_number(const Container& room_numbers);
    inline bool input_price_per_night();
    inline bool input_is_booked();
    /// @}

    /// @name ����������� ������
    /// @{
    virtual inline const string& get_room_type() const = 0;
    virtual inline const string& get_json_type() const = 0;
    virtual inline float calculate_total(int night_count) const = 0;
    virtual inline bool validate() const = 0;
    virtual json to_json() const = 0;
    virtual void from_json(const json& j) = 0;
    /// @}

    /// @name ��������� ���������
    /// @{
    friend bool operator==(const Room& r1, const Room& r2);
    friend bool operator==(int room_number, const Room& r2);
    friend bool operator==(const Room& r1, int room_number);
    friend bool operator>=(const Room& r1, const Room& r2);
    friend bool operator>=(int room_number, const Room& r2);
    friend bool operator>=(const Room& r1, int room_number);
    friend bool operator<=(const Room& r1, const Room& r2);
    friend bool operator<=(int room_number, const Room& r2);
    friend bool operator<=(const Room& r1, int room_number);
    friend bool operator> (const Room& r1, const Room& r2);
    friend bool operator> (int room_number, const Room& r2);
    friend bool operator> (const Room& r1, int room_number);
    friend bool operator< (const Room& r1, const Room& r2);
    friend bool operator< (int room_number, const Room& r2);
    friend bool operator< (const Room& r1, int room_number);
    friend bool operator!=(const Room& r1, const Room& r2);
    friend bool operator!=(int room_number, const Room& r2);
    friend bool operator!=(const Room& r1, int room_number);
    /// @}

    /// �������������� � ������
    explicit operator string() const;

    /// @name ��������� �����/������
    /// @{
    friend ostream& operator<<(ostream& os, const Room& r);
    friend istream& operator>>(istream& is, Room& r);
    /// @}

    /// ����������� ����� �������������� � ������
    virtual string to_string() const;

    /**
     * @brief ���������� ������ ��� ���������� ������
     * @tparam Container ��� ���������� (������ ��������� shared_ptr<Room>)
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, ostream&>
    friend operator<<(ostream& os, const Container& rooms);
};

#include "kondakov_lr5_room.hpp"

#endif // KONDAKOV_LR5_ROOM_H