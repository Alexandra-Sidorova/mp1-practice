#include <conio.h>
#include "Includes/exceptions.h"
#include "Includes/TContainer.h"
#include "Includes/TContainerAdvanced.h"

using namespace std;

void main()
{
    /* Common Container */

    float array_a[10] = { 1.f, 5.f, 1.2f, 0.f, 7.56f, 3.f, -5.7f, -1.f, 5.1f, -10.f };
    int array_b[3] = { 1, 2, 3 };

    TContainer<float>container_a(array_a, 10, 100);
    TContainer<int>container_b(array_b, 3, 3);

    cout << "############### COMMON CONTAINER ###############" << endl << endl;

    try
    {
        cout << "Container A: " << container_a << endl;
        cout << "Container B: " << container_b << endl;
    }
    catch (Exception exc)
    {
        cout << exc.what() << endl;
    }

    try
    {
        cout << "Container A + object 12.4f: ";
        container_a.Add(12.4f);
        cout << container_a << endl;
        
        cout << "Container B + object 12: "; // исключение не вызовет - размер контейнера увеличится (обновление)
        container_b.Add(12);
        cout << container_b << endl; 

        cout << "Container A - object -1.f: ";
        container_a.Remove(-1.f);
        cout << container_a << endl;
       
        cout << "Container A - object with Index 1: ";
        container_a.RemoveIndex(1);
        cout << container_a << endl;
        
        cout << "Container B - -5: ";  // исключение - отсутствует такой элемент
        container_b.Remove(-5);
        cout << container_b << endl;
    }
    catch (Exception exc)
    {
        cout << exc.what() << endl;
    }

    try
    {
        cout << "Container B - object with index -5: "; // исключение - отрицательный индекс
        container_b.RemoveIndex(-5);
        cout << container_b << endl;
    }
    catch (Exception exc)
    {
        cout << exc.what() << endl;
    }

    try
    {
        cout << "Container B - 1 - 2 - 3 - 12: ";
        container_b.Remove(1);
        container_b.Remove(2);
        container_b.Remove(3);
        container_b.Remove(12);
        cout << container_b << endl;
        
        cout << "Container B - object with index 0: "; // исключение - контейнер пуст
        container_b.RemoveIndex(0);
    }
    catch (Exception exc)
    {
        cout << exc.what() << endl;
    }

    try
    {
        cout << "Object in Container A with index 5: ";
        cout << container_a[5] << endl;
       
        cout << "Object in Container B with index 5: "; // исключение - индекс больше текущего размера
        cout << container_b[5] << endl;
    }
    catch (Exception exc)
    {
        cout << exc.what() << endl;
    }
    
    try
    {
        cout << "Sorting Container A: ";
        container_a.Sort();
        cout << container_a << endl;
        
        cout << "Sorting Container B: "; 
        container_b.Sort();  // исключение - контейнер пуст
        cout << container_b << endl;
    }
    catch (Exception exc)
    {
        cout << exc.what() << endl;
    } 
    //---------------------------------------------------------------------------------------

    /* Advanced Container for pointers */

    float *array_pa[10];
    int *array_pb[3];

    for (int i = 0; i < 10; i++)   // array_pa - массив указателей на элементы массива array_a
        array_pa[i] = &array_a[i]; 

    for (int i = 0; i < 3; i++)   // array_pb - массив указателей на элементы массива array_b
        array_pb[i] = &array_b[i];

    TContainer<float*>container_pa(array_pa, 10, 100);
    TContainer<int*>container_pb(array_pb, 3, 3);

    cout << "############### ADVANCED CONTAINER WITH POINTERS ###############" << endl << endl;

    try
    {
        cout << "Container PA: " << container_pa << endl;
        cout << "Container PB: " << container_pb << endl;
    }
    catch (Exception exc)
    {
        cout << exc.what() << endl;
    }

    try
    {
        float a = 5.1f;
        float *pa = &a;

        cout << "Container PA + pointer of object a = 5.1: ";
        container_pa.Add(pa);
        cout << container_pa << endl;

        int b = -1;
        int *pb = &b;
        
        cout << "Container PB + pointer of object b = -1: "; // исключение не вызовет - контейнер увеличится (обновление)
        container_pb.Add(pb);
        cout << container_pb << endl;

        cout << "Container PA - pointer of object with Index 1: ";
        container_pa.RemoveIndex(1);
        cout << container_pa << endl;

        cout << "Container PA - pointer of object -1.f: ";
        container_pa.Remove(array_pa[0]); // исключение - показываем, что контейнер и массив, которым мы заполнили
        cout << container_pa << endl;     // контейнер, ссылаются на разные адреса
    }
    catch (Exception exc)
    {
        cout << exc.what() << endl;
    }

    try
    {
        cout << "Container PA - pointer of 2nd object " << container_pa[2] << ": ";
        container_pa.Remove(container_pa[2]);
        cout << container_pa << endl;
    }
    catch (Exception exc)
    {
        cout << exc.what() << endl;
    }

    try
    {
        cout << "Object in Container PB with index 3: ";
        cout << container_pb[3] << endl;

        cout << "Object in Container PB with index 4: "; // исключение - индекс больше текущего размера
        cout << container_pb[4] << endl;
    }
    catch (Exception exc)
    {
        cout << exc.what() << endl;
    }

    _getch();
}