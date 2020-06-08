#include<stdio.h>

#include "myArray.c"


void selectionSort(int *arr, int size){
    int i,j,min;
    min=i=j=0;
    
    while(i<size){
        min=j=i;
        while(j<size){
            if(arr[min]> arr[j]) min = j;
            j++;
        }
        
        swap(&arr[min], &arr[i]);
        i++;
    }
}

int main(){
    int arr[]={1,34,54,3,45,2,22,36} ,size;
    size = sizeof(arr)/sizeof(*arr);
    // printf("size %d \n",size); 

    pArray(arr, size);
    selectionSort(arr, size);
    pArray(arr, size);
}