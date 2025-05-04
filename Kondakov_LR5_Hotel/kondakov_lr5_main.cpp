#include "kondakov_lr5_methods.h"

int main()
{
	// Русская локализация
	setlocale(LC_ALL, "Russian");

	// Тип данных для хранения комнат
	using RoomContainer = vector<shared_ptr<Room>>;

	// Список комнат
	RoomContainer rooms {};

	// Путь к файлу для сохранения комнат
	const string ROOMS_JSON = "rooms.json";

	// Меню
	vector<MenuObject> menu {
		{ 1, "Вывести список комнат;", Methods::show_rooms(rooms) },
		{ 2, "Добавить комнату:", {
			{ 1, "Добавить стандартную комнату;", Methods::add_room<StandardRoom>(rooms) },
			{ 2, "Добавить люкс комнату;", Methods::add_room<Suite>(rooms) },
			{ 3, "Добавить семейную комнату;", Methods::add_room<FamilyRoom>(rooms) }
		} },
		{ 3, "Изменить комнату;", Methods::edit_room(rooms), true },
		{ 4, "Удалить комнату;", Methods::delete_room(rooms), true },
		{ 5, "Отсортировать список комнат;", Methods::sort_rooms(rooms), true },
		{ 6, "Рассчитать стоимость проживания;", Methods::calculate_total(rooms) },
		{ 7, "Проверить валидность комнаты;", Methods::validate_room(rooms) },
		{ 8, "Дополнительные методы комнат;", Methods::additional_room_methods(rooms) },
		{ 9, "Сохранить данные.", [&ROOMS_JSON, &rooms]() {
				Serializer::save_rooms_to_file(rooms, ROOMS_JSON);
				cout << "Данные успешно сохранены.";
			}
		},
		{ 10, "Загрузить данные.", [&ROOMS_JSON, &rooms]() {
				rooms = move(Serializer::load_rooms_from_file<RoomContainer>(ROOMS_JSON));
				cout << "Данные успешно загружены.";
			}
		}
	};

	cout << "Загрузка данных..." << endl << endl;
	menu.at(9).act();
	cout << endl << endl << endl;

	// Вывод и работа с функциями меню
	MenuObject::process(menu, "Главное меню:", "Выход.");

	cout << "© 2025 Fedor Kondakov" << endl;

	return 0;
}