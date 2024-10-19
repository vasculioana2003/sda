#include <stdio.h>
#include "ArrayList.h"

// Funcția de inserare la o poziție specificată
void INSERT(ArrayList* list, int data, int position) {
    if (position < 0 || position > list->size || list->size == MAX_SIZE) {
        printf("Inserare invalidă\n");
        return;
    }
    
    for (int i = list->size; i > position; i--) {
        list->elements[i] = list->elements[i - 1];
    }
    list->elements[position] = data;
    list->size++;
}

// Funcția care returnează prima poziție care conține data dorită
int LOCATE(ArrayList* list, int data) {
    for (int i = 0; i < list->size; i++) {
        if (list->elements[i] == data) {
            return i;
        }
    }
    return -1; // Indică că elementul nu a fost găsit
}

// Funcția care returnează elementul de la o poziție dată
int RETRIEVE(ArrayList* list, int position) {
    if (position >= 0 && position < list->size) {
        return list->elements[position];
    }
    return -1; // Indică eroare
}

// Funcția care șterge un element de la o poziție dată
void DELETE(ArrayList* list, int position) {
    if (position < 0 || position >= list->size) {
        printf("Ștergere invalidă\n");
        return;
    }
    
    for (int i = position; i < list->size - 1; i++) {
        list->elements[i] = list->elements[i + 1];
    }
    list->size--;
}

// Funcția care returnează poziția următoare
int NEXT(ArrayList* list, int position) {
    if (position >= 0 && position < list->size - 1) {
        return position + 1;
    }
    return -1; // Indică eroare
}

// Funcția care returnează poziția anterioară
int PREVIOUS(ArrayList* list, int position) {
    if (position > 0 && position < list->size) {
        return position - 1;
    }
    return -1; // Indică eroare
}

// Funcția care golește lista
void MAKENULL(ArrayList* list) {
    list->size = 0;
}

// Funcția care returnează prima poziție
int FIRST(ArrayList* list) {
    if (list->size > 0) {
        return 0;
    }
    return -1;
}

// Funcția care afișează lista
void PRINTLIST(ArrayList* list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->elements[i]);
    }
    printf("\n");
}
