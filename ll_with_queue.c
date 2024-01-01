#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = 0, *rear = 0;

void enqueue(int x)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = x;
    new_node->next = 0;
    
    if (front == 0 && rear == 0) 
	{
        front = rear = new_node;
    } else 
	{
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue() 
{
    if (front == 0 && rear == 0) 
	{
        printf("Queue is empty\n");
    } else 
	{
        struct node *temp;
        temp = front;
        front = front->next;
        free(temp);
    }
}

void display() 
{
    if (front == 0 && rear == 0) 
	{
        printf("Queue is empty\n");
    } else 
	{
        struct node *temp;
        temp = front;
        while (temp != 0) 
		{
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}

int main() 
{
    int choice = 0;
    printf("Enter the choice:\n1: enqueue()\n2: dequeue()\n3: display()\n4: exit\n");
    
    do {
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice) 
		{
            case 1: {
                int n;
                printf("Enter the inserted element: ");
                scanf("%d", &n);
                enqueue(n);
                break;
            }
            case 2: {
                dequeue();
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                printf("Exit\n");
                break;
            }
            default:
                printf("Invalid choice. Enter 4 to exit.\n");
        }
    } while (choice != 4);

    // Free allocated memory (optional, as the program is exiting)
    while (front != NULL) 
	{
        struct node *temp = front;
        front = front->next;
        free(temp);
    }

    return 0;
}