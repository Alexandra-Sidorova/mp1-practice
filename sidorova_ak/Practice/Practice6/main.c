#include "vector.h"
#include <stdio.h>

void main()
{
    Vector a, b, c, res;
    float s1[3] = { 0, 3, 4 };
    float s2[3] = { 3, 4, 12 };
    float s3[5] = { 1, 4, 3, 2, 0 };
    float resPr;

    printf("a = ");
    a = Create(3);
    a = Value(a, s1, 3);
    Output(a);
    printf("b = ");
    b = Create(3);
    b = Value(b, s2, 3);
    Output(b);
    printf("c = ");
    c = Create(5);
    c = Value(c, s3, 5);
    Output(c);
    printf("\n");

    // Cложение
    printf("a + b \n");
    res = Add(a, b);
    Output(res);
    printf("a + c\n");
    res = Add(a, c);
    Delete(res);

    // Вычитание
    printf("a - b \n");
    res = Sub(a, b);
    Output(res);
    printf("a - c \n");
    res = Sub(a, c);
    Delete(res);

    // Скалярное произведение
    printf("a * b \n");
    resPr = Product(a, b);
    printf("%.3f\n", resPr);
    printf("a * c \n");
    resPr = Product(a, c);

    // Длины
    printf("|a| = %.2f\n", Length(a));
    printf("|b| = %.2f\n", Length(b));
    printf("|c| = %.2f\n", Length(c));

    // Углы
    printf("Corner between a and b = %.2f\n", Corner(a, b));
    printf("Corner between a and c = %.2f\n", Corner(a, c));
    printf("Corner between b and c = %.2f\n", Corner(b, c));

    getch(); // Консоль не закрывалась
}