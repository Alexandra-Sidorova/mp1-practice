#include <iostream>
#include <conio.h>
#include "exceptions.h"
#include "matrix.h"

using namespace std;

void main()
{
    double m_a[6] = { 1, 1, 0, 2, -1, 2 },
        m_b[12] = { 2, 1, 0, 3, 1, 2, 4, -1, 3, 0, -2, 1 },
        m_c[4] = { 1, 2, -1, 3 },
        m_d[6] = { 0, 3, -1, 2, 4, -2 };
    
    // Объявление
    Matrix A(2, 3, m_a), B(3, 4, m_b), C(2, 2, m_c), D(2, 3, m_d), res;
    cout << "Matrix A :" << endl << A << endl;
    cout << "Matrix B :" << endl << B << endl;
    cout << "Matrix C :" << endl << C << endl;
    cout << "Matrix D :" << endl << D << endl;

    try
    {
        cout << "A + D:" << endl;
        res = A + D;
        cout << res << endl;

        cout << "A + 5:" << endl;
        res = A + 5;
        cout << res << endl;

        cout << "A + B:" << endl;
        res = A + B;
        cout << res << endl;
    }
    catch (Exception exp)
    {
        cout << exp.what() << endl << endl;
    }

    try
    {
        cout << "A - D:" << endl;
        res = A - D;
        cout << res << endl;

        cout << "A - 5:" << endl;
        res = A - 5;
        cout << res << endl;

        cout << "A - B:" << endl;
        res = A - B;
        cout << res << endl;
    }
    catch (Exception exp)
    {
        cout << exp.what() << endl << endl;
    }

    try
    {
        cout << "C * 2:" << endl;
        res = C * 2;
        cout << res << endl;

        cout << "A * B:" << endl;
        res = A * B;
        cout << res;

        cout << "A * C: " << endl;
        res = A * C;
        cout << res << endl;
    }
    catch (Exception exp)
    {
        cout << exp.what() << endl << endl;
    }

    try
    {
        cout << "Secound row of B: ";
        cout << B[1] << endl;

        cout << "B[2][3] = ";
        cout << B[2][3] << endl;

        cout << "A[-11][105] = ";
        cout << A[-11][105] << endl;
    }
    catch (Exception exp)
    {
        cout << exp.what() << endl << endl;
    }

    try
    {
        cout << "A += D:" << endl;
        A += D; 
        cout << A << endl;

        cout << "C += 3:" << endl;
        C += 3; 
        cout << C << endl;

        cout << "A += C:" << endl;
        A += C;
        cout << A << endl;
    }
    catch (Exception exp)
    {
        cout << exp.what() << endl << endl;
    }

    try
    {
        cout << "A -= D:" << endl;
        A -= D;
        cout << A << endl;

        cout << "C -= 3:" << endl;
        C -= 3;
        cout << C << endl;

        cout << "A -= C:" << endl;
        A -= C;
        cout << A << endl;
    }
    catch (Exception exp)
    {
        cout << exp.what() << endl << endl;
    }

    _getch();
}