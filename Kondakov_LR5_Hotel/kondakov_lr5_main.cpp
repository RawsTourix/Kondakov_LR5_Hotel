/**
 * @file kondakov_lr5_main.cpp
 * @brief Главный файл приложения для управления гостиничными номерами
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 */

#include "kondakov_lr5_methods.h"

/**
 * @brief Точка входа в приложение
 * @return Код завершения программы (0 - успешно)
 * 
 * @details Основные функции программы:
 * - Инициализация системы (установка локали)
 * - Создание и загрузка данных о комнатах
 * - Формирование главного меню
 * - Обработка пользовательского ввода
 * - Сохранение данных при завершении
 */
int main() {
    // Установка русской локали для корректного вывода
    setlocale(LC_ALL, "Russian");

    // Определение типа контейнера для хранения комнат
    using RoomContainer = vector<shared_ptr<Room>>;

    // Основной контейнер для хранения комнат
    RoomContainer rooms {};

    // Путь к файлу для сохранения/загрузки данных
    const string ROOMS_JSON = "rooms.json";

    /**
     * @brief Главное меню приложения
     * @details Содержит следующие пункты:
     * 1. Просмотр списка комнат
     * 2. Добавление новых комнат (подменю)
     * 3. Редактирование существующих комнат
     * 4. Удаление комнат
     * 5. Сортировка комнат
     * 6. Расчет стоимости проживания
     * 7. Проверка валидности комнат
     * 8. Дополнительные операции
     * 9. Сохранение данных
     * 10. Загрузка данных
     */
    vector<MenuObject> menu {
        { 1, "Вывести список комнат;", Methods::show_rooms(rooms) },
        { 2, "Добавить комнату:", {
            { 1, "Добавить стандартную комнату;", Methods::add_room<StandardRoom>(rooms) },
            { 2, "Добавить люкс комнату;", Methods::add_room<Suite>(rooms) },
            { 3, "Добавить семейную комнату;", Methods::add_room<FamilyRoom>(rooms) }
        }},
        { 3, "Изменить комнату;", Methods::edit_room(rooms), true },
        { 4, "Удалить комнату;", Methods::delete_room(rooms), true },
        { 5, "Отсортировать список комнат;", Methods::sort_rooms(rooms), true },
        { 6, "Рассчитать стоимость проживания;", Methods::calculate_total(rooms) },
        { 7, "Проверить валидность комнаты;", Methods::validate_room(rooms) },
        { 8, "Дополнительные методы комнат;", Methods::additional_room_methods(rooms) },
        { 9, "Сохранить данные;", [&ROOMS_JSON, &rooms]() {
            cout << "Сохранение данных..." << endl << endl;
            Serializer::save_rooms_to_file(rooms, ROOMS_JSON);
            cout << "Данные успешно сохранены.";
        }},
        { 10, "Загрузить данные;", [&ROOMS_JSON, &rooms]() {
            try {
                cout << "Загрузка данных..." << endl << endl;
                rooms = move(Serializer::load_rooms_from_file<RoomContainer>(ROOMS_JSON));
                cout << "Данные успешно загружены.";
            }
            catch (const exception& e) {
                cout << "Ошибка: \"" << e.what() << "\"";
            }
        }}
    };

    // Загрузка данных при старте
    menu.at(9).act(); // Вызов пункта меню "Сохранить данные"
    cout << endl << endl << endl;

    // Запуск основного цикла обработки меню
    MenuObject::process(menu, "Главное меню:", "Выход.");

    // Вывод информации об авторе
    cout << "© 2025 Fedor Kondakov" << endl;

    return 0;
}