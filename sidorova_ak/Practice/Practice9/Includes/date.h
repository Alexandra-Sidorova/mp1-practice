#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>

using namespace std;

class Date
{
public:
    unsigned int day, mouth, year;

    Date();
    Date(unsigned int, unsigned int, unsigned int);
    Date(const Date&);
    ~Date();

    unsigned int GetDay();
    unsigned int GetMouth();
    unsigned int GetYear();
    void SetDate(unsigned int, unsigned int, unsigned int);
    void CorrectDate(Date&); // корректировка даты засчет дней и мес¤цев

    const Date& operator=(const Date&);
    Date operator+(const Date&);
    Date operator-(const Date&);
    Date& operator+=(const Date&);
    Date& operator+=(unsigned int); // добавление суток
    Date& operator-=(const Date&);
    Date& operator-=(unsigned int); // вычитание суток

    bool operator==(const Date&) const;
    bool operator!=(const Date&) const;
    bool operator>(const Date&) const;
    bool operator>=(const Date&) const;
    bool operator<(const Date&) const;
    bool operator<=(const Date&) const;

    friend istream& operator>>(istream&, Date&); // ввод
    friend ostream& operator<<(ostream&, const Date&); // вывод
};

#endif