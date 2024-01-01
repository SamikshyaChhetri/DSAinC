#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *next;
};

struct node *new_node, *head, *temp; // Make sure to declare 'temp' as a pointer

void delete_at_f();
void delete_at_e();
void delete_at_i();
void display();

int main() {
int c, ch;
head = temp = NULL; // Initialize head and temp to NULL

do {
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    
    if (head == NULL)
        head = temp = new_node;
    else {
        temp->next = new_node;
        temp = new_node;
    }

    printf("Do you want to add a new node? (0-1) ");
    scanf("%d", &c);
} while (c == 1);

printf("\nThe choices are:\n1.Delete at first\n2.Delete at end\n3.Delete at specific\n4.Display\n");
do {
    printf("\nEnter the choice: ");
    scanf("%d", &ch);
    switch (ch) {
        case 1:
            delete_at_f();
            break;
        case 2:
            delete_at_e();
            break;
        case 3:
            delete_at_i();
            break;
        case 4:
            display();
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
} while (ch != 4);

// Free remaining memory by iterating through the list and freeing nodes
temp = head;
while (temp != NULL) {
    struct node *to_free = temp;
    temp = temp->next;
    free(to_free);
}

return 0;
}

void delete_at_f() {
if (head == NULL) {
    printf("Linked list is empty.\n");
    return;
}

temp = head;
head = head->next;
free(temp);
}

void delete_at_e() {
if (head == NULL) {
    printf("Linked list is empty.\n");
    return;
}

temp = head;
struct node *pre = NULL;

while (temp->next != NULL) {
    pre = temp;
    temp = temp->next;
}

if (pre != NULL)
    pre->next = NULL;

free(temp);
}

void delete_at_i() {
if (head == NULL) {
    printf("Linked list is empty.\n");
    return;
}

int i, pos;
printf("Enter the position: ");
scanf("%d", &pos);

if (pos <= 0) {
    printf("Invalid position.\n");
    return;
}

if (pos == 1) {
    temp = head;
    head = head->next;
    free(temp);
    return;
}

temp = head;
for (i = 0; i < (pos - 2) && temp != NULL; i++) {
    temp = temp->next;
}

if (temp == NULL || temp->next == NULL) {
    printf("Invalid position.\n");
    return;
}

struct node *pre = temp->next;
temp->next = pre->next;
free(pre);
}

void display() {
temp = head;
if (temp == NULL)
    printf("Linked list is empty.\n");
else {
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
}
