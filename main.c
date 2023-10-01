#include<stdio.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    int size;
    Node *front;
    Node *rear;
} Queue;

int main()
{
    printf("Hello World");
    return 0;
}