#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX_COUNT_OF_FILES 100
#define SIZE_OF_BUFFER 2048

void Swap_Int(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void Swap_ULONGLONG(ULONGLONG *a, ULONGLONG *b)
{
    ULONGLONG tmp;

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

void SelectionSort(ULONGLONG *fileSize, int *filesNewIndex, int N)     //COMPLETE
{
    int i, j, keyIndex, keyNewIndex;
    ULONGLONG *sizes, key;

    sizes = (ULONGLONG*)malloc(N * sizeof(ULONGLONG));

    for (i = 0; i < N; i++)
        sizes[i] = fileSize[i];

    for (i = 0; i < N; i++)
    {
        key = sizes[i];
        keyIndex = i;
        keyNewIndex = filesNewIndex[i];

        for (j = i + 1; j < N; j++)
        {
            if (sizes[j] < key)
            {
                key = sizes[j];
                keyIndex = j;
            }
           
        }

        Swap_ULONGLONG(&sizes[keyIndex], &sizes[i]);
        Swap_Int(&filesNewIndex[i], &filesNewIndex[keyIndex]);
    }

    free(sizes);
}

void InsertionSort(ULONGLONG *fileSize, int *filesNewIndex, int N) //COMPLETE
{
    int i, j;
    ULONGLONG *sizes, tmp;

    sizes = (ULONGLONG*)malloc(N * sizeof(ULONGLONG));

    for (i = 0; i < N; i++)
        sizes[i] = fileSize[i];

    for (i = 1; i < N; i++)
    {
        tmp = sizes[i];
        j = i - 1;

        while ((j >= 0) && (sizes[j] > tmp))
        {
            Swap_ULONGLONG(&sizes[j + 1], &sizes[j]);
            Swap_Int(&filesNewIndex[j + 1], &filesNewIndex[j]);
            j--;
        }
    }

    free(sizes);
}

void BubbleSort(ULONGLONG *fileSize, int *filesNewIndex, int N)    //COMPLETE
{
    int i = 0, j;
    ULONGLONG *sizes, tmp;

    sizes = (ULONGLONG*)malloc(N * sizeof(ULONGLONG));

    for (i; i < N; i++)
        sizes[i] = fileSize[i];


    for (i = 0; i < N; i++)
        for (j = N - 1; j > i; j--)
        {
            if (sizes[j - 1] > sizes[j])
            {
                Swap_ULONGLONG(&sizes[j - 1], &sizes[j]);
                Swap_Int(&filesNewIndex[j - 1], &filesNewIndex[j]);

            }
        }
    free(sizes);
}

void CountingSort(ULONGLONG *fileSize, int *filesNewIndex, int N) //COMPLETE
{
    int i = 0, j = 0, index = 0;
    int *fileIndex;
    long long *count, min, max;

    min = max = fileSize[0];

    for (i = 0; i < N; i++)
    {
        if (fileSize[i] < min)
            min = fileSize[i];
        if (fileSize[i] > max)
            max = fileSize[i];
    }

    count = (long long*)malloc((max - min + 1) * sizeof(long long));
    fileIndex = (int*)malloc((max - min + 1) * sizeof(int));

    for (i = 0; i < (max - min + 1); i++)
        count[i] = fileIndex[i] = 0;

    for (i = 0; i < N; i++)
    {
        count[(int)fileSize[i] - (int)min]++;
        fileIndex[(int)fileSize[i] - (int)min] = filesNewIndex[i];
    }

    for (i = 0; i < (max - min + 1); i++)
        for (j = 0; j < count[i]; j++)
            filesNewIndex[index++] = fileIndex[i];

    free(fileIndex);
    free(count);
}

void QuickSort(ULONGLONG *fileSize, int first, int last)
{
    int midIndex, i = first, j = last;

    midIndex = (first + last) / 2;

    QuickSplit(fileSize, &i, &j, fileSize[midIndex]);

    if (j > first) 
        QuickSort(fileSize, first, j);
    if (i < last)
        QuickSort(fileSize, i, last);
}

void MergeSort(float array[], int first, int last)
{
    int midIndex;
    midIndex = (last + first) / 2;

    if (first >= last)
        return;

    MergeSort(array, first, midIndex);
    MergeSort(array, midIndex + 1, last);
    Merge(array, first, midIndex, last);
}

void TypeSort(int *tSort)
{
    do
    {
        printf("\n Choose the type of sorting, please:\n 1. BubbleSort.\n 2. InsertionSort\n "
               "3. SelectionSort\n 4. CountingSort\n 5. QuickSort\n 6. MergeSort\n "
               "Enter only the number of sorting (If you want to close the program, enter 0 (zero)): ");
        scanf("%d", tSort);
    } while ((*tSort < 0) || (*tSort > 6));
}

int ListDirectoryContents(const wchar_t *sDir, wchar_t **filesName, ULONGLONG *filesSize)
{
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    wchar_t *sPath;
    int count = 0;

    sPath = (wchar_t*)malloc(SIZE_OF_BUFFER * sizeof(wchar_t));

    wsprintf(sPath, L"%s\\*.*", sDir);
    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
    {
        wprintf(L"Path not found: [%s]\n", sDir);
        return -1;
    }

    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            ULONGLONG fileSize = fdFile.nFileSizeHigh;
            fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
            fileSize |= fdFile.nFileSizeLow;
            filesSize[count] = fileSize;

            filesName[count] = (wchar_t*)malloc(SIZE_OF_BUFFER * sizeof(wchar_t));
            wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
            wsprintf(filesName[count++], L"%s", sPath);
        }
    } while (FindNextFile(hFind, &fdFile));
    FindClose(hFind);
    return count;
}

