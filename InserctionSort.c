#include<stdio.h>

#include "myArray.c"

void insertionSort (int *arr, int size) {
    int key, j;
    for(int i = 1; i<size; i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1]= arr[j];
            --j;
        }
        arr[++j]=key; 
    }
}

int main(){
    int arr[]={1,34,54,3,45,2,22,36} ,size;
    size = sizeof(arr)/sizeof(*arr);
    // printf("size %d \n",size); 

    pArray(arr, size);
    insertionSort(arr, size);
    pArray(arr, size);
}