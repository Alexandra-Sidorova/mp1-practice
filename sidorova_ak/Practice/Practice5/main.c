#include <stdio.h>
#include <malloc.h>

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
        printf("%.2f ", array[i]);
}

void Swap(float *a, float *b)
{
    float tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void QuickSplit(float array[], int *i, int *j, int mid)
{
    do 
    {
        while (array[*i] < mid)
            (*i)++;
        while (array[*j] > mid)
            (*j)--;

        if (*i <= *j)
        {

            Swap(&(array[*i]), &(array[*j]));

            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void Merge(float array[], int first, int midIndex, int last)
{
    int i, j, step;
    float *tmp = (float*)malloc((last - first + 1) * sizeof(float));

    i = first;
    j = midIndex + 1;

    for (step = 0; step < last - first + 1; step++)
        if ((j > last) || ((i <= midIndex) && (array[i] < array[j])))
            tmp[step] = array[i++];
        else
            tmp[step] = array[j++];

    for (step = first; step < last + 1; step++)
        array[step] = tmp[step - first];
}

void SelectionSort(float array[], int n, int sort)
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

void InsertionSort(float array[], int n, int sort)
{
    int i = 1, j;
    float tmp;

    for (i; i < n; i++)
    {
        tmp = array[i];
        j = i - 1;

        while ((j >= 0) && (array[j] > tmp))
        {
            Swap(&array[j + 1], &array[j]);
            j--;
        }
    }
}

void BubbleSort(float array[], int n, int sort)
{
    int i = 0, j;

    for (i; i < n; i++)
        for (j = n - 1; j > i; j--)
            if (array[j - 1] > array[j])
                Swap(&array[j - 1], &array[j]);
}

void CountingSort(float array[], int n, int sort)
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

void QuickSort(float array[], int first, int last, int sort)
{
    int midIndex;
    int i = first;
    int j = last;

    midIndex = (first + last) / 2;

    QuickSplit(array, &i, &j, array[midIndex]);

    if (j > first) 
        QuickSort(array, first, j, sort);
    if (i < last)
        QuickSort(array, i, last, sort);
}

void MergeSort(float array[], int first, int last, int sort)
{
    int midIndex;
    midIndex = (last + first) / 2;

    if (first >= last)
        return;

    MergeSort(array, first, midIndex, 1);
    MergeSort(array, midIndex + 1, last, 1);
    Merge(array, first, midIndex, last);
}

void TypeSort(int tSort, int sort)
{
    do
    {
        printf(" Choose the type of sorting, please:\n 1. BubbleSort.\n 2. InsertionSort\n ");
        printf("3. SelectionSort\n 4. CountingSort\n 5. QuickSort\n 6. MergeSort\n ");
        printf("Enter only the number of sorting (If you want to close the program, enter 0 (zero)): ");
        scanf("%d", &tSort);
    } while ((tSort < 0) || (tSort > 6));

    do
    {
        printf("Enter '0' (zero) for sorting in ascending order or '1' (one) for sorting in descending order:");
        scanf("%d", &sort);
    } while ((sort != 0) && (sort != 1));
}

void main()
{
    float array[100];
    int n;
    char sort;

    scanf("%d", &n);

    InputArray(array, n);
    QuickSort(array, 0, n - 1, 1);
    OutputArray(array, n);
}