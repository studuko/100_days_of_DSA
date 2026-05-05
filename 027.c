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

    if (head == NULL)
        return newnode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    return head;
}

int get_length(struct node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct node* find_intersection(struct node* head1, struct node* head2) {
    int len1 = get_length(head1);
    int len2 = get_length(head2);

    int diff = abs(len1 - len2);

    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            head1 = head1->next;
    } else {
        for (int i = 0; i < diff; i++)
            head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;

    head1 = insert_end(head1, 1);
    head1 = insert_end(head1, 2);
    head1 = insert_end(head1, 3);

    struct node* common = insert_end(NULL, 4);
    common = insert_end(common, 5);

    struct node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = common;

    head2 = insert_end(head2, 9);
    head2->next = common;

    struct node* result = find_intersection(head1, head2);

    if (result != NULL)
        printf("Intersection at node with value: %d\n", result->data);
    else
        printf("No intersection\n");

    return 0;
}