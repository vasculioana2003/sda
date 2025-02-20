#include <stdlib.h>
#include <stdio.h>
#include "selection.h"

void readArray(int arr[], int n) {
    printf("Introduceți elementele vectorului: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { 
        int minIndex = i; 
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}