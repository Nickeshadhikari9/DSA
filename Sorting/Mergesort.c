#include <stdio.h>
void merge(int a[], int l, int m, int r)
{
    int x = l;
    int k = l, i;
    int y = m, b[100];
    while (x < m && y <= r)
    {
        if (a[x] < a[y])
        {
            b[k] = a[x];
            k++;
            x++;
        }
        else
        {
            b[k] = a[y];
            k++;
            y++;
        }
    }
    while (x < m)
    {
        b[k] = a[x];
        k++;
        x++;
    }
    while (y <= r)
    {
        b[k] = a[y];
        y++;
        k++;
    }
    for (i = l; i <= r; i++)
    {
        a[i] = b[i];
    }
}
void mergeSort(int a[], int l, int r)
{
    int mid;
    if (l < r)
    {
        mid = (l + r) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid + 1, r);
    }
}
void main()
{
    int a[100], n, i, l, r;
    printf("Enter no of elements:");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    l = 0;
    r = n - 1;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Original array:");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    mergeSort(a, l, r);
    printf("\nSorted array:");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}