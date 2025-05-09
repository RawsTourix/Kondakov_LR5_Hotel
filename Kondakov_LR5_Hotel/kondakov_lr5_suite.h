/**
 * @file kondakov_lr5_suite.h
 * @brief Заголовочный файл класса Suite (номер люкс)
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#ifndef KONDAKOV_LR5_SUITE_H
#define KONDAKOV_LR5_SUITE_H

#include "kondakov_lr5_room.h"

/**
 * @class Suite
 * @brief Класс номера люкс, наследующий от Room
 * @details Представляет номер повышенной комфортности с дополнительными услугами
 */
class Suite final : virtual public Room {
private:
    bool            room_service;  ///< Наличие обслуживания в номере
    bool            jacuzzi;       ///< Наличие джакузи
    vector<string>  amenities;     ///< Удобства

    const float SERVICE_PRICE = 5000.0f;      ///< Базовая стоимость услуг
    const string ROOM_TYPE = "Люкс комната";  ///< Тип комнаты для отображения
    const string JSON_TYPE = "Suite";         ///< Тип для сериализации в JSON

public:
    /// @name Конструкторы
    /// @{
    /**
     * @brief Конструктор по умолчанию
     * @details Создает номер люкс с параметрами:
     * - Номер комнаты: 0
     * - Цена за ночь: 0.0
     * - Статус бронирования: нет
     * - Обслуживание в номере: нет
     * - Наличие джакузи: нет
     * - Список удобств: "Lux", "Room service"
     */
    Suite();

    /**
     * @brief Конструктор преобразования
     * @param room_number Номер комнаты
     * @param room_service Обслуживание в номере
     * @details Создает номер люкс с указанными параметрами и значениями по умолчанию:
     * - Цена за ночь: 0.0
     * - Статус бронирования: нет
     * - Наличие джакузи: нет
     * - Список удобств: "Lux", "Room service"
     */
    Suite(int room_number, bool room_service);

    /**
     * @brief Конструктор с удобствами по умолчанию
     * @param room_number Номер комнаты
     * @param price_per_night Цена за ночь
     * @param is_booked Статус бронирования
     * @param room_service Обслуживание в номере
     * @param jacuzzi Наличие джакузи
     * @details Создает номер люкс с указанными параметрами и удобствами по умолчанию: "Lux", "Room service"
     */
    Suite(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi);

    /**
     * @brief Конструктор с параметрами (удобства строка)
     * @param room_number Номер комнаты
     * @param price_per_night Цена за ночь
     * @param is_booked Статус бронирования
     * @param room_service Обслуживание в номере
     * @param jacuzzi Наличие джакузи
     * @param amenities Удобства (строка, разделитель - запятая)
     */
    Suite(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi, string amenities);

    /**
     * @brief Конструктор с параметрами (удобства вектор)
     * @param room_number Номер комнаты
     * @param price_per_night Цена за ночь
     * @param is_booked Статус бронирования
     * @param room_service Обслуживание в номере
     * @param jacuzzi Наличие джакузи
     * @param amenities Удобства (вектор строк)
     */
    Suite(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi, vector<string> amenities);

    /// Конструктор копирования
    Suite(const Suite&) = default;
    Suite& operator=(const Suite&) = default;

    /// Конструктор перемещения
    Suite(Suite&& other) noexcept;
    Suite& operator=(Suite&&) noexcept = default;
    /// @}

    /// Деструктор
    virtual ~Suite() = default;

    /// @name Геттеры
    /// @{
    inline bool get_room_service() const;
    inline bool get_jacuzzi() const;
    virtual inline const vector<string>& get_amenities() const override;
    virtual inline string get_full_name() const override;
    /// @}

    /// @name Сеттеры
    /// @{
    inline void set_room_service(bool room_service);
    inline void set_jacuzzi(bool jacuzzi);
    inline void set_amenities(vector<string> amenities);
    /// @}

    /// @name Методы ввода
    /// @{
    inline bool input_room_service();
    inline bool input_jacuzzi();
    template <char Delim>
    inline bool input_amenities();
    /// @}

    /// @name Переопределенные методы
    /// @{
    virtual inline const string& get_room_type() const override;
    virtual inline const string& get_json_type() const override;
    virtual inline float calculate_total(int night_count) const override;
    virtual inline bool validate() const override;
    /// @}

    /**
     * @brief Заказать шампанское (добавляет услугу)
     * @param amenity Название услуги
     * @details Увеличивает цену на 2000 руб. и добавляет услугу в список
     */
    inline void order_champagne(string amenity);

    /// @name JSON методы
    /// @{
    virtual json to_json() const override;
    virtual void from_json(const json& j) override;
    /// @}

    /// @name Операторы сложения удобств
    /// @{
    friend vector<string>  operator+ (const Suite& s1, const Suite& s2);
    friend vector<string>  operator+ (const vector<string>& amenities, const Suite& s);
    friend vector<string>  operator+ (const Suite& s, const vector<string>& amenities);
    friend vector<string>& operator+=(vector<string>& amenities, const Suite& s);
    friend Suite&          operator+=(Suite& s, const vector<string>& amenities);
    friend Suite&          operator+=(Suite& s, const string& amenities);
    /// @}

    /// Преобразование в строку
    explicit operator string() const;

    /// @name Операторы ввода/вывода
    /// @{
    friend ostream& operator<<(ostream& os, const Suite& r);
    friend istream& operator>>(istream& is, Suite& r);
    /// @}

    /// @name Переопределенные методы вывода/ввода
    /// @{
    virtual void print() const override;
    virtual bool input() override;
    virtual string to_string() const override;
    /// @}
};

#include "kondakov_lr5_suite.hpp"

#endif // KONDAKOV_LR5_SUITE_H