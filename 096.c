#include <stdio.h>

long long merge(int a[], int temp[], int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    long long inv = 0;

    while (i <= m && j <= r) {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else {
            temp[k++] = a[j++];
            inv += (m - i + 1);
        }
    }

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= r)
        temp[k++] = a[j++];

    for (int x = l; x <= r; x++)
        a[x] = temp[x];

    return inv;
}

long long mergeSort(int a[], int temp[], int l, int r) {
    long long inv = 0;
    if (l < r) {
        int m = (l + r) / 2;
        inv += mergeSort(a, temp, l, m);
        inv += mergeSort(a, temp, m + 1, r);
        inv += merge(a, temp, l, m, r);
    }
    return inv;
}

int main() {
    int n;
    scanf("%d", &n);

    int a[100], temp[100];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    long long result = mergeSort(a, temp, 0, n - 1);

    printf("%lld", result);

    return 0;
}