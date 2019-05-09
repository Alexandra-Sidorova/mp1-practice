#ifndef _TCONTAINERADVANCED_H_
#define _TCONTAINERADVANCED_H_

#include "exceptions.h"
#include "TContainer.h"

/* Class for containers with pointers */

template <typename T, int maxSize>
class TContainer <T*, maxSize>
{
private:
    T** array;
    int currentSize;
public:
    TContainer();
	TContainer(T**, int);
	TContainer(const TContainer&);
    ~TContainer();

    bool Full() const;
    bool Empty() const;

    void Add(T*);
    int Search(const T*) const;
	void RemoveIndex(const int); // удалить по индексу
    void Remove(T*);

    T& operator[](const int);
    const T& operator[](const int) const;

	friend ostream& operator<<(ostream& out, const TContainer& _container)
	{
		if (_container.currentSize == 0)
		{
			out << "The container is empty";
			return out;
		}

		out << "[ ";
		for (int i = 0; i < _container.currentSize; i++)
		{
			if (i != (_container.currentSize - 1))
				out << _container[i] << ", ";
			else
				out << _container[i] << "]";
		}

		return out;
	}
};
//-----------------------------------------------------

template <typename T, int maxSize>
TContainer<T*, maxSize>::TContainer()
{
    currentSize = 0;

    array = new T*[maxSize];
};

template <typename T, int maxSize>
TContainer<T*, maxSize>::TContainer(T** _array, int size)
{
    if (size <= 0)
        throw Exception("Not correct number of elements!");
    if (_array == NULL)
        throw Exception("Array is empty!");

    currentSize = size;
    array = new T*[maxSize];

    T* tmpArray = new T[currentSize];  // массив под элементы, скрывающиеся под указателями
    for (int i = 0; i < currentSize; i++)
        tmpArray[i] = *_array[i];

    for (int i = 0; i < currentSize; i++) // переносим адреса
        array[i] = &tmpArray[i];
};

template <typename T, int maxSize>
TContainer<T*, maxSize>::TContainer(const TContainer& _copy)
{
    if (this == &_copy)
        return *this;
    
    currentSize = _copy.currentSize;
    array = new T*[maxSize];

    T* tmpArray = new T[currentSize];  // массив под элементы, скрывающиеся под указателями
    for (int i = 0; i < currentSize; i++)
        tmpArray[i] = *_copy.array[i];

    for (int i = 0; i < currentSize; i++) // переносим адреса
        array[i] = &tmpArray[i];
};

template <typename T, int maxSize>
TContainer<T*, maxSize>::~TContainer()
{
     //удалить объекты по указателям

    for (int i = 0; i < currentSize; i++)
        delete array[i];
    delete[] array;
    array = NULL;

    currentSize = 0;
};

template <typename T, int maxSize>
bool TContainer<T*, maxSize>::Full() const
{
    return(currentSize == maxSize);
};

template <typename T, int maxSize>
bool TContainer<T*, maxSize>::Empty() const
{
    return(currentSize == 0);
};

template <typename T, int maxSize>
void TContainer<T*, maxSize>::Add(T* object)
{
    if (Full())
        throw Exception("The Container is full! Make room to add an object.");

    array[currentSize] = object;
    currentSize++;
};

template <typename T, int maxSize>
int TContainer<T*, maxSize>::Search(const T* object) const
{
    if (Empty())
        throw Exception("The Container is empty! This object missing.");

    for (int i = 0; i < currentSize; i++)
        if (object == array[i])
            return i;

    throw Exception("This object missing in Container!");
};

template <typename T, int maxSize>
void TContainer<T*, maxSize>::RemoveIndex(const int index)
{
	if (Empty())
		throw Exception("The Container is empty!");
	if ((index < 0) || (index >= currentSize))
		throw Exception("Not correct index!");

	array[index] = array[currentSize - 1];
	currentSize--;
};

template <typename T, int maxSize>
void TContainer<T*, maxSize>::Remove(T* object)
{
	RemoveIndex(Search(object));
};

template <typename T, int maxSize>
T& TContainer<T*, maxSize>::operator[](const int index)
{
    if ((index < 0) || (index >= currentSize))
        throw Exception("Not correct index!");

    return *array[index];  // возвращает элемент по указателю, а не сам указатель
};

template <typename T, int maxSize>
const T& TContainer<T*, maxSize>::operator[](const int index) const
{
    if ((index < 0) || (index >= currentSize))
        throw Exception("Not correct index!");

    return *array[index];  // возвращает элемент по указателю, а не сам указатель
};

#endif 