#include "kondakov_lr5_child_care.h"

// Валюта
const string ChildCare::CURRENCY;

// Конструктор по умолчанию
ChildCare::ChildCare()
	: ChildCare(1000.0f, false) {
}

// Конструктор преобразования
ChildCare::ChildCare(bool has_child_care)
	: ChildCare(1000.0f, has_child_care) {
}

// Конструктор с параметрами
ChildCare::ChildCare(float child_care_price, bool has_child_care)
	: child_care_price(child_care_price),
	has_child_care(has_child_care) {
}

// Конструктор перемещения
ChildCare::ChildCare(ChildCare&& other) noexcept
	: child_care_price(other.child_care_price),
	has_child_care(other.has_child_care) {
}

// Красивый перевод в строку
ChildCare::operator string() const {
	ostringstream oss;
	oss << "Стоимость услуг для детей:\t" << child_care_price << " " << CURRENCY << endl
		<< "Наличие услуг для детей:\t"   << (has_child_care ? "да" : "нет");

	return oss.str();
}

// Переопределение операции вывода <<
ostream& operator<<(ostream& os, const ChildCare& cr) {
	os << static_cast<string>(cr);

	return os;
}

// Переопределение операции ввода >>
istream& operator>>(istream& is, ChildCare& cr) {
	if (cr.input_child_care_price()) { is.setstate(ios::failbit); return is; }
	if (cr.input_has_child_care())   { is.setstate(ios::failbit); return is; }

	return is;
}

// Перевод в строку
string ChildCare::to_string() const {
	ostringstream oss;
	oss << *this;
	return oss.str();
}