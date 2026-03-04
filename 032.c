#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val)
{
    if(top == MAX-1)
        printf("Stack Overflow\n");
    else
    {
        top++;
        stack[top] = val;
        printf("%d pushed\n", val);
    }
}

void pop()
{
    if(top == -1)
        printf("Stack Underflow\n");
    else
    {
        printf("%d popped\n", stack[top]);
        top--;
    }
}

void display()
{
    if(top == -1)
        printf("Stack Empty\n");
    else
    {
        for(int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    pop();

    display();

    return 0;
}