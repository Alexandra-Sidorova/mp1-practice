#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>

using namespace std;

struct Vector
{
private:
    int size;
    double *cells;
public:
    Vector();
    Vector(const Vector&);
    Vector(int);
    Vector(int, double*);
    ~Vector();

    const Vector& operator=(const Vector&);
    Vector operator+(const Vector&);
    Vector operator+(double);
    Vector operator-(const Vector&);
    Vector operator-(double);
    float operator*(const Vector&) const;  // скалярное умножение
    Vector operator*(double);
    Vector operator/(double);
    Vector operator++(int);
    Vector operator++();
    Vector operator--(int);
    Vector operator--();
    Vector& operator+=(const Vector&);
    Vector& operator+=(double);
    Vector& operator-=(const Vector&);
    Vector& operator-=(double);
    Vector& operator*=(double);
    Vector& operator/=(double);

    double& operator[](int);
    const double& operator[](int) const;

    bool operator==(const Vector&) const;
    bool operator!=(const Vector&) const;
    bool operator>(const Vector&) const;
    bool operator>=(const Vector&) const;
    bool operator<(const Vector&) const;
    bool operator<=(const Vector&) const;

    double Lenght() const;

    friend istream& operator>> (istream&, Vector&); // Ввод
    friend ostream& operator<< (ostream&, const Vector&); // Вывод
};

#endif