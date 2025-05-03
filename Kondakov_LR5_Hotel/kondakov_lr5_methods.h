#ifndef KONDAKOV_LR5_METHODS_H
#define KONDAKOV_LR5_METHODS_H

#include "kondakov_lr5_menu_object.h"

// Основные функции меню
namespace Methods {
	// Структура для краткого представления информации о комнатах
	struct RoomInfo {
		int number;			   // Номер по списку
		string full_name;	   // Название комнаты
		shared_ptr<Room> room; // Указатель на объект комнаты

		RoomInfo() = delete;
		RoomInfo(int number, string full_name, shared_ptr<Room> room);

		inline void print() const {
			cout << *this << endl;
		}

		friend ostream& operator<<(ostream& os, const RoomInfo& ri);
	};

	// 1. Вывод списка комнат
	template <typename Container>
    typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
    show_rooms(const Container& rooms);

	// 2. Добавление комнаты
	template <typename RoomType, typename Container>
	typename enable_if_t<is_base_of_v<Room, typename RoomType>&&
						 is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
	add_room(Container& rooms);

	// 3. Изменение комнаты
	template <typename Container>
	typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
	edit_room(Container& rooms);

	// 4. Удаление комнаты
	template <typename Container>
	typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
	delete_room(Container& rooms);

	// 5. Сортировка списка комнат
	template <typename Container>
	typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
	sort_rooms(Container& rooms);

	// 6. Расчёт стоимости проживания
	template <typename Container>
	typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
	calculate_total(Container& rooms);

	// 7. Проверка валидности комнаты
	template <typename Container>
	typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, function<void()>>
	validate_room(Container& rooms);


	/* Вспомогательные методы */

	// Вывод нумерованного списка комнат и выбор комнаты по номеру с возвратом её указателя
	template <typename Container>
	typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, shared_ptr<Room>>
	get_room_from_rooms_map(string main_label, string message, Container& rooms);

	// Получение списка номеров комнат
	template <typename Container>
	typename enable_if_t<is_same_v<typename Container::value_type, shared_ptr<Room>>, vector<int>>
	get_room_numbers(const Container& rooms);

	// Проверка наличия комнаты с таким же номером в списке комнат
	template <typename RoomType, typename Container>
	typename enable_if_t<is_base_of_v<Room, typename RoomType>&&
						 is_same_v<typename Container::value_type, shared_ptr<Room>>, bool>
	room_in_rooms_by_room_number(RoomType room, const Container& rooms);
};

#include "kondakov_lr5_methods.hpp"

#endif // KONDAKOV_LR5_METHODS_H