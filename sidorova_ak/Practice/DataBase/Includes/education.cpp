#include "education.h"
#include "exceptions.h"

using namespace std;

Education::Education()
{
	univercity = "MSU";
	level = Bachelor;
	specialization = "lawyer";
}

Education::Education(string _univer, LevelEducation _lvl, string _spec)
{
	univercity = _univer;
	level = _lvl;
	specialization = _spec;
}

Education::Education(const Education& _copy)
{
	univercity = _copy.univercity;
	level = _copy.level;
	specialization = _copy.specialization;
}

Education::~Education()
{
	univercity = "";
	level = Bachelor;
	specialization = "";
}

string Education::getUnivercity()
{
	return univercity;
}

LevelEducation Education::getLevel()
{
	return level;
}

string Education::getSpecialization()
{
	return specialization;
}

void Education::setUnivercity(const string _univer)
{
	if (_univer == "")
		throw Exception("Not correct the name of univercity!");

	univercity = _univer;
}

void Education::setLevel(const LevelEducation _lvl)
{
	level = _lvl;
}

void Education::setSpecialization(const string _special)
{
	if (_special == "")
		throw Exception("Not correct the specialization!");

	specialization = _special;
}

ostream& operator<<(ostream& out, const Education& _educ)
{
	string lvl;

	switch(_educ.level)
	{
		case 0:
		{
			lvl = "BasicGeneral";
			break;
		}
		case 1:
		{
			lvl = "SecondarySchool";
			break;
		}
		case 2:
		{
			lvl = "LowerPostSecondary";
			break;
		}
		case 3:
		{
			lvl = "IncompleteHigher";
			break;
		}
		case 4:
		{
			lvl = "Bachelor";
			break;
		}
		case 5:
		{
			lvl = "Specialist";
			break;
		}
		case 6:
		{
			lvl = "Master";
			break;
		}
	}

	out << lvl << ", " << _educ.specialization << ", " << _educ.univercity;

	return out;
}