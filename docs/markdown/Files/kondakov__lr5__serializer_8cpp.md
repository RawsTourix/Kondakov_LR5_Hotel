---
title: Kondakov_LR5_Hotel/kondakov_lr5_serializer.cpp
summary: Реализация регистратора типов комнат 

---

# Kondakov_LR5_Hotel/kondakov_lr5_serializer.cpp

Реализация регистратора типов комнат  [More...](#detailed-description)

## Detailed Description

Реализация регистратора типов комнат 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 



## Source code

```cpp


#include "kondakov_lr5_serializer.h"

Serializer::RoomTypeRegistry::RoomTypeRegistry() {
    creators["Standard"] = []() { return make_shared<StandardRoom>(); };
    creators["Suite"]    = []() { return make_shared<Suite>(); };
    creators["Family"]   = []() { return make_shared<FamilyRoom>(); };
}
```


-------------------------------

Updated on 2025-05-09 at 18:16:45 +0300
