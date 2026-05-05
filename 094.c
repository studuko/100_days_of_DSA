#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[100];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    int count[1000] = {0};
    int output[100];

    for (int i = 0; i < n; i++)
        count[a[i]]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", output[i]);

    return 0;
}