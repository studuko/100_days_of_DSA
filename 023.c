#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};


struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct node* insertEnd(struct node* head, int data) {
    struct node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct node* mergeLists(struct node* head1, struct node* head2) {
    
    struct node dummy;
    struct node* tail = &dummy;
    dummy.next = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            tail->next = createNode(head1->data);
            head1 = head1->next;
        } else {
            tail->next = createNode(head2->data);
            head2 = head2->next;
        }
        tail = tail->next;
    }

    while (head1 != NULL) {
        tail->next = createNode(head1->data);
        head1 = head1->next;
        tail = tail->next;
    }

    while (head2 != NULL) {
        tail->next = createNode(head2->data);
        head2 = head2->next;
        tail = tail->next;
    }

    return dummy.next;
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;

    head1 = insertEnd(head1, 1);
    head1 = insertEnd(head1, 3);
    head1 = insertEnd(head1, 5);


    head2 = insertEnd(head2, 2);
    head2 = insertEnd(head2, 4);
    head2 = insertEnd(head2, 6);

    printf("List 1: ");
    display(head1);

    printf("List 2: ");
    display(head2);

    struct node* merged = mergeLists(head1, head2);

    printf("Merged List: ");
    display(merged);

    return 0;
}