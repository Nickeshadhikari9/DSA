#include <stdio.h>
#include <string.h>
#include <math.h>

void push(int);
int stack[100];
int top = -1;
int pop();

int main() {
    int i, value[100];
    char postfix[100], operator;

    printf("Enter a valid postfix expression: ");
    gets(postfix);

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isalpha(postfix[i])) {
            printf("Enter value of '%c': ", postfix[i]);
            scanf("%d", &value[i]);
            push(value[i]);
        } else {
            operator = postfix[i];
            int operand2 = pop();
            int operand1 = pop();

            switch (operator) {
                case '+':
                    push(operand1 + operand2);
                    break;

                case '-':
                    push(operand1 - operand2);
                    break;

                case '*':
                    push(operand1 * operand2);
                    break;

                case '/':
                    push(operand1 / operand2);
                    break;

                case '$':
                    push(pow(operand1, operand2));
                    break;

                case '%':
                    push(operand1 % operand2);
                    break;
            }
        }
    }

    printf("The result is: %d\n", pop());
    
    return 0;
}

void push(int val) {
    stack[++top] = val;
}

int pop() {
    int n;
    n = stack[top--];
    return n;
}
