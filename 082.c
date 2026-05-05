#include <stdio.h>

int lowerBound(int a[], int n, int x) {
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] < x)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

int upperBound(int a[], int n, int x) {
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] <= x)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

int main() {
    int n, x;
    scanf("%d", &n);

    int a[100];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &x);

    printf("%d %d", lowerBound(a, n, x), upperBound(a, n, x));

    return 0;
}