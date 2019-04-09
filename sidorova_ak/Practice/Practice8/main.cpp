#include "exceptions.h"
#include "matrix.h"
#include "iostream"
#include "conio.h"

using namespace std;

void main()
{
    double m_a[6] = { 1, 1, 0, 2, -1, 2 },
        m_b[12] = { 2, 1, 0, 3, 1, 2, 4, -1, 3, 0, -2, 1 },
        m_c[4] = { 1, 2, -1, 3 },
        m_d[6] = { 0, 3, -1, 2, 4, -2 };
    
    try
    {
        // Объявление
        Matrix A(2, 3, m_a), B(3, 4, m_b), C(2, 2, m_c), D(2, 3, m_d);
        cout << "Matrix A :" << endl << A << endl;
        cout << "Matrix B :" << endl << B << endl;
        cout << "Matrix C :" << endl << C << endl;
        cout << "Matrix D :" << endl << D << endl;

        // Сложение и вычитание
        cout << "C + 5:" << endl << C + 5 << endl;
        cout << "A + D:" << endl << A + D << endl;
        cout << "B - 3:" << endl << B - 3 << endl;
        cout << "A - D:" << endl << A - D << endl;

        // Произведение
        cout << "C * 2:" << endl << C * 2 << endl;
        cout << "A * B:" << endl << A * B << endl;

        // []
        cout << "Secound row of B: " << B[1] << endl;
        cout << "B[2][3] = " << B[2][3] << endl << endl;

        // +=, -=, *=
        C += 3;
        cout << "C += 3:" << endl << C << endl;
        A += D;
        cout << "A += D:" << endl << A << endl;
        C -= 3;
        cout << "C -= 3:" << endl << C << endl;
        A -= D;
        cout << "A -= D:" << endl << A << endl;
        B *= 5;
        cout << "B *= 5:" << endl << B << endl;

        // Исключение
        cout << "A + C:";
        cout << A + C << endl;
    }

    catch (Exception exp)
    {
        exp.Print();
    }

    _getch();
}