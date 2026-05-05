#include <stdio.h>

int sqrtInt(int n) {
    int l = 0, r = n, ans = 0;

    while (l <= r) {
        int mid = (l + r) / 2;

        if ((long long)mid * mid <= n) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d", sqrtInt(n));

    return 0;
}