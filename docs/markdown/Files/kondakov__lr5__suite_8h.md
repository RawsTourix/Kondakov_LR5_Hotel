---
title: Kondakov_LR5_Hotel/kondakov_lr5_suite.h
summary: Заголовочный файл класса Suite (номер люкс) 

---

# Kondakov_LR5_Hotel/kondakov_lr5_suite.h

Заголовочный файл класса [Suite](Classes/class_suite.md) (номер люкс)  [More...](#detailed-description)

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[Suite](Classes/class_suite.md)** <br>Класс номера люкс, наследующий от [Room](Classes/class_room.md).  |

## Detailed Description

Заголовочный файл класса [Suite](Classes/class_suite.md) (номер люкс) 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 



## Source code

```cpp


#ifndef KONDAKOV_LR5_SUITE_H
#define KONDAKOV_LR5_SUITE_H

#include "kondakov_lr5_room.h"

class Suite final : virtual public Room {
private:
    bool            room_service;  
    bool            jacuzzi;       
    vector<string>  amenities;     

    const float SERVICE_PRICE = 5000.0f;      
    const string ROOM_TYPE = "Люкс комната";  
    const string JSON_TYPE = "Suite";         

public:

    Suite();

    Suite(int room_number, bool room_service);

    Suite(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi);

    Suite(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi, string amenities);

    Suite(int room_number, float price_per_night, bool is_booked, bool room_service, bool jacuzzi, vector<string> amenities);

    Suite(const Suite&) = default;
    Suite& operator=(const Suite&) = default;

    Suite(Suite&& other) noexcept;
    Suite& operator=(Suite&&) noexcept = default;

    virtual ~Suite() = default;

    inline bool get_room_service() const;
    inline bool get_jacuzzi() const;
    virtual inline const vector<string>& get_amenities() const override;
    virtual inline string get_full_name() const override;

    inline void set_room_service(bool room_service);
    inline void set_jacuzzi(bool jacuzzi);
    inline void set_amenities(vector<string> amenities);

    inline bool input_room_service();
    inline bool input_jacuzzi();
    template <char Delim>
    inline bool input_amenities();

    virtual inline const string& get_room_type() const override;
    virtual inline const string& get_json_type() const override;
    virtual inline float calculate_total(int night_count) const override;
    virtual inline bool validate() const override;

    inline void order_champagne(string amenity);

    virtual json to_json() const override;
    virtual void from_json(const json& j) override;

    friend vector<string>  operator+ (const Suite& s1, const Suite& s2);
    friend vector<string>  operator+ (const vector<string>& amenities, const Suite& s);
    friend vector<string>  operator+ (const Suite& s, const vector<string>& amenities);
    friend vector<string>& operator+=(vector<string>& amenities, const Suite& s);
    friend Suite&          operator+=(Suite& s, const vector<string>& amenities);
    friend Suite&          operator+=(Suite& s, const string& amenities);

    explicit operator string() const;

    friend ostream& operator<<(ostream& os, const Suite& r);
    friend istream& operator>>(istream& is, Suite& r);

    virtual void print() const override;
    virtual bool input() override;
    virtual string to_string() const override;
};

#include "kondakov_lr5_suite.hpp"

#endif // KONDAKOV_LR5_SUITE_H
```


-------------------------------

Updated on 2025-05-09 at 18:16:45 +0300
