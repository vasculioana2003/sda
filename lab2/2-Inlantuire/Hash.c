#include "Hash.h"
#include <stdio.h>
#include <stdlib.h>

void hashInit(int **hashTable, int size){
    *hashTable = (int *)malloc(size * sizeof(int));  // Allocate memory for hashTable
    if (*hashTable == NULL) {
        printf("Memory allocation failed\n");
        exit(1);  // Exit if malloc fails
    }
    for (int i = 0; i < size; i++) {
        (*hashTable)[i] = -1;
    }
}

int hashPrime(int key, int size){
    return key % size;
}

int hashProbe(int key, int index, int size){
    return (hashPrime(key, size) + index) % size;
}

int hashInsert(int *hashTable, int key, int size){
    int i = 0;
    do {
        int j = hashProbe(key, i, size);
        if (hashTable[j] == -1) {
            hashTable[j] = key;
            return j;
        }
        i++;
    } while (i != size);

    printf("Hash table is full\n");
    return -1;
}

int hashSearch(int *hashTable, int key, int size){
    int i = 0;
    do {
        int j = hashProbe(key, i, size);
        if (hashTable[j] == key) {
            return j;
        }
        i++;
    } while (i != size && hashTable[i] != -1);
    return -1;
}

int hashDelete(int *hashTable, int key, int size){
    int j = hashSearch(hashTable, key, size);
    if (j > -1) {
        hashTable[j] = -1;
        return j;
    }
    return -1;
}

void hashPrint(int *hashTable, int size){
    for (int j = 0; j < size; j++) {
        printf("%d ", hashTable[j]);
    }
    printf("\n");
}
