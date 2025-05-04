#include "kondakov_lr5_child_care.h"

// ������
const string ChildCare::CURRENCY;

// ����������� �� ���������
ChildCare::ChildCare()
	: ChildCare(1000.0f, false) {
}

// ����������� ��������������
ChildCare::ChildCare(bool has_child_care)
	: ChildCare(1000.0f, has_child_care) {
}

// ����������� � �����������
ChildCare::ChildCare(float child_care_price, bool has_child_care)
	: child_care_price(child_care_price),
	has_child_care(has_child_care) {
}

// ����������� �����������
ChildCare::ChildCare(ChildCare&& other) noexcept
	: child_care_price(other.child_care_price),
	has_child_care(other.has_child_care) {
}

// �������� ������� � ������
ChildCare::operator string() const {
	ostringstream oss;
	oss << "��������� ����� ��� �����:\t" << child_care_price << " " << CURRENCY << endl
		<< "������� ����� ��� �����:\t"   << (has_child_care ? "��" : "���");

	return oss.str();
}

// ��������������� �������� ������ <<
ostream& operator<<(ostream& os, const ChildCare& cr) {
	os << static_cast<string>(cr);

	return os;
}

// ��������������� �������� ����� >>
istream& operator>>(istream& is, ChildCare& cr) {
	if (cr.input_child_care_price()) { is.setstate(ios::failbit); return is; }
	if (cr.input_has_child_care())   { is.setstate(ios::failbit); return is; }

	return is;
}

// ������� � ������
string ChildCare::to_string() const {
	ostringstream oss;
	oss << *this;
	return oss.str();
}