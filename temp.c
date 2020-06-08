#include<stdio.h>

void TopDownSplitMerge(int *arr2, int start, int end, int *arr1 ){
    if(end - start < 2) return ;

    int mid = (end + start)/2;

    TopDownSplitMerge(arr1, start, mid, arr2);
    TopDownSplitMerge(arr1, mid, end, arr2);
    printf("%d \n", arr1[start]);

    // TopDownMerge (arr2, start, mid, end, arr1);
}

int main() {
    int A[]={1,34,54} ,size;
    size = sizeof(A)/sizeof(*A);
    int B[]= {1,34,54};
    // printf("size %d \n",size); 

    // pArray(A, size);
    TopDownSplitMerge(A,0, size, B);
    // pArray(A, size);
}