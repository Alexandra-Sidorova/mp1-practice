#include "Includes/exceptions.h"
#include "Includes/TContainer.h"
#include "Includes/TContainerAdvanced.h"
#include "conio.h"

using namespace std;

void main()
{
	float array_a[10] = { 1.f, 5.f, 1.2f, 0.f, 7.56f, 3.f, -5.7f, -1.f, 5.1f, -10.f };
	int array_b[3] = { 1, 2, 3 };
	int *b;

	TContainer<float, 100>container_a(array_a, 10);
	TContainer<int, 3>container_b(array_b, 3);

	try
	{
		cout << "Container A: " << container_a << endl;
		cout << "Container B: " << container_b << endl;
	}
	catch (Exception exc)
	{
		exc.Print();
	}

	try
	{
		container_a.Add(12.4f);
		cout << "Container A + object 12.4f: " << container_a << endl;
		container_b.Add(12);
		cout << "Container B + object 12: " << container_b << endl; // исключение
	}
	catch (Exception exc)
	{
		exc.Print();
	}
	_getch();
}