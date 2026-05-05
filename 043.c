#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node* createNode(int x){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node* buildTree(int arr[], int n){
    if(n == 0) return NULL;

    struct node* root = createNode(arr[0]);

    struct node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while(i < n){
        struct node* current = queue[front++];

        if(i < n){
            current->left = createNode(arr[i++]);
            queue[rear++] = current->left;
        }

        if(i < n){
            current->right = createNode(arr[i++]);
            queue[rear++] = current->right;
        }
    }

    return root;
}

void inorder(struct node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    struct node* root = buildTree(arr, n);

    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}