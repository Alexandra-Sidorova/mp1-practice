#ifndef _DATABASE_H_
#define _DATABASE_H_

#include "person.h"
#include <iostream>

using namespace std;

class DataBase
{
private:
	int number;  // ���������� �������
	Person* workers;
public:
	DataBase();
	DataBase(int);
	DataBase(int, Person*);
	~DataBase();

	int getNumber();

	void setNumber(const int);
};

#endif