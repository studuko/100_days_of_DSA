#include <stdio.h>

void mergeLogs(int a[], int n, int b[], int m, int merged[]) {
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            merged[k++] = a[i++];
        } else {
            merged[k++] = b[j++];
        }
    }

  
    while (i < n) {
        merged[k++] = a[i++];
    }

    while (j < m) {
        merged[k++] = b[j++];
    }
}

int main() {
    int log1[] = {1, 4, 7, 10};
    int log2[] = {2, 3, 8, 12};
    int n = 4, m = 4;

    int merged[n + m];

    mergeLogs(log1, n, log2, m, merged);

    printf("Merged Log:\n");
    for (int i = 0; i < n + m; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
