#include <stdio.h>
#include <stdlib.h>
#include "SLL.h"

// Function to initialize the list
void INIT(SLL* list) {
    list->head = NULL;
}

// Funcția de inserare după un nod specificat
void INSERT(SLL* list, int data, Node* position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data; // Setarea datelor

    if (position == NULL) { // Inserare la început
        newNode->next = list->head;
        list->head = newNode;
    } else { // Inserare după un nod specificat
        newNode->next = position->next;
        position->next = newNode;
    }
}

// Funcția care returnează primul nod care conține data dorită
Node* LOCATE(SLL* list, int data) {
    Node* current = list->head;
    while (current != NULL && current->data != data) {
        current = current->next;
    }
    return current;
}

// Funcția care returnează datele dintr-o poziție
int RETRIEVE(SLL* list, Node* position) {
    if (position != NULL) {
        return position->data;
    }
    return -1; // Indică o eroare
}

// Funcția care șterge nodul de la o poziție dată
void DELETE(SLL* list, Node* position) { 
    if (list->head == NULL || position == NULL) return; // Verificare dacă lista este goală sau poziția este NULL

    if (list->head == position) { // Ștergere primul nod
        list->head = position->next;
        free(position);
        return;
    }

    Node* prev = list->head; // Ștergere nod din altă poziție
    while (prev->next != position) {
        prev = prev->next;
    }
    prev->next = position->next;
    free(position);
}

// Funcția care returnează următorul nod
Node* NEXT(SLL* list, Node* position) {
    if (position != NULL) {
        return position->next;
    }
    return NULL;
}

// Funcția care returnează nodul anterior
Node* PREVIOUS(SLL* list, Node* position) {
    if (list->head == NULL || position == list->head) return NULL;

    Node* current = list->head;
    while (current->next != position) {
        current = current->next;
    }
    return current;
}

// Funcția care golește lista
void MAKENULL(SLL* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
}

// Funcția care returnează primul nod
Node* FIRST(SLL* list) {
    return list->head;
}

// Funcția care afișează lista
void PRINTLIST(SLL* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
























//REFAC CODUL SINGURA
//INITIALIZEZ LISTA
// void INIT (SLL* list){
//     list->head==NULL;
// }


// //INSERAM UN NOD LA O POZITIE SPECIFICA
// void INSERT(SLL* list, int data, Node* position){
//     Node* newNode =(Node*)malloc(sizeof(Node));
//     newNode->data=data; 


//     if (position ==NULL){
//         newNode->next = list->head;
//         list->head = newNode;
//     }else{
//         newNode->next = position->next;
//         position->next = newNode;
//     }
// }

// //returneaza primul nod din lista care contine data specifica
// Node * LOCATE(SLL* list, int data){
//     Node* current= list-> head;
//     while( current != NULL && current->data != data){
//         current = current->next;
//     }
//     return current;
// }

// //functia care returneaza datele dintr o pozitie
// int RETRIEVE(SLL* list, Node* position){
//     if(position != NULL){
//         return position->data;
//     }
//     return -1;
// }

// void DELETE (SLL* list, Node* position){
//     if (list->head==NULL || position == NULL) return;

//     if (list->head == position){
//         list->head = position->next;
//         free(position);
//         return;
//     }
    
//     Node* prev = list->head;
//     while(prev->next != position){
//         prev = prev->next;
//     }
//     prev->next=position->next;
//     free (position);
// }


// Node* NEXT(SLL* list, Node* position){
//     if (position != NULL){
//         return position->next;
//     }
//     return NULL;
// }

// Node* PREVIOUS(SLL* list, Node* position){
//     if (list -> head == NULL || position ==list->head) return NULL;

//     Node* current = list-> head;
//     while(current->next != position){
//         current=current->next;
//     }
//     return current;
// }

// void MAKENULL(SLL* list){
//     Node* current = list->head;
//     while (current != NULLL){
//         Node* temp = current;
//         current= current->next;
//         free (temp);
//     }
//     list->head=NULL;
// }

// Node* FIRST(SLL* list){
//     return list->head;
// }

// void PRINTLIST(SLL* list){
//     Node* current=list->head;
//     while (current!=NULL){
//         printf("%d ->", current->data);
//         current=current->next;
//     }
//     printf("NULL\n");
// }