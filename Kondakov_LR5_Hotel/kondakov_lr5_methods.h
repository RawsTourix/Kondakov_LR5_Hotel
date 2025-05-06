/**
 * @file kondakov_lr5_methods.h
 * @brief Заголовочный файл с методами работы с комнатами
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
 * @brief Пространство имён для операций с комнатами
 */
namespace Methods {
    using ::operator<<;

    /**
     * @struct RoomInfo
     * @brief Краткая информация о комнате для отображения
     */
    struct RoomInfo {
        int number;             ///< Порядковый номер в списке
        string full_name;       ///< Полное название комнаты
        shared_ptr<Room> room;  ///< Указатель на объект комнаты

        RoomInfo() = delete;
        
        /**
         * @brief Конструктор с параметрами
         * @param number Порядковый номер
         * @param full_name Название комнаты
         * @param room Указатель на комнату
         */
        RoomInfo(int number, string full_name, shared_ptr<Room> room);

        /**
         * @brief Вывод информации о комнате
         */
        inline void print() const {
            cout << *this << endl;
        }

        friend ostream& operator<<(ostream& os, const RoomInfo& ri);
    };

    /// @name Основные операции с комнатами
    /// @{
    /**
     * @brief Вывод списка комнат
     * @tparam Container Тип контейнера с комнатами
     * @param rooms Контейнер с комнатами
     * @return Функция для вывода списка
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    show_rooms(const Container& rooms);

    /**
     * @brief Добавление комнаты
     * @tparam RoomType Тип добавляемой комнаты
     * @tparam Container Тип контейнера
     * @param rooms Контейнер для добавления
     * @return Функция для добавления комнаты
     */
    template <typename RoomType, typename Container>
    typename enable_if_t<is_base_of_v<Room, typename RoomType>&&
                         is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    add_room(Container& rooms);

    /**
     * @brief Изменение комнаты
     * @tparam Container Тип контейнера
     * @param rooms Контейнер с комнатами
     * @return Функция для изменения комнаты
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    edit_room(Container& rooms);

    /**
     * @brief Удаление комнаты
     * @tparam Container Тип контейнера
     * @param rooms Контейнер с комнатами
     * @return Функция для удаления комнаты
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    delete_room(Container& rooms);

    /**
     * @brief Сортировка комнат
     * @tparam Container Тип контейнера
     * @param rooms Контейнер для сортировки
     * @return Функция для сортировки
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    sort_rooms(Container& rooms);

    /**
     * @brief Расчёт стоимости проживания
     * @tparam Container Тип контейнера
     * @param rooms Контейнер с комнатами
     * @return Функция для расчёта
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    calculate_total(Container& rooms);

    /**
     * @brief Проверка валидности комнаты
     * @tparam Container Тип контейнера
     * @param rooms Контейнер с комнатами
     * @return Функция для проверки
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    validate_room(Container& rooms);

    /**
     * @brief Дополнительные методы комнат
     * @tparam Container Тип контейнера
     * @param rooms Контейнер с комнатами
     * @return Функция для работы с доп. методами
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    additional_room_methods(Container& rooms);
    /// @}

    /// @name Вспомогательные методы
    /// @{
    /**
     * @brief Выбор комнаты из списка
     * @tparam Container Тип контейнера
     * @param main_label Заголовок меню
     * @param message Приглашение для ввода
     * @param rooms Контейнер с комнатами
     * @return Указатель на выбранную комнату
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, shared_ptr<Room>>
    get_room_from_rooms_map(string main_label, string message, Container& rooms);

    /**
     * @brief Получение списка номеров комнат
     * @tparam Container Тип контейнера
     * @param rooms Контейнер с комнатами
     * @return Вектор номеров комнат
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, vector<int>>
    get_room_numbers(const Container& rooms);

    /**
     * @brief Проверка существования комнаты
     * @tparam RoomType Тип комнаты
     * @tparam Container Тип контейнера
     * @param room Проверяемая комната
     * @param rooms Контейнер для проверки
     * @return true если комната существует
     */
    template <typename RoomType, typename Container>
    typename enable_if_t<is_base_of_v<Room, typename RoomType>&&
                         is_same_v<typename Container::value_type, shared_ptr<Room>>, bool>
    room_in_rooms_by_room_number(RoomType room, const Container& rooms);
    /// @}
};

#include "kondakov_lr5_methods.hpp"

#endif // KONDAKOV_LR5_METHODS_H