#include <stdio.h>

struct Node {
    int val, idx;
};

void merge(struct Node a[], int l, int m, int r, int count[]) {
    int i = l, j = m + 1, k = 0;
    struct Node temp[100];
    int rightCount = 0;

    while (i <= m && j <= r) {
        if (a[j].val < a[i].val) {
            temp[k++] = a[j++];
            rightCount++;
        } else {
            count[a[i].idx] += rightCount;
            temp[k++] = a[i++];
        }
    }

    while (i <= m) {
        count[a[i].idx] += rightCount;
        temp[k++] = a[i++];
    }

    while (j <= r)
        temp[k++] = a[j++];

    for (int x = 0; x < k; x++)
        a[l + x] = temp[x];
}

void mergeSort(struct Node a[], int l, int r, int count[]) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m, count);
        mergeSort(a, m + 1, r, count);
        merge(a, l, m, r, count);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node a[100];
    int count[100] = {0};

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].val);
        a[i].idx = i;
    }

    mergeSort(a, 0, n - 1, count);

    for (int i = 0; i < n; i++)
        printf("%d ", count[i]);

    return 0;
}