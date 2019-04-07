#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_
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



