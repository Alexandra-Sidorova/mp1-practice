#ifndef _TODOLIST_H_
#define _TODOLIST_H_
#include "task.h"
#include "date.h"

class TodoList
{
private:
    unsigned int count;
    Task** tasks;
public:
    TodoList();
    TodoList(unsigned int);
    TodoList(const TodoList&);
    ~TodoList();

    void Read(const string);
    void Print(Date);
};

#endif