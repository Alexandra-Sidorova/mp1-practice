#include "task.h"
#include "date.h"

// class Task ----------------------------

Task::Task()
{
	discription = '0';
	date.SetDate(1, 1, 1900);
}

Task::Task(string _discription, Date _date)
{
	discription = _discription;
	date = _date;
}

Task::Task(const Task& _copy)
{
	discription = _copy.discription;
	date = _copy.date;
}

Task::~Task()
{
	discription.clear();
	date.SetDate(1, 1, 1900);
}

// class TaskAllDay ----------------------

void TaskAllDay::Print()
{
	cout << date << discription << endl;
}

// class TaskTime ------------------------

void TaskTime::Print()
{
	cout << date << start << "-" << finish << discription << endl;
}