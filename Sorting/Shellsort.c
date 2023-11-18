#include <stdio.h>
void main()
{
    int a[100], n;
    int k, increment, i, j;
    printf("Enter number of elements:");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (increment = n / 2; increment > 0; increment /= 2)
    {
        for (i = increment; i < n; i++)
        {
            int temp = a[i];
            for (j = i; j >= increment && temp < a[j - increment]; j -= increment)
            {
                a[j] = a[j - increment];
            }
            a[j] = temp;
        }
    }
    printf("After Sorting:\n");
    for (k = 0; k < n; k++)
    {
        printf("%d\t", a[k]);
    }
}