void InputDirectory(wchar_t **sDir)                     // Ввод пути
{
    char *inputString;

    *sDir = (wchar_t*)malloc(SIZE_OF_BUFFER * sizeof(wchar_t));
    inputString = (char*)malloc(SIZE_OF_BUFFER * sizeof(char));

    fgets(inputString, SIZE_OF_BUFFER, stdin);
    inputString[strlen(inputString) - 1] = '\0';        // Избавляемся от перевода строки

    swprintf(*sDir, SIZE_OF_BUFFER, L"%hs", inputString);
}

void OutputDirectory(wchar_t **filesName, ULONGLONG *filesSize, int *filesNewIndex, int N)
{
    int i;

    printf("\n Folder contents:\n");

    for (i = 0; i < N; i++)
        wprintf(L"%d. File: %s Size: %lld\n", i + 1, filesName[filesNewIndex[i]], filesSize[filesNewIndex[i]]);
}

void main()
{
    wchar_t *inputString, **filesName;
    ULONGLONG *filesSize;
    int *filesIndex, *filesNewIndex;
    int typeOfSort = 0, count = 0, i = 0;

    filesName = (wchar_t**)malloc(MAX_COUNT_OF_FILES * sizeof(wchar_t*));
    filesSize = (ULONGLONG*)malloc(MAX_COUNT_OF_FILES * sizeof(ULONGLONG));

    printf("\n ###################### \"File manager\" ######################\n");
    printf("\n Enter the path to the folder in which you want to sort the files: ");

    InputDirectory(&inputString);
    count = ListDirectoryContents(inputString, filesName, filesSize);
    
    if (count == -1) return;

    filesIndex = filesNewIndex = (int*)malloc(count * sizeof(int));
    for (i = 0; i < count; i++)
        filesIndex[i] = filesNewIndex[i] = i;

    OutputDirectory(filesName, filesSize, filesIndex, count);
    
    do
    {
        TypeSort(&typeOfSort);
        printf("\n Starting...\n Type of sort - %d. Count of files - %d.\n", typeOfSort, count);
      
        switch (typeOfSort)
        {
        case 1:
            BubbleSort(filesSize, filesNewIndex, count);
            break;
        case 2:
            InsertionSort(filesSize, filesNewIndex, count);
            break;
        case 3:
            SelectionSort(filesSize, filesNewIndex, count);
            break;
        case 4:
            CountingSort(filesSize, filesNewIndex, count);
            break;
        }

        OutputDirectory(filesName, filesSize, filesNewIndex, count);   

        for (i = 0; i < count; i++)         // Возвращение прежних индексов для новой сортировки
            filesNewIndex[i] = i;

    } while (typeOfSort != 0);


}