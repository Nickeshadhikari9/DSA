#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
char infix[MAX], postfix[MAX], stack[MAX];
int top = -1;

void push(char);
char pop();
int isempty();
void intopost();
void print();
int precedence(char);

int main()
{
    printf("Enter the infix expression:");
    gets(infix);
    intopost();
    print();
    return 0;
}
void intopost()
{
    int i, j = 0;
    char symbol, next;
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            while ((next = pop()) != '(')
            {
                postfix[j++] = next;
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '$':
            while (!isempty() && stack[top] != '(' && precedence(stack[top]) >= precedence(symbol))
            {
                postfix[j++] = pop();
            }
            push(symbol);

            break;
        default:
            postfix[j++] = symbol;
        }
    }
    while (!isempty())
    {
        postfix[j++] = pop();
        postfix[j] = '\0';
    }
}
int precedence(char symbol)
{
    switch (symbol)
    {
    case '$':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
void print()
{
    int i = 0;
    printf("The equivalent posfix expression is:");
    while (postfix[i])
    {
        printf("%c", postfix[i++]);
    }
    printf("\n");
}
void push(char c)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top = top + 1;
    stack[top] = c;
}
char pop()
{
    char c;
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    c = stack[top];
    top = top - 1;
    return c;
}
int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}