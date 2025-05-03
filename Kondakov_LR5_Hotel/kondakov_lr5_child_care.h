#ifndef KONDAKOV_LR5_CHILD_CARE_H
#define KONDAKOV_LR5_CHILD_CARE_H

#include "kondakov_lr5_input_control.h"

// ����� ChildCare (������ ��� �����)
class ChildCare {
protected:
	float child_care_price;  // ��������� ����� ��� �����
	bool  has_child_care;	 // ������� ����� ��� �����

	// ��������������� �����
	void print() const {
		cout << *this << endl;
	}

	// ��������������� ����
	bool input() {
		return static_cast<bool>(cin >> *this);
	}

public:
	// ������
	static const string CURRENCY;

	// ����������� �� ���������
	ChildCare();

	// ����������� ��������������
	ChildCare(bool has_child_care);

	// ����������� � �����������
	ChildCare(float child_care_price, bool has_child_care);

	// ����������� �����������
	ChildCare(const ChildCare&) = default;
	ChildCare& operator=(const ChildCare&) = default;

	// ����������� �����������
	ChildCare(ChildCare&& other) noexcept;
	ChildCare& operator=(ChildCare&&) noexcept = default;

	// ����������� ����������
	~ChildCare() = default;

	// ������ ��������� ����� ��� �����
	inline float get_child_care_price() const;

	// ������ ��������� ����� ��� �����
	inline bool get_has_child_care() const;

	// ������ ��������� ����� ��� �����
	inline void set_child_care_price(float child_care_price);

	// ������ ��������� ����� ��� �����
	inline void set_has_child_care(bool has_child_care);

	// �������� ��������� ����� ��� �����
	inline bool input_child_care_price();

	// �������� ��������� ����� ��� �����
	inline bool input_has_child_care();

	// �������� ������� � ������
	explicit operator string() const;

	// ��������������� �������� ������ <<
	friend ostream& operator<<(ostream& os, const ChildCare& cr);

	// ��������������� �������� ����� >>
	friend istream& operator>>(istream& is, ChildCare& cr);

};

#include "kondakov_lr5_child_care.hpp"

#endif // KONDAKOV_LR5_CHILD_CARE_H