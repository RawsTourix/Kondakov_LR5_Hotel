#ifndef KONDAKOV_LR5_METHODS_HPP
#define KONDAKOV_LR5_METHODS_HPP

#include "kondakov_lr5_methods.h"

// ����������� ������������� � ������� ��������� RoomInfo
Methods::RoomInfo::RoomInfo(int number, string full_name, shared_ptr<Room> room) :
	number(number), full_name(full_name), room(room) {
}

ostream& Methods::operator<<(ostream& os, const RoomInfo& ri) {
	os << ri.number << ". " << ri.full_name;
	return os;
}

// 1. ����� ������ ������
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
Methods::show_rooms(const Container& rooms) {
	return [&rooms]() {
		cout << rooms << "������ ������ ������� �������.";  // ����� ���������� ������ � ������� ���������� << �� Room
	};
}

// ��������� ������� ��� ��������� �������
template <typename RoomPtr, typename Container>
typename enable_if_t<is_base_of_v<Room, typename RoomPtr::element_type>&&
                     is_same_v<typename Container::value_type, shared_ptr<Room>>, vector<function<bool()>>>
get_room_edit_methods(RoomPtr room, const Container& rooms) {
    // ��������� ������ ������� ������
    vector<int> room_numbers(Methods::get_room_numbers(rooms));

    // ����������� ������� ������� ��� ��������� �������
    vector<function<bool()>> room_edit_methods{};
    room_edit_methods.push_back([room, room_numbers]() -> bool { return room->input_room_number(room_numbers); });
    room_edit_methods.push_back([room]() -> bool { return room->input_price_per_night(); });
    room_edit_methods.push_back([room]() -> bool { return room->input_is_booked(); });

    if constexpr (is_same_v<typename RoomPtr::element_type, StandardRoom>) {
        room_edit_methods.push_back([room]() -> bool { return room->input_bed_count(); });
        room_edit_methods.push_back([room]() -> bool { return room->input_has_tv(); });
        room_edit_methods.push_back([room]() -> bool { return room->input_amenities<','>(); });
    }
    else if constexpr (is_same_v<typename RoomPtr::element_type, Suite>) {
        room_edit_methods.push_back([room]() -> bool { return room->input_room_service(); });
        room_edit_methods.push_back([room]() -> bool { return room->input_jacuzzi(); });
        room_edit_methods.push_back([room]() -> bool { return room->input_amenities<','>(); });
    }
    else if constexpr (is_same_v<typename RoomPtr::element_type, FamilyRoom>) {
        room_edit_methods.push_back([room]() -> bool { return room->input_child_care_price(); });
        room_edit_methods.push_back([room]() -> bool { return room->input_has_child_care(); });
        room_edit_methods.push_back([room]() -> bool { return room->input_child_beds(); });
        room_edit_methods.push_back([room]() -> bool { return room->input_toy_kit(); });
        room_edit_methods.push_back([room]() -> bool { return room->input_amenities<','>(); });
    }

    return room_edit_methods;
}

// 2. ���������� �������
template <typename RoomType, typename Container>
typename enable_if_t<is_base_of_v<Room, typename RoomType> &&
                     is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
Methods::add_room(Container& rooms) {
	return [&rooms]() {
        // �������� ������� �� ���������
        shared_ptr<RoomType> room = make_shared<RoomType>();

        // ��������� ������� ��� ��������� �������
        vector<function<bool()>> edit_methods(get_room_edit_methods(room, rooms));

        // ��������� ���������� �������
        for (const auto& action : edit_methods) {
            if (action()) { return; }
        }

		cout << endl;
		room->print();
		rooms.push_back(move(room));
		cout << "������� ������� ���������.";
	};
}

// �������� ������������� ������������ ���� ��� ��������� �������
template <typename RoomPtr, typename Container>
typename enable_if_t<is_base_of_v<Room, typename RoomPtr::element_type> &&
                     is_same_v<typename Container::value_type, shared_ptr<Room>>, void>
