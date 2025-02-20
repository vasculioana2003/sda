#include <stdio.h>
#include "heapSort.h"

int main() {
    int n;
    
    // Citirea lungimii array-ului
    printf("Introduceți lungimea array-ului: ");
    scanf("%d", &n);

    // Alocarea memoriei pentru array
    int array[n];
    
    // Citirea elementelor array-ului
    printf("Introduceți elementele array-ului: ");

    // Apelarea funcției de heapsort
    heap_sort(array, n);  

    // Afișarea array-ului sortat
    printf("Array-ul sortat este: ");
    print_array(array, n);

    return 0;
}
