#include <stdio.h>
#include <stdlib.h>
#include "selection.h"

int main() {
    int n;
    printf("Introduceți numărul de elemente: ");
    scanf("%d", &n);

    int arr[n];
    readArray(arr, n);  
    printf("Inainte de sortare: ");
    printArray(arr, n);  
    selectionSort(arr, n);  
    printf("Dupa sortare: ");
    printArray(arr, n);  

    return 0;
}