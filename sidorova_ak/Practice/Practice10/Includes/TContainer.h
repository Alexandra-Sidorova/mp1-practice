#ifndef _TCONTAINER_H_
#define _TCONTAINER_H_

#include <iostream>
#include "exceptions.h"
#include "TQuickSort.h"

using namespace std;

template <typename T>
class TContainer
{
private:
    T* array;
    int currentSize;
    int maxSize;
public:
    TContainer(int);
    TContainer(T*, int, int);
    TContainer(const TContainer&);
    ~TContainer();

    bool Full() const;
    bool Empty() const;

    void Resize(const int);  // увеличить размер контейнера на определенное число
    void Add(const T);
    int Search(const T) const;
    void RemoveIndex(const int); // удалить по индексу
    void Remove(const T);
    void Sort();

    T& operator[](int);
    const T& operator[](int) const;

    friend istream& operator>>(istream&, TContainer& _container)
    {
        for (int i = 0; i < _container.curruntSize; i++)
            in >> _container[i];

        return in;
    };

    friend ostream& operator<<(ostream& out, const TContainer& _container)
    {
        if (_container.currentSize == 0)
        {
            out << "The container is empty";
            return out;
        }

        out << "[ ";

        for (int i = 0; i < _container.currentSize - 1; i++)
            out << _container[i] << ", ";

        out << _container[_container.currentSize - 1] << "]";

        return out;
    }
};
//-----------------------------------------------------

template <typename T>
TContainer<T>::TContainer(int _maxSize)
{
    currentSize = 0;
    maxSize = _maxSize;

    array = new T[maxSize];
};

template <typename T>
TContainer<T>::TContainer(T* _array, int size, int mSize)
{
    if (size <= 0)
        throw Exception("Not correct number of elements!");
    if (_array == NULL)
        throw Exception("Array is empty!");

    currentSize = size;
    maxSize = mSize;
    array = new T[maxSize];
    for (int i = 0; i < currentSize; i++)
        array[i] = _array[i];
};

template <typename T>
TContainer<T>::TContainer(const TContainer& _copy)
{
    currentSize = _copy.currentSize;
    maxSize = _copy.maxSize;
    array = new T[maxSize];
    for (int i = 0; i < currentSize; i++)
        array[i] = _copy.array[i];
};

template <typename T>
TContainer<T>::~TContainer()
{
    currentSize = 0;
    maxSize = 0;
    array = NULL;
};

template <typename T>
bool TContainer<T>::Full() const
{
    return(currentSize == maxSize);
};

template <typename T>
bool TContainer<T>::Empty() const
{
    return(currentSize == 0);
};

template <typename T>
void TContainer<T>::Resize(const int step)
{
    T* tmp = new T[currentSize];     // запоминаем данные из контейнера
    for (int i = 0; i < currentSize; i++)
        tmp[i] = array[i];
    delete[] array;  // удаляем старое хранилище

    array = tmp;
    maxSize += step;
};

template <typename T>
void TContainer<T>::Add(const T object)
{
    if (Full())
        Resize(1);

    array[currentSize] = object;
    currentSize++;
};

template <typename T>
int TContainer<T>::Search(const T object) const
{
    if (Empty())
        throw Exception("The Container is empty! This object missing.");

    for (int i = 0; i < currentSize; i++)
        if (object == array[i])
            return i;
    
    return -1;
};

template <typename T>
void TContainer<T>::RemoveIndex(const int index)
{
    if (Empty())
        throw Exception("The Container is empty!");
    if ((index < 0) || (index >= currentSize))
        throw Exception("Not correct index!");

    array[index] = array[currentSize - 1];
    currentSize--;
};

template <typename T>
void TContainer<T>::Remove(const T object)
{
    RemoveIndex(Search(object));
};

template <typename T>
void TContainer<T>::Sort()
{
    if (Empty())
        throw Exception("The Container is empty!");

    QuickSort<T>(array, 0, currentSize - 1);
};

template <typename T>
T& TContainer<T>::operator[](int index)
{
    if ((index < 0) || (index >= currentSize))
        throw Exception("Not correct index!");

    return array[index];
};

template <typename T>
const T& TContainer<T>::operator[](int index) const
{
    if ((index < 0) || (index >= currentSize))
        throw Exception("Not correct index!");

    return array[index];
};

#endif 