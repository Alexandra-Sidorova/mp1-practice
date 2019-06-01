#ifndef __VECTOR_H_
#define __VECTOR_H_

typedef struct
{
    int size;
    float *coord;
} Vector;

// Функции
Vector Create(int size);
Vector Value(Vector vector, float *value, int valueSize);
Vector Equal(Vector vector);
void Delete(Vector del);
Vector Add(Vector add1, Vector add2);
Vector Sub(Vector sub1, Vector sub2);
float Product(Vector factor1, Vector factor2);
Vector ProductNum(Vector vector, float factor);
float Length(Vector vector);
float Corner(Vector v1, Vector v2);
void Output(Vector vector);

#endif