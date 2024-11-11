#include <stdio.h>
#include <stdlib.h>
#include "selection.h"

int main() {
    int n;
    printf("Introduceți numărul de elemente: ");
    scanf("%d", &n);

    int arr[n];
    readArray(arr, n);  // Apelează funcția pentru citirea array-ului
    printf("Inainte de sortare: ");
    printArray(arr, n);  // Afișează array-ul introdus
    selectionSort(arr, n);  // Sortează array-ul
    printf("Dupa sortare: ");
    printArray(arr, n);  // Afișează array-ul sortat

    return 0;
}