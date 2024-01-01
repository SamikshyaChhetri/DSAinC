#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull()
{
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == front - 1))
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}

void enqueue(int x)
{
    if (isFull())
    {
        printf("Queue is full. Cannot enqueue element %d.\n", x);
    }
    else
    {
        if (front == -1)
            front = 0;

        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = x;
        printf("Enqueued element: %d\n", x);
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty. Cannot dequeue element.\n");
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

        printf("Dequeued element: %d\n", dequeuedElement);
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty. Nothing to display.\n");
    }
    else
    {
        printf("Circular Queue elements: ");
        int i = front;

        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX_SIZE;
        }

        // printf("%d\n", queue[i]);
    }
}

int main()
{
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    enqueue(11);
    display();

    dequeue();
    dequeue();
    display();

    enqueue(12);
    enqueue(13);
    display();

    return 0;
}
