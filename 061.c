#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, type;
    scanf("%d %d", &n, &m);
    scanf("%d", &type);

    int** adj = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)calloc(n, sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        if (type == 0)
            adj[v][u] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }

    for (int i = 0; i < n; i++)
        free(adj[i]);
    free(adj);

    return 0;
}