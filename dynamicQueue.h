#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    int size;
    Node *front;
    Node *rear;
} Queue;

void checkNull(void *ptr);
Queue * createQueue();
int isEmpty(Queue *q);
void enqueue(Queue *q, int value);
void display(Queue *q);
int dequeue(Queue *q);

#endif