#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int val)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

int pop()
{
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int evaluate(char postfix[])
{
    int i = 0;

    while(postfix[i] != '\0')
    {
        if(isdigit(postfix[i]))
            push(postfix[i] - '0');

        else
        {
            int b = pop();
            int a = pop();

            switch(postfix[i])
            {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }

        i++;
    }

    return pop();
}

int main()
{
    char postfix[100];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    int result = evaluate(postfix);

    printf("Result = %d\n", result);

    return 0;
}