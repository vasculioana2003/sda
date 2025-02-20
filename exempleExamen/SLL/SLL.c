#include <stdio.h>
#include <stdlib.h>
#include "SLL.h"

void INIT(SLL* list) { list->head = NULL; }

void INSERT(SLL* list, char caracter, Node* position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->caracter = caracter;
    newNode->next = NULL;
    if (position == NULL) {
        if (list->head == NULL) {
            list->head = newNode;
        } else {
            Node* current = list->head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    } else {
        newNode->next = position->next;
        position->next = newNode;
    }
}

Node* NEXT(SLL* list, Node* position) {
    if (position != NULL) {
        return position->next;
    }
    return NULL;
}

void PRINTLIST(SLL* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%c -> ", current->caracter);
        current = current->next;
    }
    printf("NULL\n");
}
