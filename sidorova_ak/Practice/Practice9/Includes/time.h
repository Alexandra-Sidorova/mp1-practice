#ifndef _TIME_H_
#define _TIME_H_
#include "iostream"

using namespace std;

class Time
{
private:
	unsigned int hours, min;
public:
	Time();
	Time(unsigned int, unsigned int);
	Time(const Time& );
	~Time();

	unsigned int GetHours();
	unsigned int GetMin();
	void SetTime(unsigned int, unsigned int);
	void CorrectTime(Time&); // ������������� ������� ������ �����

	const Time& operator=(const Time&);
	Time operator+(const Time&);
	Time operator-(const Time&);
	Time operator+=(const Time&);
	Time operator+=(unsigned int); // ���������� �����
	Time operator-=(const Time&);
	Time operator-=(unsigned int); // ��������� �����

	bool operator==(const Time&) const;
	bool operator!=(const Time&) const;
	bool operator>(const Time&) const;
	bool operator>=(const Time&) const;
	bool operator<(const Time&) const;
	bool operator<=(const Time&) const;

	friend istream& operator>>(istream&, Time&); // ����
	friend ostream& operator<<(ostream&, const Time&); // �����
};

#endif