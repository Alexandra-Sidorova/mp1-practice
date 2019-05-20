#ifndef _EDUCATION_H_
#define _EDUCATION_H_

#include <string>

using namespace std;

enum LevelEducation {BasicGeneral, SecondarySchool, LowerPostSecondary, 
	IncompleteHigher, Bachelor, Specialist, Master};

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
	string getSpecial();

	void setUnivercity();
	void setLevel();
	void setSpecial();
};

#endif;
