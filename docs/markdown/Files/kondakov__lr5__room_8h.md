---
title: Kondakov_LR5_Hotel/kondakov_lr5_room.h
summary: Заголовочный файл абстрактного класса Room. 

---

# Kondakov_LR5_Hotel/kondakov_lr5_room.h

Заголовочный файл абстрактного класса [Room](Classes/class_room.md).  [More...](#detailed-description)

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[Room](Classes/class_room.md)** <br>Абстрактный базовый класс для представления гостиничного номера  |

## Detailed Description

Заголовочный файл абстрактного класса [Room](Classes/class_room.md). 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 



## Source code

```cpp


#ifndef KONDAKOV_LR5_ROOM_H
#define KONDAKOV_LR5_ROOM_H


#include "kondakov_lr5_input_control.h"

class Room {
protected:
    int     room_number;      
    float   price_per_night;  
    bool    is_booked;        

    virtual void print() const {
        cout << *this << endl;
    }

    virtual bool input() {
        return static_cast<bool>(cin >> *this);
    }

public:
    static const string CURRENCY;


    Room();

    Room(int room_number);

    Room(int room_number, float price_per_night, bool is_booked);

    Room(const Room&) = default;
    Room& operator=(const Room&) = default;

    Room(Room&& other) noexcept;
    Room& operator=(Room&&) noexcept = default;

    virtual ~Room() = default;

    inline int get_room_number() const;
    inline float get_price_per_night() const;
    inline bool get_is_booked() const;
    virtual inline const vector<string>& get_amenities() const = 0;
    virtual inline string get_full_name() const = 0;

    inline void set_room_number(int room_number);
    inline void set_price_per_night(float price_per_night);
    inline void set_is_booked(bool is_booked);

    inline bool input_room_number();
    template <typename Container>
    inline typename enable_if_t<is_same_v<typename Container::value_type, int>, bool>
    input_room_number(const Container& room_numbers);
    inline bool input_price_per_night();
    inline bool input_is_booked();

    virtual inline const string& get_room_type() const = 0;
    virtual inline const string& get_json_type() const = 0;
    virtual inline float calculate_total(int night_count) const = 0;
    virtual inline bool validate() const = 0;
    virtual json to_json() const = 0;
    virtual void from_json(const json& j) = 0;

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

    explicit operator string() const;

    friend ostream& operator<<(ostream& os, const Room& r);
    friend istream& operator>>(istream& is, Room& r);

    virtual string to_string() const;

    template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, ostream&>
    friend operator<<(ostream& os, const Container& rooms);
};

#include "kondakov_lr5_room.hpp"
 // Конец группы room_hierarchy

#endif // KONDAKOV_LR5_ROOM_H
```


-------------------------------

Updated on 2025-05-09 at 18:16:45 +0300
