#ifndef KONDAKOV_LR5_INPUT_CONTROL_H
#define KONDAKOV_LR5_INPUT_CONTROL_H

#include "kondakov_lr5_def.h"

namespace InputControl {
	// Контейнер для работы с разделителем (базовый шаблон)
	template <char Delim, typename Container, typename = void>
	struct DelimitedContainer;

	// Контейнер для работы с разделителем (основная реализация)
	template <char Delim, typename Container>
	struct DelimitedContainer<Delim, Container&, enable_if_t<is_same_v<typename Container::value_type, string>, void>>;

	// Удаление пробелов вначале и в конце (trim)
	void trim(string& str);

	// Разделение строки на контейнер подстрок
	template <char Delim, typename Container>
	void split(const string& input_line, DelimitedContainer<Delim, Container&>& dc);

	// Возврат строки в lowercase
	string get_lowercase(const string str);

	// Делает первую букву строки заглавной
	void make_first_letter_uppercase(string& str);

	// Проверка на пустой ввод для отмены операции
	bool is_input_empty(const string& input);

	// Проверить диапазон числа
	template <typename T>
	bool check_min_max(const T& number, T min, T max);

	// Ввод для строк
	bool input(string& varLink, const string& label);
	
	// Ввод для bool
	bool input(bool& varLink, const string& label);

	// Ввод для чисел и bool
	template <typename T>
	enable_if_t<is_arithmetic_v<T>, bool>
	input(T& varLink, const string& label, T min = 0, T max = numeric_limits<T>::max());

	// Возвращает один символ
	char get_char();

	// Считывает нажатие клавиши y/n
	bool yes_or_no(const string& label);
};

#include "kondakov_lr5_input_control.hpp"
#include "kondakov_lr5_container_operations.hpp"  // Дополнение для работы с контейнерами

#endif // !KONDAKOV_LR5_INPUT_CONTROL_H