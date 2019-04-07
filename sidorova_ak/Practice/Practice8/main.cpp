#include "exceptions.h"
#include "matrix.h"
#include "iostream"
#include "conio.h"

using namespace std;

void main()
{
	double m_a[6] = { 1, 1, 0, 2, -1, 2 },
		m_b[12] = { 2, 1, 0, 3, 1, 2, 4, -1, 3, 0, -2, 1 },
		m_c[4] = { 1, 2, -1, 3 };
	
	try
	{
		Matrix A(2, 3, m_a), B(3, 4, m_b), C(2, 2, m_c);
		cout << "Matrix A :" << endl << A << endl;
		cout << "Matrix B :" << endl << B << endl;
		cout << A*B << endl;
	}

	catch (Exception exp)
	{
		exp.Print();
	}

	_getch();
}