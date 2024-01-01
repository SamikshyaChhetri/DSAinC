#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *temp = NULL;

void insert_at_first(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insert_at_end(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void insert_at_specific(int data, int position) {
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        insert_at_first(data);
        return;
    }
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    struct node *current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void delete_at_f() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
}

void delete_at_e() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct node *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

void delete_at_i(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct node *current = head;
    struct node *prev = NULL;
    for (int i = 1; i < position && current != NULL; i++) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Position out of range\n");
        return;
    }
    prev->next = current->next;
    free(current);
}

void display() {
    struct node *current = head;
    if (current == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int ch, data, position;
    head = NULL;

    printf("The choices are:\n1.insert_at_first \n2.insert_at_end \n3.insert_at_specific \n4.delete_at_f \n5.delete_at_e \n6.delete_at_i \n7.display\n");

    do {
        printf("\nEnter the choice:");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert_at_first(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insert_at_specific(data, position);
                break;
            case 4:
                delete_at_f();
                break;
            case 5:
                delete_at_e();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                delete_at_i(position);
                break;
            case 7:
                display();
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (ch != 8);

    // Free allocated memory
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
