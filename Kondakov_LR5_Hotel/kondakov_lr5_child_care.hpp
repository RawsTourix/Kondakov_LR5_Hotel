/**
 * @file kondakov_lr5_child_care.hpp
 * @brief Реализация методов класса ChildCare
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#ifndef KONDAKOV_LR5_CHILD_CARE_HPP
#define KONDAKOV_LR5_CHILD_CARE_HPP

#include "kondakov_lr5_child_care.h"

/**
 * @brief Получить стоимость услуг для детей
 * @return Стоимость услуг в рублях
 */
inline float ChildCare::get_child_care_price() const {
    return child_care_price;
}

/**
 * @brief Получить наличие услуг для детей
 * @return true если услуги доступны, false если нет
 */
inline bool ChildCare::get_has_child_care() const {
    return has_child_care;
}

/**
 * @brief Установить стоимость услуг для детей
 * @param child_care_price Новая стоимость услуг
 */
inline void ChildCare::set_child_care_price(float child_care_price) {
    this->child_care_price = child_care_price;
}

/**
 * @brief Установить наличие услуг для детей
 * @param has_child_care Новое значение наличия услуг
 */
inline void ChildCare::set_has_child_care(bool has_child_care) {
    this->has_child_care = has_child_care;
}

/**
 * @brief Ввод стоимости услуг для детей
 * @return true если ввод отменен, false если успешен
 */
inline bool ChildCare::input_child_care_price() {
    ostringstream message;
    message << "Стоимость услуг для детей (" << CURRENCY << "): ";
    if (InputControl::input(child_care_price, message.str(), 0.0f, 10000.0f)) { 
        return true; 
    }
    return false;
}

/**
 * @brief Ввод наличия услуг для детей
 * @return true если ввод отменен, false если успешен
 */
inline bool ChildCare::input_has_child_care() {
    if (InputControl::input(has_child_care, "Наличие услуг для детей (1/0): ")) { 
        return true; 
    }
    return false;
}

#endif // KONDAKOV_LR5_CHILD_CARE_HPP