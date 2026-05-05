#include <stdio.h>
#include <stdlib.h>

struct Car {
    int pos;
    int speed;
    float time;
};

int cmp(const void *a, const void *b) {
    struct Car *x = (struct Car*)a;
    struct Car *y = (struct Car*)b;
    return y->pos - x->pos;
}

int main() {
    int n, target;
    scanf("%d", &n);

    struct Car a[100];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i].pos);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i].speed);

    scanf("%d", &target);

    for (int i = 0; i < n; i++)
        a[i].time = (float)(target - a[i].pos) / a[i].speed;

    qsort(a, n, sizeof(struct Car), cmp);

    int fleets = 0;
    float maxTime = 0;

    for (int i = 0; i < n; i++) {
        if (a[i].time > maxTime) {
            fleets++;
            maxTime = a[i].time;
        }
    }

    printf("%d", fleets);

    return 0;
}