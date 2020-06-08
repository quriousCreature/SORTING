#include <stdio.h>

#include "myArray.c"

int HoarePartitionLeft(int A[], int lowerbound, int upper_bound);
int HoarePartitionRight(int A[], int lowerbound, int upper_bound);

void QuickSortMod(int A[], int lower_index, int higher_index)
{

    if (lower_index < higher_index)
    {
        int border = HoarePartitionRight(A, lower_index, higher_index);
        QuickSortMod(A, lower_index, border -1);
        QuickSortMod(A, border , higher_index);
    }
}

int HoarePartitionRight(int A[], int lower_bound, int upper_bound)
{
    int pivot = A[upper_bound], i = lower_bound - 1, j = upper_bound + 1;
    while (1)
    {
        do
            j--;
        while (A[j] > pivot);
        do
            i++;
        while (A[i] < pivot);
        if (i < j)
            swap(&A[i], &A[j]);
        else
            return i;
    }
}

void QuickSort(int A[], int lower_index, int higher_index)
{

    if (lower_index < higher_index)
    {
        int border = HoarePartitionLeft(A, lower_index, higher_index);
        QuickSort(A, lower_index, border);
        QuickSort(A, border + 1, higher_index);
    }
}

int HoarePartitionLeft(int A[], int lower_bound, int upper_bound)
{
    int pivot = A[lower_bound], i = lower_bound - 1, j = upper_bound + 1;
    while (1)
    {
        do
            j--;
        while (A[j] > pivot);
        do
            i++;
        while (A[i] < pivot);
        if (i < j)
            swap(&A[i], &A[j]);
        else
            return j;
    }
}

int main()
{
    int A[] = {10, 5, 6, 20} , size;
    size = sizeof(A) / sizeof(*A);
    // int B[] = {10, 5, 6, 20}; A[] = {1, 34, 54, 3, 45, 2, 22, 36, 0};
    // {0, 25, 16, 20}
    // printf("size %d \n",size);

    pArray(A, size);
    QuickSortMod(A, 0, size - 1);
    pArray(A, size);
}