//Program to Create and enqueue a data to it.
#include <stdio.h>
#define MAX_SIZE 100
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if ((rear + 1) % MAX_SIZE == front)
    {
        printf("Queue is full. Cannot insert element.\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}

int main()
{

    enqueue(10);
    enqueue(20);
    enqueue(30);

    return 0;
}
