#include <stdio.h>
#define size 5

int a[size];
int front = -1;
int rear = -1;

void enqueue(int x);
void dequeue();
void display();

int main()
{
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    enqueue(11);
    display();
    dequeue();
    display();

    return 0;
}

void enqueue(int x)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        a[rear] = x;
    }
    else if ((rear + 1) % size == front)
    {
        printf("Queue is full \n");
    }
    else
    {
        rear = (rear + 1) % size;
        a[rear] = x;
        printf("Inserted element is %d \n", x);
    }
}

void dequeue()
{
    int delemat;
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty \n");
    }
    else if (front == rear)
    {
        delemat = a[front];
        front = -1;
        rear = -1;
        printf("Deleted element is %d \n", delemat);
    }
    else
    {
        delemat = a[front];
        front = (front + 1) % size;
        printf("Deleted element is %d \n", delemat);
    }
}

void display()
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty \n");
    }
    else
    {
        printf("Circular queue elements: \n");
        for (i = front; i != rear; i = (i + 1) % size)
        {
            printf("%d\t", a[i]);
        }
        printf("%d\n", a[i]);
    }
}
