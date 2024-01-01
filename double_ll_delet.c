#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *next;
struct node *pre;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *new_node = NULL;

void create_node() {
int c;
head = NULL;
do {
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &new_node->data);
    new_node->pre = NULL;
    new_node->next = NULL;

    if (head == NULL) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        new_node->pre = tail;
        tail = new_node;
    }

    printf("Do you want to continue (0-1): ");
    scanf("%d", &c);
} while (c == 1);
}

void deletion_at_s() {
if (head == NULL) {
    printf("Double linked list is empty\n");
} else {
    struct node *temp = head;
    head = head->next;
    if (head != NULL) {
        head->pre = NULL;
    }
    free(temp);
}
}

void deletion_at_e() {
if (tail == NULL) {
    printf("Double linked list is empty\n");
} else {
    struct node *temp = tail;
    tail = tail->pre;
    if (tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
}
}

void deletion_at_i() {
if (head == NULL) {
    printf("Double linked list is empty\n");
    return;
}

int i, pos;
printf("Enter the position: ");
scanf("%d", &pos);

if (pos <= 0) {
    printf("Invalid position\n");
    return;
}

if (pos == 1) {
    deletion_at_s();
    return;
}

struct node *temp = head;
for (i = 0; i < (pos - 1) && temp != NULL; i++) {
    temp = temp->next;
}

if (temp == NULL) {
    printf("Invalid position\n");
    return;
}

temp->pre->next = temp->next;

if (temp->next != NULL) {
    temp->next->pre = temp->pre;
}

free(temp);
}

void display() {
struct node *current = head;
if (current == NULL) {
    printf("Double linked list is empty\n");
} else {
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}
}

int main() {
int ch = 0;
printf("Enter the choice:\n1:create_node()\n2:deletion_at_s()\n3:deletion_at_e()\n4:deletion_at_i()\n5:display()\n");

do {
    printf("\nEnter the choice: ");
    scanf("%d", &ch);
    switch (ch) {
        case 1:
            create_node();
            break;
        case 2:
            deletion_at_s();
            break;
        case 3:
            deletion_at_e();
            break;
        case 4:
            deletion_at_i();
            break;
        case 5:
            display();
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
} while (ch != 6);

// Free allocated memory
while (head != NULL) {
    struct node *temp = head;
    head = head->next;
    free(temp);
}

return 0;
}
