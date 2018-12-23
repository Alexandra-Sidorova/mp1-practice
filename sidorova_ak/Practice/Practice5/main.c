#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX_COUNT_OF_FILES 65535
#define SIZE_OF_BUFFER 2048

void InputDirectory(wchar_t **sDir)                                       
{
    char *inputString;

    *sDir = (wchar_t*)malloc(SIZE_OF_BUFFER * sizeof(wchar_t));
    inputString = (char*)malloc(SIZE_OF_BUFFER * sizeof(char));

    fgets(inputString, SIZE_OF_BUFFER, stdin);
    inputString[strlen(inputString) - 1] = '\0';                    // Избавляемся от перевода строки в конце

    swprintf(*sDir, SIZE_OF_BUFFER, L"%hs", inputString);
}

void OutputDirectory(wchar_t **filesName, ULONGLONG *filesSize, unsigned long *filesIndex, unsigned long N,
    int ascDescType)
{
    unsigned long i;

    printf("\n Folder contents:\n");

    if (ascDescType == 1)
        for (i = 0; i < N; i++)
            wprintf(L" %d. File: %s Size: %lld bytes\n", i + 1, filesName[filesIndex[i]], filesSize[filesIndex[i]]);
    else
        for (i = N; i > 0; i--)
            wprintf(L" %d. File: %s Size: %lld bytes\n", N - i + 1, filesName[filesIndex[i - 1]], filesSize[filesIndex[i - 1]]);
}

