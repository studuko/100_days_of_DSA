#include <stdio.h>
#include <stdlib.h>

int hash(int key, int m) {
    if (key < 0) key = -key;
    return key % m;
}

int main() {
    int m, q;
    scanf("%d %d", &m, &q);

    int* table = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) table[i] = -1;

    while (q--) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if (op[0] == 'I') {
            int h = hash(key, m);
            for (int i = 0; i < m; i++) {
                int idx = (h + i * i) % m;
                if (table[idx] == -1) {
                    table[idx] = key;
                    break;
                }
            }
        } else if (op[0] == 'S') {
            int h = hash(key, m);
            int found = 0;
            for (int i = 0; i < m; i++) {
                int idx = (h + i * i) % m;
                if (table[idx] == -1) break;
                if (table[idx] == key) {
                    found = 1;
                    break;
                }
            }
            if (found) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }

    free(table);
    return 0;
}