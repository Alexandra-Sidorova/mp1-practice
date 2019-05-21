#ifndef _PASSPORT_H_
#define _PASSPORT_H_

#include "date.h"
#include "address.h"
#include <string>
#include <iostream>

using namespace std;

class Passport
{
private:
	int series;  // серия
	long number;  // номер
	string departmentIssue;  // кем выдано
	Date dateIssue;  // дата выдачи
	Date dateBirth;  // дата рождения
	Address addressRegist;  // место проживания

public:
	Passport();
	Passport(const Passport&);
	~Passport();

	int getSeries();
	long getNumber();
	string getDepartmentIssue();
	Date getDateIssue();
	Date getDateBirth();
	Address getAddressRegist();

	void setSeries(const int);
	void setNumber(const long);
	void setDepartmentIssue(const string);
	void setDateIssue(const Date);
	void setDateBirth(const Date);
	void setAddressRegist(const Address);

	friend ostream& operator<<(ostream&, const Passport&);
};

#endif