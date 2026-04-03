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

int main() {
    int n, m, type;
    scanf("%d %d", &n, &m);
    scanf("%d", &type);

    struct Node** adj = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* node = newNode(v);
        node->next = adj[u];
        adj[u] = node;

        if (type == 0) {
            struct Node* node2 = newNode(u);
            node2->next = adj[v];
            adj[v] = node2;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        struct Node* temp = adj[i];
        while (temp) {
            printf(" %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        struct Node* temp = adj[i];
        while (temp) {
            struct Node* t = temp;
            temp = temp->next;
            free(t);
        }
    }
    free(adj);

    return 0;
}