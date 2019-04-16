#include "time.h"
#include "math.h"
#include "exceptions.h"

Time::Time()
{
	hours = 0;
	min = 0;
}

Time::Time(unsigned int _hours, unsigned int _min)
{
	if ((_hours < 0) || (hours >= 24) || (_min < 0) || (_min >= 60))
		throw Exception("Not correct time!");

	hours = _hours;
	min = _min;
}

Time::Time(const Time& _copy)
{
	hours = _copy.hours;
	min = _copy.min;
}

Time::~Time()
{
	hours = 0;
	min = 0;
}

unsigned int Time::GetHours()
{
	return hours;
}

unsigned int Time::GetMin()
{
	return min;
}

void Time::SetTime(unsigned int _hours, unsigned int _min)
{
	if ((_hours < 0) || (hours >= 24) || (_min < 0) || (_min >= 60))
		throw Exception("Not correct time!");

	hours = _hours;
	min = _min;
}

void Time::CorrectTime(Time& _time)
{
	if ((_time.min > 0) && ((_time.min / 60) != 0))
	{
		_time.hours += (_time.min / 60);
		_time.min = (_time.min % 60);
		return;
	}

	if ((_time.min < 0) && ((fabs(_time.min) / 60) != 0))
	{
		_time.hours -= (_time.min / 60);
		_time.min = (_time.min % 60);
		return;
	}

	// TODO
	// 25 HOURS
}

const Time& Time::operator=(const Time& _time)
{
	if (&_time == this)
		return *this;

	hours = _time.hours;
	min = _time.min;

	return *this;
}

Time Time::operator+(const Time& _add)
{
	Time result;

	result.hours = hours + _add.hours;
	result.min = min + _add.min;

	CorrectTime(*this);

	return result;
}

Time Time::operator-(const Time& _sub)
{
	Time result;

	result.hours = hours + _sub.hours;
	result.min = min + _sub.min;
	CorrectTime(*this);

	return result;
}

Time Time::operator+=(const Time& _add)
{
	hours += _add.hours;
	min += _add.min;
	CorrectTime(*this);

	return *this;
}

Time Time::operator+=(unsigned int _min)
{
	min += _min;
	CorrectTime(*this);

	return *this;
}

Time Time::operator-=(const Time& _sub)
{
	hours += _sub.hours;
	min += _sub.min;
	CorrectTime(*this);

	return *this;
}

Time Time::operator-=(unsigned int _sub)
{
	min += _sub;
	CorrectTime(*this);

	return *this;
}

bool Time::operator==(const Time& time) const
{
	return((hours == time.hours) && (min == time.min));
}

bool Time::operator!=(const Time& time) const
{
	return((hours != time.hours) || (min != time.min));
}

bool Time::operator>(const Time& time) const
{
	return((hours > time.hours) || ((hours == time.hours) && (min > time.min)));
}

bool Time::operator>=(const Time& time) const
{
	return((hours >= time.hours) || ((hours == time.hours) && (min >= time.min)));
}

bool Time::operator<(const Time& time) const
{
	return((hours < time.hours) || ((hours == time.hours) && (min < time.min)));
}

bool Time::operator<=(const Time& time) const
{
	return((hours <= time.hours) || ((hours == time.hours) && (min <= time.min)));
}

istream& operator>> (istream& in, Time& _time)
{
	in >> _time.hours >> _time.min;

	return in;
}

ostream& operator<< (ostream& out, const Time& _time)
{
	out << _time.hours << ":" << _time.min;
	
	return out;
}