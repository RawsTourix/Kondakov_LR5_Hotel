#ifndef KONDAKOV_LR5_METHODS_H
#define KONDAKOV_LR5_METHODS_H

#include "kondakov_lr5_menu_object.h"

// �������� ������� ����
namespace Methods {
	// ��������� ��� �������� ������������� ���������� � ��������
	struct RoomInfo {
		int number;			   // ����� �� ������
		string full_name;	   // �������� �������
		shared_ptr<Room> room; // ��������� �� ������ �������

		RoomInfo() = delete;
		RoomInfo(int number, string full_name, shared_ptr<Room> room);

		inline void print() const {
			cout << *this << endl;
		}

		friend ostream& operator<<(ostream& os, const RoomInfo& ri);
	};

	// 1. ����� ������ ������
	template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    show_rooms(const Container& rooms);

	// 2. ���������� �������
	template <typename RoomType, typename Container>
	typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
	add_room(Container& rooms);

	// 3. ��������� �������
	template <typename Container>
	typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
	edit_room(Container& rooms);

	// ����� ������������� ������ ������ � ����� ������� �� ������ � ��������� � ���������
	template <typename Container>
	typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, shared_ptr<Room>>
	get_room_from_rooms_map(string main_label, string message, Container& rooms);
};

#include "kondakov_lr5_methods.hpp"

#endif // KONDAKOV_LR5_METHODS_H