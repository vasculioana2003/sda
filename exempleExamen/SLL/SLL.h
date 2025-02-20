#ifndef SLL_H
#define SLL_H

// Structura pentru un nod
typedef struct Node {
    char caracter;
    struct Node* next;
} Node;

// Structura pentru lista simplu înlănțuită
typedef struct {
    Node* head;
} SLL;

// Funcții
void INIT(SLL* list);
void INSERT(SLL* list, char caracter, Node* position);
Node* NEXT(SLL* list, Node* position);
Node* FIRST(SLL* list);
void PRINTLIST(SLL* list);

#endif // SLL_H
