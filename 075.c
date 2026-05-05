#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    int value;
    struct Node* next;
};

#define SIZE 100003

struct Node* table[SIZE];

int hash(int key) {
    if (key < 0) key = -key;
    return key % SIZE;
}

void insert(int key, int value) {
    int h = hash(key);
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->value = value;
    node->next = table[h];
    table[h] = node;
}

int search(int key, int* value) {
    int h = hash(key);
    struct Node* temp = table[h];
    while (temp) {
        if (temp->key == key) {
            *value = temp->value;
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < SIZE; i++)
        table[i] = NULL;

    int sum = 0, maxLen = 0;

    insert(0, -1);

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        int idx;
        if (search(sum, &idx)) {
            int len = i - idx;
            if (len > maxLen)
                maxLen = len;
        } else {
            insert(sum, i);
        }
    }

    printf("%d\n", maxLen);

    for (int i = 0; i < SIZE; i++) {
        struct Node* temp = table[i];
        while (temp) {
            struct Node* t = temp;
            temp = temp->next;
            free(t);
        }
    }

    free(arr);
    return 0;
}