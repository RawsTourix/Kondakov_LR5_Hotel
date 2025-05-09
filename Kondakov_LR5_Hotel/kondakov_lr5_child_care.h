/**
 * @file kondakov_lr5_child_care.h
 * @brief Заголовочный файл класса ChildCare (услуги для детей)
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#ifndef KONDAKOV_LR5_CHILD_CARE_H
#define KONDAKOV_LR5_CHILD_CARE_H

#include "kondakov_lr5_input_control.h"

/**
 * @class ChildCare
 * @brief Класс, представляющий услуги по уходу за детьми
 */
class ChildCare {
protected:
    float child_care_price;  ///< Стоимость услуг для детей (в рублях)
    bool  has_child_care;    ///< Флаг наличия услуг для детей

    /**
     * @brief Вывод информации об услугах
     */
    void print() const {
        cout << *this << endl;
    }

    /**
     * @brief Ввод информации об услугах
     * @return true если ввод отменен, false если успешен
     */
    bool input() {
        return static_cast<bool>(cin >> *this);
    }

public:
    /// Валюта для отображения цен
    static const string CURRENCY;

    /// @name Конструкторы
    /// @{
    /**
     * @brief Конструктор по умолчанию
     * @details Создает услуги для детей с параметрами:
     * - Стоимость услуг: 1000.0
     * - Наличие услуг: нет
     */
    ChildCare();

    /**
     * @brief Конструктор преобразования
     * @param has_child_care Наличие услуг для детей
     * @details Создает услуги для детей с указанным параметром:
     * - Стоимость услуг: 1000.0
     */
    ChildCare(bool has_child_care);

    /**
     * @brief Основной конструктор с параметрами
     * @param child_care_price Стоимость услуг
     * @param has_child_care Наличие услуг
     */
    ChildCare(float child_care_price, bool has_child_care);

    /// Конструктор копирования
    ChildCare(const ChildCare&) = default;
    ChildCare& operator=(const ChildCare&) = default;

    /// Конструктор перемещения
    ChildCare(ChildCare&& other) noexcept;
    ChildCare& operator=(ChildCare&&) noexcept = default;
    /// @}

    /// Деструктор
    ~ChildCare() = default;

    /// @name Геттеры
    /// @{
    inline float get_child_care_price() const;
    inline bool get_has_child_care() const;
    /// @}

    /// @name Сеттеры
    /// @{
    inline void set_child_care_price(float child_care_price);
    inline void set_has_child_care(bool has_child_care);
    /// @}

    /// @name Методы ввода
    /// @{
    inline bool input_child_care_price();
    inline bool input_has_child_care();
    /// @}

    /**
     * @brief Преобразование в строку
     * @return Строковое представление услуг
     */
    explicit operator string() const;

    /// @name Операторы ввода/вывода
    /// @{
    friend ostream& operator<<(ostream& os, const ChildCare& cr);
    friend istream& operator>>(istream& is, ChildCare& cr);
    /// @}

    /**
     * @brief Преобразование в строку
     * @return Строковое представление объекта
     */
    virtual string to_string() const;
};

#include "kondakov_lr5_child_care.hpp"

#endif // KONDAKOV_LR5_CHILD_CARE_H