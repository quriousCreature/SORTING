#include <stdio.h>

#include "myArray.c"

int Partition_Lamuto(int A[], int lower_bound, int upper_bound);
int Partition(int A[], int lower_bound, int upper_bound);


void QuickSort(int A[], int lower_index, int higher_index)
{

    if (lower_index < higher_index)
    {
        // int border = Partition_Lamuto(A, lower_index, higher_index);
        // QuickSort(A, lower_index, border-1);
        int border = Partition(A, lower_index, higher_index);
        QuickSort(A, lower_index, border);
        QuickSort(A, border +1 , higher_index);
    }
}

int Partition(int A[], int lower_bound, int upper_bound)
{
    int i, j, pivot;
    pivot = A[(lower_bound + (upper_bound - lower_bound) / 2)];
    // pivot = A[upper_bound];
    i = lower_bound;
    j = upper_bound;

    while (1)
    {
        while (A[i] < pivot)
            i++;
        while (A[j] > pivot)
            j--;

        if (i >= j)
        {
            // if(pivot == A[i]) printf("Pivot index in I  A[%d]=%d  But J -- %d \n", i, pivot, j);
            // else if(pivot == A[j]) printf("Pivot index in J  A[%d]=%d  But I -- %d \n", j, pivot, i);
            // else printf("Pivot index in none :  I -- %d, j--%d, pivot--%d \n",  i, j, pivot);
            return j;
        }

        swap(&A[i++], &A[j--]);
    }

}



int Partition_Lamuto(int A[], int lower_bound, int upper_bound){
    int pivot = A[ lower_bound + (upper_bound-lower_bound) /2 ];
    // int pivot = A[upper_bound];
    int i, j;
    i = j = lower_bound;
    for(j=lower_bound; j<upper_bound; j++){
        if(A[j]<pivot) {
            swap(&A[i], &A[j]);
            i++;
            }

    }
    swap(&A[i], &A[upper_bound]);
    return i;
}

int main()
{
    int A[] = {10, 5, 6, 20}, size;
    size = sizeof(A) / sizeof(*A);
    // int B[] = {10, 5, 6, 20}; A[] = {1, 34, 54, 3, 45, 2, 22, 36, 0}
    // printf("size %d \n",size);

    pArray(A, size);
    QuickSort(A, 0, size - 1);
    pArray(A, size);
}