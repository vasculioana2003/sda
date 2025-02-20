#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void initStack(Stack* stack, int size){
    stack->data = malloc(size * sizeof(int))
    stack->top = 0; //indica ca stiva e initial goala
}

void freeStack(Stack* stack){
    free(stack->data);
    stack->data = NULL;
    stack->top = -1;
}

bool isEmpty(Stack stack){
    return stack.top == 0;
}

void push(Stack* stack, int value){
    stack->data[stack->top] = value; 
    stack->top = stack->top + 1; 
}

int pop(Stack* stack){
    int e = stack->data[stack->top];
    stack->data[stack->top] = 0;
    stack->top = stack->top - 1;
    return e; 
}

void printStack(Stack stack){
    if(isEmpty(stack)){
        printf("stack is empty!\n");
        return;
    }
    for (int i = 0; i < stack.top; i++) {
        printf("%d ", stack.data[i]);
    }
    printf("\n");
}