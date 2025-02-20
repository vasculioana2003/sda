#include <stdio.h>
#include <stdlib.h>
#include "DLL.h"

void addNode(Lista* lista, Nod_lista* nod) {
    if (nod == NULL) { return; }
    if (lista->head == NULL) {
        lista->head = nod; //
        return;
    }
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
    while (current != NULL) {
        printf("%d ", current->cheie);
        current = current->next;
    }
    printf("\n");
}

void deleteNode(Lista* lista, Nod_lista* nod) {
    if(nod->prev != NULL) { 
        nod->prev->next = nod->next; 
    } else { 
        lista->head = nod->next;
    }
    if(nod->next != NULL) { 
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
        free(current); //free is a function that deallocates memory
        current = next;
    }
    lista->head = NULL;
}




































typedef struct Nod_lista{
    int cheie;
    struct Nod_lista* next;
    struct Nod_lista* prev;
}Nod_lista;

typedef struct Lista{
    Nod_lista* head;
}Lista;



void addNode(Lista* lista, Nod_lista* nod){
    if (nod==NULL) return;

    if (lista->head==NULL){
        lista->head=nod;
        return;
    }

    Nod_lista* current = lista->head;
    while (current != NULL){
        current= current->next;
    }
    current->next=nod;
    nod->prev=current;
}




void PrintLista(Lista lista){
    printf ("LISTA:");
    Nod_lista* current = lista.head;
    if(current == NULL){
        printf("Lista e vida:\n");
        return;
    }
    while(current != NULL){
        printf("%d", current->cheie);
        current=current->next;
    }
    prinf("\n");
}

void deleteNode(Lista* lista, Nod_lista* nod){
    if(nod->prev!=NULL){
        nod->prev->next=nod->next;
    } else{
        lista->head=nod->next;
    }
    if (nod->next != NULL){
        nod->next->prev=nod->prev;
    }
}


Nod_lista* listSearch(Lista lista, int cheie){
    Nod_lista* current= lista.head;
    while(current != NULL){
        if(current->cheie == cheie){
            return current;
        }
        current=current->next;
    }
    return NULL;
}

void makeNull(Lista* lista){
    lista->head=NULL;
}

void listFree (Lista* lista){
    Nod_lista* current=lista->head;
    Nod_lista* temp;

    while(current != NULL){
        temp=current->next;
        free(current);
        current = temp;
    }
    lista->head = NULL;
}