#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start, end;
};

int cmp(const void *a, const void *b) {
    struct Interval *x = (struct Interval*)a;
    struct Interval *y = (struct Interval*)b;
    return x->start - y->start;
}

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapifyUp(int heap[], int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int heap[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < n && heap[l] < heap[smallest])
        smallest = l;
    if (r < n && heap[r] < heap[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, n, smallest);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Interval a[100];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &a[i].start, &a[i].end);

    qsort(a, n, sizeof(struct Interval), cmp);

    int heap[100], size = 0;

    heap[size++] = a[0].end;

    for (int i = 1; i < n; i++) {
        if (a[i].start >= heap[0]) {
            heap[0] = a[i].end;
            heapifyDown(heap, size, 0);
        } else {
            heap[size] = a[i].end;
            heapifyUp(heap, size);
            size++;
        }
    }

    printf("%d", size);

    return 0;
}