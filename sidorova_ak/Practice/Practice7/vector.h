#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "iostream"

using namespace std;

struct Vector
{
private:
    int size;
    double *cells;
public:
    Vector();
    Vector(Vector&);
    Vector(int);
    Vector(int, double*);
    ~Vector();

    double Lenght() const;

    Vector& operator=(const Vector&);
    Vector operator+(const Vector&);
    Vector operator+(double);
    Vector operator-(const Vector&);
    Vector operator-(double);
    Vector operator*(const Vector&);
    Vector operator*(double);
    Vector operator/(double);
    Vector operator++(int);
    Vector operator++();
    Vector operator--(int);
    Vector operator--();
    Vector operator+=(const Vector&);
    Vector operator+=(double);
    Vector operator-=(const Vector&);
    Vector operator-=(double);
    Vector operator*=(const Vector&);
    Vector operator*=(double);
    Vector operator/=(double);

    double& operator[](int);
    const double& operator[](int) const;

    bool operator==(const Vector&);
    bool operator!=(const Vector&);
    bool operator>(const Vector&);
    bool operator>=(const Vector&);
    bool operator<(const Vector&);
    bool operator<=(const Vector&);

    void* operatornew(size_t);
    void operatordelete(void*);

    friend istream& operator>> (istream&, Vector&); // Ввод
    friend ostream& operator<< (ostream&, const Vector&); // Вывод
};

#endif