#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int valid = 1;

    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (2 * i + 1 < n && arr[i] > arr[2 * i + 1])
            valid = 0;
        if (2 * i + 2 < n && arr[i] > arr[2 * i + 2])
            valid = 0;
    }

    if (valid)
        printf("YES\n");
    else
        printf("NO\n");

    free(arr);
    return 0;
}