#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if(rear == NULL){
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue(){
    if(front == NULL){
        printf("Queue Underflow\n");
        return;
    }

    struct node* temp = front;
    printf("Deleted: %d\n", front->data);
    front = front->next;

    if(front == NULL){
        rear = NULL;
    }

    free(temp);
}

void display(){
    struct node* temp = front;

    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int choice, value;

    while(1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}