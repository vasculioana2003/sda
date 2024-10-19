#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void initQueue(Queue* queue, int size){
    queue->head = 0;
    queue->tail = 0;
    queue->length = size;
    queue->data = (int*)malloc(size * sizeof(int));
}

void freeQueue(Queue* queue){
    queue->head = -1;
    queue->tail = -1;
    queue->length = 0;
    free(queue->data);
    queue->data = NULL;
}

void printQueue(Queue queue){
    if(isEmpty(queue)){
        printf("Queue is empty!\n");
        return;
    }
    for (int i=queue.head; i<(queue.head + queue.length - 1); i++){
        printf("%d ", queue.data[i]);
    }
    printf("\n");
}

bool isEmpty(Queue queue){
    return queue.head == queue.tail;
}

void enqueue(Queue* queue, int value){
    queue->data[queue->tail] = value;
    queue->length = queue->length + 1;
    if(queue->tail == queue->length){
        queue->tail = 1;
    }
    else {
        queue->tail = queue->tail + 1;
    }
}

int dequeue(Queue* queue){
    int e = queue->data[queue->head];
    queue->length = queue->length - 1;
    if (queue->head == queue->length){
        queue->head = 1;
    }
    else{
        queue->head = queue->head + 1;
    }
    return e;
}
