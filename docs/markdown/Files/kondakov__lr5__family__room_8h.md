---
title: Kondakov_LR5_Hotel/kondakov_lr5_family_room.h
summary: Заголовочный файл класса FamilyRoom (семейный номер) 

---

# Kondakov_LR5_Hotel/kondakov_lr5_family_room.h

Заголовочный файл класса [FamilyRoom](Classes/class_family_room.md) (семейный номер)  [More...](#detailed-description)

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[FamilyRoom](Classes/class_family_room.md)** <br>Класс семейного номера, наследует [Room]() и [ChildCare](Classes/class_child_care.md).  |

## Detailed Description

Заголовочный файл класса [FamilyRoom](Classes/class_family_room.md) (семейный номер) 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 



## Source code

```cpp


#ifndef KONDAKOV_LR5_FAMILY_ROOM_H
#define KONDAKOV_LR5_FAMILY_ROOM_H

#include "kondakov_lr5_room.h"
#include "kondakov_lr5_child_care.h"

class FamilyRoom final : virtual public Room, virtual public ChildCare {
private:
    int             child_beds;  
    bool            toy_kit;     
    vector<string>  amenities;   

    const string ROOM_TYPE = "Семейная комната";  
    const string JSON_TYPE = "Family";            

public:
    FamilyRoom();
    FamilyRoom(int room_number, int child_beds);
    FamilyRoom(int room_number, float price_per_night, bool is_booked, 
              float child_care_price, bool has_child_care, 
              int child_beds, bool toy_kit);
    FamilyRoom(int room_number, float price_per_night, bool is_booked,
              float child_care_price, bool has_child_care,
              int child_beds, bool toy_kit, string amenities);
    FamilyRoom(const FamilyRoom&) = default;
    FamilyRoom& operator=(const FamilyRoom&) = default;
    FamilyRoom(FamilyRoom&& other) noexcept;
    FamilyRoom& operator=(FamilyRoom&&) noexcept = default;
    virtual ~FamilyRoom() = default;

    inline int get_child_beds() const;
    inline bool get_toy_kit() const;
    virtual inline const vector<string>& get_amenities() const override;
    virtual inline string get_full_name() const override;

    inline void set_child_beds(int child_beds);
    inline void set_toy_kit(bool toy_kit);
    inline void set_amenities(vector<string> amenities);

    inline bool input_child_beds();
    inline bool input_toy_kit();
    template <char Delim = ','>
    inline bool input_amenities();

    virtual inline const string& get_room_type() const override;
    virtual inline const string& get_json_type() const override;
    virtual inline float calculate_total(int night_count) const override;
    virtual inline bool validate() const override;

    inline void add_play_area();
    inline void remove_play_area();

    virtual json to_json() const override;
    virtual void from_json(const json& j) override;

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

    friend vector<string>  operator+(const FamilyRoom& fr1, const FamilyRoom& fr2);
    friend vector<string>  operator+(const vector<string>& amenities, const FamilyRoom& fr);
    friend vector<string>  operator+(const FamilyRoom& fr, const vector<string>& amenities);
    friend vector<string>& operator+=(vector<string>& amenities, const FamilyRoom& fr);
    friend FamilyRoom&     operator+=(FamilyRoom& fr, const vector<string>& amenities);
    friend FamilyRoom&     operator+=(FamilyRoom& fr, const string& amenities);

    explicit operator string() const;
    friend ostream& operator<<(ostream& os, const FamilyRoom& r);
    friend istream& operator>>(istream& is, FamilyRoom& r);
    virtual void print() const override;
    virtual bool input() override;
    virtual string to_string() const override;
};

#include "kondakov_lr5_family_room.hpp"

#endif // KONDAKOV_LR5_FAMILY_ROOM_H
```


-------------------------------

Updated on 2025-05-06 at 23:16:47 +0300
