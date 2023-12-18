#include <stdio.h>
int Max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}
void countingSort(int arr[], int size, int place) {
    const int RADIX = 10;
    int output[size], count[RADIX], max = (arr[0] / place) % RADIX;
    for (int i = 0; i < RADIX; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        count[(arr[i] / place) % RADIX]++;
        if ((arr[i] / place) % RADIX > max)
            max = (arr[i] / place) % RADIX;
    }
    for (int i = 1; i < RADIX; i++){
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--){
        output[--count[(arr[i] / place) % RADIX]] = arr[i];
    }
    for (int i = 0; i < size; i++){
        arr[i] = output[i];
    }
}
int main() {
    int n, arr[100],max,i,place;
    printf("Enter no of elements:");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Original array: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    max = Max(arr, n);
    for (place = 1; max / place > 0; place *= 10) {
        countingSort(arr, n, place);
    }
    printf("\nSorted array: ");
    for (i = 0; i < n; ++i) {
        printf("%d\t", arr[i]);
    }
}
