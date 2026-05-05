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

    if(front == NULL){
        front = rear = temp;
        temp->next = front;
    } else {
        rear->next = temp;
        rear = temp;
        rear->next = front;
    }
}

void dequeue(){
    if(front == NULL){
        printf("Queue Underflow\n");
        return;
    }

    struct node* temp = front;

    if(front == rear){
        printf("Deleted: %d\n", front->data);
        front = rear = NULL;
    } else {
        printf("Deleted: %d\n", front->data);
        front = front->next;
        rear->next = front;
    }

    free(temp);
}

void display(){
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }

    struct node* temp = front;

    do{
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != front);

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