#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

int main() {
    int n;
    scanf("%d", &n);

    char** arr = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        arr[i] = (char*)malloc(101);
        scanf("%s", arr[i]);
    }

    qsort(arr, n, sizeof(char*), cmp);

    int maxCount = 0, count = 1;
    char result[101];
    strcpy(result, arr[0]);

    for (int i = 1; i < n; i++) {
        if (strcmp(arr[i], arr[i - 1]) == 0) {
            count++;
        } else {
            if (count > maxCount) {
                maxCount = count;
                strcpy(result, arr[i - 1]);
            }
            count = 1;
        }
    }

    if (count > maxCount) {
        maxCount = count;
        strcpy(result, arr[n - 1]);
    }

    printf("%s\n", result);

    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);

    return 0;
}