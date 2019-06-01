#include <iostream>
#include <conio.h>
#include "Includes\time.h"
#include "Includes\date.h"
#include "Includes\todoList.h"
#include "Includes\exceptions.h"

using namespace std;

void main()
{
    TodoList list;
    Date date;

    cout << "########## CALENDARY 'TODO LIST' ##########" << endl << endl;
    cout << "Date: ";

    try
    {
        cin >> date;
        cout << endl;
    
        list.Read("ToDo.txt");
        list.Print(date);
    }

    catch (Exception exp)
    {
        cout << exp.what() << endl;
    }

    _getch();
}