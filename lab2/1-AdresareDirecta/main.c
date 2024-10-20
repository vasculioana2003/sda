#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"

int main() {
    int *hashTable;
    int size;

    // Input the size of the hash table
    printf("Introduceți dimensiunea: ");
    scanf("%d", &size);

    // Initialize the hash table
    hashInit(&hashTable, size);

    // Insert numbers until 0 is entered
    printf("Introduceți numere până la citirea lui 0\n");
    int key = -1;  // Initialize key to something other than 0
    int j;
    while (key != 0) {
        printf("Introduceți cheie: ");
        scanf("%d", &key);
        if (key != 0) {  // Ensure key 0 is not inserted
            j = hashInsert(hashTable, key, size);
            if (j != -1) {
                printf("\nCheia inserată la locația %d\n", j);
            } else {
                printf("\nInserarea nu a reușit, tabela este plină.\n");
            }
        }
    }

    // Print the hash table
    hashPrint(hashTable, size);

    // Search for a key
    printf("Căutare cheie: ");
    scanf("%d", &key);
    j = hashSearch(hashTable, key, size);
    if (j > -1) {
        printf("Cheia a fost găsită la locația %d\n", j);
    } else {
        printf("Cheia NU a fost găsită\n");
    }

    // Delete a key
    printf("Ștergere cheie: ");
    scanf("%d", &key);
    j = hashDelete(hashTable, key, size);
    if (j > -1) {
        printf("Cheia ștearsă la locația %d\n", j);
    } else {
        printf("Cheia NU a fost ștearsă\n");
    }

    // Free the allocated memory
    free(hashTable);
    
    return 0;
}
