#include<stdio.h>
#include<conio.h>
void TOH(int,char,char,char);
void main(){
    int n;
    printf("Enter number of disks:");
    scanf("%d",&n);
    TOH(n,'O','D','I');

}
void TOH(int n,char A,char B,char C){
    if(n==1){
        printf("Move disk %d from %c to %c\n",n,A,B);
    }
    
    
    else{
        TOH(n-1,A,C,B);
        printf("Move disk %d from %c to %c\n",n,A,B);
        TOH(n-1,C,B,A);
    }

    
}
