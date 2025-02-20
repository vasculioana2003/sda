#include <stdlib.h>
#include <stdio.h>
#include "heapSort.h"

int HEAP_SIZE = 0;
int left(int n) { return 2 * n + 1; } 
int right(int n) { return 2 * n + 2; }

void max_heapify(int array[], int n, int i) {
    int l = left(i); 
    int r = right(i);
    int largest = i;
    if (l < n && array[l] > array[largest]) { 
        largest = l;
    }
    if (r < n && array[r] > array[largest]) {
        largest = r;
    }
    if (largest != i) {
        int temp = array[i]; 
        array[i] = array[largest];
        array[largest] = temp;
        max_heapify(array, n, largest); 
    }
}
void build_max_heap(int array[], int n) {
    HEAP_SIZE = n;
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(array, n, i);
    }
}

void heap_sort(int array[], int n) {
    build_max_heap(array, n); 
    for (int i = n - 1; i >= 1; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        HEAP_SIZE--; 
        max_heapify(array, i, 0); 
    }
}
void read_array_heap(int array[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
}
void print_array_heap(int array[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
        if(i != n - 1) { 
            printf(", "); 
        }
    }
    printf("]\n");
}
