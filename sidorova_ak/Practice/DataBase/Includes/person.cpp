#include "person.h"
#include "exceptions.h"

Person::Person()
{
	firstName = "Ivan";
	lastName = "Ivanov";
	patronymic = "Ivanovich";
	subdivision = "Workers";
	post = "lawyer";
	pay = 20000;
}

Person::Person(const Person& _copy)
{
	firstName = _copy.firstName;
	lastName = _copy.lastName;
	patronymic = _copy.patronymic;
	passportData = _copy.passportData;
	educationData = _copy.educationData;
	subdivision = _copy.subdivision;
	post = _copy.post;
	pay = _copy.pay;
	startWorking = _copy.startWorking;
	lastAppointment = _copy.lastAppointment;
}

Person::Person(string _fn, string _ln, string _ptr)
{
	firstName = _fn;
	lastName = _ln;
	patronymic = _ptr;
	subdivision = "Workers";
	post = "lawyer";
	pay = 20000;
}

Person::~Person()
{
	firstName = "";
	lastName = "";
	patronymic = "";
	subdivision = "";
	post = "";
	pay = 0;
}

string Person::getFirstName()
{
	return firstName;
}

string Person::getLastName()
{
	return lastName;
}

string Person::getPatronymic()
{
	return patronymic;
}

Passport Person::getPassportData()
{
	return passportData;
}

Education Person::getEducationData()
{
	return educationData;
}

string Person::getSubdivision()
{
	return subdivision;
}

string Person::getPost()
{
	return post;
}

double Person::getPay()
{
	return pay;
}

Date Person::getStartWorking()
{
	return startWorking;
}

Date Person::getLastAppointment()
{
	return lastAppointment;
}

void Person::setFirstName(const string _fn)
{
	if (_fn == "")
		throw Exception("Not correct the first name!");

	firstName = _fn;
}

void Person::setLastName(const string _ln)
{
	if (_ln == "")
		throw Exception("Not correct the last name!");

	lastName = _ln;
}

void Person::setPatronymic(const string _ptr)
{
	if (_ptr == "")
		throw Exception("Not correct the patronymic!");

	patronymic = _ptr;
}

void Person::setPassportData(const Passport _passport)
{
	passportData = _passport;
}

void Person::setEducationData(const Education _education)
{
	educationData = _education;
}

void Person::setSubdivision(const string _subd)
{
	if (_subd == "")
		throw Exception("Not correct the subdivision!");

	subdivision = _subd;
}

void Person::setPost(const string _post)
{
	if (_post == "")
		throw Exception("Not correct the post!");

	post = _post;
}

void Person::setPay(const double _pay)
{
	if (_pay <= 0)
		throw Exception("Not correct the pay!");

	pay = _pay;
}

void Person::setStartWorking(const Date _stw)
{
	startWorking = _stw;
}

void Person::setLastAppointment(const Date _lap)
{
	lastAppointment = _lap;
}

const Person& Person::operator=(const Person& _copy)
{
	firstName = _copy.firstName;
	lastName = _copy.lastName;
	patronymic = _copy.patronymic;
	passportData = _copy.passportData;
	educationData = _copy.educationData;
	subdivision = _copy.subdivision;
	post = _copy.post;
	pay = _copy.pay;
	startWorking = _copy.startWorking;
	lastAppointment = _copy.lastAppointment;
}

ostream& operator<<(ostream& out, const Person& _p)
{
	out << _p.lastName << " " << _p.firstName << " " << _p.patronymic << endl
		<< "Passport data: " << _p.passportData << endl
		<< "Education data: " << _p.educationData << endl
		<< "Subdivision: " << _p.subdivision << endl
		<< "Post: " << _p.post << endl
		<< "Pay: " << _p.pay << endl
		<< "Date of staring of work: " << _p.startWorking << endl
		<< "Date of last appointment: " << _p.lastAppointment;

	return out;
}