add_edit_menu_items(vector<MenuObject>& menu, RoomPtr room, const Container& rooms) {
    // ��������� ������� ��� ��������� �������
    vector<function<bool()>> edit_methods(get_room_edit_methods(room, rooms));

    // ����� ������ ��� ���� ������
    menu.emplace_back(
        1, "�������� ����� �������;",
        room,
        // ���� ������ ������� � ��������� �� ������������
        edit_methods.at(0),
        "��������� ������ �������.",
        "����� ������� ������� ������."
    );
    menu.emplace_back(
        2, "�������� ���� �� ����;",
        room,
        edit_methods.at(1),
        "��������� ���� �� ����.",
        "���� �� ���� ������� ��������."
    );
    menu.emplace_back(
        3, "�������� ������ ������������;",
        room,
        edit_methods.at(2),
        "��������� ������� ������������.",
        "������ ������������ ������� ������."
    );

    if constexpr (is_same_v<typename RoomPtr::element_type, StandardRoom>) {
        menu.emplace_back(
            4, "�������� ���������� ��������;",
            room,
            edit_methods.at(3),
            "��������� ���������� ��������.",
            "���������� �������� ������� ��������."
        );
        menu.emplace_back(
            5, "�������� ������� ����������;",
            room,
            edit_methods.at(4),
            "��������� ������� ����������.",
            "������� ���������� ������� ��������."
        );
        menu.emplace_back(
            6, "�������� ��������;",
            room,
            edit_methods.at(5),
            "��������� �������.",
            "�������� ������� ��������."
        );
    }
    else if constexpr (is_same_v<typename RoomPtr::element_type, Suite>) {
        menu.emplace_back(
            4, "�������� ������� ������������;",
            room,
            edit_methods.at(3),
            "��������� ������� ������������.",
            "������� ������������ ������� ��������."
        );
        menu.emplace_back(
            5, "�������� ������� �������;",
            room,
            edit_methods.at(4),
            "��������� ������� �������.",
            "������� ������� ������� ��������."
        );
        menu.emplace_back(
            6, "�������� ��������;",
            room,
            edit_methods.at(5),
            "��������� �������.",
            "�������� ������� ��������."
        );
    }
    else if constexpr (is_same_v<typename RoomPtr::element_type, FamilyRoom>) {
        menu.emplace_back(
            4, "�������� ��������� ����� ��� �����;",
            room,
            edit_methods.at(3),
            "��������� ��������� ����� ��� �����.",
            "��������� ����� ��� ����� ������� ��������."
        );
        menu.emplace_back(
            5, "�������� ������� ����� ��� �����;",
            room,
            edit_methods.at(4),
            "��������� ������� ����� ��� �����.",
            "������� ����� ��� ����� ������� ��������."
        );
        menu.emplace_back(
            6, "�������� ���������� ������� ��������;",
            room,
            edit_methods.at(5),
            "��������� ���������� ������� ��������.",
            "���������� ������� �������� ������� ��������."
        );
        menu.emplace_back(
            7, "�������� ������� ������ ������� �������;",
            room,
            edit_methods.at(6),
            "��������� ������� ������ ������� �������.",
            "������� ������ ������� ������� ������� ��������."
        );
        menu.emplace_back(
            8, "�������� ��������;",
            room,
            edit_methods.at(7),
            "��������� �������.",
            "�������� ������� ��������."
        );
    }
}

// 3. ��������� �������
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
Methods::edit_room(Container& rooms) {
	return [&rooms]() {
		// ��������� ������� �� ������
		shared_ptr<Room> room = get_room_from_rooms_map("��������� �������:", "����� ����: ", rooms);
		if (room == nullptr) { return; }

		// �������� ������������� ���� ��� ���������� �������
		vector<MenuObject> edit_room_menu {};
		if (room->get_room_type() == "����������� �������") {
			// ��� ����������� �������
			add_edit_menu_items(edit_room_menu, dynamic_pointer_cast<StandardRoom>(room), rooms);
		}
		else if (room->get_room_type() == "���� �������") {
			// ��� ���� �������
			add_edit_menu_items(edit_room_menu, dynamic_pointer_cast<Suite>(room), rooms);
		}
		else if (room->get_room_type() == "�������� �������") {
			// ��� �������� �������
			add_edit_menu_items(edit_room_menu, dynamic_pointer_cast<FamilyRoom>(room), rooms);
		}

		// ��������� ������������� ������������ ���� ��� ��������� ���������� �������
		MenuObject::process(edit_room_menu, room->get_full_name(), "�����.", 0, true);
	};
}

