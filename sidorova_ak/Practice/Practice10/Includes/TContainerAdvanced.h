#ifndef _TCONTAINERADVANCED_H_
#define _TCONTAINERADVANCED_H_

#include "exceptions.h"


template <typename T, int maxSize>
class TContainerAdvanced
{
private:
	T* array;
	int currentSize;
public:
	TContainerAdvanced();
	TContainerAdvanced(T**, int);
	TContainerAdvanced(const TContainerAdvanced&);
	~TContainerAdvanced();

	bool Full() const;
	bool Empty() const;

	void Add(T*);
	int Search(T*) const;
	void Remove(T*);
	void Remove(const int); // удалить по индексу

	T operator[](const int);
	friend istream& operator>>(istream&, TContainerAdvanced&); // ввод
	friend ostream& operator<<(ostream&, const TContainerAdvanced&); // вывод
};
//-----------------------------------------------------

template <typename T, int maxSize>
TContainerAdvanced<T, maxSize>::TContainerAdvanced()
{
	currentSize = 0;

	array = new T[maxSize];
}

template <typename T, int maxSize>
TContainerAdvanced<T, maxSize>::TContainerAdvanced(T** _array, int size)
{
	if (size <= 0)
		throw Exception("Not correct number of elements!");
	if (_array = NULL)
		throw Exception("Array is empty!");

	currentSize = size;
	array = new T[maxSize];
	for (int i = 0; i < currentSize; i++)
		array[i] = _array[i];
}

template <typename T, int maxSize>
TContainerAdvanced<T, maxSize>::TContainerAdvanced(const TContainerAdvanced& _copy)
{
	if (this == &_copy)
		return *this;
	
	currentSize = _copy.currentSize;
	array = new T[maxSize];

	// отдельные указатели
	//for (int i = 0; i < currentSize; i++)
	//	array[i] = _copy.array[i];
}

template <typename T, int maxSize>
TContainerAdvanced<T, maxSize>::~TContainerAdvanced()
{
	currentSize = 0;
	// удалить объекты по указателям
}

template <typename T, int maxSize>
bool TContainerAdvanced<T, maxSize>::Full() const
{
	return(currentSize == maxSize);
}

template <typename T, int maxSize>
bool TContainerAdvanced<T, maxSize>::Empty() const
{
	return(currentSize == 0);
}

template <typename T, int maxSize>
void TContainerAdvanced<T, maxSize>::Add(T* object)
{
	if (Full())
		throw Exception("The Container is full! Make room to add an object.");

	array[currentSize] = object;
	currentSize++;
}

template <typename T, int maxSize>
int TContainerAdvanced<T, maxSize>::Search(T* object) const
{
	if (Emplty())
		throw Exception("The Container is empty! This object missing.");

	for (int i = 0; i < currentSize; i++)
		if (object == array[i])
			return i;

	throw Exception("This object missing in Container!");
}

template <typename T, int maxSize>
void TContainerAdvanced<T, maxSize>::Remove(T* object)
{
	if (Empty())
		throw Exception("The Container is empty!");

	int index = Search(object);

	array[index] = array[currentSize - 1];
	currentSize--;
}

template <typename T, int maxSize>
void TContainerAdvanced<T, maxSize>::Remove(const int index)
{
	if (Empty())
		throw Exception("The Container is empty!");
	if ((index < 0) || (index >= currentSize))
		throw Exception("Not correct index!");

	array[index] = array[currentSize - 1];
	currentSize--;
}

template <typename T, int maxSize>
T TContainerAdvanced<T, maxSize>::operator[](const int index)
{
	if ((index < 0) || (index >= currentSize))
		throw Exception("Not correct index!");

	return array[index];
}

template <typename T, int maxSize>
istream& operator>>(istream& in, TContainerAdvanced<T, maxSize>& _container)
{
	for (int i = 0; i < _container.curruntSize; i++)
		in >> _container[i];

	return in;
}

template <typename T, int maxSize>
ostream& operator<<(ostream& out, const TContainerAdvanced<T, maxSize>& _container)
{
	if (_container.currentSize == 0)
		return("The container is empty");

	out << "[ ";
	for (int i = 0; i < _container.curruntSize; i++)
	{
		if (i != (_container.currentSize - 1))
			out << _container[i] << ", ";
		else
			out << _container[i] << "]";
	}

	return out;
}

#endif 
