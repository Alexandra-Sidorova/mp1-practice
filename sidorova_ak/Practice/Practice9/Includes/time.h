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
	void CorrectTime(Time&); // корректировка времени засчет минут

	const Time& operator=(const Time&);
	Time operator+(const Time&);
	Time operator-(const Time&);
	Time operator+=(const Time&);
	Time operator+=(unsigned int); // добавление минут
	Time operator-=(const Time&);
	Time operator-=(unsigned int); // вычитание минут

	bool operator==(const Time&) const;
	bool operator!=(const Time&) const;
	bool operator>(const Time&) const;
	bool operator>=(const Time&) const;
	bool operator<(const Time&) const;
	bool operator<=(const Time&) const;

	friend istream& operator>>(istream&, Time&); // Ввод
	friend ostream& operator<<(ostream&, const Time&); // Вывод
};

#endif