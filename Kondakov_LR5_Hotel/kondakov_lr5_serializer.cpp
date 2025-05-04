#include "kondakov_lr5_serializer.h"

// ����������� �� ���������, ����������� creators
Serializer::RoomTypeRegistry::RoomTypeRegistry() {
    creators["����������� �������"] = []() { return make_shared<StandardRoom>(); };
    creators["���� �������"]        = []() { return make_shared<Suite>(); };
    creators["�������� �������"]    = []() { return make_shared<FamilyRoom>(); };
}