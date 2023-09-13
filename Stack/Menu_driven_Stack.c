// Online C compiler to run C program online
#include <stdio.h>
int stack[100],choice,data,n,top=-1;
void main(){
    printf("Enter number of element in stack:");
    scanf("%d",&n);
    printf("\n1.push\n2.pop\n3.display\n4.peek\n5.exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    while(choice!=5){
        switch(choice){
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            peek();
            break;
            case 5:
            printf("Exiting......");
            break;
            default:
            printf("Enter valid choice.\n");
        
        }
        printf("Enter your choice:");
    scanf("%d",&choice);
    }
}
void push(){
    if(top==n-1){
        printf("Stack Overflow\n");
        
    }
    else{
        printf("\nEnter item/data:");
        scanf("%d",&data);
        top=top+1;
        stack[top]=data;
    }
}
void pop(){
    if(top==-1){
        printf("Stack Underflow\n");
    }
    else{
        printf("Poped item/data is %d.\n",stack[top]);
        top=top-1;
    }
}
void display(){
    int i;
    for(i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
     if(top==-1){
        printf("Stack Underflow\n");
    }
}
void peek(){
     if(top==-1){
        printf("Stack Underflow\n");
    }
    else{
        printf("The top of the stack is %d.\n",stack[top]);
    }
}
