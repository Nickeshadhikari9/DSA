#include <stdio.h>
#define MaxSize 5
int queue[MaxSize];
int rear = -1;
int front = 0;
int item;
void enqueue()
{
    if (rear == MaxSize - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        rear = rear + 1;
        printf("enter item:");
        scanf("%d", &item);
        queue[rear] = item;
    }
}