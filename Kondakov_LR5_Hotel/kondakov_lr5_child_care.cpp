/**
 * @file kondakov_lr5_child_care.cpp
 * @brief Реализация методов класса ChildCare
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#include "kondakov_lr5_child_care.h"

const string ChildCare::CURRENCY = "руб.";  ///< Инициализация статического поля

/**
 * @brief Конструктор по умолчанию
 */
ChildCare::ChildCare()
    : ChildCare(1000.0f, false) {
}

/**
 * @brief Конструктор преобразования
 * @param has_child_care Наличие услуг для детей
 */
ChildCare::ChildCare(bool has_child_care)
    : ChildCare(1000.0f, has_child_care) {
}

/**
 * @brief Конструктор с параметрами
 * @param child_care_price Стоимость услуг
 * @param has_child_care Наличие услуг
 */
ChildCare::ChildCare(float child_care_price, bool has_child_care)
    : child_care_price(child_care_price),
      has_child_care(has_child_care) {
}

/**
 * @brief Конструктор перемещения
 * @param other Другой объект ChildCare
 */
ChildCare::ChildCare(ChildCare&& other) noexcept
    : child_care_price(other.child_care_price),
      has_child_care(other.has_child_care) {
}

/**
 * @brief Преобразование в строку
 */
ChildCare::operator string() const {
    ostringstream oss;
    oss << "Стоимость услуг для детей:\t" << child_care_price << " " << CURRENCY << endl
        << "Наличие услуг для детей:\t"   << (has_child_care ? "да" : "нет");
    return oss.str();
}

/**
 * @brief Оператор вывода
 * @param os Поток вывода
 * @param cr Объект для вывода
 * @return Поток вывода
 */
ostream& operator<<(ostream& os, const ChildCare& cr) {
    os << static_cast<string>(cr);
    return os;
}

/**
 * @brief Оператор ввода
 * @param is Поток ввода
 * @param cr Объект для ввода
 * @return Поток ввода
 */
istream& operator>>(istream& is, ChildCare& cr) {
    if (cr.input_child_care_price()) { is.setstate(ios::failbit); return is; }
    if (cr.input_has_child_care())   { is.setstate(ios::failbit); return is; }
    return is;
}

/**
 * @brief Преобразование в строку
 * @return Строковое представление объекта
 */
string ChildCare::to_string() const {
    ostringstream oss;
    oss << *this;
    return oss.str();
}