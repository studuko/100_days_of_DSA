#include <stdio.h>

int stack[100];
int top = -1;

void push(int val)
{
    if(top == 99)
        printf("Stack Overflow\n");
    else
    {
        top++;
        stack[top] = val;
    }
}

void pop()
{
    if(top == -1)
        printf("Stack Underflow\n");
    else
        top--;
}

void display()
{
    if(top == -1)
        printf("Stack is empty\n");
    else
    {
        for(int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main()
{
    int choice, val;

    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;
        }
    }
}