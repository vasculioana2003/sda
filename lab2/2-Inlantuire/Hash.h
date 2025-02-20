#ifndef HASH_H
#define HASH_H

typedef struct Nod_lista {
    int cheie;
    struct Nod_lista *next, *prev;
} Nod_lista;

typedef struct Lista {
    Nod_lista *head;
} Lista;

void hashInit(Lista** hashTable, int size);
int hashFunction(int key, int size);
int listInsert(Lista* hashTable, int key, int size);
int chainedHashInsert(Lista* hashTable, int key, int size);
int chainedHashSearch(Lista* hashTable, int key, int size);
int chainedHashDelete(Lista* hashTable, int key, int size);
void printHashtable(Lista* hashTable, int size);

#endif // HASH_H



