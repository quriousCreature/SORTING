#include<stdio.h>

#include "myArray.c"

// #define MIN (a,b) (a<b ? a : b)



void bubbleSort (int arr[], int size){
    for(int i=0; i<size-1; i++)
    for(int j=0; j<size-1; j++){
        if(arr[j]>arr[j+1]) SWAP(arr[j], arr[j+1])

    }
}

int main() {
    int arr[]={1,34,54,3,45,2,22,36} ,size;
    size = sizeof(arr)/sizeof(*arr);
    // printf("size %d \n",size); 
    pArray(arr, size);
    bubbleSort(arr, size);
    pArray(arr, size);
}