#include "dynamicQueue.h"

void checkNull(void *ptr){
    if(NULL == ptr){
        puts("Memory not allocated");
        exit(EXIT_FAILURE);
    }
}

Queue * createQueue(){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    checkNull(q);
    q->front = q->rear = NULL;
    q->size = 0;

    return q;
}

int isEmpty(Queue *q){
    if(NULL == q->front)
        return 1;
    return 0;
}

void enqueue(Queue *q, int value){

    Node *n = (Node *)malloc(sizeof(Node));
    checkNull(n);
    n->data = value;
    n->next = NULL;

    if(isEmpty(q)){
        q->front = q->rear = n;
    }
    else{
        q->rear->next = n;
        q->rear = n;
    }
    q->size++;
}

void display(Queue *q){
    Node *ptr = q->front;

    while(NULL != ptr){
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
}

int dequeue(Queue *q){
    int signal = -1;
    if(isEmpty(q)){
        puts("Queue is empty\n");
        return signal;
    }
    else{
        Node *n = q->front;
        q->front = q->front->next;
        signal = n->data;
        free(n);

        return signal;
    }
}