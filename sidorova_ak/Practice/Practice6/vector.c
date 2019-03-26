#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

Vector Create(int size)
{
    Vector res;
    int i;

    res.size = size;
    res.coord = (float*)malloc(res.size * sizeof(float));
    for (i = 0; i < size; i++)
        res.coord[i] = 0;

    return res;
}

Vector Value(Vector vector, float *value, int valueSize)
{
    int i;

    if (valueSize != vector.size)
    {
        printf("Error. Not correct size\n");
        return vector;
    }

    for (i = 0; i < valueSize; i++)
        vector.coord[i] = value[i];

    return vector;
}

Vector Equal(Vector vector)
{
    Vector res;
    int i;

    res.size = vector.size;
    res.coord = (float*)malloc(res.size * sizeof(float));
    for (i = 0; i < res.size; i++)
        res.coord[i] = vector.coord[i];

    return res;
}

void Delete(Vector del)
{
    free(del.coord);
    del.size = 0;
}

Vector Add(Vector add1, Vector add2)
{
    Vector res = Create(add1.size);
    int i;

    if (add1.size != add2.size)
    {
        printf("Error. Not correct size of vectors.\n");
        return res;
    }

    for (i = 0; i < res.size; i++)
        res.coord[i] = add1.coord[i] + add2.coord[i];

    return res;
}

Vector Sub(Vector sub1, Vector sub2)
{
    Vector res = Create(sub1.size);
    int i;

    if (sub1.size != sub2.size)
    {
        printf("Error. Not correct size of vectors.\n");
        return res;
    }

    for (i = 0; i < res.size; i++)
        res.coord[i] = sub1.coord[i] - sub2.coord[i];

    return res;
}

Vector Product(Vector factor1, Vector factor2)
{
    Vector res = Create(factor1.size);
    int i;

    if (factor1.size != factor2.size)
    {
        printf("Error. Not correct size of vectors.\n");
        return res;
    }

    for (i = 0; i < res.size; i++)
        res.coord[i] = factor1.coord[i] * factor2.coord[i];

    return res;
}

Vector ProductNum(Vector vector, float factor)
{
    Vector res = Create(vector.size);
    int i;

    for (i = 0; i < res.size; i++)
        res.coord[i] = vector.coord[i] * factor;

    return res;
}

float Length(Vector vector)
{
    float lenght = 0;
    int i;

    for (i = 0; i < vector.size; i++)
        lenght += (vector.coord[i] * vector.coord[i]);

    lenght = sqrt(lenght);

    return lenght;
}

float Corner(Vector v1, Vector v2)
{
    float corner, tmp = 0;
    int i;

    if (v1.size != v2.size)
    {
        printf("Error. Not correct size.\n");
        return 0;
    }

    for (i = 0; i < v1.size; i++)
        tmp += (v1.coord[i] * v2.coord[i]);

    corner =  tmp / ((Length(v1) * Length(v2)));
    corner = acos(corner) * 180 / PI;

    return corner;
}

void Output(Vector vector)
{
    int i;

    if (vector.size == 0)
    {
        printf("Error <Empty vector.\n");
    }

    printf("Vector = (");
    for (i = 0; i < vector.size; i++)
    {
        if (i + 1 == vector.size)
            printf("%.2f)\n", vector.coord[i]);
        else
            printf("%.2f ", vector.coord[i]);
    }
}