int ListDirectoryContents(const wchar_t *sDir, wchar_t **filesName, ULONGLONG *filesSize)
{
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    wchar_t *sPath;
    unsigned long count = 0;

    sPath = (wchar_t*)malloc(SIZE_OF_BUFFER * sizeof(wchar_t));
    wsprintf(sPath, L"%s\\*.*", sDir);

    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
    {
        wprintf(L"Path not found: [%s].\n Try again: ", sDir);
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

void TypeSort(int *tSort, int *ascDescTSort)
{
    do
    {
        printf("\n Choose the type of sorting, please:\n 1. BubbleSort\n 2. InsertionSort\n "
            "3. SelectionSort\n 4. CountingSort (ATTENTION! Not recommended for huge difference between sizes!\n "
            "5. QuickSort\n 6. MergeSort\n Enter only the number of sorting"
            "(If you want to close the program, enter 0 (zero)) : ");
        scanf("%d", tSort);
    } while ((*tSort < 0) || (*tSort > 6));

    do
    {
        printf("\n Choose the type of sorting:\n 1. Ascending\n 2. Descending\n Enter only the number of sorting: ");
        scanf("%d", ascDescTSort);
    } while ((*ascDescTSort < 1) || (*ascDescTSort > 2));
}

void Swap_Ulong(unsigned long *a, unsigned long *b)
{
    unsigned long tmp;

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

void QuickSplit(ULONGLONG *filesSize, unsigned long *i, unsigned long *j, ULONGLONG mid, unsigned long *filesIndex)
{
    do
    {
        while (filesSize[*i] < mid)
            (*i)++;
        while (filesSize[*j] > mid)
            (*j)--;

        if (*i <= *j)
        {
            Swap_ULONGLONG(&(filesSize[*i]), &(filesSize[*j]));
            Swap_Ulong(&(filesIndex[*i]), &(filesIndex[*j]));

            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void Merge(ULONGLONG *filesSize, unsigned long *filesIndex, unsigned long first, unsigned long midIndex, unsigned long last)
{
    unsigned long i = first, j = midIndex + 1, step;
    unsigned long *tmpIndex = (unsigned long*)malloc((last - first + 1) * sizeof(unsigned long));
    ULONGLONG *tmp = (ULONGLONG*)malloc((last - first + 1) * sizeof(ULONGLONG));

    for (step = 0; step < last - first + 1; step++)
        if ((j > last) || ((i <= midIndex) && (filesSize[i] < filesSize[j])))
        {
            tmp[step] = filesSize[i];
            tmpIndex[step] = filesIndex[i++];
        }
        else
        {
            tmp[step] = filesSize[j];
            tmpIndex[step] = filesIndex[j++];
        }

    for (step = first; step < last + 1; step++)
    {
        filesSize[step] = tmp[step - first];
        filesIndex[step] = tmpIndex[step - first];
    }

    free(tmp);
    free(tmpIndex);
}

void BubbleSort(ULONGLONG *filesSize, unsigned long *filesIndex, unsigned long N)
{
    unsigned long i, j;

    for (i = 0; i < N; i++)
        for (j = N - 1; j > i; j--)
        {
            if (filesSize[j - 1] > filesSize[j])
            {
                Swap_ULONGLONG(&filesSize[j - 1], &filesSize[j]);
                Swap_Ulong(&filesIndex[j - 1], &filesIndex[j]);
            }
        }
}

void InsertionSort(ULONGLONG *filesSize, unsigned long *filesIndex, unsigned long N)
{
    long long i, j, tmpIndex;
    ULONGLONG tmp;

    for (i = 1; i < N; i++)
    {
        tmp = filesSize[i];
        tmpIndex = filesIndex[i];
        j = i - 1;

        while ((j >= 0) && (filesSize[j] > tmp))
        {
            filesSize[j + 1] = filesSize[j];
            filesIndex[j + 1] = filesIndex[j];
            j--;
        }

        filesSize[j + 1] = tmp;
        filesIndex[j + 1] = tmpIndex;
    }
}

void SelectionSort(ULONGLONG *filesSize, unsigned long *filesIndex, unsigned long N)
{
    unsigned long i, j, keyIndex, keyNewIndex;
    ULONGLONG key;

    for (i = 0; i < N; i++)
    {
        key = filesSize[i];
        keyIndex = i;
        keyNewIndex = filesIndex[i];

        for (j = i + 1; j < N; j++)
        {
            if (filesSize[j] < key)
            {
                key = filesSize[j];
                keyIndex = j;
            }
        }

        Swap_ULONGLONG(&filesSize[keyIndex], &filesSize[i]);
        Swap_Ulong(&filesIndex[i], &filesIndex[keyIndex]);
    }
}

void CountingSort(ULONGLONG *filesSize, unsigned long *filesIndex, unsigned long N)
{
    unsigned long i = 0, j = 0, index = 0, diff = 0, k = 0;
    unsigned long *fileIndex;
    ULONGLONG **count, min, max;
    int repeatCount = 0, maxRepeatCount = 0;

    min = max = filesSize[0];

    for (i = 0; i < N; i++)
    {
        if (filesSize[i] < min)
            min = filesSize[i];
        if (filesSize[i] > max)
            max = filesSize[i];
    }

    for (i = 0; i < N; i++)
    {
        repeatCount = 0;

        for (j = i + 1; j < N; j++)
        {
            if (filesSize[i] == filesSize[j])
                repeatCount++;
        }
        
        if (repeatCount > maxRepeatCount)
            maxRepeatCount = repeatCount;
    }

    diff = max - min + 1;
    count = (ULONGLONG**)malloc(diff * sizeof(ULONGLONG*));
    for (i = 0; i < diff; i++)
        count[i] = (ULONGLONG*)malloc((maxRepeatCount + 1) * sizeof(ULONGLONG));
    for (i = 0; i < diff; i++)
        for (j = 0; j < (maxRepeatCount + 1); j++)
            count[i][j] = 0;

    for (i = 0; i < N; i++)
    {
        count[filesSize[i] - min][0]++;
        count[filesSize[i] - min][(int)count[filesSize[i] - min][0]] = filesIndex[i];
    }

    for (i = 0; i < diff; i++)
        for (j = 0; j < (count[i][0] + 1); j++)
            if (j!= 0) filesIndex[k++] = count[i][j];

    free(count);
}

void QuickSort(ULONGLONG *filesSize, unsigned long *filesIndex, unsigned long first, unsigned long last)
{
    unsigned long midIndex, i = first, j = last;

    midIndex = (first + last) / 2;

    QuickSplit(filesSize, &i, &j, filesSize[midIndex], filesIndex);

    if (j > first)
        QuickSort(filesSize, filesIndex, first, j);
    if (i < last)
        QuickSort(filesSize, filesIndex, i, last);
}

void MergeSort(ULONGLONG *filesSize, unsigned long *filesIndex, unsigned long first, unsigned long last)
{
    unsigned long midIndex = (last + first) / 2;

    if (first >= last)
        return;

    MergeSort(filesSize, filesIndex, first, midIndex);
    MergeSort(filesSize, filesIndex, midIndex + 1, last);
    Merge(filesSize, filesIndex, first, midIndex, last);
}

void main()
{
    wchar_t *filesPath, **filesName;
    ULONGLONG *filesSize, *tmpSizes;
    clock_t start, finish;
    unsigned long *filesIndex;
    unsigned long count = -1, i = 0;
    int typeOfSort = 0, ascDescType = 1, f = 0;

    filesName = (wchar_t**)malloc(MAX_COUNT_OF_FILES * sizeof(wchar_t*));
    filesSize = (ULONGLONG*)malloc(MAX_COUNT_OF_FILES * sizeof(ULONGLONG));

    printf("\n ###################### \"File manager \"Quick sort\"\" ######################\n");
    printf("\n Enter the path to the folder in which you want to sort the files: ");

    while (count == -1)
    {
        InputDirectory(&filesPath);
        count = ListDirectoryContents(filesPath, filesName, filesSize);
    }

    filesIndex = (unsigned long*)malloc(count * sizeof(unsigned long));
    for (i = 0; i < count; i++)
        filesIndex[i] = i;

    OutputDirectory(filesName, filesSize, filesIndex, count, 1);

    do
    {
        TypeSort(&typeOfSort, &ascDescType);
        if (typeOfSort == 0) return;

        tmpSizes = (ULONGLONG*)malloc(count * sizeof(ULONGLONG));           // Выделение доп. памяти для
        for (i = 0; i < count; i++)                                         // сохранения и изменения размеров файлов
            tmpSizes[i] = filesSize[i];

        printf("\n Starting...\n Type of sort - %d.", typeOfSort);
        if (ascDescType == 1) printf(" Ascending. Count of files - %d.\n", count);
        else printf(" Descending. Count of files - %d.\n", count);       

        start = clock();

        switch (typeOfSort)
        {
        case 1:
            BubbleSort(tmpSizes, filesIndex, count);
            break;
        case 2:
            InsertionSort(tmpSizes, filesIndex, count);
            break;
        case 3:
            SelectionSort(tmpSizes, filesIndex, count);
            break;
        case 4:
            CountingSort(tmpSizes, filesIndex, count);
            break;
        case 5:
            QuickSort(tmpSizes, filesIndex, 0, (count - 1));
            break;
        case 6:
            MergeSort(tmpSizes, filesIndex, 0, (count - 1));
            break;
        }

        finish = clock();

        OutputDirectory(filesName, filesSize, filesIndex, count, ascDescType);
        
        printf("\n Time: %.4lf sec.\n", (double)(finish - start) / CLOCKS_PER_SEC);

        for (i = 0; i < count; i++)         // Возвращение прежних индексов для новой сортировки
            filesIndex[i] = i;
        start = finish = 0;
        free(tmpSizes);
    } while (1);
}