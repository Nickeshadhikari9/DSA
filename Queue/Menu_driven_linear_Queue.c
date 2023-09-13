#include<stdio.h>
#define MAX 100
int queue[MAX];
int rear=-1;
int front=0;
int choice,item,i;
void enqueue();
void dequeue();
void display();
void main(){
    printf("1.insert\n2.delete\n3.display\n4.exit\n");
     do{
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
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
            printf("exiting.....");
            break;
            default:
            printf("Enter a valid choice.\n");
            
        }
        
    }
    while(choice!=4);
}
void enqueue(){
    if(rear==MAX-1){
        printf("Queue is Full.\n");
    }
    else{
        rear++;
        printf("Enter item to be inserted:");
        scanf("%d",&queue[rear]);
    }
}
void dequeue(){
    if(rear<front){
        printf("Queue is Empty.\n");
    }
    else{
        printf("%d is deleted.\n",queue[front]);
        front++;
    }
}
void display(){
     if(rear<front){
        printf("Queue is Empty.\n");
    }
    else{
        for(i=front;i<=rear;i++){
            printf("%d\t",queue[i]);
        }
        printf("\n");
    }
}