/**
 * @file kondakov_lr5_serializer.cpp
 * @brief Реализация регистратора типов комнат
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup serialization
 */

#include "kondakov_lr5_serializer.h"

/**
 * @brief Конструктор регистратора типов комнат
 * @details Инициализирует фабрику для создания StandardRoom, Suite и FamilyRoom
 */
Serializer::RoomTypeRegistry::RoomTypeRegistry() {
    creators["Standard"] = []() { return make_shared<StandardRoom>(); };
    creators["Suite"]    = []() { return make_shared<Suite>(); };
    creators["Family"]   = []() { return make_shared<FamilyRoom>(); };
}