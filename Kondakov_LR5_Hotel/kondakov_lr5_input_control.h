#ifndef KONDAKOV_LR5_INPUT_CONTROL_H
#define KONDAKOV_LR5_INPUT_CONTROL_H

#include "kondakov_lr5_def.h"

namespace InputControl {
	// ��������� ��� ������ � ������������ (������� ������)
	template <char Delim, typename Container, typename = void>
	struct DelimitedContainer;

	// ��������� ��� ������ � ������������ (�������� ����������)
	template <char Delim, typename Container>
	struct DelimitedContainer<Delim, Container&, enable_if_t<is_same_v<typename Container::value_type, string>, void>>;

	// �������� �������� ������� � � ����� (trim)
	void trim(string& str);

	// ���������� ������ �� ��������� ��������
	template <char Delim, typename Container>
	void split(const string& input_line, DelimitedContainer<Delim, Container&>& dc);

	// ������� ������ � lowercase
	string get_lowercase(const string str);

	// ������ ������ ����� ������ ���������
	void make_first_letter_uppercase(string& str);

	// �������� �� ������ ���� ��� ������ ��������
	bool is_input_empty(const string& input);

	// ��������� �������� �����
	template <typename T>
	bool check_min_max(const T& number, T min, T max);

	// ���� ��� �����
	bool input(string& varLink, const string& label);
	
	// ���� ��� bool
	bool input(bool& varLink, const string& label);

	// ���� ��� ����� � bool
	template <typename T>
	enable_if_t<is_arithmetic_v<T>, bool>
	input(T& varLink, const string& label, T min = 0, T max = numeric_limits<T>::max());

	// ���������� ���� ������
	char get_char();

	// ��������� ������� ������� y/n
	bool yes_or_no(const string& label);
};

#include "kondakov_lr5_input_control.hpp"
#include "kondakov_lr5_container_operations.hpp"  // ���������� ��� ������ � ������������

#endif // !KONDAKOV_LR5_INPUT_CONTROL_H