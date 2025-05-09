/**
 * @file kondakov_lr5_family_room.h
 * @brief Заголовочный файл класса FamilyRoom (семейный номер)
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#ifndef KONDAKOV_LR5_FAMILY_ROOM_H
#define KONDAKOV_LR5_FAMILY_ROOM_H

#include "kondakov_lr5_room.h"
#include "kondakov_lr5_child_care.h"

/**
 * @class FamilyRoom
 * @brief Класс семейного номера, наследует Room и ChildCare
 */
class FamilyRoom final : virtual public Room, virtual public ChildCare {
private:
    int             child_beds;  ///< Количество детских кроватей
    bool            toy_kit;     ///< Наличие набора игрушек
    vector<string>  amenities;   ///< Список удобств

    const string ROOM_TYPE = "Семейная комната";  ///< Тип комнаты для отображения
    const string JSON_TYPE = "Family";            ///< Тип для сериализации в JSON

public:
    /// @name Конструкторы
    /// @{
    /**
     * @brief Конструктор по умолчанию
     * @details Создает семейный номер с параметрами:
     * - Номер комнаты: 0
     * - Цена за ночь: 0.0
     * - Статус бронирования: нет
     * - Стоимость услуг для детей: 0.0
     * - Наличие услуг для детей: нет
     * - Детских кроватей: 0
     * - Набор игрушек: нет
     * - Список удобств: "Wi-Fi", "Air condition"
     */
    FamilyRoom();

    /**
     * @brief Базовый конструктор
     * @param room_number Номер комнаты
     * @param child_beds Количество детских кроватей
     * @details Создает семейный номер с указанными параметрами:
     * - Цена за ночь: 0.0
     * - Статус бронирования: нет
     * - Стоимость услуг для детей: 0.0
     * - Наличие услуг для детей: нет
     * - Набор игрушек: нет
     * - Список удобств: "Wi-Fi", "Air condition"
     */
    FamilyRoom(int room_number, int child_beds);

    /**
     * @brief Конструктор с удобствами по умолчанию
     * @param room_number Номер комнаты
     * @param price_per_night Цена за ночь
     * @param is_booked Статус бронирования
     * @param child_care_price Стоимость услуг для детей
     * @param has_child_care Наличие услуг для детей
     * @param child_beds Количество детских кроватей
     * @param toy_kit Набор игрушек
     * @details Создает семейный номер с указанными параметрамис и удобствами по умолчанию: "Wi-Fi", "Air condition"
     */
    FamilyRoom(int room_number, float price_per_night, bool is_booked,
        float child_care_price, bool has_child_care,
        int child_beds, bool toy_kit);

    /**
     * @brief Конструктор с параметрами (удобства в строке)
     * @param room_number Номер комнаты
     * @param price_per_night Цена за ночь
     * @param is_booked Статус бронирования
     * @param child_care_price Стоимость услуг для детей
     * @param has_child_care Наличие услуг для детей
     * @param child_beds Количество детских кроватей
     * @param toy_kit Набор игрушек
     * @param amenities Удобства (строка, разделитель - запятая)
     */
    FamilyRoom(int room_number, float price_per_night, bool is_booked,
        float child_care_price, bool has_child_care,
        int child_beds, bool toy_kit, string amenities);

    /**
     * @brief Конструктор с параметрами (удобства в векторе)
     * @param room_number Номер комнаты
     * @param price_per_night Цена за ночь
     * @param is_booked Статус бронирования
     * @param child_care_price Стоимость услуг для детей
     * @param has_child_care Наличие услуг для детей
     * @param child_beds Количество детских кроватей
     * @param toy_kit Набор игрушек
     * @param amenities Удобства (вектор строк)
     */
    FamilyRoom(int room_number, float price_per_night, bool is_booked,
        float child_care_price, bool has_child_care,
        int child_beds, bool toy_kit, vector<string> amenities);

    /// Конструктор копирования
    FamilyRoom(const FamilyRoom&) = default;
    FamilyRoom& operator=(const FamilyRoom&) = default;

    /// Конструктор перемещения
    FamilyRoom(FamilyRoom&& other) noexcept;
    FamilyRoom& operator=(FamilyRoom&&) noexcept = default;
    /// @}

    /// Деструктор
    virtual ~FamilyRoom() = default;

    /// @name Геттеры
    /// @{
    inline int get_child_beds() const;
    inline bool get_toy_kit() const;
    virtual inline const vector<string>& get_amenities() const override;
    virtual inline string get_full_name() const override;
    /// @}

    /// @name Сеттеры
    /// @{
    inline void set_child_beds(int child_beds);
    inline void set_toy_kit(bool toy_kit);
    inline void set_amenities(vector<string> amenities);
    /// @}

    /// @name Методы ввода
    /// @{
    inline bool input_child_beds();
    inline bool input_toy_kit();
    template <char Delim = ','>
    inline bool input_amenities();
    /// @}

    /// @name Переопределенные методы
    /// @{
    virtual inline const string& get_room_type() const override;
    virtual inline const string& get_json_type() const override;
    virtual inline float calculate_total(int night_count) const override;
    virtual inline bool validate() const override;
    /// @}

    /// @name Дополнительные методы
    /// @{
    inline void add_play_area();
    inline void remove_play_area();
    /// @}

    /// @name JSON методы
    /// @{
    virtual json to_json() const override;
    virtual void from_json(const json& j) override;
    /// @}

    /// @name Операторы доступа по индексу
    /// @{
    string operator[](int index) const;
    template <typename T>
    typename enable_if_t<is_same_v<T, float>, T> operator[](int index) const;
    template <typename T>
    typename enable_if_t<is_same_v<T, bool>, T> operator[](int index) const;
    template <typename T>
    typename enable_if_t<is_same_v<T, int>, T> operator[](int index) const;
    template <typename T>
    typename enable_if_t<is_same_v<T, string>, T> operator[](int index) const;
    template <typename T>
    typename enable_if_t<is_same_v<T, float>, T&> operator[](int index);
    template <typename T>
    typename enable_if_t<is_same_v<T, bool>, T&> operator[](int index);
    template <typename T>
    typename enable_if_t<is_same_v<T, int>, T&> operator[](int index);
    template <typename T>
    typename enable_if_t<is_same_v<T, string>, T&> operator[](int index);
    /// @}

    /// @name Операторы сложения удобств
    /// @{
    friend vector<string>  operator+(const FamilyRoom& fr1, const FamilyRoom& fr2);
    friend vector<string>  operator+(const vector<string>& amenities, const FamilyRoom& fr);
    friend vector<string>  operator+(const FamilyRoom& fr, const vector<string>& amenities);
    friend vector<string>& operator+=(vector<string>& amenities, const FamilyRoom& fr);
    friend FamilyRoom&     operator+=(FamilyRoom& fr, const vector<string>& amenities);
    friend FamilyRoom&     operator+=(FamilyRoom& fr, const string& amenities);
    /// @}

    /// @name Преобразования и ввод/вывод
    /// @{
    explicit operator string() const;
    friend ostream& operator<<(ostream& os, const FamilyRoom& r);
    friend istream& operator>>(istream& is, FamilyRoom& r);
    virtual void print() const override;
    virtual bool input() override;
    virtual string to_string() const override;
    /// @}
};

#include "kondakov_lr5_family_room.hpp"

#endif // KONDAKOV_LR5_FAMILY_ROOM_H