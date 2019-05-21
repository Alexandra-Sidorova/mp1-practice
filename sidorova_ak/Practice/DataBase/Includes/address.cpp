#include "address.h"
#include "exceptions.h"

Address::Address()
{
	region = "Moskow";
	city = "Moskow";
	street = "Arbat";
	house = 1;
	flat = 1;
}

Address::Address(string _reg, string _city, string _str, int num, int _flat)
{
	if ((_reg == "") || (_city == "") || (_str == "") || (num <= 0) || (flat <= 0))
		throw Exception("Not correct address!");

	region = _reg;
	city = _city;
	street = _str;
	house = num;
	flat = _flat;
}

Address::Address(const Address& _copy)
{
	region = _copy.region;
	city = _copy.city;
	street = _copy.street;
	house = _copy.house;
	flat = _copy.flat;
}

Address::~Address()
{
	region = "";
	city = "";
	street = "";
	house = 0;
	flat = 0;
}

string Address::getRegion()
{
	return region;
}

string Address::getCity()
{
	return city;
}

string Address::getStreet()
{
	return street;
}

int Address::getHouse()
{
	return house;
}

int Address::getFlat()
{
	return flat;
}

void Address::setRegion(const string _reg)
{
	if (_reg == "")
		throw Exception("Not correct the region!");
	
	region = _reg;
}

void Address::setCity(const string _city)
{
	if (_city == "")
		throw Exception("Not correct the city!");

	city = _city;
}

void Address::setStreet(const string _str)
{
	if (_str == "")
		throw Exception("Not correct the street!");

	street = _str;
}

void Address::setHouse(const int num)
{
	if (num < 0 || num > 1000)
		throw Exception("Not correct the number of house!");

	house = num;
}

void Address::setFlat(const int _flat)
{
	if (_flat < 0 || _flat > 1000)
		throw Exception("Not correct the number of flat!");

	flat = _flat;
}

const Address& Address::operator=(const Address& _copy)
{
	if (this == &_copy)
		return *this;

	region = _copy.region;
	city = _copy.city;
	street = _copy.street;
	house = _copy.house;
	flat = _copy.flat;

	return *this;
}

ostream& operator<<(ostream& out, const Address& address)
{
	out << address.region << ", " << address.city << ", " << address.street <<
		" str., " << address.house << ", " << address.flat;

	return out;
}