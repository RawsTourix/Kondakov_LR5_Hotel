/**
 * @file kondakov_lr5_input_control.cpp
 * @brief Реализация функций управления вводом
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup input_control
 */

#include "kondakov_lr5_input_control.h"

/**
 * @brief Удаляет пробелы в начале и конце строки
 * @param str Строка для обработки
 */
void InputControl::trim(string& str) {
    // Удаляем пробелы с начала
    while (!str.empty() && str.front() == ' ')
        str.erase(str.begin());

    // Удаляем пробелы с конца
    while (!str.empty() && str.back() == ' ')
        str.pop_back();
}

/**
 * @brief Преобразует строку в нижний регистр
 * @param str Входная строка
 * @return Строка в нижнем регистре
 */
string InputControl::get_lowercase(const string str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(),
        [](unsigned char c) { return tolower(c); });
    return result;
}

/**
 * @brief Делает первую букву строки заглавной
 * @param str Строка для обработки
 */
void InputControl::make_first_letter_uppercase(string& str) {
    if (!str.empty()) {
        str[0] = static_cast<unsigned char>(toupper(str[0]));
    }
}

/**
 * @brief Проверяет, является ли ввод пустым (для отмены операции)
 * @param input Входная строка
 * @return true если ввод пустой, иначе false
 * @details Выводит сообщение "[Отмена операции]" если ввод пустой
 */
bool InputControl::is_input_empty(const string& input) {
    if (input.empty()) {
        cout << endl << "[Отмена операции]";
        return true;
    }
    return false;
}

/**
 * @brief Функция ввода для строк
 * @param varLink Ссылка на переменную для сохранения результата
 * @param label Подпись для ввода
 * @return true если операция отменена, иначе false
 */
bool InputControl::input(string& varLink, const string& label) {
    string raw_input;

    cout << label;
    getline(cin, raw_input);
    trim(raw_input);
    if (is_input_empty(raw_input))
        return true;   // отмена операции
    else {
        varLink = raw_input;
        return false;  // продолжение операции
    }
}

/**
 * @brief Функция ввода для bool
 * @param varLink Ссылка на переменную для сохранения результата
 * @param label Подпись для ввода
 * @return true если операция отменена, иначе false
 * @details Использует ввод числа (0 или 1) с последующим преобразованием в bool
 */
bool InputControl::input(bool& varLink, const string& label) {
    int bool_param = 0;
    if (input(bool_param, label, 0, 1)) {  // Делегирование через input<int>
        return true;  // Отмена операции
    }
    varLink = static_cast<bool>(bool_param);
    return false;
}

/**
 * @brief Получает один символ из ввода
 * @return Введённый символ
 * @details Очищает буфер ввода после считывания символа
 */
char InputControl::get_char() {
    char ch;
    cin >> ch;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return ch;
}

/**
 * @brief Запрашивает подтверждение (y/n)
 * @param label Подпись для запроса
 * @return true если введено 'y' или 'Y', false если 'n' или 'N'
 * @details Циклически запрашивает ввод пока не будет получен корректный ответ
 */
bool InputControl::yes_or_no(const string& label) {
    char ch;

    while (true) {
        cout << label << " (y/n): ";
        ch = get_char();
        cout << endl;

        if (ch == 'y' || ch == 'Y') return true;
        if (ch == 'n' || ch == 'N') return false;

        cout << endl << "Некорректный ввод!" << endl << endl;
    }
}