#ifndef _MATRIX_H_
#define _MATRIX_H_
#include "iostream"

using namespace std;

class Matrix
{
private:
	int rows, cols; // строки и столбцы
	double* cells;
public:
	Matrix();
	Matrix(int, int);
	Matrix(int, int, double*);
	Matrix(const Matrix&);
	~Matrix();

	Matrix& operator=(const Matrix&);
	Matrix operator+(const Matrix&);
	Matrix operator+(double);
	Matrix operator-(const Matrix&);
	Matrix operator-(double);
	Matrix operator*(const Matrix&);
	Matrix operator*(double);
	const double& operator[](int) const;
	double& operator[](int);

	friend istream& operator >> (istream&, Matrix&); // Ввод
	friend ostream& operator<< (ostream&, const Matrix&); // Вывод
};


#endif