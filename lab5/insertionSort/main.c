#include <stdio.h>
#include <stdlib.h>
#include "insert.h"

int main(){
    int n;
    printf("introduceti nr de elem al vect = ");
    scanf("%d", &n);
    int A[n];
    readArray(A, n);
    printf("Inainte de sortare: ");
    printArray(A, n);
    insertionSort(A, n);
    printf("Dupa sortare: ");
    printArray(A, n);
}