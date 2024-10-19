#include <stdio.h>
#include <stdlib.h>
#include "DLL.h"

// Add a node to the list
void addNode(Lista* lista, Nod_lista* nod) {
    if (nod == NULL) {  
        return;
    }
    if (lista->head == NULL) {
        lista->head = nod;
        return;
    }
    // Insert the new node after the last node
    Nod_lista* current = lista->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = nod;
    nod->prev = current;
}

void listPrint(Lista lista) {
    printf("Lista: ");
    Nod_lista* current = lista.head;

    if (current == NULL) {
        printf("Lista e vida\n");
        return;
    }

    // Traverse the list and print each node's key
    while (current != NULL) {
        printf("%d ", current->cheie);
        current = current->next;
    }
    printf("\n");
}

void deleteNode(Lista* lista, Nod_lista* nod) {
    if(nod->prev != NULL) { // daca NU suntem la inceputul listei (in Head)
        nod->prev->next = nod->next;
    } 
    else { // Daca suntem in Head
        lista->head = nod->next;
    }
    if(nod->next != NULL) { // daca NU suntem la sfarsitul listei
        nod->next->prev = nod->prev;
    }
}

Nod_lista* listSearch(Lista lista, int cheie) {
    Nod_lista* current = lista.head;
    while (current != NULL) {
        if (current->cheie == cheie) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void makeNull(Lista* lista) {
    lista->head = NULL;
}

void listFree(Lista* lista) {
    Nod_lista* current = lista->head;
    Nod_lista* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    lista->head = NULL;
}