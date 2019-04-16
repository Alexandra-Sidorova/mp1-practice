#include "todoList.h"
#include "exceptions.h"
#include "fstream"

TodoList::TodoList()
{
	count = 1;
	*tasks = (Task*)malloc(sizeof(Task));
}

TodoList::TodoList(unsigned int _count)
{
	if (_count < 1)
		throw Exception("Not correct count of tasks!");

	count = _count;
	*tasks = (Task*)malloc(count * sizeof(Task));
}

TodoList::TodoList(const TodoList& _copy)
{
	delete[] *tasks;

	count = _copy.count;
	*tasks = (Task*)malloc(count * sizeof(Task));

	for (int i = 0; i < count; i++)
		tasks[i] = _copy.tasks[i];
}

TodoList::~TodoList()
{
	delete[] *tasks;
	count = 0;
}

void TodoList::Read()
{
	ifstream file;
	file.open("ToDo.txt");

	if (!file.is_open())
		throw Exception("Not correct name of file!");
	else
	{
		string 

	}

	file.close();
}

void TodoList::Print()
{
	for (int i = 0; i < count; i++)
	{
		cout << i << ").";
		tasks[i]->Print();
	}
}