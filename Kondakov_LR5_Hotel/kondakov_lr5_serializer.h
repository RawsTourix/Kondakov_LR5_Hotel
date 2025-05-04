#ifndef KONDAKOV_LR5_SERIALIZER_H
#define KONDAKOV_LR5_SERIALIZER_H

#include "kondakov_lr5_standard_room.h"
#include "kondakov_lr5_suite.h"
#include "kondakov_lr5_family_room.h"

namespace Serializer {

    // Регистратор типов наследников Room
    struct RoomTypeRegistry {
        map<string, function<shared_ptr<Room>()>> creators;

        // Конструктор по умолчанию, заполняющий creators
        RoomTypeRegistry();
    };

    // Статический объект регистратора для доступа внутри пространства имён
    static RoomTypeRegistry registry;

    // Парсинг комнат в json
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, json>
    serialize_rooms(const Container& rooms);

    // Парсинг комнат из json
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, Container>
    deserialize_rooms(const json& j);

    // Сохранение в файл
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, void>
    save_rooms_to_file(const Container& rooms, const string& filename);

    // Загрузка из файла
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, Container>
    load_rooms_from_file(const string& filename);
}

#include "kondakov_lr5_serializer.hpp"

#endif // KONDAKOV_LR5_SERIALIZER_H