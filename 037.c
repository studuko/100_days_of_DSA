#include <stdio.h>
#define MAX 100

int pq[MAX];
int size = 0;

void enqueue(int x){
    if(size == MAX){
        printf("Queue Overflow\n");
        return;
    }

    int i = size - 1;

    while(i >= 0 && pq[i] > x){
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = x;
    size++;
}

void dequeue(){
    if(size == 0){
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted: %d\n", pq[0]);

    for(int i = 0; i < size - 1; i++){
        pq[i] = pq[i + 1];
    }

    size--;
}

void display(){
    if(size == 0){
        printf("Queue is empty\n");
        return;
    }

    for(int i = 0; i < size; i++){
        printf("%d ", pq[i]);
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
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}