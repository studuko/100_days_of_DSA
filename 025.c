#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};


struct node* insert_end(struct node* head, int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        return newnode;
    }

    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
    return head;
}


int count_occurrence(struct node* head, int key) {
    int count = 0;
    struct node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    return count;
}


int main() {
    struct node* head = NULL;
    int n, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        head = insert_end(head, value);
    }

    printf("Enter element to count: ");
    scanf("%d", &key);

    int result = count_occurrence(head, key);

    printf("Element %d occurs %d time(s)\n", key, result);

    return 0;
}