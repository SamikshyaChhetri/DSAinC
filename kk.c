#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int item) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = item;
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    if (front == rear) {
        front = rear = -1;
    } else {
        printf("Dequeued item is: %d\n",queue[front]);
        front++;
    }
}



int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();

    return 0;
}