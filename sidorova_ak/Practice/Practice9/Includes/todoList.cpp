#include "todoList.h"
#include "exceptions.h"
#include "taskAllDay.h"
#include "taskTime.h"
#include "fstream"

using namespace std;

TodoList::TodoList()
{
    count = 0;
    tasks = NULL;
}

TodoList::TodoList(unsigned int _count)
{
    if (_count < 1)
        throw Exception("Not correct count of tasks!");

    count = _count;
    tasks = new Task*[count];
}

TodoList::TodoList(const TodoList& _copy)
{
    delete[] *tasks;

    count = _copy.count;
    tasks = new Task*[count];

    for (unsigned int i = 0; i < count; i++)
        tasks[i] = _copy.tasks[i];
}

TodoList::~TodoList()
{
    delete[] *tasks;
    count = 0;
}

void TodoList::Read(const string nameFile)
{
    ifstream file;
    file.open(nameFile);

    if (!file.is_open())
        throw Exception("Not correct name of file!");
    
    if (file.peek() == EOF)
        throw Exception("Empty file!");
    
    file >> count;
    tasks = new Task*[count];
    int type;
    int day, mouth, year;
    string discription;

    for (unsigned int i = 0; i < count; i++)
    {
        file >> type;

        if (type == 1)
        {
			Date tmpDate;

			file >> tmpDate;
            getline(file, discription, '\n');
            tasks[i] = new TaskAllDay(discription, tmpDate);
            continue;
        }
            
        if (type == 2)
        {
            Date tmpDate;
            Time tmpTimeStart;
            Time tmpTimeFinish;
			char a;

			file >> tmpDate; //>> tmpTimeStart >> a >> tmpTimeFinish;
			file >> tmpTimeStart;
			file >> a;
			file >> tmpTimeFinish;
            getline(file, discription, '\n');
            tasks[i] = new TaskTime(discription, tmpDate, tmpTimeStart, tmpTimeFinish);
            continue;
        }

        throw Exception("Not correct type of event!");
    }

    file.close();
}

void TodoList::Print(Date _date)
{
    bool flag = 0;
    int n = 1;

    for (unsigned int i = 0; i < count; i++)
    {
        if (tasks[i]->GetDate() == _date)
        {
            cout << n++ << ") ";
            tasks[i]->Print();
            flag = 1;
        }
    }

    if (flag == 0)
        throw Exception("No tasks in this day!");
}