#include "date.h"
#include "exceptions.h"

Date::Date()
{
    day = 1;
    mouth = 1;
    year = 1900;
}

Date::Date(unsigned int _day, unsigned int _mouth, unsigned int _year)
{
    if ((_day <= 0) || (_day > 31) || (_mouth <= 0) || (_mouth > 12) || (_year < 1900))
        throw Exception("Not correct date!");

    if((_day > 29) && (_mouth == 2)) // проверка на 28-29 суток в феврале
        throw Exception("Not correct date!");

    day = _day;
    mouth = _mouth;
    year = _year;
}

Date::Date(const Date& _copy)
{
    day = _copy.day;
    mouth = _copy.mouth;
    year = _copy.year;
}

Date::~Date()
{
    day = 0;
    mouth = 0;
    year = 0;
}

unsigned int Date::GetDay()
{
    return day;
}

unsigned int Date::GetMouth()
{
    return mouth;
}

unsigned int Date::GetYear()
{
    return year;
}

void Date::SetDate(unsigned int _day, unsigned int _mouth, unsigned int _year)
{
    if ((_day <= 0) || (_day > 31) || (_mouth <= 0) || (_mouth > 12) || (_year < 1900))
        throw Exception("Not correct date!");

    if ((_day > 29) && (_mouth == 2)) // проверка на 28-29 суток в феврале
        throw Exception("Not correct date!");

    day = _day;
    mouth = _mouth;
    year = _year;
}

void Date::CorrectDate(Date& _date)
{
    if ((_date.day / 31) != 0)
    {
        _date.mouth += (_date.day / 31);
        _date.day = (_date.day % 31);
    }

    if ((_date.mouth / 12) != 0)
    {
        _date.year += (_date.mouth / 12);
        _date.mouth = (_date.mouth % 12);
    }

    return;
}

const Date& Date::operator=(const Date& _date)
{
    if (&_date == this)
        return *this;

    day = _date.day;
    mouth = _date.mouth;
    year = _date.year;

    return *this;
}

Date Date::operator+(const Date& _add)
{
    Date result;

    result.day = day + _add.day;
    result.mouth = mouth + _add.mouth;
    result.year = year + _add.year;

    CorrectDate(*this);

    return result;
}

Date Date::operator-(const Date& _sub)
{
    Date result;

    result.day = day + _sub.day;
    result.mouth = mouth + _sub.mouth;
    result.year = year + _sub.year;

    CorrectDate(*this);

    return result;
}

Date Date::operator+=(const Date& _add)
{
    day += _add.day;
    mouth += _add.mouth;
    year += _add.year;
    CorrectDate(*this);

    return *this;
}

Date Date::operator+=(unsigned int _day)
{
    day += _day;
    CorrectDate(*this);

    return *this;
}

Date Date::operator-=(const Date& _sub)
{
    day -= _sub.day;
    mouth -= _sub.mouth;
    year -= _sub.year;
    CorrectDate(*this);

    return *this;
}

Date Date::operator-=(unsigned int _day)
{
    day -= _day;
    CorrectDate(*this);

    return *this;
}

bool Date::operator==(const Date& date) const
{
    return ((day == date.day) && (mouth == date.mouth) && (year == date.year));
}

bool Date::operator!=(const Date& date) const
{
    return ((day != date.day) || (mouth != date.mouth) || (year != date.year));
}

bool Date::operator>(const Date& date) const
{
    if ((day > date.day) && (mouth == date.mouth) && (year == date.year))
        return 1;

    if ((mouth > date.mouth) && (year == date.year))
        return 1;

    if (year > date.year)
        return 1;

    return 0;
}

bool Date::operator>=(const Date& date) const
{
    if ((day >= date.day) && (mouth == date.mouth) && (year == date.year))
        return 1;

    if ((mouth >= date.mouth) && (year == date.year))
        return 1;

    if (year >= date.year)
        return 1;

    return 0;
}

bool Date::operator<(const Date& date) const
{
    if ((day < date.day) && (mouth == date.mouth) && (year == date.year))
        return 1;

    if ((mouth < date.mouth) && (year == date.year))
        return 1;

    if (year < date.year)
        return 1;

    return 0;
}

bool Date::operator<=(const Date& date) const
{
    if ((day <= date.day) && (mouth == date.mouth) && (year == date.year))
        return 1;

    if ((mouth <= date.mouth) && (year == date.year))
        return 1;

    if (year <= date.year)
        return 1;

    return 0;
}

istream& operator>>(istream& in, Date& _date)
{
    in >> _date.day >> _date.mouth >> _date.year;

    return in;
}

ostream& operator<<(ostream& out, const Date& _date)
{
    out << _date.day << "." << _date.mouth << "." << _date.year;

    return out;
}