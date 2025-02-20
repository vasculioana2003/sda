#include <stdio.h>
#include "quickSort.h"

void quick_sort(int array[], int p, int r) {
    if (p < r) {
        int q = partition(array, p, r);
        quick_sort(array, p, q - 1);
        quick_sort(array, q + 1, r);
    }
}

int partition(int array[], int p, int r) {
    int x = array[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (array[j] <= x) {
            i++;
            // Schimbăm elementele array[i] și array[j]
            int aux = array[i];
            array[i] = array[j];
            array[j] = aux;
        }
    }
    // Schimbăm elementele array[i + 1] și array[r]
    int aux = array[i + 1];
    array[i + 1] = array[r];
    array[r] = aux;
    return i + 1;
}

void read_array(int array[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
}

void print_array(int array[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
        if(i != n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}