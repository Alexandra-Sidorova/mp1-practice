#include "taskAllDay.h"

TaskAllDay::TaskAllDay()
{
    discription = '0';
    date.SetDate(1, 1, 1900);
}

TaskAllDay::TaskAllDay(string _discription, Date _date)
{
    discription = _discription;
    date = _date;
}

TaskAllDay::TaskAllDay(const TaskAllDay& _copy)
{
    discription = _copy.discription;
    date = _copy.date;
}

TaskAllDay::~TaskAllDay()
{
    discription.clear();
    date.SetDate(1, 1, 1900);
}

void TaskAllDay::Print()
{
    cout << date << " " << discription << endl;
}