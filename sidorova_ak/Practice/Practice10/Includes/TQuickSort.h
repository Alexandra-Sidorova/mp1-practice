#ifndef _TQUICHSORT_H_
#define _TQUICKSORT_H_

template <typename T>
void Swap(T &a, T &b)
{
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
};

template <typename T>
void QuickSplit(T *array, int &i, int &j, T mid)
{
    do
    {
        while (array[i] < mid)
            i++;
        while (array[j] > mid)
            j--;

        if (i <= j)
        {
            Swap(array[i], array[j]);

            i++;
            j--;
        }
    } while (i <= j);
};

template <typename T>
void QuickSort(T *array, int first, int last)
{
    int i = first, j = last;
    int midIndex = (first + last) / 2;

    QuickSplit(array, i, j, array[midIndex]);

    if (j > first)
        QuickSort(array, first, j);
    if (i < last)
        QuickSort(array, i, last);
};

#endif