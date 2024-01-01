//program to pop a data from a stack
#include<stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;
void push(int value)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack is full. Cannot push element.\n");
    }
    else
    {
        stack[++top] = value;
        printf("Pushed %d to the stack.\n", value);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty. Cannot pop element.\n");
    }
    else
    {
        int poppedElement = stack[top--];
        printf("Popped %d from the stack.\n", poppedElement);
    }
}

int main()
{
    // Pushing elements onto the stack
    push(10);
    push(20);
    push(30);

    // Popping elements from the stack
    pop();
    pop();
    pop();
    pop();

    return 0;
}
