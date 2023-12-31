#include <stdio.h>
int binary_search(int a[100], int l, int r, int key)
{
    int m,flag = 0;
    if (l <= r){
        m = ( l + r )/ 2;
        if (key == a[m])
            flag = m;
        else if (key < a[m])
            return binary_search(a, l, m - 1, key);
        else
            return binary_search(a, m + 1, r, key);
    }
    else
        return flag;
}
void main(){
    int n, a[100], i, key, flag;
    printf("Enter the no of elements:");
    scanf("%d", &n);
    printf("Enter %d elements in sorted form:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the number to be searched:");
    scanf("%d", &key);
    flag = binary_search(a, 0, n - 1, key);
    if (flag == 0)
    {
        printf("%d is not present in the array.",key);
    }
    else
    {
        printf("%d is present at location %d.", key, flag + 1);
    }
}