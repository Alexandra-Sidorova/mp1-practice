#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H
#include "iostream"
#include "string"

using namespace std;

class Exception
{
private:
    string msg;
public:
    Exception(string _msg) : msg(_msg) {};

    void Print()
    {
        cout << "\nWarning!\nError: " << msg << endl;
    }
};

#endif



