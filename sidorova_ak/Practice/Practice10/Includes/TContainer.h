#ifndef _TCONTAINER_H_
#define _TCONTAINER_H_
#include "Includes\exceptions.h"
#include "Includes\TQuickSort.h"

template <typename T, int maxSize>
class TContainer
{
private:
	T* array;
	int currentSize;
public:
	TContainer();
	TContainer(int);
	TContainer(T*, int);
	TContainer(const TContainer&);
	~TContainer();

	bool Full() const;
	bool Empty() const;

	void Add(T);  // не доделано
	int Search(T) const;
	void Remove(T);
	void Remove(const int); // удалить по индексу
	void Sort();

	T operator[](const int);
	friend istream& operator>>(istream&, TContainer&); // ввод
	friend ostream& operator<<(ostream&, const TContainer&); // вывод
};
//-----------------------------------------------------

template <typename T, int maxSize>
TContainer<T, maxSize>::TContainer()
{
	currentSize = 0;
	array = NULL;
}

template <typename T, int maxSize>
TContainer<T, maxSize>::TContainer(int size)
{
	if (size <= 0)
		throw Exception("Not correct size of container!");

	currentSize = size;
	array = new T[currentSize];
	for (int i = 0; i < currentSize; i++)
		array[i] = 0;
}

template <typename T, int maxSize>
TContainer<T, maxSize>::TContainer(T* _array, int size)
{
	if (size <= 0)
		throw Exception("Not correct size of container!");
	if (_array = NULL)
		throw Exception("Array is empty!");

	currentSize = size;
	array = new T[currentSize];
	for (int i = 0; i < currentSize; i++)
		array[i] = _array[i];
}

template <typename T, int maxSize>
TContainer<T, maxSize>::TContainer(const TContainer& _copy)
{
	if (this == &_copy)
		return *this;

	currentSize = _copy.currentSize;
	array = new T[currentSize];
	for (int i = 0; i < currentSize; i++)
		array[i] = _copy.array[i];
}

template <typename T, int maxSize>
TContainer<T, maxSize>::~TContainer()
{
	currentSize = 0;
	array = NULL;
}

template <typename T, int maxSize>
bool TContainer<T, maxSize>::Full() const
{
	return(currentSize == maxSize);
}

template <typename T, int maxSize>
bool TContainer<T, maxSize>::Empty() const
{
	return(currentSize == 0);
}

template <typename T, int maxSize>
void TContainer<T, maxSize>::Add(T object)
{
	if (Full())
		throw Exception("The Container is full! Make room to add an object.");

	// TODO 
	//увеличить размер массива
}

template <typename T, int maxSize>
int TContainer<T, maxSize>::Search(T object) const
{
	if (Emplty())
		throw Exception("The Container is empty! This object missing.");

	for (int i = 0; i < currentSize; i++)
		if (object == array[i])
			return i;
	
	throw Exception("This object missing in Container!");
}

template <typename T, int maxSize>
void TContainer<T, maxSize>::Remove(T object)
{
	if (Empty())
		throw Exception("The Container is empty!");

	int index = Search(object);

	array[index] = array[currentSize - 1];
	delete array[currentSize - 1];
	currentSize--;
}

template <typename T, int maxSize>
void TContainer<T, maxSize>::Remove(const int index)
{
	if (Empty())
		throw Exception("The Container is empty!");
	if ((index < 0) || (index >= currentSize))
		throw Exception("Not correct index!");

	array[index] = array[currentSize - 1];
	delete array[currentSize - 1];
	currentSize--;
}

template <typename T, int maxSize>
void TContainer<T, maxSize>::Sort()
{
	if (Empty())
		throw Exception("The Container is empty!");

	QuickSort(this, 0, currentSize - 1);
}

template <typename T, int maxSize>
T TContainer<T, maxSize>::operator[](const int index)
{
	if ((index < 0) || (index >= currentSize))
		throw Exception("Not correct index!");

	return array[index];
}

template <typename T, int maxSize>
istream& operator>>(istream& in, TContainer& _container)
{
	for (int i = 0; i < _container.curruntSize; i++)
		in >> _container[i];

	return in;
}

template <typename T, int maxSize>
ostream& operator<<(ostream& out, const TContainer& _container)
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