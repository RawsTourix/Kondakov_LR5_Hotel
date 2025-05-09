/**
 * @file kondakov_lr5_input_control.cpp
 * @brief ���������� ������� ���������� ������
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup input_control
 */

#include "kondakov_lr5_input_control.h"

/**
 * @brief ������� ������� � ������ � ����� ������
 * @param str ������ ��� ���������
 */
void InputControl::trim(string& str) {
    // ������� ������� � ������
    while (!str.empty() && str.front() == ' ')
        str.erase(str.begin());

    // ������� ������� � �����
    while (!str.empty() && str.back() == ' ')
        str.pop_back();
}

/**
 * @brief ����������� ������ � ������ �������
 * @param str ������� ������
 * @return ������ � ������ ��������
 */
string InputControl::get_lowercase(const string str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(),
        [](unsigned char c) { return tolower(c); });
    return result;
}

/**
 * @brief ������ ������ ����� ������ ���������
 * @param str ������ ��� ���������
 */
void InputControl::make_first_letter_uppercase(string& str) {
    if (!str.empty()) {
        str[0] = static_cast<unsigned char>(toupper(str[0]));
    }
}

/**
 * @brief ���������, �������� �� ���� ������ (��� ������ ��������)
 * @param input ������� ������
 * @return true ���� ���� ������, ����� false
 * @details ������� ��������� "[������ ��������]" ���� ���� ������
 */
bool InputControl::is_input_empty(const string& input) {
    if (input.empty()) {
        cout << endl << "[������ ��������]";
        return true;
    }
    return false;
}

/**
 * @brief ������� ����� ��� �����
 * @param varLink ������ �� ���������� ��� ���������� ����������
 * @param label ������� ��� �����
 * @return true ���� �������� ��������, ����� false
 */
bool InputControl::input(string& varLink, const string& label) {
    string raw_input;

    cout << label;
    getline(cin, raw_input);
    trim(raw_input);
    if (is_input_empty(raw_input))
        return true;   // ������ ��������
    else {
        varLink = raw_input;
        return false;  // ����������� ��������
    }
}

/**
 * @brief ������� ����� ��� bool
 * @param varLink ������ �� ���������� ��� ���������� ����������
 * @param label ������� ��� �����
 * @return true ���� �������� ��������, ����� false
 * @details ���������� ���� ����� (0 ��� 1) � ����������� ��������������� � bool
 */
bool InputControl::input(bool& varLink, const string& label) {
    int bool_param = 0;
    if (input(bool_param, label, 0, 1)) {  // ������������� ����� input<int>
        return true;  // ������ ��������
    }
    varLink = static_cast<bool>(bool_param);
    return false;
}

/**
 * @brief �������� ���� ������ �� �����
 * @return �������� ������
 * @details ������� ����� ����� ����� ���������� �������
 */
char InputControl::get_char() {
    char ch;
    cin >> ch;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return ch;
}

/**
 * @brief ����������� ������������� (y/n)
 * @param label ������� ��� �������
 * @return true ���� ������� 'y' ��� 'Y', false ���� 'n' ��� 'N'
 * @details ���������� ����������� ���� ���� �� ����� ������� ���������� �����
 */
bool InputControl::yes_or_no(const string& label) {
    char ch;

    while (true) {
        cout << label << " (y/n): ";
        ch = get_char();
        cout << endl;

        if (ch == 'y' || ch == 'Y') return true;
        if (ch == 'n' || ch == 'N') return false;

        cout << endl << "������������ ����!" << endl << endl;
    }
}