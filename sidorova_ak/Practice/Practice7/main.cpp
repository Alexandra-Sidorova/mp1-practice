#include "vector.h"
#include "exceptions.h"
#include "conio.h"

void main()
{
    double a1[5] = { 1, 2, 0, 3, -2 },
        a2[5] = { -3, 1, 5, -1, 0 },
        a3[3] = { 1, 0, -1 };

    try
    {
        cout << "##### TEST #####" << endl << endl;
        
        // Объявления векторов
        Vector v1(5, a1), v2(5, a2), v3(3, a3);
        cout << "Vector v1 = " << v1 << endl;
        cout << "Vector v2 = " << v2 << endl;
        cout << "Vector v3 = " << v3 << endl << endl;

        // Длины векторов
        cout << "Lenght of v1 = " << v1.Lenght() << endl;
        cout << "Lenght of v2 = " << v2.Lenght() << endl;
        cout << "Lenght of v3 = " << v3.Lenght() << endl << endl;

        // Простые операции
        cout << "v1 + v2 = " << v1 + v2 << endl;
        cout << "v1 - v2 = " << v1 - v2 << endl;
        cout << "v1 * v2 = " << v1 * v2 << endl << endl;
        cout <<"v3 / 5 = " << v3 / 5 << endl;
        v3 *= 10;
        cout << "v3 *= 10 : " << v3 << endl;
        v3 /= 2;
        cout << "v3 /= 2 : " << v3 << endl;
        v3 += 10;
        cout << "v3 += 10 : " << v3 << endl;
        cout << "v3-- : " << v3-- << endl;

        // Посложнее пример
        Vector ab = ++v1 * 2 - v2 * 3;
        cout << "++v1 * 2 - (v2 * 3) = " << ab << endl;
        cout << "Vector v1 = " << v1 << endl << endl;

        // Индексация
        cout << "v1[2] = " << v1[2] << endl << endl;

        // Условие
        cout << "v1 < v2 ? : " << (v1 < v2) << endl << endl;
        cout << "v1 >= v2 ? : " << (v1 >= v2) << endl << endl;

        // Исключение
        cout << "v3 * v1 = "; 
        cout << v3 * v1 << endl;
    }

    catch (Exception exp)
    {
        exp.Print();
    }
    
    _getch();
}