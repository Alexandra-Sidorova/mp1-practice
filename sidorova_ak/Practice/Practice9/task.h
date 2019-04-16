#ifndef _TASK_H_
#define _TASK_H_
#include "string"
#include "Date.h"
#include "Time.h"

using namespace std;

class Task
{
protected:
	string discription;
	Date date;
public:
	Task();
	Task(string, Date);
	Task(const Task&);
	~Task();

	virtual void Print() = 0;
};

class TaskAllDay : public Task
{
public:
	void Print();
};

class TaskTime : public Task
{
private:
	Time start, finish;
public:
	void Print();
};


#endif