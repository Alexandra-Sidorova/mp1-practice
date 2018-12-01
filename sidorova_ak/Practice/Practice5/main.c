#include <stdio.h>

void Swap(float a, float b)
{
    float tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void SelectionSort(float array[], int n, char sort)
{
    int i = 0, j, minIndex;
    float min;

    for (i; i < n; i++)
    {
        min = array[i];
        minIndex = i;
        
        for (j = i + 1; j < n; j++)
        {
            if (array[j] < min)
            {
                min = array[j];
                minIndex = j;
            }
        }

        array[minIndex] = array[i];
        array[i] = min;
    }
}

void InsertionSort(float array[], int n, char sort)
{
    int i = 1, j;
    float tmp;

    for (i; i < n; i++)
    {
        tmp = array[i];
        j = i - 1;

        while ((j >= 0) && (array[j] > tmp))
        {
            array[j + 1] = array[j];
            array[j] = tmp;
            j--;
        }
    }
}

void BubbleSort(float array[], int n, char sort)
{
    int i = 0, j = 1;

    for (i; i < n; i++)
    {
        for (j; j < n - i; j++)
        {
            if (array[j - 1] > array[j])
                Swap(array[j - 1], array[j]);
        }
    }
}

void CountingSort(float array[], int n, char sort)
{

}