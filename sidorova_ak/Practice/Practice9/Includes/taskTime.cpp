#include "taskTime.h"

TaskTime::TaskTime()
{
	discription = '0';
	date.SetDate(1, 1, 1900);
	start.SetTime(0, 0);
	finish.SetTime(0, 0);
}

TaskTime::TaskTime(string _discription, Date _date, Time _start, Time _finish)
{
	discription = _discription;
	date = _date;
	start = _start;
	finish = _finish;
}

TaskTime::TaskTime(const TaskTime& _copy)
{
	discription = _copy.discription;
	date = _copy.date;
	start = _copy.start;
	finish = _copy.finish;
}

TaskTime::~TaskTime()
{
	discription.clear();
	date.SetDate(1, 1, 1900);
	start.SetTime(0, 0);
	finish.SetTime(0, 0);
}

Time TaskTime::GetTimeStart()
{
	return start;
}

Time TaskTime::GetTimeFinish()
{
	return finish;
}

void TaskTime::Print()
{
	cout << date << " " << start << " - " << finish << " " << discription << endl;
}