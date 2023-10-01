#include<stdio.h>
#include<stdlib.h>

void checkNull(void *ptr){
    if(NULL == ptr){
        puts("Memory not allocated");
        exit(EXIT_FAILURE);
    }
}

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    int size;
    Node *front;
    Node *rear;
} Queue;

Queue * createQueue(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    checkNull(q);
    Node *n = (Node *)malloc(sizeof(Node));
    checkNull(n);
    n->next = NULL;
    q->front = q->rear = n;
    q->size = 1;

    return q;
}

int main()
{

    return 0;
}