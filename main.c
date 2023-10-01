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

void dequeue(Queue *q){
    if(isEmpty(q)){
        puts("Queue is empty\n");
    }
    else{
        Node *n = q->front;
        q->front = q->front->next;
        free(n);
    }
}

int main()
{
    Queue *q = createQueue();

    // testing
    
    for(int i = 1; i < 11; i++){
        enqueue(q, i*10);
    }

    display(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    enqueue(q, 210);
    enqueue(q, 3230);
    enqueue(q, 234);

    puts("\n");

    display(q);

    return 0;
}