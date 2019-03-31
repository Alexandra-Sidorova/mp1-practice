#include "vector.h"
#include "cmath"
#include "iostream"

using namespace std;

Vector::Vector()
{
	size = 5;
	cells = new double[size];
	for (int i = 0; i < size; i++)
		cells[i] = 0;
}

Vector::Vector(Vector& tmp)
{
	if (tmp.size < 0)
		return; // исключение SIZE

	size = tmp.size;
	cells = new double[size];
	for (int i = 0; i < size; i++)
		cells[i] = tmp.cells[i];
}

Vector::Vector(int _size)
{
	if (_size < 0)  //исключения SIZE
		return;

	size = _size;
	cells = new double[size];
	for (int i = 0; i < size; i++)
		cells[i] = 0;
}

Vector::Vector(int _size, double *_cells)
{
	if (*_cells == NULL)
		return; // исключение EMPTY

	if (_size < 0)
		return; // исключение SIZE

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

void Vector::PrintVector()
{
	cout << "Vector " << this << " = (" << endl;

	for (int i = 0; i < size; i++)
	{
		if (i != size - 1)
			cout << cells[i] << ", ";
		else
			cout << cells[i] << ")";
	}
}

Vector& Vector::operator=(const Vector& _rez)
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
	if ((_add.size != size) || ((_add.size == 0) & (size == 0)))
	{
		std::cout << "Error" << std::endl; // исключения SIZE | EMPTY
		return *this;
	}

	Vector rez(size);

	for (int i = 0; i < size; i++)
		rez.cells[i] = cells[i] + _add.cells[i];

	return rez;
}

Vector Vector::operator-(const Vector& _add)
{
	if ((_add.size != size) || ((_add.size == 0) & (size == 0)))
	{
		std::cout << "Error" << std::endl; // исключения SIZE | EMPTY
		return *this;
	}

	Vector rez(size);

	for (int i = 0; i < size; i++)
		rez.cells[i] = cells[i] - _add.cells[i];

	return rez;
}

Vector Vector::operator*(const Vector& _vector)
{
	if ((_vector.size != size) || ((_vector.size == 0) & (size == 0)))
	{
		std::cout << "Error" << std::endl; // исключения SIZE | EMPTY
		return *this;
	}

	Vector rez(size);

	for (int i = 0; i < size; i++)
		rez.cells[i] = cells[i] * _vector.cells[i];

	return rez;
}

Vector Vector::operator*(double factor)
{
	if (size == 0)
	{
		std::cout << "Error" << std::endl; // исключения EMPTY
		return *this;
	}

	Vector rez(size);

	for (int i = 0; i < size; i++)
		rez.cells[i] = cells[i] * factor;

	return rez;
}

Vector Vector::operator++(int num)
{
	if (size == 0)
	{
		std::cout << "Error" << std::endl; // исключения EMPTY
		return *this;
	}

	for (int i = 0; i < size; i++)
		cells[i]++;
	return *this;
}

Vector Vector::operator++()
{
	if (size == 0)
	{
		std::cout << "Error" << std::endl; // исключения EMPTY
		return *this;
	}

	for (int i = 0; i < size; i++)
		++cells[i];
	return *this;
}

Vector Vector::operator--(int num)
{
	if (size == 0)
	{
		std::cout << "Error" << std::endl; // исключения EMPTY
		return *this;
	}

	for (int i = 0; i < size; i++)
		cells[i]--;
	return *this;
}

Vector Vector::operator--()
{
	if (size == 0)
	{
		std::cout << "Error" << std::endl; // исключения EMPTY
		return *this;
	}

	for (int i = 0; i < size; i++)
		--cells[i];
	return *this;
}

Vector Vector::operator+=(const Vector& _vector)
{
	if ((_vector.size != size) || ((_vector.size == 0) & (size == 0)))
	{
		std::cout << "Error" << std::endl; // исключения EMPTY | SIZE
		return *this;
	}

	for (int i = 0; i < size; i++)
		cells[i] += _vector.cells[i];

	return *this;
}

