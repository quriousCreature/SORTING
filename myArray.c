#include <stdio.h> 
  
#define SWAP(a,b) {\
    a^=b;\
    b^=a;\
    a^=b;\
    }

void swap(int *a,int *b) {
  int  temp;
  temp = *a;
  *a= *b;
  *b =temp; 
}

void pArray(int *arr, int size) {
    printf("[");
    for (int i=0; i<size; i++ )
        printf("  %d,", arr[i]);
    printf("] \n");
}

void CopyArray(int *src, int start, int end, int *dest) {
    while(start < end) {
        dest[start] = src[start]; 
        ++start;
    }
}