#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    int prefix = 0;

    int freq[2*n+1];
    for(int i = 0; i < 2*n+1; i++)
        freq[i] = 0;

    freq[n] = 1;

    for(int i = 0; i < n; i++) {
        prefix += arr[i];

        if(prefix + n >= 0 && prefix + n <= 2*n) {
            count += freq[prefix + n];
            freq[prefix + n]++;
        }
    }

    printf("Number of subarrays with sum 0 = %d\n", count);

    return 0;
}
