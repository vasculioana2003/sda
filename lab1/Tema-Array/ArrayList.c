#include <stdio.h>
#include "ArrayList.h"

// Funcția de inserare la o poziție specificată
void INSERT(ArrayList* list, int data, int position) {
    if (position < 0 || position > list->size || list->size == MAX_SIZE) {
        printf("Inserare invalidă\n");
        return;
    }
    //Se parcurge lista de la dreapta la stânga, începând de la list->size până la position + 1
    for (int i = list->size; i > position; i--) { 
        list->elements[i] = list->elements[i - 1];//Fiecare element este mutat cu o poziție spre dreapta, pentru a elibera spațiu la poziția position
    }
    list->elements[position] = data;
    list->size++;
}

//Caută un element într-o listă și returnează poziția sa
int LOCATE(ArrayList list, int data) {
    for (int i = 0; i < list.size; i++) {
        if (list.elements[i] == data) {
            return i; 
        }
    }
    return -1; // Indică că elementul nu a fost găsit
}

//returnează elementul de pe poziția specificată
int RETRIEVE(ArrayList list, int position) {
    if (position >= 0 && position < list.size) {
        return list.elements[position];
    }
    return -1; // Indică eroare
}

void DELETE(ArrayList* list, int position) {
    if (position < 0 || position >= list->size) { //">=" deoarece nu poti sterge elemntul 5 intr un vector de 5 [0 1 2 3 4]
        printf("Ștergere invalidă\n");
        return;
    }
    for (int i = position; i < list->size - 1; i++) { //trebuie să ne oprim la penultimul element (size - 2), ca să copiem ultimul 
        list->elements[i] = list->elements[i + 1]; //i merge până la penultimul element (list->size - 2), pentru că accesăm list->elements[i + 1], iar i + 1 trebuie să rămână în limitele array-ului
    }
    list->size--;
}

int NEXT(ArrayList list, int position) {
    if (position >= 0 && position < list.size - 1) { //merge pana la penultimul element adica list->size - 2 deoarece este folosit "<" si nu "<="!!!!!
        return position + 1;
    }
    return -1; // Indică eroare
}
int PREVIOUS(ArrayList list, int position) {
    if (position > 0 && position < list.size) {//merge de la al doilea element adica de la 1 pana la ultimul element adica list->size - 1
        return position - 1;
    }
    return -1; // Indică eroare
}

void MAKENULL(ArrayList* list) {
    list->size = 0;
}
int FIRST(ArrayList list) {
    if (list.size > 0) return 0;  //returneaza 0 deoarece primul element este pe pozitia 0
    return -1;
}
void PRINTLIST(ArrayList list) {
    for (int i = 0; i < list.size; i++) {
        printf("%d ", list.elements[i]);
    }
    printf("\n");
}
