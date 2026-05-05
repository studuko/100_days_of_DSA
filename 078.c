#include <stdio.h>
#define MAX 100
#define INF 999999

int minKey(int key[], int mstSet[], int n) {
    int min = INF, min_index = -1;
    for (int i = 0; i < n; i++)
        if (mstSet[i] == 0 && key[i] < min)
            min = key[i], min_index = i;
    return min_index;
}

int primMST(int graph[MAX][MAX], int n) {
    int parent[MAX], key[MAX], mstSet[MAX];
    int total = 0;

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    for (int i = 1; i < n; i++)
        total += graph[i][parent[i]];

    return total;
}

int main() {
    int n;
    scanf("%d", &n);

    int graph[MAX][MAX];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int result = primMST(graph, n);
    printf("%d", result);

    return 0;
}