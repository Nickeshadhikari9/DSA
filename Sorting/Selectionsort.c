#include <stdio.h>
void selectionSort(int arr[], int n)
{
    int i,least,position,j,temp;
    for (i = 0; i < n; i++)
    {
        least = arr[i];
        position = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                least = arr[j];
                position = j;
            }
        }
        temp = arr[position];
        arr[position] = arr[i];
        arr[i] = temp;
    }
}
int main()
{
    int n, arr[100], i;
    printf("Enter no of elements:");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Original array:");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    selectionSort(arr, n);
    printf("\nSorted array:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
