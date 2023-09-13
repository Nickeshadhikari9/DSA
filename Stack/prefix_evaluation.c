#include <stdio.h>
#include <string.h>
#include <math.h>

void push(int);
int stack[100];
int top = -1;
int pop();

int main() {
    int i, value[100];
    char prefix[100], operator;
    printf("Enter a valid prefix expression: ");
    gets(prefix);
    for (i = strlen(prefix) - 1; i >= 0; i--) {
        if (isalpha(prefix[i])) {
            printf("Enter value of '%c': ", prefix[i]);
            scanf("%d", &value[i]);
            push(value[i]);
        } else {
            operator = prefix[i];
            int operand2 = pop();
            int operand1 = pop();

            switch (operator) {
                case '+':
                    push(operand2 + operand1);
                    break;

                case '-':
                    push(operand2 - operand1);
                    break;

                case '*':
                    push(operand2 * operand1);
                    break;

                case '/':
                    push(operand2 / operand1);
                    break;

                case '$':
                    push(pow(operand2, operand1));
                    break;

                case '%':
                    push(operand2 % operand1);
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
