#include "Hash.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Lista* hashTable;  // Define the hash table (array of lists)
    int size;

    // Input the size of the hash table
    printf("Funcția de dispersie h(k)=k mod m\n");
    printf("Introduceți dimensiunea tabelei de dispersie: ");
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
            j = chainedHashInsert(hashTable, key, size);
            printf("\nCheia inserată la locația %d\n", j);
        }

        // Print the updated hash table
        printf("Tabela actualizată: \n");
        printHashtable(hashTable, size);
    }

    // Search for a key
    printf("Căutare cheie: ");
    scanf("%d", &key);
    j = chainedHashSearch(hashTable, key, size);
    if (j > -1) {
        printf("Cheia a fost găsită la locația %d\n", j);
    } else {
        printf("Cheia NU a fost găsită\n");
    }

    // Delete a key
    printf("Cheia pentru ștergere: ");
    scanf("%d", &key);
    j = chainedHashDelete(hashTable, key, size);
    if (j > -1) {
        printf("Cheia ștearsă de la locația %d\n", j);
        // Print the updated hash table
        printHashtable(hashTable, size);
    } else {
        printf("Cheia NU a fost găsită pentru ștergere\n");
    }

    // Free the allocated memory for hash table
    free(hashTable);

    return 0;
}
