#include <conio.h>
#include "vector.h"
#include "exceptions.h"

void main()
{
    double a1[5] = { 1, 2, 0, 3, -2 },
        a2[5] = { -3, 1, 5, -1, 0 },
        a3[3] = { 1, 0, -1 };

    cout << "##### TEST #####" << endl << endl;
        
    // Объявления векторов
    Vector v1(5, a1), v2(5, a2), v3(3, a3), res;
    cout << "Vector v1 = " << v1 << endl;
    cout << "Vector v2 = " << v2 << endl;
    cout << "Vector v3 = " << v3 << endl << endl;

    // Длины векторов
    cout << "Lenght of v1 = " << v1.Lenght() << endl;
    cout << "Lenght of v2 = " << v2.Lenght() << endl;
    cout << "Lenght of v3 = " << v3.Lenght() << endl << endl;

    try
    {
        cout << "v1 + v2 = ";
        res = v1 + v2;
        cout << res << endl;

        cout << "v1 + v3 = ";
        res = v1 + v3;
        cout << res << endl;
    }
    catch (Exception exp)
    {
        cout << exp.what();
    }

    try
    {
        cout << "v1 - v2 = ";
        res = v1 - v2;
        cout << res << endl;

        cout << "v1 - v3 = ";
        res = v1 - v3;
        cout << res << endl;
    }
    catch (Exception exp)
    {
        cout << exp.what();
    }

    try
    {
        cout << "v1 * v2 = ";
        float res = v1 * v2;
        cout << res << endl;

        cout << "v1 * v3 = ";
        res = v1 * v3;
        cout << res << endl;
    }
    catch (Exception exp)
    {
        cout << exp.what();
    }
        
    try
    {
        cout << "v1 * 5 = ";
        res = v1 * 5;
        cout << res << endl;

        cout << "v3 / 5 = ";
        res = v3 / 5;
        cout << res << endl;

        cout << "v3 / 0 = ";
        res = v3 / 0;
        cout << res << endl;
    }
    catch (Exception exp)
    {
        cout << exp.what();
    }

    try
    {
        cout << "v3 += 2 : ";
        v3 += 2;
        cout << v3 << endl;

        cout << "v3 -= 2 : ";
        v3 -= 2;
        cout << v3 << endl;

        cout << "v3 *= 10 : ";
        v3 *= 10;
        cout << v3 << endl;

        cout << "v3 /= 2 : ";
        v3 /= 2;
        cout << v3 << endl;

        cout << "v2 /= 0 : ";
        v2 /= 0;
        cout << v2 << endl;
    }
    catch (Exception exp)
    {
        cout << exp.what();
    }

    try
    {
        cout << "v1++ : ";
        v1++;
        cout << v1 << endl;

        cout << "v1-- : ";
        v1--;
        cout << v1 << endl;

        Vector ab = ++v1 * 2 - v2 * 3;
        cout << "++v1 * 2 - (v2 * 3) = " << ab << endl;
        cout << "Vector v1 = " << v1 << endl;

        cout << "v1[2] = ";
        cout << v1[2] << endl;

        cout << "v1[-105] = ";
        cout << v1[-105] << endl;
    }
    catch (Exception exp)
    {
        cout << exp.what();
    }

    try
    {
        cout << "v1 = v2 ? : ";
        cout << (v1 == v2) << endl;

        cout << "v1 < v2 ? : ";
        cout << (v1 < v2) << endl;

        cout << "v1 > v2 ? : ";
        cout << (v1 < v2) << endl;

        cout << "v1 >= v2 ? : ";
        cout << (v1 >= v2) << endl;

        cout << "v1 >= v3 ? : ";
        cout << (v1 >= v2) << endl;
    }
    catch (Exception exp)
    {
        cout << exp.what();
    }

    
    try
    {
        cout << "v1 <= v2 ? : ";
        cout << (v1 >= v2) << endl;

        cout << "v1 <= v3 ? : ";
        cout << (v1 <= v2) << endl;

    }
    catch (Exception exp)
    {
        cout << exp.what();
    }
    
    _getch();
}