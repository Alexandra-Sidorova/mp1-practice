#ifndef _TASKALLDAY_H_
#define _TASKALLDAY_H_
#include "task.h"
#include "date.h"

class TaskAllDay : public Task
{
public:
	TaskAllDay();
	TaskAllDay(string, Date);
	TaskAllDay(const TaskAllDay&);
	~TaskAllDay();

	void Print();
};

#endif