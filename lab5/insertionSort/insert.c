#include <stdlib.h>
#include <stdio.h>
#include "insert.h"

void readArray(int A[], int n){
    for(int i=0; i<n; i++){
        printf("A[%d] = ", i+1);
        scanf("%d", &A[i]);
    }
}

void printArray(int A[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int A[], int n){
    for(int j=1; j<n; j++){
        int key =A[j]; 
        int i = j-1;
        while(i>=0 && A[i]>key){
            A[i+1] = A[i];
            i = i-1;
        }
        A[i+1] = key;
    }
}