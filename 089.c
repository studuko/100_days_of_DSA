#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int isPossible(int a[], int n, int m, int limit) {
    int students = 1, sum = 0;

    for (int i = 0; i < n; i++) {
        if (sum + a[i] > limit) {
            students++;
            sum = a[i];
            if (students > m)
                return 0;
        } else {
            sum += a[i];
        }
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d", &n);

    int a[100];
    int sum = 0, mx = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        mx = max(mx, a[i]);
    }

    scanf("%d", &m);

    int l = mx, r = sum, ans = sum;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (isPossible(a, n, m, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}