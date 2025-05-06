---
title: Classes

---

# Classes




* **class [ChildCare](Classes/class_child_care.md)** <br>Класс, представляющий услуги по уходу за детьми 
* **class [FamilyRoom](Classes/class_family_room.md)** <br>Класс семейного номера, наследует [Room]() и [ChildCare](Classes/class_child_care.md). 
* **namespace [InputControl](Namespaces/namespace_input_control.md)** <br>Пространство имён для функций управления вводом данных 
    * **struct [DelimitedContainer](Classes/struct_input_control_1_1_delimited_container.md)** <br>Шаблонный класс для работы с разделителями (базовый шаблон) 
    * **struct [DelimitedContainer< Delim, Container &, enable_if_t< is_same_v< typename Container::value_type, string >, void > >](Classes/struct_input_control_1_1_delimited_container_3_01_delim_00_01_container_01_6_00_01enable__if__t_e12e72f0c289026bc10ec07e7fe406c5.md)** <br>Специализация [DelimitedContainer](Classes/struct_input_control_1_1_delimited_container.md) для работы со строками 
* **class [MenuObject](Classes/class_menu_object.md)** <br>Класс для представления пункта меню 
* **namespace [Methods](Namespaces/namespace_methods.md)** <br>Пространство имён для операций с комнатами 
    * **struct [RoomInfo](Classes/struct_methods_1_1_room_info.md)** <br>Краткая информация о комнате для отображения 
* **class [Room](Classes/class_room.md)** <br>Абстрактный базовый класс для представления гостиничного номера 
* **namespace [Serializer](Namespaces/namespace_serializer.md)** <br>Пространство имён для операций сериализации 
    * **struct [RoomTypeRegistry](Classes/struct_serializer_1_1_room_type_registry.md)** <br>Регистратор типов комнат для фабричного создания 
* **class [StandardRoom](Classes/class_standard_room.md)** <br>Класс стандартного номера (наследник [Room](Classes/class_room.md)) 
* **class [Suite](Classes/class_suite.md)** <br>Класс номера люкс, наследующий от [Room](Classes/class_room.md). 
* **namespace [std](Namespaces/namespacestd.md)** <br>< JSON-библиотека (nlohmann::json). 



-------------------------------

Updated on 2025-05-06 at 23:16:47 +0300
