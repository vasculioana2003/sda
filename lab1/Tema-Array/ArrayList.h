#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#define MAX_SIZE 100

// Structura pentru lista cu șir
typedef struct ArrayList {
    int elements[MAX_SIZE];
    int size;
} ArrayList;

// Funcții
void INSERT(ArrayList* list, int data, int position);
int LOCATE(ArrayList list, int data);
int RETRIEVE(ArrayList list, int position);
void DELETE(ArrayList* list, int position);
int NEXT(ArrayList list, int position);
int PREVIOUS(ArrayList list, int position);
void MAKENULL(ArrayList* list);
int FIRST(ArrayList list);
void PRINTLIST(ArrayList list);

#endif // ARRAYLIST_H

























