#include <stdio.h>

void InputArray(float array[], int n)
{
    int i = 0;

    for (i; i < n; i++)
        scanf("%f", &array[i]);
}

void OutputArray(float array[], int n)
{
    int i = 0;

    for (i; i < n; i++)
        printf("%f ", array[i]);
}

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
    int i = 0, j = 0, index = 0, min, max;
    int count[100] = { 0 };

    min = max = array[0];

    for (i; i < n; i++)
        if ((array[i] - (int)array[i]) != 0)
        {
            printf("It isn't Z!");
            return;
        }

    for (i = 0; i < n; i++)
    {
        if (array[i] < min) 
            min = array[i];
        if (array[i] > max)
            max = array[i];
    }

    for (i = 0; i < n; i++)
        count[(int)array[i] - (int)min]++;

    for (i = 0; i < (max - min); i++)
        for (j; j < count[i]; j++)
            array[index++] = i;

}

void main()
{
    float array[100];
    int n;
    char sort;

    scanf("%d", &n);

    InputArray(array, n);
    CountingSort(array, n, 'a');
    OutputArray(array, n);
}