#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* insert_end(struct node* head, int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;

    if (head == NULL) {
        newnode->next = newnode;
        return newnode;
    }

    struct node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newnode;
    newnode->next = head;

    return head;
}

void traverse(struct node* head) {
    if (head == NULL)
        return;

    struct node* temp = head;

    printf("Circular List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() {
    struct node* head = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        head = insert_end(head, value);
    }

    traverse(head);

    return 0;
}