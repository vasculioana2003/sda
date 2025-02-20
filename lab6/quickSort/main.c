#include <stdio.h>
#include "quickSort.h"

int main() {
    int n;
    printf("Introduceți lungimea array-ului: ");
    scanf("%d", &n);

    int array[n];
    printf("Introduceți elementele array-ului: ");
    read_array(array, n);

    printf("Array-ul inainte de sortare este: ");
    print_array(array, n);

    quick_sort(array, 0, n - 1);

    printf("Array-ul sortat este: ");
    print_array(array, n);

    return 0;
}