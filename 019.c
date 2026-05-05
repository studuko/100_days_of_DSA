#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if(n < 2) {
        printf("Need at least 2 elements.\n");
        return 0;
    }

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int minSum = abs(arr[left] + arr[right]);
    int first = arr[left];
    int second = arr[right];

    while(left < right) {
        int sum = arr[left] + arr[right];

        if(abs(sum) < minSum) {
            minSum = abs(sum);
            first = arr[left];
            second = arr[right];
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    printf("Two elements closest to zero: %d and %d\n", first, second);

    return 0;
}