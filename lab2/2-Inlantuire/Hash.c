#include "Hash.h"
#include <stdio.h>
#include <stdlib.h>

// Initialize hash table
void hashInit(Lista** hashTable, int size) {
    *hashTable = (Lista*)malloc(size * sizeof(Lista));  // Allocate memory for hashTable
    for (int j = 0; j < size; j++) {
        (*hashTable)[j].head = NULL;
    }
}




// Hash function
int hashFunction(int key, int size) {
    return key % size;
}





// Insert a node in the list (chaining)
int listInsert(Lista* hashTable, int key, int size) {
    Nod_lista* x = (Nod_lista*)malloc(sizeof(Nod_lista));
    if (x == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }
    x->cheie = key; // set the key value
    int index = hashFunction(key, size);
    
    // Insert at the beginning of the list
    x->next = hashTable[index].head;
    if (hashTable[index].head != NULL) {
        hashTable[index].head->prev = x;
    }
    x->prev = NULL;
    hashTable[index].head = x; 
    
    return index;
}




// Insert a key into the hash table
int chainedHashInsert(Lista* hashTable, int key, int size) {
    return listInsert(hashTable, key, size);
}




// Search for a key in the hash table
int chainedHashSearch(Lista* hashTable, int key, int size) {
    int j = hashFunction(key, size);
    Nod_lista* x = hashTable[j].head;

    while (x != NULL) {
        if (x->cheie == key) {
            return j;
        }
        x = x->next;
    }
    return -1;  // Key not found
}




// Delete a node from the list
void listDelete(Lista* hashTable, Nod_lista* x, int size) {
    if (x == NULL) return;  // Safety check: don't delete a NULL node

    // Update the previous node's next pointer
    if (x->prev != NULL) {
        x->prev->next = x->next;
    } else {
        int index = hashFunction(x->cheie, size); // Added to get the correct index
        hashTable[index].head = x->next;
    }
    if (x->next != NULL) {
        x->next->prev = x->prev;
    }
    free(x);
}

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



// Print the hash table
void printHashtable(Lista* hashTable, int size) {
    printf("\n");
    for (int j = 0; j < size; j++) {
        Nod_lista* x = hashTable[j].head;
        printf("Lista %d: ", j);
        while (x != NULL) {
            printf("%d ", x->cheie);
            x = x->next;
        }
        printf("\n");
    }
}



