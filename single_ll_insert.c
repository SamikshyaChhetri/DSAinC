#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *next;
};

struct node *head = NULL; // Initialize head to NULL

void creation() {
int c;
struct node *new_node, *temp;

do {
new_node = (struct node *)malloc(sizeof(struct node));
printf("Enter the data: ");
scanf("%d", &new_node->data);
new_node->next = NULL;

if (head == NULL) {
    head = temp = new_node;
} else {
    temp->next = new_node;
    temp = new_node;
}

printf("Do you want to add a new node? (0-1) ");
scanf("%d", &c);
} while (c == 1);
}

void insert_at_first() {
struct node *new_node = (struct node *)malloc(sizeof(struct node));
printf("Enter the data: ");
scanf("%d", &new_node->data);
new_node->next = head;
head = new_node;
}

void insert_at_end() {
struct node *new_node = (struct node *)malloc(sizeof(struct node));
printf("Enter the data: ");
scanf("%d", &new_node->data);
new_node->next = NULL;

if (head == NULL) {
head = new_node;
return;
}

struct node *temp = head;
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = new_node;
}

void insert_at_specific() {
struct node *new_node = (struct node *)malloc(sizeof(struct node));
printf("Enter the data: ");
scanf("%d", &new_node->data);

int pos;
printf("Enter the position: ");
scanf("%d", &pos);

if (pos <= 0) {
printf("Invalid position\n");
return;
}

if (pos == 1) {
new_node->next = head;
head = new_node;
return;
}

struct node *temp = head;
for (int i = 1; i < pos - 1 && temp != NULL; i++) {
temp = temp->next;
}

if (temp == NULL) {
printf("Invalid position\n");
return;
}

new_node->next = temp->next;
temp->next = new_node;
}

void display() {
struct node *temp = head;
if (temp == NULL) {
printf("The list is empty.\n");
} else {
while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
}
printf("\n");
}
}

int main() {
int ch = 0;
printf("The choices are:\n1.creation \n2.insert_at_first \n3.insert_at_end \n4.insert_at_specific \n5.display\n");

do {
printf("\nEnter the choice: ");
scanf("%d", &ch);
switch (ch) {
    case 1:
        creation();
        break;
    case 2:
        insert_at_first();
        break;
    case 3:
        insert_at_end();
        break;
    case 4:
        insert_at_specific();
        break;
    case 5:
        display();
        break;
    default:
        printf("Invalid choice\n");
        break;
}
} while (ch != 6);

return 0;
}
