#include<stdio.h>
#include<stdbool.h>

#include "myArray.c"

#define SHRINK 1.3
// #define SWAP(a,b) {\
//     a^=b;\
//     b^=a;\
//     a^=b;\
//     }


void combSort(int * arr, int size){
    int i,  gap = size;

    bool sorted = false;

    while(!sorted){
        gap /= SHRINK;
        if(gap <= 1){
            gap = 1;
            sorted = true;
        }
        i=0;
        while(i+gap < size){
            if( arr[i] > arr[i+gap]){
                SWAP(arr[i], arr[i+gap])
                sorted = false;
            }
            ++i;

        }
    }

}

int main() {
    int arr[]={1,34,54,3,45,2,22,36} ,size;
    size = sizeof(arr)/sizeof(*arr);
    // printf("size %d \n",size); 
    pArray(arr, size);
    combSort(arr, size);
    pArray(arr, size);
}