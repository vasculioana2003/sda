#ifndef SLL_H
#define SLL_H

// Structura pentru un nod
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Structura pentru lista simplu înlănțuită
typedef struct {
    Node* head;
} SLL;

// Funcții
void INIT(SLL* list);
void INSERT(SLL* list, int data, Node* position);
Node* LOCATE(SLL* list, int data);
int RETRIEVE(SLL* list, Node* position);
void DELETE(SLL* list, Node* position);
Node* NEXT(SLL* list, Node* position);
Node* PREVIOUS(SLL* list, Node* position);
void MAKENULL(SLL* list);
Node* FIRST(SLL* list);
void PRINTLIST(SLL* list);

#endif // SLL_H




