#ifndef __VECTOR_H
#define __VECTOR_H

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

	void PrintVector();

	Vector& operator=(const Vector&);
	Vector operator+(const Vector&);
	Vector operator-(const Vector&);
	Vector operator*(const Vector&);
	Vector operator*(double);
	Vector operator++(int);
	Vector operator++();
	Vector operator--(int);
	Vector operator--();
	Vector operator+=(const Vector&);
	Vector operator+=(double);
	Vector operator-=(const Vector&);
	Vector operator-=(double);

	const int& operator[](int) const;

	bool operator==(const Vector&);
	bool operator!=(const Vector&);
	bool operator>(const Vector&);
	bool operator>=(const Vector&);
	bool operator<(const Vector&);
	bool operator<=(const Vector&);
	 
	double Lenght(const Vector&);

	friend istream& operator>> (istream&, Vector&); // Ввод
	friend ostream& operator<< (ostream&, const Vector&); // Вывод
};

#endif
