#ifndef _PERSON_H_
#define _PERSON_H_

#include "date.h"
#include "passport.h"
#include "education.h"
#include <string>
#include <iostream>

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
	Person(string, string, string); // ФИО
	~Person();

	string getFirstName();
	string getLastName();
	string getPatronymic();
	Passport getPassportData();
	Education getEducationData();
	string getSubdivision();
	string getPost();
	double getPay();
	Date getStartWorking();
	Date getLastAppointment();

	void setFirstName(const string);
	void setLastName(const string);
	void setPatronymic(const string);
	void setPassportData(const Passport);
	void setEducationData(const Education);
	void setSubdivision(const string);
	void setPost(const string);
	void setPay(const double);
	void setStartWorking(const Date);
	void setLastAppointment(const Date);

	const Person& operator=(const Person&);
	friend ostream& operator<<(ostream&, const Person&);
};

#endif