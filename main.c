#include "dynamicQueue.h"

int main()
{
    Queue *q = createQueue();

    // testing

    for(int i = 1; i < 11; i++){
        enqueue(q, i*10);
    }
    display(q);
    printf("\n%d\n",dequeue(q));
    display(q);
    return 0;
}