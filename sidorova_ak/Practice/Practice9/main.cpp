#include "time.h"
#include "date.h"
#include "iostream"
#include "conio.h"

using namespace std;

void main()
{
	Time a;
	Date b;
	cin >> a;
	cin >> b;
	cout << a << " " << b << endl;
	a += 120;
	b += 1;
	cout << a << " " << b << endl;

	_getch();
}