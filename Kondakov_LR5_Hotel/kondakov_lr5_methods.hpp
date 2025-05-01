#ifndef KONDAKOV_LR5_METHODS_HPP
#define KONDAKOV_LR5_METHODS_HPP

#include "kondakov_lr5_methods.h"

// Определение конструкторов и методов структуры RoomInfo
Methods::RoomInfo::RoomInfo(int number, string full_name, shared_ptr<Room> room) :
	number(number), full_name(full_name), room(room) {
}

ostream& Methods::operator<<(ostream& os, const RoomInfo& ri) {
	os << ri.number << ". " << ri.full_name;
	return os;
}

// 1. Вывод списка комнат
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
Methods::show_rooms(const Container& rooms) {
	return [&rooms]() {
		cout << rooms << "Список комнат успешно выведен.";  // Вывод контейнера комнат с помощью перегрузки << из Room
	};
}

// 2. Добавление комнаты
template <typename RoomType, typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
Methods::add_room(Container& rooms) {
	return [&rooms]() {
		RoomType room;
		if (room.input()) {
			cout << endl;
			room.print();
			rooms.push_back(make_shared<RoomType>(move(room)));
			cout << "Комната успешно добавлена.";
		}
	};
}

// Создание динамического одноразового меню для изменения комнаты
template <typename RoomPtr>
typename enable_if_t<is_base_of_v<Room, typename RoomPtr::element_type>, void>
add_edit_menu_items(vector<MenuObject>& menu, RoomPtr room) {
    // Общие пункты для всех комнат
    menu.emplace_back(
        1, "Изменить номер комнаты;",
        room,
        [room]() -> bool { return room->input_room_number(); },
        "Изменение номера комнаты.",
        "Номер комнаты успешно изменён."
    );
    menu.emplace_back(
        2, "Изменить цену за ночь;",
        room,
        [room]() -> bool { return room->input_price_per_night(); },
        "Изменение цены за ночь.",
        "Цена за ночь успешно изменена."
    );
    menu.emplace_back(
        3, "Изменить статус бронирования;",
        room,
        [room]() -> bool { return room->input_is_booked(); },
        "Изменение статуса бронирования.",
        "Статус бронирования успешно изменён."
    );

    // Специфичные пункты через if constexpr
    if constexpr (is_same_v<typename RoomPtr::element_type, StandardRoom>) {
        menu.emplace_back(
            4, "Изменить количество кроватей;",
            room,
            [room]() -> bool { return room->input_bed_count(); },
            "Изменение количества кроватей.",
            "Количество кроватей успешно изменено."
        );
        menu.emplace_back(
            5, "Изменить наличие телевизора;",
            room,
            [room]() -> bool { return room->input_has_tv(); },
            "Изменение наличия телевизора.",
            "Наличие телевизора успешно изменено."
        );
        menu.emplace_back(
            6, "Изменить удобства;",
            room,
            [room]() -> bool { return room->input_amenities<','>(); },
            "Изменение удобств.",
            "Удобства успешно изменены."
        );
    }
    else if constexpr (is_same_v<typename RoomPtr::element_type, Suite>) {
        menu.emplace_back(
            4, "Изменить наличие обслуживания;",
            room,
            [room]() -> bool { return room->input_room_service(); },
            "Изменение наличия обслуживания.",
            "Наличие обслуживания успешно изменено."
        );
        menu.emplace_back(
            5, "Изменить наличие джакузи;",
            room,
            [room]() -> bool { return room->input_jacuzzi(); },
            "Изменение наличия джакузи.",
            "Наличие джакузи успешно изменено."
        );
        menu.emplace_back(
            6, "Изменить удобства;",
            room,
            [room]() -> bool { return room->input_amenities<','>(); },
            "Изменение удобств.",
            "Удобства успешно изменены."
        );
    }
    else if constexpr (is_same_v<typename RoomPtr::element_type, FamilyRoom>) {
        menu.emplace_back(
            4, "Изменить стоимость услуг для детей;",
            room,
            [room]() -> bool { return room->input_child_care_price(); },
            "Изменение стоимости услуг для детей.",
            "Стоимость услуг для детей успешно изменена."
        );
        menu.emplace_back(
            5, "Изменить наличие услуг для детей;",
            room,
            [room]() -> bool { return room->input_has_child_care(); },
            "Изменение наличия услуг для детей.",
            "Наличие услуг для детей успешно изменено."
        );
        menu.emplace_back(
            6, "Изменить количество детских кроватей;",
            room,
            [room]() -> bool { return room->input_child_beds(); },
            "Изменение количества детских кроватей.",
            "Количество детских кроватей успешно изменено."
        );
        menu.emplace_back(
            7, "Изменить наличие набора детских игрушек;",
            room,
            [room]() -> bool { return room->input_toy_kit(); },
            "Изменение наличия набора детских игрушек.",
            "Наличие набора детских игрушек успешно изменено."
        );
        menu.emplace_back(
            8, "Изменить удобства;",
            room,
            [room]() -> bool { return room->input_amenities<','>(); },
            "Изменение удобств.",
            "Удобства успешно изменены."
        );
    }
}

// 3. Изменение комнаты
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
Methods::edit_room(Container& rooms) {
	return [&]() {
		// Получение комнаты из списка
		shared_ptr<Room> room = get_room_from_rooms_map("Изменение комнаты:", "Пункт меню: ", rooms);
		if (room == nullptr) { return; }

		// Создание динамического меню для конкретной комнаты
		vector<MenuObject> edit_room_menu {};
		if (room->get_room_type() == "Стандартная комната") {
			// Для стандартной комнаты
			add_edit_menu_items(edit_room_menu, dynamic_pointer_cast<StandardRoom>(room));
		}
		else if (room->get_room_type() == "Люкс комната") {
			// Для люкс комнаты
			add_edit_menu_items(edit_room_menu, dynamic_pointer_cast<Suite>(room));
		}
		else if (room->get_room_type() == "Семейная комната") {
			// Для семейной комнаты
			add_edit_menu_items(edit_room_menu, dynamic_pointer_cast<FamilyRoom>(room));
		}

		// Обработка динамического одноразового меню для изменения конкретной комнаты
		MenuObject::process(edit_room_menu, room->get_full_name(), "Назад.", 0, true);
	};
}

// Вывод нумерованного списка комнат и выбор комнаты по номеру с возвратом её указателя
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, shared_ptr<Room>>
Methods::get_room_from_rooms_map(string main_label, string message, Container& rooms) {
    vector<RoomInfo> edit_room_info{};
    int key = 1;
    cout << main_label << endl << endl;
    for (const auto& room : rooms) {
        edit_room_info.emplace_back(key++, room->get_full_name(), room);
        edit_room_info.back().print();
    }
    edit_room_info.emplace_back(0, "Назад", nullptr);
    edit_room_info.back().print();
    cout << endl << endl;

    int room_choice = 0;
    if (InputControl::input(room_choice, message, 0, static_cast<int>(edit_room_info.size()))) { cout << endl; return nullptr; }
    if (room_choice == 0) { return nullptr; }
    auto it = find_if(edit_room_info.begin(), edit_room_info.end(), [room_choice](RoomInfo ri) { return ri.number == room_choice; });
    if (it == edit_room_info.end()) {
        cout << endl << "Ошибка при выборе комнаты!";
        return nullptr;
    }
    cout << endl << endl;

    return it->room;
}

#endif // KONDAKOV_LR5_METHODS_HPP