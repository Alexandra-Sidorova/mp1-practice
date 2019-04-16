#ifndef _TODOLIST_H_
#define _TODOLIST_H_
#include "task.h"

using namespace std;

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

	void Read();
	void Print();
	//void Sort();
};

#endif