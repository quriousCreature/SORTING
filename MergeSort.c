#include <stdio.h>

#include "myArray.c"


void TopDownMerge(int *src, int start, int mid, int end, int *dest);
void TopDownSplitMerge(int *arr2, int start, int end, int *arr1 );

void TopDownMergeSort(int A[], int B[], int size) {
    CopyArray(A, 0, size, B);
    TopDownSplitMerge(B, 0, size, A);
}

void TopDownSplitMerge(int *arr2, int start, int end, int *arr1 ){
    if(end - start < 2) return ;

    int mid = (end + start)/2;

    TopDownSplitMerge(arr1, start, mid, arr2);
    TopDownSplitMerge(arr1, mid, end, arr2);

    TopDownMerge (arr2, start, mid, end, arr1);
}

void TopDownMerge(int *src, int start, int mid, int end, int *dest) {
    int i = start, j = mid;

    for(int k = start; k < end; k++){
        if(i < mid && (j >= end || src[i] <= src[j])){
            dest[k] = src[i];
            ++i;
        } else {
            dest[k] = src [j];
            ++j;
        }
    }
}

int main() {
    int A[]={1,34,54,3,45,2,22,36, 0} ,size;
    size = sizeof(A)/sizeof(*A);
    int B[size] ;
    // printf("size %d \n",size); 

    pArray(A, size);
    TopDownMergeSort(A, B, size);
    pArray(A, size);
}