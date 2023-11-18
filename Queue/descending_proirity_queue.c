#include <stdio.h>
#define MAX 100

int queue[MAX];
int rear = -1;
int front = 0;
int choice, item, i;

void enqueue();
void dequeue();
void display();

int main()
{
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
    if (rear == MAX - 1)
    {
        printf("Queue is Full.\n");
    }
    else
    {
        rear++;
        printf("Enter item to be inserted:");
        scanf("%d", &queue[rear]);
    }
}

void dequeue()
{
    if (rear < front)
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        int largestIndex = front;
        for (i = front + 1; i <= rear; i++)
        {
            if (queue[i] > queue[largestIndex])
            {
                largestIndex = i;
            }
        }

        printf("%d is deleted.\n", queue[largestIndex]);

        for (i = largestIndex; i <= rear - 1; i++)
        {
            queue[i] = queue[i + 1];
        }

        rear--;
    }
}

void display()
{
    if (rear < front)
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        printf("Items in queue:\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}
