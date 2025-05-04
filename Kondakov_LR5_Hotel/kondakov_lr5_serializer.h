#ifndef KONDAKOV_LR5_SERIALIZER_H
#define KONDAKOV_LR5_SERIALIZER_H

#include "kondakov_lr5_standard_room.h"
#include "kondakov_lr5_suite.h"
#include "kondakov_lr5_family_room.h"

namespace Serializer {

    // ����������� ����� ����������� Room
    struct RoomTypeRegistry {
        map<string, function<shared_ptr<Room>()>> creators;

        // ����������� �� ���������, ����������� creators
        RoomTypeRegistry();
    };

    // ����������� ������ ������������ ��� ������� ������ ������������ ���
    static RoomTypeRegistry registry;

    // ������� ������ � json
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, json>
    serialize_rooms(const Container& rooms);

    // ������� ������ �� json
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, Container>
    deserialize_rooms(const json& j);

    // ���������� � ����
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, void>
    save_rooms_to_file(const Container& rooms, const string& filename);

    // �������� �� �����
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, Container>
    load_rooms_from_file(const string& filename);
}

#include "kondakov_lr5_serializer.hpp"

#endif // KONDAKOV_LR5_SERIALIZER_H