#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int canPlace(int a[], int n, int k, int dist) {
    int count = 1, last = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] - last >= dist) {
            count++;
            last = a[i];
        }
        if (count >= k)
            return 1;
    }
    return 0;
}

int main() {
    int n, k;
    scanf("%d", &n);

    int a[100];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &k);

    qsort(a, n, sizeof(int), cmp);

    int l = 1, r = a[n - 1] - a[0], ans = 0;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (canPlace(a, n, k, mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    printf("%d", ans);

    return 0;
}