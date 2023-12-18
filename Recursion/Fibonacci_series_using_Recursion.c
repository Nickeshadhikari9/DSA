#include <stdio.h>
void main()
{
    int n;
    int fibonacci(int);
    printf("Enter number of terms for fibonacci series:");
    scanf("%d", &n);
    printf("Fibonacci series:\n");
    printf("%d", fibonacci(n));
}
int fibonacci(int k)
{
    if (k == 1 || k == 2)
        return 1;
    else
        return fibonacci(k - 1) + fibonacci(k - 2);
}