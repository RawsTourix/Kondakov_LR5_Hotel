---
title: Kondakov_LR5_Hotel/kondakov_lr5_standard_room.h
summary: Заголовочный файл класса StandardRoom. 

---

# Kondakov_LR5_Hotel/kondakov_lr5_standard_room.h

Заголовочный файл класса [StandardRoom](Classes/class_standard_room.md).  [More...](#detailed-description)

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[StandardRoom](Classes/class_standard_room.md)** <br>Класс стандартного номера (наследник [Room](Classes/class_room.md))  |

## Detailed Description

Заголовочный файл класса [StandardRoom](Classes/class_standard_room.md). 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 



## Source code

```cpp


#ifndef KONDAKOV_LR5_STANDARD_ROOM_H
#define KONDAKOV_LR5_STANDARD_ROOM_H

#include "kondakov_lr5_room.h"

class StandardRoom final : virtual public Room {
private:
    int             bed_count;  
    bool            has_tv;     
    vector<string>  amenities;  

    const string ROOM_TYPE = "Стандартная комната";  
    const string JSON_TYPE = "Standard";             

public:

    StandardRoom();

    StandardRoom(int room_number, int bed_count);

    StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv);

    StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv, string amenities);

    StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv, vector<string> amenities);

    StandardRoom(const StandardRoom&) = default;
    StandardRoom& operator=(const StandardRoom&) = default;

    StandardRoom(StandardRoom&& other) noexcept;
    StandardRoom& operator=(StandardRoom&&) noexcept = default;
    
    virtual ~StandardRoom() = default;

    inline int get_bed_count() const;
    inline bool get_has_tv() const;
    virtual inline const vector<string>& get_amenities() const override;
    virtual inline string get_full_name() const override;

    inline void set_bed_count(int bed_count);
    inline void set_has_tv(bool has_tv);
    inline void set_amenities(vector<string> amenities);

    inline bool input_bed_count();
    inline bool input_has_tv();
    template <char Delim>
    inline bool input_amenities();

    virtual inline const string& get_room_type() const override;
    virtual inline const string& get_json_type() const override;
    virtual inline float calculate_total(int night_count) const override;
    virtual inline bool validate() const override;

    inline void exstra_bed();

    virtual json to_json() const override;
    virtual void from_json(const json& j) override;

    friend vector<string>  operator+ (const StandardRoom& sr1, const StandardRoom& sr2);
    friend vector<string>  operator+ (const vector<string>& amenities, const StandardRoom& sr);
    friend vector<string>  operator+ (const StandardRoom& sr, const vector<string>& amenities);
    friend vector<string>& operator+=(vector<string>& amenities, const StandardRoom& sr);
    friend StandardRoom&   operator+=(StandardRoom& sr, const vector<string>& amenities);
    friend StandardRoom&   operator+=(StandardRoom& sr, const string& amenities);

    explicit operator string() const;

    friend ostream& operator<<(ostream& os, const StandardRoom& r);
    friend istream& operator>>(istream& is, StandardRoom& r);

    virtual void print() const override;
    virtual bool input() override;
    virtual string to_string() const override;
};

#include "kondakov_lr5_standard_room.hpp"

#endif // KONDAKOV_LR5_STANDARD_ROOM_H
```


-------------------------------

Updated on 2025-05-09 at 18:16:45 +0300
