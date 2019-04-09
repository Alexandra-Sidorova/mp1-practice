#include "matrix.h"
#include "exceptions.h"
#include "iostream"

Matrix::Matrix()
{
    rows = 5;
    cols = 5;

    cells = (double*)malloc(rows * cols * sizeof(double));
    for (int i = 0; i < rows * cols; i++)
        cells[i] = 0;
}

Matrix::Matrix(int _rows, int _cols)
{
    if ((_rows <= 0) || (_cols <= 0))
        throw Exception("Not correct size of matrix!");

    rows = _rows;
    cols = _cols;

    cells = (double*)malloc(rows * cols * sizeof(double));
    for (int i = 0; i < rows * cols; i++)
        cells[i] = 0;
}

Matrix::Matrix(int _rows, int _cols, double* _cells)
{
    if (_cells == NULL)
        throw Exception("Empty array!");

    if ((_rows <= 0) || (_cols <= 0))
        throw Exception("Not correct size of matrix!");

    rows = _rows;
    cols = _cols;

    cells = (double*)malloc(rows * cols * sizeof(double));
    for (int i = 0; i < rows * cols; i++)
        cells[i] = _cells[i];
}

Matrix::Matrix(const Matrix& _matrix)
{
    rows = _matrix.rows;
    cols = _matrix.cols;

    cells = (double*)malloc(rows * cols * sizeof(double));
    for (int i = 0; i < cols * rows; i++)
        cells[i] = _matrix.cells[i];
}

Matrix::~Matrix()
{
    rows = 0;
    cols = 0;
    delete[] cells;
}

const Matrix& Matrix::operator=(const Matrix& _matrix)
{
    if (this == &_matrix)
        return *this;

    rows = _matrix.rows;
    cols = _matrix.cols;
    
    delete[] cells;
    cells = (double*)malloc(rows * cols * sizeof(double));
    for (int i = 0; i < cols * rows; i++)
        cells[i] = _matrix.cells[i];

    return *this;
}

Matrix Matrix::operator+(const Matrix& _add)
{
    if ((rows != _add.rows) || (cols != _add.cols))
        throw Exception("Not correct size of matrix!");

    Matrix result(rows, cols);

    for (int i = 0; i < rows * cols; i++)
        result.cells[i] += (cells[i] + _add.cells[i]);

    return result;
}

Matrix Matrix::operator+(double num)
{
    Matrix result(rows, cols);

    for (int i = 0; i < rows * cols; i++)
        result.cells[i] += (cells[i] + num);

    return result;
}

Matrix Matrix::operator-(const Matrix& _sub)
{
    if ((rows != _sub.rows) || (cols != _sub.cols))
        throw Exception("Not correct size of matrix!");

    Matrix result(rows, cols);

    for (int i = 0; i < rows * cols; i++)
        result.cells[i] += (cells[i] - _sub.cells[i]);

    return result;
}

Matrix Matrix::operator-(double num)
{
    Matrix result(rows, cols);

    for (int i = 0; i < rows * cols; i++)
        result.cells[i] += (cells[i] - num);

    return result;
}

Matrix Matrix::operator+=(const Matrix& _add)
{
    if ((rows != _add.rows) || (cols != _add.cols))
        throw Exception("Not correct size of matrix!");

    for (int i = 0; i < rows * cols; i++)
        cells[i] += _add.cells[i];

    return *this;
}

Matrix Matrix::operator+=(double num)
{
    for (int i = 0; i < rows * cols; i++)
        cells[i] += num;

        return *this;
}

Matrix Matrix::operator-=(const Matrix& _add)
{
    if ((rows != _add.rows) || (cols != _add.cols))
        throw Exception("Not correct size of matrix!");

    for (int i = 0; i < rows * cols; i++)
        cells[i] -= _add.cells[i];

    return *this;
}

Matrix Matrix::operator-=(double num)
{
    for (int i = 0; i < rows * cols; i++)
        cells[i] -= num;

    return *this;
}

Matrix Matrix::operator*=(double num)
{
    for (int i = 0; i < rows * cols; i++)
        cells[i] *= num;

    return *this;
}

Matrix Matrix::operator*(const Matrix& _factor)
{
    if (cols != _factor.rows)
        throw Exception("Not correct size of matrix!");

    Matrix result(rows, _factor.cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < _factor.cols; j++)
            for (int k = 0; k < cols; k++)
                result.cells[i * _factor.cols + j] += 
                (cells[i * cols + k] * _factor.cells[k * _factor.cols + j]);
        
    return result;
}

Matrix Matrix::operator*(double num)
{
    Matrix result(rows, cols);

    for (int i = 0; i < rows * cols; i++)
        result.cells[i] += (cells[i] * num);

    return result;
}

double* Matrix::operator[](int index_rows)
{
    if ((index_rows < 0) || (index_rows >= rows))
        throw Exception("Not correct index!");

    return(cells + cols * index_rows);
}

istream& operator>>(istream& in, Matrix& _matrix)
{
    for (int i = 0; i < (_matrix.rows * _matrix.cols); i++)
        in >> _matrix.cells[i];

    return in;
}

ostream& operator<<(ostream &out, const Matrix& _matrix)
{
    if ((_matrix.rows * _matrix.cols) == 0)
    {
        out << "Empty matrix.";
        return out;
    }

    for (int i = 0; i < (_matrix.rows * _matrix.cols); i++)
    {
        if (i % _matrix.cols == 0)
            out << "| ";

        out << _matrix.cells[i] << " ";

        if ((i + 1) % _matrix.cols == 0)
            out << "|" << endl;
    }

    return out;
}