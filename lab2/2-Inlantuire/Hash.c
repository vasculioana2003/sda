#include "Hash.h"
#include <stdio.h>
#include <stdlib.h>

void hashInit(Lista** hashTable, int size) {
    *hashTable = (Lista*)malloc(size * sizeof(Lista)); 
    for (int j = 0; j < size; j++) {
        (*hashTable)[j].head = NULL;//olosim . (punct) în loc de -> deoarece (*hashTable)[j] este o structură, nu un pointer la structură
    }
}


int hashFunction(int key, int size) {
    return key % size;
}


int listInsert(Lista* hashTable, int key, int size) {
    Nod_lista* x = (Nod_lista*)malloc(sizeof(Nod_lista));
    if (x == NULL) { 
        printf("Memory allocation failed.\n");
        return -1;
    }
    x->cheie = key;
    int index = hashFunction(key, size);
    x->next = hashTable[index].head;//daca lista e goala, x->next va fi automat NULL
    if (hashTable[index].head != NULL) {
        hashTable[index].head->prev = x;
    }
    x->prev = NULL;
    hashTable[index].head = x; 
    return index;
}


int chainedHashInsert(Lista* hashTable, int key, int size) {
    return listInsert(hashTable, key, size);
}


int chainedHashSearch(Lista* hashTable, int key, int size) {
    int j = hashFunction(key, size);
    Nod_lista* x = hashTable[j].head;
    while (x != NULL) {
        if (x->cheie == key) { return j; }
        x = x->next;
    }
    return -1; 
}


//Șterge un nod dat dintr-o listă dublu înlănțuită(Primește direct un pointer x către nodul care trebuie șters)
void listDelete(Lista* hashTable, Nod_lista* x, int size) {
    if (x == NULL) return; 
    if (x->prev != NULL) {
        x->prev->next = x->next;
    } else {
        int index = hashFunction(x->cheie, size);
        hashTable[index].head = x->next;
    }
    if (x->next != NULL) {
        x->next->prev = x->prev;
    }
    free(x);
}


//Caută un nod în tabela hash și îl șterge(primeste cheia nodului)
int chainedHashDelete(Lista* hashTable, int key, int size) {
    int j = hashFunction(key, size);
    Nod_lista* x = hashTable[j].head;
    while (x != NULL) {
        if (x->cheie == key) {
            listDelete(hashTable, x, size);
            return j;
        }
        x = x->next;
    }
    return -1;
}


void printHashtable(Lista* hashTable, int size) {
    printf("\n");
    for (int j = 0; j < size; j++) {
        printf("Lista %d: ", j);
        Nod_lista* x = hashTable[j].head;
        while (x != NULL) {
            printf("%d ", x->cheie);
            x = x->next;
        }
        printf("\n");
    }
}



