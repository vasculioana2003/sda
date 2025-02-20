#include <stdlib.h>
#include <stdio.h>
#include "merge.h"

void mergeSort(int A[], int p, int r){
    int q=0;
    if(p<r){
        q = (p+r)/2;
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        merge(A, p, q, r);
    }
}

void merge(int A[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int left[n1 + 1], right[n2 + 1];
    
    for (int i = 0; i < n1; i++) {
        left[i] = A[p + i]; 
    }
    for (int j = 0; j < n2; j++) {
        right[j] = A[q + 1 + j]; 
    }
    left[n1] = __INT_MAX__; 
    right[n2] = __INT_MAX__;
    
    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        if (left[i] <= right[j]) {
            A[k] = left[i];
            i++;
        } else {
            A[k] = right[j];
            j++;
        }
    }
}

void readArray(int A[], int n) {
    printf("Adaugati %d elemente: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
}

void printArray(int A[], int n){
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

}