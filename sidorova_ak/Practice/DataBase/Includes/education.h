#ifndef _EDUCATION_H_
#define _EDUCATION_H_

#include <string>
#include <iostream>

using namespace std;

enum LevelEducation 
{
	BasicGeneral, 
	SecondarySchool, 
	LowerPostSecondary, 
	IncompleteHigher, 
	Bachelor, 
	Specialist, 
	Master
};

class Education
{
private:
	string univercity;
	LevelEducation level;
	string specialization;

public:
	Education();
	Education(string, LevelEducation, string);
	Education(const Education&);
	~Education();

	string getUnivercity();
	LevelEducation getLevel();
	string getSpecialization();

	void setUnivercity(const string);
	void setLevel(const LevelEducation);
	void setSpecialization(const string);

	friend ostream& operator<<(ostream&, const Education&);
};

#endif;
