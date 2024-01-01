//Program to create a queue and enqueue and dequque data from it.
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

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty. Cannot remove element.\n");
    }
    else
    {
        int dequeuedElement = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
        printf("Removed %d from the queue.\n", dequeuedElement);
    }
}

int main()
{ 
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    return 0;
}
