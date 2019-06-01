#ifndef _TASK_H_
#define _TASK_H_

#include <string>
#include "date.h"
#include "time.h"

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
    virtual ~Task();

    Date GetDate();
    virtual void Print() = 0;
};

#endif