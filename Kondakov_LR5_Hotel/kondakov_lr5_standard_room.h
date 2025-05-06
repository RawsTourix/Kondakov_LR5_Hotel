/**
 * @file kondakov_lr5_standard_room.h
 * @brief Заголовочный файл класса StandardRoom
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
 * @brief Класс стандартного номера (наследник Room)
 */
class StandardRoom final : virtual public Room {
private:
    int             bed_count;  ///< Количество кроватей
    bool            has_tv;     ///< Наличие телевизора
    vector<string>  amenities;  ///< Удобства

    const string ROOM_TYPE = "Стандартная комната";  ///< Тип комнаты
    const string JSON_TYPE = "Standard";             ///< Тип для JSON

public:
    /// Конструктор по умолчанию
    StandardRoom();

    /**
     * @brief Конструктор преобразования
     * @param room_number Номер комнаты
     * @param bed_count Количество кроватей
     */
    StandardRoom(int room_number, int bed_count);

    /**
     * @brief Конструктор с удобствами по умолчанию
     * @param room_number Номер комнаты
     * @param price_per_night Цена за ночь
     * @param is_booked Статус бронирования
     * @param bed_count Количество кроватей
     * @param has_tv Наличие телевизора
     */
    StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv);

    /**
     * @brief Конструктор с параметрами (удобства строка)
     * @param room_number Номер комнаты
     * @param price_per_night Цена за ночь
     * @param is_booked Статус бронирования
     * @param bed_count Количество кроватей
     * @param has_tv Наличие телевизора
     * @param amenities Удобства (строка с разделителями)
     */
    StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv, string amenities);

    /**
     * @brief Конструктор с параметрами (удобства вектор)
     * @param room_number Номер комнаты
     * @param price_per_night Цена за ночь
     * @param is_booked Статус бронирования
     * @param bed_count Количество кроватей
     * @param has_tv Наличие телевизора
     * @param amenities Удобства (вектор строк)
     */
    StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv, vector<string> amenities);

    /// Конструктор копирования
    StandardRoom(const StandardRoom&) = default;
    StandardRoom& operator=(const StandardRoom&) = default;

    /// Конструктор перемещения
    StandardRoom(StandardRoom&& other) noexcept;
    StandardRoom& operator=(StandardRoom&&) noexcept = default;

    /// Деструктор
    virtual ~StandardRoom() = default;

    /// @name Геттеры
    /// @{
    inline int get_bed_count() const;
    inline bool get_has_tv() const;
    virtual inline const vector<string>& get_amenities() const override;
    virtual inline string get_full_name() const override;
    /// @}

    /// @name Сеттеры
    /// @{
    inline void set_bed_count(int bed_count);
    inline void set_has_tv(bool has_tv);
    inline void set_amenities(vector<string> amenities);
    /// @}

    /// @name Методы ввода
    /// @{
    inline bool input_bed_count();
    inline bool input_has_tv();
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

    /// Добавить дополнительную кровать (+20% к цене)
    inline void exstra_bed();

    /// @name JSON методы
    /// @{
    virtual json to_json() const override;
    virtual void from_json(const json& j) override;
    /// @}

    /// @name Операторы сложения удобств
    /// @{
    friend vector<string>  operator+ (const StandardRoom& sr1, const StandardRoom& sr2);
    friend vector<string>  operator+ (const vector<string>& amenities, const StandardRoom& sr);
    friend vector<string>  operator+ (const StandardRoom& sr, const vector<string>& amenities);
    friend vector<string>& operator+=(vector<string>& amenities, const StandardRoom& sr);
    friend StandardRoom&   operator+=(StandardRoom& sr, const vector<string>& amenities);
    friend StandardRoom&   operator+=(StandardRoom& sr, const string& amenities);
    /// @}

    /// Преобразование в строку
    explicit operator string() const;

    /// @name Операторы ввода/вывода
    /// @{
    friend ostream& operator<<(ostream& os, const StandardRoom& r);
    friend istream& operator>>(istream& is, StandardRoom& r);
    /// @}

    /// @name Переопределенные методы вывода/ввода
    /// @{
    virtual void print() const override;
    virtual bool input() override;
    virtual string to_string() const override;
    /// @}
};

#include "kondakov_lr5_standard_room.hpp"

#endif // KONDAKOV_LR5_STANDARD_ROOM_H