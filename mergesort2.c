#include <stdio.h>

#include "myArray.c"

void Merge(int arr[], int start, int mid, int end) {
    int i, j, k;
    
    int n1 = mid-start+1, n2=end-mid;
    int Subarray_left[n1];
    int Subarray_right[n2];

    for(i=0,j=0; i<n1 || j<n2; i++,j++){
        i<n1 && (Subarray_left[i]= arr[start + i])  ;
        j<n2 && (Subarray_right[j] = arr[mid+j+1]) ;
    }
    i=j=0, k=start;
    while(k< start+n1+n2) {
        if(i<n1 && (Subarray_left[i] <= Subarray_right[j] || n2 <= j )) arr[k++] = Subarray_left[i++];
        else arr[k++] = Subarray_right[j++];
    }

}


void MergeSort(int arr[], int start, int end){
    if(start < end){
        int mid = start + (end - start)/2;

        MergeSort(arr, start, mid);
        MergeSort(arr, mid+1, end);

        Merge(arr, start, mid, end);
    }
}





int main() {
    int A[]={1,34,54,3,45,2,22,36, 5} ,size;
    size = sizeof(A)/sizeof(*A);
    int B[size] ;
    // printf("size %d \n",size); 

    pArray(A, size);
    MergeSort(A, 0, size-1);
    pArray(A, size);
}