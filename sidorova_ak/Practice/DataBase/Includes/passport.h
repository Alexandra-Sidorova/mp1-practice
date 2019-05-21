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
	int series;  // �����
	long number;  // �����
	string departmentIssue;  // ��� ������
	Date dateIssue;  // ���� ������
	Date dateBirth;  // ���� ��������
	Address addressRegist;  // ����� ����������

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