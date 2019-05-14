#include "vector.h"
#include "cmath"
#include "iostream"
#include "exceptions.h"

using namespace std;

Vector::Vector()
{
    size = 5;
    cells = new double[size];
    for (int i = 0; i < size; i++)
        cells[i] = 0;
}

Vector::Vector(const Vector& tmp)
{
    size = tmp.size;
    cells = new double[size];
    for (int i = 0; i < size; i++)
        cells[i] = tmp.cells[i];
}

Vector::Vector(int _size)
{
    if (_size <= 0) 
        throw Exception("Not correct size of vector!");

    size = _size;
    cells = new double[size];
    for (int i = 0; i < size; i++)
        cells[i] = 0;
}

Vector::Vector(int _size, double *_cells)
{
    if (*_cells == NULL)
        throw Exception("Empty array!");

    if (_size <= 0)
        throw Exception("Not correct size of vector!");

    size = _size;
    cells = new double[size];
    for (int i = 0; i < size; i++)
        cells[i] = _cells[i];
}

Vector::~Vector()
{
    size = 0;
    delete[] cells;
}

double Vector::Lenght() const
{
    double lenght = 0;

    for (int i = 0; i < size; i++)
        lenght += (cells[i] * cells[i]);

    return sqrt(lenght);
}

const Vector& Vector::operator=(const Vector& _rez)
{
    if (this == &_rez)
        return *this;

    delete[] cells;
    size = _rez.size;
    cells = new double[size];

    for (int i = 0; i < size; i++)
        cells[i] = _rez.cells[i];

    return *this;
}

Vector Vector::operator+(const Vector& _add)
{
    if (_add.size != size)
        throw Exception("Not correct size of vector!");

    Vector rez(size);

    for (int i = 0; i < size; i++)
        rez.cells[i] = cells[i] + _add.cells[i];

    return rez;
}

Vector Vector::operator+(double num)
{
    Vector rez(size);

    for (int i = 0; i < size; i++)
        rez.cells[i] = cells[i] + num;

    return rez;
}

Vector Vector::operator-(const Vector& _sub)
{
    if (_sub.size != size)
        throw Exception("Not correct size of vector!");

    Vector rez(size);

    for (int i = 0; i < size; i++)
        rez.cells[i] = cells[i] - _sub.cells[i];

    return rez;
}

Vector Vector::operator-(double num)
{
    Vector rez(size);

    for (int i = 0; i < size; i++)
        rez.cells[i] = cells[i] - num;

    return rez;
}

Vector Vector::operator*(const Vector& _vector)
{
    if (_vector.size != size)
        throw Exception("Not correct size of vector!");

    Vector rez(size);

    for (int i = 0; i < size; i++)
        rez.cells[i] = cells[i] * _vector.cells[i];

    return rez;
}

Vector Vector::operator*(double factor)
{
    Vector rez(size);

    for (int i = 0; i < size; i++)
        rez.cells[i] = cells[i] * factor;

    return rez;
}

Vector Vector::operator/(double factor)
{
    if (factor == 0)
        throw Exception("Division by zero!");

    Vector rez(size);

    for (int i = 0; i < size; i++)
        rez.cells[i] = cells[i] / factor;

    return rez;
}

Vector Vector::operator++(int num)
{
    for (int i = 0; i < size; i++)
        cells[i]++;
    return *this;
}

Vector Vector::operator++()
{
    for (int i = 0; i < size; i++)
        ++cells[i];
    return *this;
}

Vector Vector::operator--(int num)
{
    for (int i = 0; i < size; i++)
        cells[i]--;
    return *this;
}

Vector Vector::operator--()
{
    for (int i = 0; i < size; i++)
        --cells[i];
    return *this;
}

Vector Vector::operator+=(const Vector& _vector)
{
    if (_vector.size != size) 
        throw Exception("Not correct size of vector!");

    for (int i = 0; i < size; i++)
        cells[i] += _vector.cells[i];

    return *this;
}

Vector Vector::operator+=(double num)
{
    for (int i = 0; i < size; i++)
        cells[i] += num;

    return *this;
}

Vector Vector::operator-=(const Vector& _vector)
{
    if (_vector.size != size)
        throw Exception("Not correct size of vector!");

    for (int i = 0; i < size; i++)
        cells[i] -= _vector.cells[i];

    return *this;
}

Vector Vector::operator-=(double num)
{
    for (int i = 0; i < size; i++)
        cells[i] -= num;

    return *this;
}

Vector Vector::operator*=(const Vector& _vector)
{
    if (_vector.size != size)
        throw Exception("Not correct size of vector!");

    for (int i = 0; i < size; i++)
        cells[i] *= _vector.cells[i];

    return *this;
}

Vector Vector::operator*=(double num)
{
    for (int i = 0; i < size; i++)
        cells[i] *= num;

    return *this;
}

Vector Vector::operator/=(double num)
{
    if (num == 0)
        throw Exception("Division by zero!");

    for (int i = 0; i < size; i++)
        cells[i] /= num;

    return *this;
}

double& Vector::operator[](int index)
{
    if ((index < 0) || (index >= size))
        throw Exception("Not correct index!");

    return cells[index];
}

const double& Vector::operator[](int index) const
{
    if ((index < 0) || (index >= size))
        throw Exception("Not correct index!");

    return cells[index];
}

bool Vector::operator==(const Vector& _vector) const
{
    if (_vector.size != size)
        return 0; 

    for (int i = 0; i < size; i++)
        if (cells[i] != _vector.cells[i]) 
            return 0;

    return 1;
}

bool Vector::operator!=(const Vector& _vector) const
{
    if (_vector.size != size)
        return 1;

    int flag = 0;

    for (int i = 0; i < size; i++)
        if (cells[i] = _vector.cells[i])
            flag++;
    if (flag == size) return 0;

    return 1;
}

bool Vector::operator>(const Vector& _vector) const
{
    if (_vector.size != size)
        throw Exception("Not correct size of vector!");

    return(Lenght() > _vector.Lenght());
}

bool Vector::operator>=(const Vector& _vector) const
{
    if (_vector.size != size)
        throw Exception("Not correct size of vector!");

    return(Lenght() >= _vector.Lenght());
}

bool Vector::operator<(const Vector& _vector) const
{
    if (_vector.size != size)
        throw Exception("Not correct size of vector!");

    return(Lenght() < _vector.Lenght());
}

bool Vector::operator<=(const Vector& _vector) const
{
    if (_vector.size != size)
        throw Exception("Not correct size of vector!");

    return(Lenght() <= _vector.Lenght());
}

istream& operator>> (istream& in, Vector& _vector)
{
    for (int i = 0; i < _vector.size; i++)
        in >> _vector.cells[i];

    return in;
}

ostream& operator<< (ostream &out, const Vector& _vector)
{
    if (_vector.size == 0)
    {
        out << "Empty vector.";
        return out;
    }

    out << "(";

    for (int i = 0; i < _vector.size; i++)
    {
        if (i != _vector.size - 1)
            out << _vector[i] << ", ";
        else
            out << _vector[i] << ")";
    }

    return out;
}