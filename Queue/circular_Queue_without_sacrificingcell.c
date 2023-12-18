#include <stdio.h>
#define MAX 5
int queue[MAX];
int rear;
int front;
int count = 0;
int choice;
void enqueue();
void dequeue();
void display();

int main()
{
    rear = MAX - 1;
    front = MAX - 1;
    printf("1.insert\n2.delete\n3.display\n4.exit\n");
    do
    {
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("exiting.....\n");
            break;
        default:
            printf("Enter a valid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

void enqueue()
{
    if (count == MAX)
    {
        printf("Queue is Full.\n");
    }
    else
    {
        rear = (rear + 1) % MAX;
        printf("Enter item to be inserted:");
        scanf("%d", &queue[rear]);
        count++;
    }
}

void dequeue()
{
    if (count == 0)
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        front = (front + 1) % MAX;
        printf("%d is deleted.\n", queue[front]);
        count--;
    }
}

void display()
{
    if (count == 0)
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        printf("Items in queue:\n");
        for (int i = 0; i < count; i++)
        {
            front = (front + 1) % MAX;
            printf("%d\t", queue[front]);
        }
        printf("\n");
    }
}
