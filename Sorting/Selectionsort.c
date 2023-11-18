#include <stdio.h>
void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int least = arr[i];
        int position = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                least = arr[j];
                position = j;
            }
        }
        int temp = arr[position];
        arr[position] = arr[i];
        arr[i] = temp;
    }
}
int main()
{
    int arr[] = {25, 57, 48, 37, 12};
    int n = 5;
    selectionsort(arr, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
