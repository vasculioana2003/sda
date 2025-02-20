#ifndef HASH_H
#define HASH_H

void hashInit(int **hashTable, int size);
int hashPrime(int key, int size);
int hashProbe(int key, int index, int size);
int hashInsert(int *hashTable, int key, int size);
int hashSearch(int *hashTable, int key, int size);
int hashDelete(int *hashTable, int key, int size);
void hashPrint(int *hashTable, int size);

#endif









