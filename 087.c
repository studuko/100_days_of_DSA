#include <stdio.h>

int binarySearch(int a[], int n, int x) {
    int l = 0, r = n - 1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (a[mid] == x)
            return mid;
        else if (a[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

int main() {
    int n, x;
    scanf("%d", &n);

    int a[100];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &x);

    int res = binarySearch(a, n, x);

    printf("%d", res);

    return 0;
}