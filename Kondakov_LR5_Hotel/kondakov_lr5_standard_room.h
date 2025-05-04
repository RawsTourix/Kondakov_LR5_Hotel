#ifndef KONDAKOV_LR5_STANDARD_ROOM_H
#define KONDAKOV_LR5_STANDARD_ROOM_H

#include "kondakov_lr5_room.h"

// ��������� Room
class StandardRoom final : virtual public Room {
private:
	int			   bed_count;  // ���������� ��������
	bool		   has_tv;	   // ������� ����������
	vector<string> amenities;  // ��������

	// ��� �������
	const string ROOM_TYPE = "����������� �������";

	// ��� ���������� � json
	const string JSON_TYPE = "Standard";

public:
	// ����������� �� ���������
	StandardRoom();

	// ����������� �������������� (�������� �� room_number � bed_count)
	StandardRoom(int room_number, int bed_count);

	// ����������� �������������� (� ���������� �� ���������)
	StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv);

	// ����������� � ����������� (�������� ������)
	StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv, string amenities);

	// ����������� � ����������� (�������� ������)
	StandardRoom(int room_number, float price_per_night, bool is_booked, int bed_count, bool has_tv, vector<string> amenities);

	// ����������� �����������
	StandardRoom(const StandardRoom&) = default;
	StandardRoom& operator=(const StandardRoom&) = default;

	// ����������� �����������
	StandardRoom(StandardRoom&& other) noexcept;
	StandardRoom& operator=(StandardRoom&&) noexcept = default;

	// ����������� ����������
	virtual ~StandardRoom() = default;

	// ������ ���������� ��������
	inline int get_bed_count() const;

	// ������ ������� ����������
	inline bool get_has_tv() const;

	// ������ ������ �������
	virtual inline const vector<string>& get_amenities() const override;

	// ������ ������� �������� �������
	virtual inline string get_full_name() const override;

	// ������ ���������� ��������
	inline void set_bed_count(int bed_count);

	// ������ ������� ����������
	inline void set_has_tv(bool has_tv);

	// ������ �������
	inline void set_amenities(vector<string> amenities);

	// �������� ���������� ��������
	inline bool input_bed_count();

	// �������� ������� ����������
	inline bool input_has_tv();

	// �������� �������
	template <char Delim>
	inline bool input_amenities();

	// ����������� ������ ���� �������
	virtual inline const string& get_room_type() const override;

	// ����������� ������ ���� ���������� ������� � json
	virtual inline const string& get_json_type() const override;

	// ������ ��������� ���������� (������� �� ���� ������)
	virtual inline float calculate_total(int night_count) const override;

	// �������� bed_count >= 1
	virtual inline bool validate() const override;

	// ���������� ������� (+20% � ����)
	inline void exstra_bed();

	// ������� � json
	virtual json to_json() const override;

	// ������� �� json
	virtual void from_json(const json& j) override;

	// �������� �������
	friend vector<string>  operator+ (const StandardRoom& sr1, const StandardRoom& sr2);
	friend vector<string>  operator+ (const vector<string>& amenities, const StandardRoom& sr);
	friend vector<string>  operator+ (const StandardRoom& sr, const vector<string>& amenities);
	friend vector<string>& operator+=(vector<string>& amenities, const StandardRoom& sr);
	friend StandardRoom&   operator+=(StandardRoom& sr, const vector<string>& amenities);
	friend StandardRoom&   operator+=(StandardRoom& sr, const string& amenities);

	// �������� ������� � ������
	explicit operator string() const;

	// ��������������� �������� ������ <<
	friend ostream& operator<<(ostream& os, const StandardRoom& r);

	// ��������������� �������� ����� >>
	friend istream& operator>>(istream& is, StandardRoom& r);

	// ��������������� �����
	virtual void print() const override;

	// ��������������� ����
	virtual bool input() override;

	// ������� � ������
	virtual string to_string() const override;
};

#include "kondakov_lr5_standard_room.hpp"

#endif // KONDAKOV_LR5_STANDARD_ROOM_H