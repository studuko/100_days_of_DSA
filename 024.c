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


struct node* deleteKey(struct node* head, int key) {

    
    if (head == NULL)
        return head;

    struct node* temp = head;
    struct node* prev = NULL;


    if (temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

 
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

  
    if (temp == NULL)
        return head;

  
    prev->next = temp->next;
    free(temp);

    return head;
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

    struct node* head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 20);
    head = insertEnd(head, 40);

    printf("Original List:\n");
    display(head);

    int key = 20;

    head = deleteKey(head, key);

    printf("After Deleting First Occurrence of %d:\n", key);
    display(head);

    return 0;
}