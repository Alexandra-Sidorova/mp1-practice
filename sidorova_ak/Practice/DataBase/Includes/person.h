#ifndef _PERSON_H_
#define _PERSON_H_

#include "date.h"
#include "passport.h"
#include "education.h"
#include "exceptions.h"
#include <string>

using namespace std;

class Person
{
private:
	string firstName;
	string lastName;
	string patronymic;  // отчество
	Passport passportData;
	Education educationData;
	string subdivision;  // подразделение
	string post;  // должность
	double pay;
	Date startWorking;  // дата поступления в фирму
	Date lastAppointment;  // дата последнего назначения

public:
	Person();
	Person(const Person&);
	Person(string, string, string);
	~Person();
};

#endif