#include "kondakov_lr5_input_control.h"

// Удаление пробелов вначале и в конце (trim)
void InputControl::trim(string& str) {
	// Удаляем пробелы с начала
	while (!str.empty() && str.front() == ' ')
		str.erase(str.begin());

	// Удаляем пробелы с конца
	while (!str.empty() && str.back() == ' ')
		str.pop_back();
}

// Возврат строки в lowercase
string InputControl::get_lowercase(const string str) {
	string result = str;
	transform(result.begin(), result.end(), result.begin(),
		[](unsigned char c) { return tolower(c); });
	return result;
}

// Делает первую букву строки заглавной
void InputControl::make_first_letter_uppercase(string& str) {
	if (!str.empty()) {
		str[0] = static_cast<unsigned char>(toupper(str[0]));
	}
}

// Проверка на пустой ввод для отмены операции
bool InputControl::is_input_empty(const string& input) {
	if (input.empty()) {
		cout << endl << "[Отмена операции]";
		return true;
	}
	return false;
}

// Ввод для строк
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

// Ввод для bool
bool InputControl::input(bool& varLink, const string& label) {
	int bool_param = 0;
	if (input(bool_param, label, 0, 1)) {  // Делегирование через input<int>
		return true;  // Отмена операции
	}
	varLink = static_cast<bool>(bool_param);
	return false;
}

// Возвращает один символ
char InputControl::get_char() {
	char ch;
	cin >> ch;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return ch;
}

// Считывает нажатие клавиши y/n
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