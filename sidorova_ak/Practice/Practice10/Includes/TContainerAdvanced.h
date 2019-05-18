#ifndef _TCONTAINERADVANCED_H_
#define _TCONTAINERADVANCED_H_

#include "exceptions.h"
#include "TContainer.h"

/* Class for containers with pointers */

template <typename T>
class TContainer <T*>
{
private:
    T** array;
    int currentSize;
    int maxSize;
public:
    TContainer();
    TContainer(T**, int, int);
    TContainer(const TContainer&);
    ~TContainer();

    bool Full() const;
    bool Empty() const;

    void Resize(const int); // увеличить размер контейнера на определенное число
    void Add(T*);
    int Search(const T*) const;
    void RemoveIndex(const int); // удалить по индексу
    void Remove(T*);

    T& operator[](int);
    const T& operator[](int) const;

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

template <typename T>
TContainer<T*>::TContainer()
{
    currentSize = 0;
    maxSize = 1;

    array = new T*[maxSize];
};

template <typename T>
TContainer<T*>::TContainer(T** _array, int size, int mSize)
{
    if (size <= 0)
        throw Exception("Not correct number of elements!");
    if (_array == NULL)
        throw Exception("Array is empty!");

    currentSize = size;
    maxSize = mSize;
    array = new T*[maxSize];

    T* tmpArray = new T[currentSize];  // массив под элементы, скрывающиеся под указателями
    for (int i = 0; i < currentSize; i++)
        tmpArray[i] = *_array[i];

    for (int i = 0; i < currentSize; i++) // переносим адреса
        array[i] = &tmpArray[i];
};

template <typename T>
TContainer<T*>::TContainer(const TContainer& _copy)
{
    currentSize = _copy.currentSize;
    maxSize = _copy.maxSize;
    array = new T*[maxSize];

    T* tmpArray = new T[currentSize];  // массив под элементы, скрывающиеся под указателями
    for (int i = 0; i < currentSize; i++)
        tmpArray[i] = *_copy.array[i];

    for (int i = 0; i < currentSize; i++) // переносим адреса
        array[i] = &tmpArray[i];
};

template <typename T>
TContainer<T*>::~TContainer() //удалить объекты по указателям
{
    for (int i = 0; i < currentSize; i++)
        delete array[i];
    delete[] array;
    array = NULL;

    currentSize = 0;
    maxSize = 0;
};

template <typename T>
bool TContainer<T*>::Full() const
{
    return(currentSize == maxSize);
};

template <typename T>
bool TContainer<T*>::Empty() const
{
    return(currentSize == 0);
};

template<typename T>
void TContainer<T*>::Resize(const int step)
{
    T** tmp = new T*[currentSize];
    for (int i = 0; i < currentSize; i++)
        tmp[i] = array[i];
    delete[] array;

    array = new T*[maxSize + step];
    for (int i = 0; i < currentSize; i++)
        array[i] = tmp[i];
    delete[] tmp;

    maxSize += step;
};

template <typename T>
void TContainer<T*>::Add(T* object)
{
    if (Full())
        Resize(1);

    array[currentSize] = object;
    currentSize++;
};

template <typename T>
int TContainer<T*>::Search(const T* object) const
{
    if (Empty())
        throw Exception("The Container is empty! This object missing.");

    for (int i = 0; i < currentSize; i++)
        if (object == array[i])
            return i;

    throw Exception("This object missing in Container!");
};

template <typename T>
void TContainer<T*>::RemoveIndex(const int index)
{
    if (Empty())
        throw Exception("The Container is empty!");
    if ((index < 0) || (index >= currentSize))
        throw Exception("Not correct index!");

    array[index] = array[currentSize - 1];
    currentSize--;
};

template <typename T>
void TContainer<T*>::Remove(T* object)
{
    RemoveIndex(Search(object));
};

template <typename T>
T& TContainer<T*>::operator[](int index)
{
    if ((index < 0) || (index >= currentSize))
        throw Exception("Not correct index!");

    return *array[index];  // возвращает элемент по указателю, а не сам указатель
};

template <typename T>
const T& TContainer<T*>::operator[](int index) const
{
    if ((index < 0) || (index >= currentSize))
        throw Exception("Not correct index!");

    return *array[index];  // возвращает элемент по указателю, а не сам указатель
};

#endif 