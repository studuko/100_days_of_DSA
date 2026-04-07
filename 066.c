#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* newNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}

int dfs(int v, struct Node** adj, int* visited, int* rec) {
    visited[v] = 1;
    rec[v] = 1;

    struct Node* temp = adj[v];
    while (temp) {
        int u = temp->vertex;

        if (!visited[u]) {
            if (dfs(u, adj, visited, rec))
                return 1;
        } else if (rec[u]) {
            return 1;
        }

        temp = temp->next;
    }

    rec[v] = 0;
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node** adj = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* node = newNode(v);
        node->next = adj[u];
        adj[u] = node;
    }

    int* visited = (int*)calloc(n, sizeof(int));
    int* rec = (int*)calloc(n, sizeof(int));

    int hasCycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, rec)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    for (int i = 0; i < n; i++) {
        struct Node* temp = adj[i];
        while (temp) {
            struct Node* t = temp;
            temp = temp->next;
            free(t);
        }
    }

    free(adj);
    free(visited);
    free(rec);
    return 0;
}