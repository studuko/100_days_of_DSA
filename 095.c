#include <stdio.h>

void insertionSort(float b[], int n) {
    for (int i = 1; i < n; i++) {
        float key = b[i];
        int j = i - 1;
        while (j >= 0 && b[j] > key) {
            b[j + 1] = b[j];
            j--;
        }
        b[j + 1] = key;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float a[100];
    for (int i = 0; i < n; i++)
        scanf("%f", &a[i]);

    float bucket[100][100];
    int count[100] = {0};

    for (int i = 0; i < n; i++) {
        int idx = n * a[i];
        bucket[idx][count[idx]++] = a[i];
    }

    for (int i = 0; i < n; i++)
        if (count[i] > 0)
            insertionSort(bucket[i], count[i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < count[i]; j++)
            printf("%f ", bucket[i][j]);

    return 0;
}