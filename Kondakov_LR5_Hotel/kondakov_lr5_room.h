/**
 * @file kondakov_lr5_room.h
 * @brief Заголовочный файл абстрактного класса Room
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup room_hierarchy
 */

#ifndef KONDAKOV_LR5_ROOM_H
#define KONDAKOV_LR5_ROOM_H

#include "kondakov_lr5_input_control.h"

/**
 * @class Room
 * @brief Абстрактный базовый класс для представления гостиничного номера
 */
class Room {
protected:
    int     room_number;      ///< Номер комнаты
    float   price_per_night;  ///< Цена за ночь
    bool    is_booked;        ///< Статус бронирования

    /**
     * @brief Виртуальный метод вывода информации о комнате
     */
    virtual void print() const {
        cout << *this << endl;
    }

    /**
     * @brief Виртуальный метод ввода информации о комнате
     * @return true если операция отменена, false если успешно
     */
    virtual bool input() {
        return static_cast<bool>(cin >> *this);
    }

public:
    /// Валюта для отображения цен
    static const string CURRENCY;

    /// Конструктор по умолчанию
    Room();

    /// Конструктор преобразования (по номеру комнаты)
    Room(int room_number);

    /**
     * @brief Конструктор с параметрами
     * @param room_number Номер комнаты
     * @param price_per_night Цена за ночь
     * @param is_booked Статус бронирования
     */
    Room(int room_number, float price_per_night, bool is_booked);

    /// Конструктор копирования
    Room(const Room&) = default;
    Room& operator=(const Room&) = default;

    /// Конструктор перемещения
    Room(Room&& other) noexcept;
    Room& operator=(Room&&) noexcept = default;

    /// Виртуальный деструктор
    virtual ~Room() = default;

    /// @name Геттеры
    /// @{
    inline int get_room_number() const;
    inline float get_price_per_night() const;
    inline bool get_is_booked() const;
    virtual inline const vector<string>& get_amenities() const = 0;
    virtual inline string get_full_name() const = 0;
    /// @}

    /// @name Сеттеры
    /// @{
    inline void set_room_number(int room_number);
    inline void set_price_per_night(float price_per_night);
    inline void set_is_booked(bool is_booked);
    /// @}

    /// @name Методы ввода
    /// @{
    inline bool input_room_number();
    template <typename Container>
    inline typename enable_if_t<is_same_v<typename Container::value_type, int>, bool>
    input_room_number(const Container& room_numbers);
    inline bool input_price_per_night();
    inline bool input_is_booked();
    /// @}

    /// @name Абстрактные методы
    /// @{
    virtual inline const string& get_room_type() const = 0;
    virtual inline const string& get_json_type() const = 0;
    virtual inline float calculate_total(int night_count) const = 0;
    virtual inline bool validate() const = 0;
    virtual json to_json() const = 0;
    virtual void from_json(const json& j) = 0;
    /// @}

    /// @name Операторы сравнения
    /// @{
    friend bool operator==(const Room& r1, const Room& r2);
    friend bool operator==(int room_number, const Room& r2);
    friend bool operator==(const Room& r1, int room_number);
    friend bool operator>=(const Room& r1, const Room& r2);
    friend bool operator>=(int room_number, const Room& r2);
    friend bool operator>=(const Room& r1, int room_number);
    friend bool operator<=(const Room& r1, const Room& r2);
    friend bool operator<=(int room_number, const Room& r2);
    friend bool operator<=(const Room& r1, int room_number);
    friend bool operator> (const Room& r1, const Room& r2);
    friend bool operator> (int room_number, const Room& r2);
    friend bool operator> (const Room& r1, int room_number);
    friend bool operator< (const Room& r1, const Room& r2);
    friend bool operator< (int room_number, const Room& r2);
    friend bool operator< (const Room& r1, int room_number);
    friend bool operator!=(const Room& r1, const Room& r2);
    friend bool operator!=(int room_number, const Room& r2);
    friend bool operator!=(const Room& r1, int room_number);
    /// @}

    /// Преобразование в строку
    explicit operator string() const;

    /// @name Операторы ввода/вывода
    /// @{
    friend ostream& operator<<(ostream& os, const Room& r);
    friend istream& operator>>(istream& is, Room& r);
    /// @}

    /// Виртуальный метод преобразования в строку
    virtual string to_string() const;

    /**
     * @brief Перегрузка вывода для контейнера комнат
     * @tparam Container Тип контейнера (должен содержать shared_ptr<Room>)
     */
    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, ostream&>
    friend operator<<(ostream& os, const Container& rooms);
};

#include "kondakov_lr5_room.hpp"

#endif // KONDAKOV_LR5_ROOM_H