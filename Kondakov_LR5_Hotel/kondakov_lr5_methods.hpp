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

// Выбор комнаты из списка
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, shared_ptr<Room>>
Methods::get_room_from_rooms_map(string main_label, string message, Container& rooms) {
	vector<RoomInfo> edit_room_info {};
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

// Создание динамического одноразового меню для конкретной комнаты
template <typename RoomPtr>
typename enable_if_t<is_base_of_v<Room, typename RoomPtr::element_type>, void>
add_edit_menu_items(vector<MenuObject>& menu, RoomPtr room) {
	menu.emplace_back(
		1, "Изменить номер комнаты;", [room]() {
			cout << endl << endl << "Изменение номера комнаты." << endl << endl;
			if (!room->input_room_number()) {
				cout << endl;
				room->print();
				cout << endl << "Номер комнаты успешно изменён.";
			}
			else { cout << endl; }
		}
	);
	menu.emplace_back(
		2, "Изменить цену за ночь;", [room]() {
			cout << endl << endl << "Изменение цены за ночь." << endl << endl;
			if (!room->input_price_per_night()) {
				cout << endl;
				room->print();
				cout << endl << "Цена за ночь успешно изменена.";
			}
			else { cout << endl; }
		}
	);
	menu.emplace_back(
		3, "Изменить статус бронирования;", [room]() {
			cout << endl << endl << "Изменение статуса бронирования." << endl << endl;
			if (!room->input_is_booked()) {
				cout << endl;
				room->print();
				cout << endl << "Статус бронирования успешно изменён.";
			}
			else { cout << endl; }
		}
	);
	if constexpr (is_same_v<typename RoomPtr::element_type, StandardRoom>) {
		menu.emplace_back(
			4, "Изменить количество кроватей;", [room]() {
				cout << endl << endl << "Изменение количества кроватей." << endl << endl;
				if (!room->input_bed_count()) {
					cout << endl;
					room->print();
					cout << endl << "Количество кроватей успешно изменено.";
				}
				else { cout << endl; }
			}
		);
		menu.emplace_back(
			5, "Изменить наличие телевизора;", [room]() {
				cout << endl << endl << "Изменение наличия телевизора." << endl << endl;
				if (!room->input_has_tv()) {
					cout << endl;
					room->print();
					cout << endl << "Наличие телевизора успешно изменено.";
				}
				else { cout << endl; }
			}
		);
		menu.emplace_back(
			6, "Изменить удобства;", [room]() {
				cout << endl << endl << "Изменение удобств." << endl << endl;
				if (!room->input_amenities<','>()) {
					cout << endl;
					room->print();
					cout << endl << "Удобства успешно изменены.";
				}
				else { cout << endl; }
			}
		);
	}
	else if constexpr (is_same_v<typename RoomPtr::element_type, Suite>) {
		menu.emplace_back(
			4, "Изменить наличие обслуживания;", [room]() {
				cout << endl << endl << "Изменение наличия обслуживания." << endl << endl;
				if (!room->input_room_service()) {
					cout << endl;
					room->print();
					cout << endl << "Наличие обслуживания успешно изменено.";
				}
				else { cout << endl; }
			}
		);
		menu.emplace_back(
			5, "Изменить наличие джакузи;", [room]() {
				cout << endl << endl << "Изменение наличия джакузи." << endl << endl;
				if (!room->input_jacuzzi()) {
					cout << endl;
					room->print();
					cout << endl << "Наличие джакузи успешно изменено.";
				}
				else { cout << endl; }
			}
		);
		menu.emplace_back(
			6, "Изменить удобства;", [room]() {
				cout << endl << endl << "Изменение удобств." << endl << endl;
				if (!room->input_amenities<','>()) {
					cout << endl;
					room->print();
					cout << endl << "Удобства успешно изменены.";
				}
				else { cout << endl; }
			}
		);
	}
	else if constexpr (is_same_v<typename RoomPtr::element_type, FamilyRoom>) {
		menu.emplace_back(
			4, "Изменить стоимость услуг для детей;", [room]() {
				cout << endl << endl << "Изменение стоимости услуг для детей." << endl << endl;
				if (!room->input_child_care_price()) {
					cout << endl;
					room->print();
					cout << endl << "Стоимость услуг для детей успешно изменена.";
				}
				else { cout << endl; }
			}
		);
		menu.emplace_back(
			5, "Изменить наличие услуг для детей;", [room]() {
				cout << endl << endl << "Изменение наличия услуг для детей." << endl << endl;
				if (!room->input_has_child_care()) {
					cout << endl;
					room->print();
					cout << endl << "Наличие услуг для детей успешно изменено.";
				}
				else { cout << endl; }
			}
		);
		menu.emplace_back(
			6, "Изменить количество детских кроватей;", [room]() {
				cout << endl << endl << "Изменение количества детских кроватей." << endl << endl;
				if (!room->input_child_beds()) {
					cout << endl;
					room->print();
					cout << endl << "Количество детских кроватей успешно изменено.";
				}
				else { cout << endl; }
			}
		);
		menu.emplace_back(
			7, "Изменить наличие набора детских игрушек;", [room]() {
				cout << endl << endl << "Изменение наличия набора детских игрушек." << endl << endl;
				if (!room->input_toy_kit()) {
					cout << endl;
					room->print();
					cout << endl << "Наличие набора детских игрушек успешно изменено.";
				}
				else { cout << endl; }
			}
		);
		menu.emplace_back(
			8, "Изменить удобства;", [room]() {
				cout << endl << endl << "Изменение удобств." << endl << endl;
				if (!room->input_amenities<','>()) {
					cout << endl;
					room->print();
					cout << endl << "Удобства успешно изменены.";
				}
				else { cout << endl; }
			}
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

#endif // KONDAKOV_LR5_METHODS_HPP