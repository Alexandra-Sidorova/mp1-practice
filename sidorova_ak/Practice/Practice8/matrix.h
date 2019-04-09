#ifndef _MATRIX_H_
#define _MATRIX_H_
#include "iostream"

using namespace std;

class Matrix
{
private:
	int rows; // строки
	int cols; // столбцы
	double* cells;
public:
	Matrix();
	Matrix(int, int);
	Matrix(int, int, double*);
	Matrix(const Matrix&);
	~Matrix();

	const Matrix& operator=(const Matrix&);
	Matrix operator+(const Matrix&);
	Matrix operator+(double);
	Matrix operator-(const Matrix&);
	Matrix operator-(double);
	Matrix operator*(const Matrix&);
	Matrix operator*(double);
	Matrix operator+=(const Matrix&);
	Matrix operator+=(double num);
	Matrix operator-=(const Matrix&);
	Matrix operator-=(double num);
	Matrix operator*=(double num);
	Matrix operator~();
	double* operator[](int index_rows);

	friend istream& operator>> (istream&, Matrix&); // Ввод
	friend ostream& operator<< (ostream&, const Matrix&); // Вывод
};


#endif