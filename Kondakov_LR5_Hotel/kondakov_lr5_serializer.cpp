#include "kondakov_lr5_serializer.h"

// Конструктор по умолчанию, заполняющий creators
Serializer::RoomTypeRegistry::RoomTypeRegistry() {
    creators["Стандартная комната"] = []() { return make_shared<StandardRoom>(); };
    creators["Люкс комната"]        = []() { return make_shared<Suite>(); };
    creators["Семейная комната"]    = []() { return make_shared<FamilyRoom>(); };
}