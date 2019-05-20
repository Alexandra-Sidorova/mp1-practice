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
	string patronymic;  // ��������
	Passport passportData;
	Education educationData;
	string subdivision;  // �������������
	string post;  // ���������
	double pay;
	Date startWorking;  // ���� ����������� � �����
	Date lastAppointment;  // ���� ���������� ����������

public:
	Person();
	Person(const Person&);
	Person(string, string, string);
	~Person();
};

#endif