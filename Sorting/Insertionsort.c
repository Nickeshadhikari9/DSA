#include <stdio.h>
void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int sort = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > sort)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = sort;
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
    printf("Original array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    insertionSort(arr, n);
    printf("\nSorted array:");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}