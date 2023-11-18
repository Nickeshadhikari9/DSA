#include <stdio.h>
void insertionsort(int arr[], int n)
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
    int arr[] = {7, 18, 34, 76, 90};
    int n = 5;
    insertionsort(arr, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}