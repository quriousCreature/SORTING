#include <stdio.h>

#include "myArray.c"

void BottomUpMerge(int src[], int start, int mid, int end, int dest[]);
int min(int a, int b){ return a<b ? a: b;}

void BottomUpMergeSort(int A[], int B[], int size){
    for(int width=1; width<size; width*=2){
        for(int i=0; i<size; i += 2*width) {
            BottomUpMerge(A, i, min(i+width, size), min(i+2*width, size), B);
        }
        CopyArray(B, 0, size, A);
    }


}

void BottomUpMerge(int src[], int start, int mid, int end, int dest[]){
    int i=start, j=mid, k;
    k=start;
    while(k < end){
        if(i<mid && (j>=end || src[i]<src[j])) dest[k++] = src[i++];
        else dest[k++] = src[j++];
    }
}


int main() {
    int A[]={1,34,54,3,45,2,22,36, 0} ,size;
    size = sizeof(A)/sizeof(*A);
    int B[size] ;
    // printf("size %d \n",size); 

    pArray(A, size);
    BottomUpMergeSort(A, B, size);
    pArray(A, size);
}