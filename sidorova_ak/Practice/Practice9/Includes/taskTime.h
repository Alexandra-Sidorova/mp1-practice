#ifndef _TASKTIME_H_
#define _TASKTIME_H_
#include "task.h"
#include "date.h"
#include "time.h"

class TaskTime : public Task
{
private:
	Time start, finish;
public:
	TaskTime();
	TaskTime(string, Date, Time, Time);
	TaskTime(const TaskTime&);
	~TaskTime();

	Time GetTimeStart();
	Time GetTimeFinish();
	void Print();
};

#endif