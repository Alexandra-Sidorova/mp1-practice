#include "passport.h"

Passport::Passport()
{
	series = 0;
	number = 0;
	departmentIssue = "FMSD Moscow";
}

Passport::Passport(const Passport& _copy) // : addressRegist(_copy.addressRegist)
{
	series = _copy.series;
	number = _copy.number;
	dateIssue = _copy.dateIssue;
	dateBirth = _copy.dateBirth;
	addressRegist = _copy.addressRegist;
}

Passport::~Passport()
{
	series = 0;
	number = 0;
	departmentIssue = "";
}

int Passport::getSeries()
{
	return series;
}

long Passport::getNumber()
{
	return number;
}

string Passport::getDepartmentIssue()
{
	return departmentIssue;
}

Date Passport::getDateIssue()
{
	return dateIssue;
}

Date Passport::getDateBirth()
{
	return dateBirth;
}

Address Passport::getAddressRegist()
{
	return addressRegist;
}

void Passport::setSeries(const int _series)
{
	if (_series < 100 && _series > 9999)
		throw Exception("Not correct series of passport!");

	series = _series;
}

void Passport::setNumber(const long _number)
{
	if (_number < 100000 || _number > 999999)
		throw Exception("Not correct number of passport!");

	number = _number;
}

void Passport::setDepartmentIssue(const string _dep)
{
	if (_dep == "")
		throw Exception("Not correct department of issue!");

	departmentIssue = _dep;
}

void Passport::setDateIssue(const Date _issue)
{
	dateIssue = _issue;
}

void Passport::setDateBirth(const Date _birth)
{
	dateBirth = _birth;
}

void Passport::setAddressRegist(const Address _reg)
{
	addressRegist = _reg;
}

ostream& operator<<(ostream& out, const Passport& _passport)
{
	string series[4], number[6];
	int tmpSeries = _passport.series;
	long tmpNumber = _passport.number;

	for (int i = 0; i < 4; i++)
	{
		series[i] = tmpSeries % 10;
		tmpSeries /= 10;
	}

	for (int i = 0; i < 6; i++)
	{
		number[i] = tmpNumber % 10;
		tmpNumber /= 10;
	}
	
	out << tmpSeries << " " << tmpNumber << endl
		<< "Issued by: " << _passport.departmentIssue << " " << _passport.dateIssue << endl
		<< "Date of Birth: " << _passport.dateBirth << endl
		<< "Registration address: " << _passport.addressRegist;

	return out;
}