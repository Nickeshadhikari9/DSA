#include <stdio.h>
int main()
{
    int a[100], key, i, n;
    int count=0;
    printf("Enter the no of elements:");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the number to be searched:");
    scanf("%d", &key);
    for (i = 0; i < n; i++){
        if (a[i] == key)
        {
            printf("%d is present at location %d.", key, i + 1);
            count++;
            break;
        }
    }
    if (count != 1)
    {
        printf("%d is not present in the array.", key);
    }
}
