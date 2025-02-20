// This uses all lab6 sorting methods
#include <stdio.h>
#include "./quickSort/quickSort.h"
#include "./heapSort/heapSort.h"

int main() {
    int n;
     
    while(1){
        printf("\nIntroduceți metoda de sortare: \n");
        printf("1. Quick Sort\n");
        printf("2. Heap Sort\n");

        int metoda;
        scanf("%d", &metoda);

        printf("Introduceți lungimea array-ului: ");
        scanf("%d", &n);

        int array[n];
        printf("Introduceți elementele array-ului: ");

        switch(metoda){
            case 1:
                read_array(array, n);
                quick_sort(array, 0, n - 1);
                print_array(array, n);
                break;
            case 2:
                read_array_heap(array, n);
                heap_sort(array, n);
                print_array_heap(array, n);
                break;
            default:
                printf("Metoda de sortare nu există\n");
                break;
        }
    }
    return 0;
}