Vector Vector::operator+=(double num)
{
	if (size == 0)
	{
		std::cout << "Error" << std::endl; // исключения EMPTY
		return *this;
	}

	for (int i = 0; i < size; i++)
		cells[i] += num;

	return *this;
}

Vector Vector::operator-=(const Vector& _vector)
{
	if ((_vector.size != size) || ((_vector.size == 0) & (size == 0)))
	{
		std::cout << "Error" << std::endl; // исключения EMPTY | SIZE
		return *this;
	}

	for (int i = 0; i < size; i++)
		cells[i] -= _vector.cells[i];

	return *this;
}

Vector Vector::operator-=(double num)
{
	if (size == 0)
	{
		std::cout << "Error" << std::endl; // исключения EMPTY
		return *this;
	}

	for (int i = 0; i < size; i++)
		cells[i] -= num;

	return *this;
}

const int& Vector::operator[](int index) const
{
	if ((index < 0) && (index > size))
		return 1; // // исключения INDEX

	return cells[index];
}

bool Vector::operator==(const Vector& _vector)
{
	if (_vector.size != size)
		return 0; 

	for (int i = 0; i < size; i++)
		if (cells[i] != _vector.cells[i]) 
			return 0;

	return 1;
}

bool Vector::operator!=(const Vector& _vector)
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

bool Vector::operator>(const Vector& _vector)
{
	if (_vector.size < size)
		return 1;

	if (_vector.size > size)
		return 0;

	float d_this = 0, d_vector = 0;

	for (int i = 0; i < size; i++)
	{
		d_this += (cells[i] * cells[i]);
		d_vector += (_vector.cells[i] * _vector.cells[i]);
	}

	if (sqrt(d_this) > sqrt(d_vector))
		return 1;

	return 0;
}

bool Vector::operator>=(const Vector& _vector)
{
	if (_vector.size < size)
		return 1;

	if (_vector.size > size)
		return 0;

	float d_this = 0, d_vector = 0;

	for (int i = 0; i < size; i++)
	{
		d_this += (cells[i] * cells[i]);
		d_vector += (_vector.cells[i] * _vector.cells[i]);
	}

	if (sqrt(d_this) >= sqrt(d_vector))
		return 1;

	return 0;
}

bool Vector::operator<(const Vector& _vector)
{
	if (_vector.size > size)
		return 1;

	if (_vector.size < size)
		return 0;

	float d_this = 0, d_vector = 0;

	for (int i = 0; i < size; i++)
	{
		d_this += (cells[i] * cells[i]);
		d_vector += (_vector.cells[i] * _vector.cells[i]);
	}

	if (sqrt(d_this) < sqrt(d_vector))
		return 1;

	return 0;
}

bool Vector::operator<=(const Vector& _vector)
{
	if (_vector.size > size)
		return 1;

	if (_vector.size < size)
		return 0;

	float d_this = 0, d_vector = 0;

	for (int i = 0; i < size; i++)
	{
		d_this += (cells[i] * cells[i]);
		d_vector += (_vector.cells[i] * _vector.cells[i]);
	}

	if (sqrt(d_this) <= sqrt(d_vector))
		return 1;

	return 0;
}

double Vector::Lenght(const Vector& _vector)
{
	if (_vector.size == 0)
		return 0;

	double lenght = 0;

	for (int i = 0; i < _vector.size; i++)
		lenght += (_vector.cells[i] * _vector.cells[i]);

	return sqrt(lenght);
}

istream& operator>> (istream& in, Vector& _vector)
{
	for (int i = 0; i < _vector.size; i++)
		in >> _vector.cells[i];

	return in;
}

ostream& operator<< (ostream &out, const Vector& _vector)
{

	out << "Vector = (" << endl;

	for (int i = 0; i < _vector.size; i++)
	{
		if (i != _vector.size - 1)
			out << _vector[i] << ", ";
		else
			out << _vector[i] << ")";
	}

	return out;
}