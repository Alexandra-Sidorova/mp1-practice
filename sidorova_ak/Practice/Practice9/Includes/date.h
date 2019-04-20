#ifndef _DATE_H_
#define _DATE_H_
#include "iostream"

using namespace std;

class Date
{
private:
	unsigned int day, mouth, year;
public:
	Date();
	Date(unsigned int, unsigned int, unsigned int);
	Date(const Date&);
	~Date();

	unsigned int GetDay();
	unsigned int GetMouth();
	unsigned int GetYear();
	void SetDate(unsigned int, unsigned int, unsigned int);
	void CorrectDate(Date&); // ������������� ���� ������ ���� � �������

	const Date& operator=(const Date&);
	Date operator+(const Date&);
	Date operator-(const Date&);
	Date operator+=(const Date&);
	Date operator+=(unsigned int); // ���������� �����
	Date operator-=(const Date&);
	Date operator-=(unsigned int); // ��������� �����

	bool operator==(const Date&) const;
	bool operator!=(const Date&) const;
	bool operator>(const Date&) const;
	bool operator>=(const Date&) const;
	bool operator<(const Date&) const;
	bool operator<=(const Date&) const;

	friend istream& operator>>(istream&, Date&); // ����
	friend ostream& operator<<(ostream&, const Date&); // �����
};

#endif