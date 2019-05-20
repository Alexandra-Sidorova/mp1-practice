#ifndef _ADDRESS_H_
#define _ADDRESS_H_

#include <string>
#include <iostream>

using namespace std;

class Address
{
private:
	string region;
	string city;
	string street;
	int house;
	int flat;

public:
	Address();
	Address(string, string, string, int, int);
	Address(const Address&);
	~Address();

	string getRegion();
	string getCity();
	string getStreet();
	int getHouse();
	int getFlat();

	void setRegion(const string);
	void setCity(const string);
	void setStreet(const string);
	void setHouse(const int);
	void setFlat(const int);

	const Address& operator=(const Address&);
	friend ostream& operator<<(ostream&, const Address&);
};

#endif