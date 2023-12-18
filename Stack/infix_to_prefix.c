#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
char infix[MAX], prefix[MAX], stack[MAX];
int top = -1;

void push(char);
char pop();
int isempty();
void intopre();
void print();
int precedence(char);

int main()
{
    printf("Enter the infix expression:");
    gets(infix);
    intopre();
    print();
    return 0;
}

void intopre()
{
    int i, j = 0;
    char symbol, next;
    for (i = strlen(infix) - 1; i >= 0; i--)
    {
        symbol = infix[i];
        switch (symbol)
        {
        case ')':
            push(symbol);
            break;
        case '(':
            while ((next = pop()) != ')')
            {
                prefix[j++] = next;
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '$':
            while (!isempty() && stack[top] != ')' && precedence(stack[top]) > precedence(symbol))
            {
                prefix[j++] = pop();
            }
            push(symbol);
            break;
        default:
            prefix[j++] = symbol;
        }
    }
    while (!isempty())
    {
        prefix[j++] = pop();
    }
    prefix[j] = '\0';
}

int precedence(char symbol)
{
    switch (symbol)
    {
    case '$':
        return 4;
    case '/':
    case '*':
        return 3;
    case '+':
    case '-':
        return 2;
    default:
        return 1;
    }
}

void print()
{
    int i = strlen(prefix) - 1;
    printf("The equivalent prefix expression is: ");
    while (i >= 0)
    {
        printf("%c", prefix[i--]);
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
