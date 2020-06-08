#include<stdio.h>



#include "myArray.c"

void shellSort(int *arr, int size) {
int i, gap, j, key;
i = gap = size/2;

while(gap > 0){
    if ( i >= size) i = gap /=2;

    key = arr[i];
    j= i;
    while(j >= gap && key < arr[j-gap]) {
        arr[j] = arr[j-gap];
        j-=gap;
        
    }
    arr[j] = key;
    i++;
}

}

int main() {
    int arr[]={1,34,54,3,45,2,22,36} ,size;
    size = sizeof(arr)/sizeof(*arr);
    // printf("size %d \n",size); 

    pArray(arr, size);
    shellSort(arr, size);
    pArray(arr, size);
}