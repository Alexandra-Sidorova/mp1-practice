#ifndef _TCONTAINERADVANCED_H_
#define _TCONTAINERADVANCED_H_

#include "exceptions.h"

/* Class for containers with pointers */

template <typename T, int maxSize>
class TContainerAdvanced
{
private:
    T** array;
    int currentSize;
public:
    TContainerAdvanced();
    TContainerAdvanced(T**, int);
    TContainerAdvanced(const TContainerAdvanced&);
    ~TContainerAdvanced();

    bool Full() const;
    bool Empty() const;

    void Add(const T*);
    int Search(const T*) const;
    void Remove(T*);
    void Remove(const int); // удалить по индексу

    T& operator[](const int);
    const T& operator[](const int) const;
};
//-----------------------------------------------------

template <typename T, int maxSize>
TContainerAdvanced<T, maxSize>::TContainerAdvanced()
{
    currentSize = 0;

    array = new T*[maxSize];
};

template <typename T, int maxSize>
TContainerAdvanced<T, maxSize>::TContainerAdvanced(T** _array, int size)
{
    if (size <= 0)
        throw Exception("Not correct number of elements!");
    if (_array = NULL)
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
TContainerAdvanced<T, maxSize>::TContainerAdvanced(const TContainerAdvanced& _copy)
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
TContainerAdvanced<T, maxSize>::~TContainerAdvanced()
{
    // удалить объекты по указателям

    for (int i = 0; i < currentSize; i++)
        delete array[i];
    delete[] array;
    array = NULL;

    currentSize = 0;
};

template <typename T, int maxSize>
bool TContainerAdvanced<T, maxSize>::Full() const
{
    return(currentSize == maxSize);
};

template <typename T, int maxSize>
bool TContainerAdvanced<T, maxSize>::Empty() const
{
    return(currentSize == 0);
};

template <typename T, int maxSize>
void TContainerAdvanced<T, maxSize>::Add(const T* object)
{
    if (Full())
        throw Exception("The Container is full! Make room to add an object.");

    array[currentSize] = object;
    currentSize++;
};

template <typename T, int maxSize>
int TContainerAdvanced<T, maxSize>::Search(const T* object) const
{
    if (Empty())
        throw Exception("The Container is empty! This object missing.");

    for (int i = 0; i < currentSize; i++)
        if (object == array[i])
            return i;

    throw Exception("This object missing in Container!");
};

template <typename T, int maxSize>
void TContainerAdvanced<T, maxSize>::Remove(T* object)
{
    if (Empty())
        throw Exception("The Container is empty!");

    int index = Search(object);

    array[index] = array[currentSize - 1];
    currentSize--;
};

template <typename T, int maxSize>
void TContainerAdvanced<T, maxSize>::Remove(const int index)
{
    if (Empty())
        throw Exception("The Container is empty!");
    if ((index < 0) || (index >= currentSize))
        throw Exception("Not correct index!");

    array[index] = array[currentSize - 1];
    currentSize--;
};

template <typename T, int maxSize>
T& TContainerAdvanced<T, maxSize>::operator[](const int index)
{
    if ((index < 0) || (index >= currentSize))
        throw Exception("Not correct index!");

    return *array[index];
};

template <typename T, int maxSize>
const T& TContainerAdvanced<T, maxSize>::operator[](const int index) const
{
    if ((index < 0) || (index >= currentSize))
        throw Exception("Not correct index!");

    return *array[index];
};

#endif 