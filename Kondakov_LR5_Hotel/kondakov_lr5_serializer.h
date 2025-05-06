/**
 * @file kondakov_lr5_serializer.h
 * @brief ������������ ���� ��� ������������/�������������� ������
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup serialization
 */

#ifndef KONDAKOV_LR5_SERIALIZER_H
#define KONDAKOV_LR5_SERIALIZER_H

#include "kondakov_lr5_standard_room.h"
#include "kondakov_lr5_suite.h"
#include "kondakov_lr5_family_room.h"

/**
 * @namespace Serializer
 * @brief ������������ ��� ��� �������� ������������
 */
namespace Serializer {

    /**
     * @struct RoomTypeRegistry
     * @brief ����������� ����� ������ ��� ���������� ��������
     */
    struct RoomTypeRegistry {
        map<string, function<shared_ptr<Room>()>> creators; ///< ����� ���������� ��������

        /**
         * @brief ����������� ������������ �����
         * @details �������������� ����� creators ��� ���� ����� ������
         */
        RoomTypeRegistry();
    };

    /// ����������� ��������� ������������ �����
    static RoomTypeRegistry registry;

    /**
     * @brief ������������ ���������� ������ � JSON
     * @tparam Container ��� ���������� (������ ��������� shared_ptr<Room>)
     * @param rooms ��������� � ���������
     * @return JSON ������ � ������� ������
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, json>
    serialize_rooms(const Container& rooms);

    /**
     * @brief �������������� ������ �� JSON
     * @tparam Container ��� ���������� ��� �����������
     * @param j JSON ������ � �������
     * @return ��������� � ������������������ ���������
     * @throws runtime_error ��� ����������� ���� �������
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, Container>
    deserialize_rooms(const json& j);

    /**
     * @brief ���������� ������ � ����
     * @tparam Container ��� ���������� � ���������
     * @param rooms ��������� ��� ����������
     * @param filename ��� ����� ��� ����������
     * @throws runtime_error ��� ������ �������� �����
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, void>
    save_rooms_to_file(const Container& rooms, const string& filename);

    /**
     * @brief �������� ������ �� �����
     * @tparam Container ��� ���������� ��� �����������
     * @param filename ��� ����� ��� ��������
     * @return ��������� � ������������ ���������
     * @throws runtime_error ��� ������ �������� �����
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, Container>
    load_rooms_from_file(const string& filename);
}

#include "kondakov_lr5_serializer.hpp"

#endif // KONDAKOV_LR5_SERIALIZER_H