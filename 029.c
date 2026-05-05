#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while(temp->next)
        temp = temp->next;

    temp->next = newNode;
}

struct Node* rotateRight(struct Node* head, int k)
{
    if(head == NULL || head->next == NULL)
        return head;

    int len = 1;
    struct Node* temp = head;

    while(temp->next)
    {
        temp = temp->next;
        len++;
    }

    temp->next = head;

    k = k % len;
    int steps = len - k;

    struct Node* newTail = head;

    for(int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

void printList(struct Node* head)
{
    struct Node* temp = head;
    while(temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node* head = NULL;

    insertEnd(&head,1);
    insertEnd(&head,2);
    insertEnd(&head,3);
    insertEnd(&head,4);
    insertEnd(&head,5);

    int k = 2;

    head = rotateRight(head,k);

    printList(head);

    return 0;
}