#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int i){
    while(i > 0 && heap[(i - 1) / 2] > heap[i]){
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i){
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void insert(int x){
    if(size == MAX){
        printf("Heap Overflow\n");
        return;
    }

    heap[size] = x;
    heapifyUp(size);
    size++;
}

void deleteMin(){
    if(size == 0){
        printf("Heap Underflow\n");
        return;
    }

    printf("Deleted: %d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

void display(){
    if(size == 0){
        printf("Heap is empty\n");
        return;
    }

    for(int i = 0; i < size; i++){
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main(){
    int choice, value;

    while(1){
        printf("\n1.Insert\n2.Delete Min\n3.Display\n4.Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                deleteMin();
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