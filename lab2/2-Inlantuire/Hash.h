#ifndef HASH_H
#define HASH_H

typedef struct Nod_lista {
    int cheie;
    struct Nod_lista *next, *prev;
} Nod_lista;

typedef struct Lista {
    Nod_lista *head;
} Lista;

/** Initialize the hash table */  
void hashInit(Lista** hashTable, int size);

/** Hash function to calculate the index for a given key */ 
int hashFunction(int key, int size);

/** Insert a key into the hash table using chaining */ 
int listInsert(Lista* hashTable, int key, int size);

/** Insert a key into the hash table (wrapper function) */ 
int chainedHashInsert(Lista* hashTable, int key, int size);

/** Search for a key in the hash table */ 
int chainedHashSearch(Lista* hashTable, int key, int size);

/** Delete a key from the hash table */ 
int chainedHashDelete(Lista* hashTable, int key, int size);

/** Print the contents of the hash table */ 
void printHashtable(Lista* hashTable, int size);

#endif // HASH_H
