#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main() {
    Stack stack;
    int e = -1;
    initStack(&stack, 20);
    while (e != 0) {
        printf("Enter a number: ");
        scanf("%d", &e);
        push(&stack, e);
        printStack(stack);
    }
    while (!isEmpty(stack)) {
        pop(&stack);
        printStack(stack);
    }
    freeStack(&stack);
    printStack(stack);
    return 0;
}