#include "dataBase.h"
#include "exceptions.h"

DataBase::DataBase()
{
	number = 1;
	workers = new Person;
}

DataBase::DataBase(int _num)
{
	if (_num <= 0)
		throw Exception("Not correct the number of working!");

	number = _num;
	workers = new Person[number];
}

DataBase::DataBase(int _num, Person* _array)
{
	if (_num <= 0)
		throw Exception("Not correct the number of working!");

	if (_array == NULL)
		throw Exception("Not correct the array of persons!");

	number = _num;
	workers = new Person[number];

	for (int i = 0; i < number; i++)
		workers[i] = _array[i];
}

DataBase::~DataBase()
{
	number = 0;
	workers = NULL;
}

int DataBase::getNumber()
{
	return number;
}

void DataBase::setNumber(const int _num)
{
	if (_num <= 0 )
		throw Exception("Not correct the number of working!");

	number = _num;
}
