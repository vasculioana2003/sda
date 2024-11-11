#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

int main(){
    int n;
    printf("introduceti numarul de elemente al vectorului: ");
    scanf("%d", &n);

    int A[n];
    readArray(A, n);
    printf("Inainte de sortare: ");
    printArray(A, n);
    mergeSort(A, 0, n-1);
    printf("Dupa sortare: ");
    printArray(A, n);
    return 0;
}