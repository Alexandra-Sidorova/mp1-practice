#ifndef _DATABASE_H_
#define _DATABASE_H_

#include "person.h"

class DataBase
{
private:
	Person* workers;
	int number;  // ���������� �������
public:
	DataBase();
	DataBase(int);
	DataBase(Person*, int);
	~DataBase();
};

#endif