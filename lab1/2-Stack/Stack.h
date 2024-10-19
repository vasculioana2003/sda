#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct Stack {
    int top;
    int *data;
} Stack;

void initStack(Stack* stack, int size);

void freeStack(Stack* stack);

bool isEmpty(Stack stack);

void push(Stack* stack, int value);

int pop(Stack* stack);

void printStack(Stack stack);

#endif