// 4. �������� �������
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
Methods::delete_room(Container& rooms) {
    return [&rooms]() {
        // ��������� ������� �� ������
        shared_ptr<Room> room = get_room_from_rooms_map("�������� �������:", "����� ����: ", rooms);
        if (room == nullptr) { return; }

        // ������������� �������� � �������� ��� ����������� ������� � ����
        ostringstream message;
        message << "�� ����� ������ ������� [" << room->get_full_name() << "]?";
        if (InputControl::yes_or_no(message.str())) {

            auto it = remove_if(rooms.begin(), rooms.end(), [&room](shared_ptr<Room> r) { return room->get_room_number() == r->get_room_number(); });

            if (it == rooms.end()) {
                cout << "������� � ����� ������� ��� � ������.";
            }
            else {
                rooms.erase(it, rooms.end());
                cout << "������� ������� �������.";
            }
        }
        else {
            delete_room(rooms)();
        }
    };
}

// 5. ���������� ������ ������
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
Methods::sort_rooms(Container& rooms) {
    return [&rooms]() {
        // �������� ���� ��� ����������
        vector<MenuObject> sort_menu {
            { 1, "������������� �� ������ �������.",
                [&rooms]() {
                    vector<MenuObject> sort_by_room_number_menu {
                        { 1, "�� �����������;", [&rooms]() {
                                sort(rooms.begin(), rooms.end(), [](shared_ptr<Room> r1, shared_ptr<Room> r2) {
                                    return r1->get_room_number() < r2->get_room_number(); }
                                );
                                cout << endl << endl << "������ ������ ������� ������������ �� ����������� ������� ������." << endl;
                            }
                        },
                        { 2, "�� ��������.", [&rooms]() {
                                sort(rooms.begin(), rooms.end(), [](shared_ptr<Room> r1, shared_ptr<Room> r2) {
                                    return r1->get_room_number() > r2->get_room_number(); }
                                );
                                cout << endl << endl << "������ ������ ������� ������������ �� �������� ������� ������." << endl;
                            }
                        }
                    };

                    MenuObject::process(sort_by_room_number_menu, "\n\n������������� �� ������ �������:", "�����.", 0, true);
                }
            },
            { 2, "������������� �� ���� �������.",
                [&rooms]() {
                    vector<MenuObject> sort_by_room_type_menu {
                        { 1, "�� �����������;", [&rooms]() {
                                sort(rooms.begin(), rooms.end(), [](shared_ptr<Room> r1, shared_ptr<Room> r2) {
                                    return make_tuple(r1->get_room_type(), r1->get_room_number()) <
                                        make_tuple(r2->get_room_type(), r2->get_room_number()); }
                                );
                                cout << endl << endl << "������ ������ ������� ������������ �� ����������� ����� ������." << endl;
                            }
                        },
                        { 2, "�� ��������.", [&rooms]() {
                                sort(rooms.begin(), rooms.end(), [](shared_ptr<Room> r1, shared_ptr<Room> r2) {
                                    return make_tuple(r1->get_room_type(), r1->get_room_number()) >
                                        make_tuple(r2->get_room_type(), r2->get_room_number()); }
                                );
                                cout << endl << endl << "������ ������ ������� ������������ �� �������� ����� ������." << endl;
                            }
                        },
                    };

                    MenuObject::process(sort_by_room_type_menu, "\n\n������������� �� ���� �������:", "�����.", 0, true);
                }
            },
            { 3, "������������� �� ���� �� ����.",
                [&rooms]() {
                    vector<MenuObject> sort_by_price_per_night_menu {
                        { 1, "�� �����������;", [&rooms]() {
                                sort(rooms.begin(), rooms.end(), [](shared_ptr<Room> r1, shared_ptr<Room> r2) {
                                    return make_tuple(r1->get_price_per_night(), r1->get_room_number()) <
                                        make_tuple(r2->get_price_per_night(), r2->get_room_number()); }
                                );
                                cout << endl << endl << "������ ������ ������� ������������ �� ����������� ��� �� ����." << endl;
                            }
                        },
                        { 2, "�� ��������.", [&rooms]() {
                                sort(rooms.begin(), rooms.end(), [](shared_ptr<Room> r1, shared_ptr<Room> r2) {
                                    return make_tuple(r1->get_price_per_night(), r1->get_room_number()) >
                                        make_tuple(r2->get_price_per_night(), r2->get_room_number()); }
                                );
                                cout << endl << endl << "������ ������ ������� ������������ �� �������� ��� �� ����." << endl;
                            }
                        },
                    };

                    MenuObject::process(sort_by_price_per_night_menu, "\n\n������������� �� ���� �� ����:", "�����.", 0, true);
                }
            },
            { 4, "������������� �� ������� ������������.",
                [&rooms]() {
                    vector<MenuObject> sort_by_is_booked_menu {
                        { 1, "�� �����������;", [&rooms]() {
                                sort(rooms.begin(), rooms.end(), [](shared_ptr<Room> r1, shared_ptr<Room> r2) {
                                    return make_tuple(r1->get_is_booked(), r1->get_room_number()) <
                                        make_tuple(r2->get_is_booked(), r2->get_room_number()); }
                                );
                                cout << endl << endl << "������ ������ ������� ������������ �� ����������� �������� ������������." << endl;
                            }
                        },
                        { 2, "�� ��������.", [&rooms]() {
                                sort(rooms.begin(), rooms.end(), [](shared_ptr<Room> r1, shared_ptr<Room> r2) {
                                    return make_tuple(r1->get_is_booked(), r1->get_room_number()) >
                                        make_tuple(r2->get_is_booked(), r2->get_room_number()); }
                                );
                                cout << endl << endl << "������ ������ ������� ������������ �� �������� �������� ������������." << endl;
                            }
                        },
                    };

                    MenuObject::process(sort_by_is_booked_menu, "\n\n������������� �� ������� ������������:", "�����.", 0, true);
                }
            }
        };

        // ��������� ������������ ���� ��� ���������� ������ ������
        MenuObject::process(sort_menu, "������������� ������ ������:", "�����.", 0, true);
    };
}

