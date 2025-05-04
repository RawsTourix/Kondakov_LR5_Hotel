#include "kondakov_lr5_serializer.h"

// ����������� �� ���������, ����������� creators
Serializer::RoomTypeRegistry::RoomTypeRegistry() {
    creators["Standard"] = []() { return make_shared<StandardRoom>(); };
    creators["Suite"]    = []() { return make_shared<Suite>(); };
    creators["Family"]   = []() { return make_shared<FamilyRoom>(); };
}