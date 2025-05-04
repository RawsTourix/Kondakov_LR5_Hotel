#ifndef KONDAKOV_LR5_SERIALIZER_HPP
#define KONDAKOV_LR5_SERIALIZER_HPP

#include "kondakov_lr5_serializer.h"

// ������� ������ � json
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, json>
Serializer::serialize_rooms(const Container& rooms) {
    json j;

    for (const auto& room : rooms) {
        json room_json = room->to_json();
        room_json["type"] = room->get_room_type();
        j.push_back(room_json);
    }

    return j;
}

// ������� ������ �� json
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, Container>
Serializer::deserialize_rooms(const json& j) {
    vector<shared_ptr<Room>> rooms;

    for (const auto& item : j) {
        const string type(item["type"]);
        auto it = registry.creators.find(type);
        if (it == registry.creators.end()) {
            throw runtime_error("����������� ��� �������: " + type);
        }

        auto room = it->second();
        room->from_json(item);
        rooms.push_back(room);
    }

    return rooms;
}

// ���������� � ����
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, void>
Serializer::save_rooms_to_file(const Container& rooms, const string& filename) {
    ofstream f(filename);
    if (!f.is_open()) {
        throw runtime_error("������ �������� �����: " + filename);
    }

    f << serialize_rooms(rooms).dump(2);
}

// �������� �� �����
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, Container>
Serializer::load_rooms_from_file(const string& filename) {
    ifstream f(filename);
    if (!f.is_open()) {
        throw runtime_error("������ �������� �����: " + filename);
    }

    json j;
    f >> j;
    return deserialize_rooms<Container>(j);
}

#endif // KONDAKOV_LR5_SERIALIZER_HPP