#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "myArray.c"

int RandomPartitionHoare(int A[], int lower_bound, int upper_bound);
int RandomPartitionLomuto(int A[], int lower_bound, int upper_bound);

void RandomQuickSort(int A[], int lower_index, int higher_index){
    if(lower_index < higher_index) {
        // int border = RandomPartitionHoare( A, lower_index, higher_index);
        // RandomQuickSort(A, lower_index, border);
        int border = RandomPartitionLomuto(A, lower_index, higher_index);
        RandomQuickSort(A, lower_index, border -1);
        RandomQuickSort(A, border +1, higher_index);
    }
}

int RandomPartitionHoare(int A[], int lower_bound, int upper_bound) {
    srand(time(0));
    int pivot = A[lower_bound + rand() % (upper_bound - lower_bound)];
    int i, j;
    i = lower_bound; j=upper_bound;
    while (1) {
        while (A[i] < pivot) 
            i++;
        while (A[j] > pivot)
            j--;
        if( j<=i ) 
            return j;
        swap(&A[i++], &A[j--]);
    }
}

int RandomPartitionLomuto(int A[], int lower_bound, int upper_bound) {
    srand(time(0));
    // int pivot = A[ lower_bound + rand() % (upper_bound - lower_bound)];
    swap(&A[upper_bound], &A[ lower_bound + rand() % (upper_bound - lower_bound)]);
    int pivot = A[upper_bound];
    int i, j;
    i=j= lower_bound;
    for(;j<upper_bound; j++){
        if(A[j] < pivot) {
            swap(&A[j], &A[i]);
            i++;
        }
    }
    swap(&A[i], &A[upper_bound]);
    return i;
}

int main()
{
    int A[] = {1, 34, 54, 3, 45, 2, 22, 36, 0}, size;
    size = sizeof(A) / sizeof(*A);
    // int B[] = {10, 5, 6, 20}; A[] = {1, 34, 54, 3, 45, 2, 22, 36, 0};
    // {0, 25, 16, 20}
    // printf("size %d \n",size);

    pArray(A, size);
    RandomQuickSort(A, 0, size - 1);
    pArray(A, size);
}