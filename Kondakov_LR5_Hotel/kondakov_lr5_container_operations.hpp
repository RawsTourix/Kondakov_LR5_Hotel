#ifndef KONDAKOV_LR5_CONTAINER_OPERATIONS_HPP
#define KONDAKOV_LR5_CONTAINER_OPERATIONS_HPP

#include "kondakov_lr5_input_control.h"

// Контейнер для работы с разделителем (основная реализация)
template <char Delim, typename Container>
struct InputControl::DelimitedContainer<Delim, Container&, enable_if_t<is_same_v<typename Container::value_type, string>, void>> {
	Container& ref;
	explicit DelimitedContainer(Container& r) : ref(r) {}
};

// Перегрузка вывода контейнера строк
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, ostream&>
operator<<(ostream& os, const Container& strings) {
	if (!strings.empty()) {
		auto it = strings.begin();
		os << *it;

		for (++it; it != strings.end(); ++it) {
			os << ", " << *it;
		}
	}
	return os;
}

// Перегрузка сложения контейнеров строк
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, Container>
operator+(const Container& lhs, const Container& rhs) {
	Container result = lhs;
	for (const auto& str : rhs) {
		if (find(result.begin(), result.end(), str) == result.end()) {
			result.push_back(str);
		}
	}
	return result;
}

// Перегрузка присваивания сложения контейнеров строк
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, Container&>
operator+=(Container& lhs, const Container& rhs) {
	for (const auto& str : rhs) {
		if (find(lhs.begin(), lhs.end(), str) == lhs.end()) {
			lhs.push_back(str);
		}
	}
	return lhs;
}

// Перегрузка присваивания сложения контейнера строк со строкой
template <typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, Container&>
operator+=(Container& lhs, const string& str) {
	if (find(lhs.begin(), lhs.end(), str) == lhs.end()) {
		lhs.push_back(str);
	}
	return lhs;
}

// Перегрузка ввода контейнера строк с разделителем
// Задаётся: vector<string> data { ... }; InputControl::DelimitedContainer<',', vector<string>&> dc(data); cin >> dc;
template <char Delim, typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, istream&>
operator>>(istream& is, InputControl::DelimitedContainer<Delim, Container&>& dc) {
    string input_line;

	// Обработка ошибки чтения
	if (!getline(is, input_line)) { is.setstate(ios::failbit); return is; }

	InputControl::trim(input_line);

	// Отмена операции
	if (InputControl::is_input_empty(input_line)) { is.setstate(ios::failbit); return is; }

	InputControl::split(input_line, dc);

    return is;
}

// Разделение строки и запись в контейнер
template <char Delim, typename Container>
typename enable_if_t<is_same_v<typename Container::value_type, string>, Container&>
operator>>(InputControl::DelimitedContainer<Delim, Container&>& dc, const string& input_line) {
	InputControl::split(input_line, dc);
	return dc.ref;
}

#endif // KONDAKOV_LR5_CONTAINER_OPERATIONS_HPP