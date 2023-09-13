#include <stdio.h>
#define MAX 5
int queue[MAX];
int rear,front;
int choice, item,i;
void enqueue();
void dequeue();
void display();

int main() {
    rear = MAX-1;
    front = MAX-1;
    printf("1.insert\n2.delete\n3.display\n4.exit\n");
    do {
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice) {
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

void enqueue() {
    if ((rear + 1) % MAX == front) {
        printf("Queue is Full.\n");
    } else {
        rear = (rear + 1) % MAX;
        printf("Enter item to be inserted:");
        scanf("%d", &queue[rear]);
    }
}

void dequeue() {
    if (front == rear) {
        printf("Queue is Empty.\n");
    } else {
        front = (front + 1) % MAX;
        printf("%d is deleted.\n", queue[front]);
        
    }
}

void display() {
    if (front == rear) {
        printf("Queue is Empty.\n");
    } else {
        printf("Items in queue:\n");
        for(i=(front+1)%MAX;i!=rear;i=(i+1)%MAX){
            printf("%d\t", queue[i]);
        }
        printf("%d\t",queue[rear]);
        printf("\n");
    }
}