#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int c, int e)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node** head, int c, int e)
{
    struct Node* newNode = createNode(c,e);

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

void display(struct Node* head)
{
    struct Node* temp = head;

    while(temp)
    {
        printf("%dx^%d", temp->coeff, temp->exp);
        if(temp->next)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node* poly = NULL;

    insert(&poly,5,3);
    insert(&poly,4,2);
    insert(&poly,2,1);
    insert(&poly,7,0);

    display(poly);

    return 0;
}