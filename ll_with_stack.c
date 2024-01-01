//List List with Stack
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = value;
    new_node->next = top;
    top = new_node;
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct node* temp = top;
    top = top->next;
    free(temp);
}

int peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return -1; // You can choose a proper error value
    }
    return top->data;
}

void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Stack elements: ");
    display();

    printf("Top element: %d\n", peek());

    pop();
    
    printf("Stack elements after pop: ");
    display();

    return 0;
}