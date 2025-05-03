#include "kondakov_lr5_methods.h"

int main()
{
	// Русская локализация
	setlocale(LC_ALL, "Russian");

	// Список комнат
	vector<shared_ptr<Room>> rooms {};

	// Стандартные комнаты
	rooms.push_back(make_shared<StandardRoom>(1, 3000.0f, false, 1, true));
	rooms.push_back(make_shared<StandardRoom>(2, 3000.0f, false, 1, true));
	rooms.push_back(make_shared<StandardRoom>(3, 4500.0f, true, 2, true));
	rooms.push_back(make_shared<StandardRoom>(4, 4500.0f, true, 2, true));
	rooms.push_back(make_shared<StandardRoom>(5, 4500.0f, true, 2, true));
	rooms.push_back(make_shared<StandardRoom>(6, 6000.0f, false, 3, true));

	// Люкс комнаты
	rooms.push_back(make_shared<Suite>(7, 5000.0f, false, true, false));
	rooms.push_back(make_shared<Suite>(8, 5000.0f, false, true, false));
	rooms.push_back(make_shared<Suite>(9, 5000.0f, true, true, false));
	rooms.push_back(make_shared<Suite>(10, 8000.0f, false, true, true));

	// Семейные комнаты
	rooms.push_back(make_shared<FamilyRoom>(11, 4500.0f, false, 1500.0f, true, 1, false));
	rooms.push_back(make_shared<FamilyRoom>(12, 4500.0f, false, 1500.0f, true, 1, false));
	rooms.push_back(make_shared<FamilyRoom>(13, 5000.0f, false, 1500.0f, true, 2, false));
	rooms.push_back(make_shared<FamilyRoom>(14, 7000.0f, false, 1500.0f, true, 3, true));


	// Меню
	vector<MenuObject> menu {
		{ 1, "Вывести список комнат;", Methods::show_rooms(rooms) },
		{ 2, "Добавление комнаты:", {
			{ 1, "Добавить стандартную комнату;", Methods::add_room<StandardRoom>(rooms) },
			{ 2, "Добавить люкс комнату;", Methods::add_room<Suite>(rooms) },
			{ 3, "Добавить семейную комнату;", Methods::add_room<FamilyRoom>(rooms) }
		} },
		{ 3, "Изменить комнату;", Methods::edit_room(rooms), true },
		{ 4, "Удалить комнату;", Methods::delete_room(rooms), true },
		{ 5, "Отсортировать список комнат.", Methods::sort_rooms(rooms), true }
	};

	// Вывод и работа с функциями меню
	MenuObject::process(menu, "Главное меню:", "Выход.");

	cout << "© 2025 Fedor Kondakov" << endl;

	return 0;
}