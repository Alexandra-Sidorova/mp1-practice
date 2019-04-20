#include "Includes\time.h"
#include "Includes\date.h"
#include "Includes\todoList.h"
#include "Includes\exceptions.h"
#include "iostream"
#include "conio.h"

using namespace std;

void main()
{
    TodoList list;
    int day, mouth, year;

    cout << "########## CALENDARY 'TODO LIST' ##########" << endl << endl;
    cout << "Date: ";
    cin >> day >> mouth >> year;
    Date date(day, mouth, year);
    cout << endl;
    
    try 
    {
        list.Read("ToDo.txt");
        list.Print(date);
    }
    catch (Exception exp)
    {
        exp.Print();
    }

    _getch();
}