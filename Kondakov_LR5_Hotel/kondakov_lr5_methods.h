/**
 * @file kondakov_lr5_methods.h
 * @brief ������������ ���� � �������� ������ � ���������
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_operations
 */

#ifndef KONDAKOV_LR5_METHODS_H
#define KONDAKOV_LR5_METHODS_H

#include "kondakov_lr5_menu_object.h"

/**
 * @namespace Methods
 * @brief ������������ ��� ��� �������� � ���������
 */
namespace Methods {
    using ::operator<<;

    /**
     * @struct RoomInfo
     * @brief ������� ���������� � ������� ��� �����������
     */
    struct RoomInfo {
        int number;             ///< ���������� ����� � ������
        string full_name;       ///< ������ �������� �������
        shared_ptr<Room> room;  ///< ��������� �� ������ �������

        RoomInfo() = delete;
        
        /**
         * @brief ����������� � �����������
         * @param number ���������� �����
         * @param full_name �������� �������
         * @param room ��������� �� �������
         */
        RoomInfo(int number, string full_name, shared_ptr<Room> room);

        /**
         * @brief ����� ���������� � �������
         */
        inline void print() const {
            cout << *this << endl;
        }

        friend ostream& operator<<(ostream& os, const RoomInfo& ri);
    };

    /// @name �������� �������� � ���������
    /// @{
    /**
     * @brief ����� ������ ������
     * @tparam Container ��� ���������� � ���������
     * @param rooms ��������� � ���������
     * @return ������� ��� ������ ������
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    show_rooms(const Container& rooms);

    /**
     * @brief ���������� �������
     * @tparam RoomType ��� ����������� �������
     * @tparam Container ��� ����������
     * @param rooms ��������� ��� ����������
     * @return ������� ��� ���������� �������
     */
    template <typename RoomType, typename Container>
    typename enable_if_t<is_base_of_v<Room, typename RoomType>&&
                         is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    add_room(Container& rooms);

    /**
     * @brief ��������� �������
     * @tparam Container ��� ����������
     * @param rooms ��������� � ���������
     * @return ������� ��� ��������� �������
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    edit_room(Container& rooms);

    /**
     * @brief �������� �������
     * @tparam Container ��� ����������
     * @param rooms ��������� � ���������
     * @return ������� ��� �������� �������
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    delete_room(Container& rooms);

    /**
     * @brief ���������� ������
     * @tparam Container ��� ����������
     * @param rooms ��������� ��� ����������
     * @return ������� ��� ����������
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    sort_rooms(Container& rooms);

    /**
     * @brief ������ ��������� ����������
     * @tparam Container ��� ����������
     * @param rooms ��������� � ���������
     * @return ������� ��� �������
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    calculate_total(Container& rooms);

    /**
     * @brief �������� ���������� �������
     * @tparam Container ��� ����������
     * @param rooms ��������� � ���������
     * @return ������� ��� ��������
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    validate_room(Container& rooms);

    /**
     * @brief �������������� ������ ������
     * @tparam Container ��� ����������
     * @param rooms ��������� � ���������
     * @return ������� ��� ������ � ���. ��������
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    additional_room_methods(Container& rooms);
    /// @}

    /// @name ��������������� ������
    /// @{
    /**
     * @brief ����� ������� �� ������
     * @tparam Container ��� ����������
     * @param main_label ��������� ����
     * @param message ����������� ��� �����
     * @param rooms ��������� � ���������
     * @return ��������� �� ��������� �������
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, shared_ptr<Room>>
    get_room_from_rooms_map(string main_label, string message, Container& rooms);

    /**
     * @brief ��������� ������ ������� ������
     * @tparam Container ��� ����������
     * @param rooms ��������� � ���������
     * @return ������ ������� ������
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, vector<int>>
    get_room_numbers(const Container& rooms);

    /**
     * @brief �������� ������������� �������
     * @tparam RoomType ��� �������
     * @tparam Container ��� ����������
     * @param room ����������� �������
     * @param rooms ��������� ��� ��������
     * @return true ���� ������� ����������
     */
    template <typename RoomType, typename Container>
    typename enable_if_t<is_base_of_v<Room, typename RoomType>&&
                         is_same_v<typename Container::value_type, shared_ptr<Room>>, bool>
    room_in_rooms_by_room_number(RoomType room, const Container& rooms);
    /// @}
};

#include "kondakov_lr5_methods.hpp"

#endif // KONDAKOV_LR5_METHODS_H