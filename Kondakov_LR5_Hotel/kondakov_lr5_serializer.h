/**
 * @file kondakov_lr5_serializer.h
 * @brief Заголовочный файл для сериализации/десериализации комнат
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
 * @brief Пространство имён для операций сериализации
 */
namespace Serializer {

    /**
     * @struct RoomTypeRegistry
     * @brief Регистратор типов комнат для фабричного создания
     */
    struct RoomTypeRegistry {
        map<string, function<shared_ptr<Room>()>> creators; ///< Карта создателей объектов

        /**
         * @brief Конструктор регистратора типов
         * @details Инициализирует карту creators для всех типов комнат
         */
        RoomTypeRegistry();
    };

    /// Статический экземпляр регистратора типов
    static RoomTypeRegistry registry;

    /**
     * @brief Сериализация контейнера комнат в JSON
     * @tparam Container Тип контейнера (должен содержать shared_ptr<Room>)
     * @param rooms Контейнер с комнатами
     * @return JSON объект с данными комнат
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, json>
    serialize_rooms(const Container& rooms);

    /**
     * @brief Десериализация комнат из JSON
     * @tparam Container Тип контейнера для результатов
     * @param j JSON объект с данными
     * @return Контейнер с десериализованными комнатами
     * @throws runtime_error При неизвестном типе комнаты
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, Container>
    deserialize_rooms(const json& j);

    /**
     * @brief Сохранение комнат в файл
     * @tparam Container Тип контейнера с комнатами
     * @param rooms Контейнер для сохранения
     * @param filename Имя файла для сохранения
     * @throws runtime_error При ошибке открытия файла
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, void>
    save_rooms_to_file(const Container& rooms, const string& filename);

    /**
     * @brief Загрузка комнат из файла
     * @tparam Container Тип контейнера для результатов
     * @param filename Имя файла для загрузки
     * @return Контейнер с загруженными комнатами
     * @throws runtime_error При ошибке открытия файла
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, Container>
    load_rooms_from_file(const string& filename);
}

#include "kondakov_lr5_serializer.hpp"

#endif // KONDAKOV_LR5_SERIALIZER_H