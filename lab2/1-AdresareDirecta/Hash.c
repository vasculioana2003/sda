#include "Hash.h"
#include <stdio.h>
#include <stdlib.h>


//Nu ai avut nevoie de ** până acum pentru că:
// În liste (SLL, DLL), cozi (Queue), stive (Stack), ArrayList, pointerul spre date era deja parte dintr-o structură de date.
// Funcțiile doar modificau conținutul structurilor, nu adresa pointerului principal.
// La hashInit(), trebuie să modifici direct adresa unui pointer din main(), deci ai nevoie de **


// int **hashTable (folosit în hashInit): Folosim ** pentru că vrem să modificăm adresa la care hashTable indică (adică să schimbăm pointerul original).
// int *hashTable (folosit în hashInsert): Folosim * pentru că doar vrem să manipulăm valorile din tabelul hash la adresa la care hashTable indică deja, fără să schimbăm pointerul.




void hashInit(int **hashTable, int size){//am nevoie de valoarea de la locatia unde arata hashTable
    *hashTable = (int *)malloc(size * sizeof(int));  //*hashTable e folosit pt dereferentiere (din pointer la pointer cum e declarat mai sus il facem un pointer la int--acest pointer va pastra adresa alocata de maloc)
    for (int i = 0; i < size; i++) {
        (*hashTable)[i] = -1; //tot dereferntiaza
    }
}


//de exemplu daca size=10 si key=15, 15%10=5-->returneaza 5(verifica unde se va insera cheia)
int hashPrime(int key, int size){
    return key % size;
}

//daca size=10 index=3, key=15, 15%10=5, 5+3=8, 8%10=8(verifica unde se va insera cheia)
int hashProbe(int key, int index, int size){
    return (hashPrime(key, size) + index) % size;
}

int hashInsert(int *hashTable, int key, int size){
    for(int i=0;i<size;i++){
        int j = hashProbe(key, i, size);
        //verificam daca locatia e libera
        if (hashTable[j] == -1) {
            hashTable[j] = key;
            return j; //returnam indexul unde a fost inserat
        }
    }
    printf("Hash table is full\n");
    return -1; 
}

int hashSearch(int *hashTable, int key, int size){
    for (int i = 0; i < size && hashTable[i] != -1; i++){
        int j = hashProbe(key, i, size);
        if (hashTable[j] == key) {
            return j;
        }
    }
    printf ("elementul nu a fost gasit\n");
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

















