#ifndef DLL_H
#define DLL_H

/** Structura unui nod al listei dublu înlănțuite */
typedef struct Nod_lista {
    int cheie;
    struct Nod_lista *next;
    struct Nod_lista *prev;
} Nod_lista;

typedef struct Lista {
    /** Reprezinta pointerul catre primul nod al listei. */
    Nod_lista *head;
} Lista;
 

/** Functie care insereaza un nod in lista (list_insert) */
void addNode(Lista* lista, Nod_lista* nod);

/** Functie care cauta un nod in lista si returneaza adresa acestuia */
Nod_lista* listSearch(Lista lista, int cheie);

/** Functie care sterge un nod din lista (list_delete) */
void deleteNode(Lista* lista, Nod_lista* nod);

/** Functie care afiseaza elementele din lista */
void listPrint(Lista lista);

/** Functie care face lista goala */
void makeNull(Lista *lista);

/** Functie care elibereaza memoria pentru lista intreaga */
void listFree(Lista *lista);

#endif