// 6. ������ ��������� ����������
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
Methods::calculate_total(Container& rooms) {
    return [&rooms]() {
        // ��������� ������� �� ������
        shared_ptr<Room> room = get_room_from_rooms_map("���������� ��������� ����������:", "����� ����: ", rooms);
        if (room == nullptr) { return; }

        // ���� ���������� ����� � ���������� ��������� ����������
        int night_count;
        if (InputControl::input(night_count, "���������� �����: ", 0, 365)) { return; }
        cout << endl << endl << 
            "��������� ���������� � [" << room->get_full_name() << "]" << endl << endl <<
            "���������� �����: " << night_count << endl << endl <<
            "���������: " << room->calculate_total(night_count) << " " << Room::CURRENCY << endl;
    };
}

// 7. �������� ���������� �������
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
Methods::validate_room(Container& rooms) {
    return [&rooms]() {
        // ��������� ������� �� ������
        shared_ptr<Room> room = get_room_from_rooms_map("���������� ��������� ����������:", "����� ����: ", rooms);
        if (room == nullptr) { return; }

        cout << "[" << room->get_full_name() << "] � " << (room->validate() ? "" : "��") << "�������." << endl;
    };
}


/* ��������������� ������ */

// ����� ������������� ������ ������ � ����� ������� �� ������ � ��������� � ���������
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
    edit_room_info.emplace_back(0, "�����", nullptr);
    edit_room_info.back().print();
    cout << endl << endl;

    int room_choice = 0;
    if (InputControl::input(room_choice, message, 0, static_cast<int>(edit_room_info.size() - 1))) { cout << endl; return nullptr; }
    if (room_choice == 0) { return nullptr; }
    auto it = find_if(edit_room_info.begin(), edit_room_info.end(), [room_choice](RoomInfo ri) { return ri.number == room_choice; });
    if (it == edit_room_info.end()) {
        cout << endl << "������ ��� ������ �������!";
        return nullptr;
    }
    cout << endl << endl;

    return it->room;
}

// ��������� ������ ������� ������
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, vector<int>>
Methods::get_room_numbers(const Container& rooms) {
    vector<int> room_numbers {};
    for (const auto& room : rooms) {
        room_numbers.push_back(room->get_room_number());
    }
    return room_numbers;
}

// �������� ������� ������� � ����� �� ������� � ������ ������
template <typename RoomType, typename Container>
typename enable_if_t<is_base_of_v<Room, typename RoomType> &&
                     is_same_v<typename Container::value_type, shared_ptr<Room>>, bool>
Methods::room_in_rooms_by_room_number(RoomType room, const Container& rooms) {
    // ��������� ������ ������� ������
    vector<int> room_numbers(get_room_numbers(rooms));

    return find(room_numbers.begin(), room_numbers.end(), room.get_room_number()) != room_numbers.end();
}

#endif // KONDAKOV_LR5_METHODS_HPP