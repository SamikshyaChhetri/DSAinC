#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
struct node *pre;
};

struct node *new_node, *head, *tail, *temp; // Make sure to declare pointers

void insert_at_f();
void insert_at_l();
void insert_at_i();
void display();

int main() {
int c, ch = 0;
head = tail = NULL;

// ... code for creating the doubly linked list ...

printf("The choices are:\n1.insert_at_f \n2.insert_at_l \n3.insert_at_i \n4.display\n");

do {
    printf("\nEnter the choice:");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
            insert_at_f();
            break;
        case 2:
            insert_at_l();
            break;
        case 3:
            insert_at_i();
            break;
        case 4:
            display();
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
} while (ch != 5);

// Free allocated memory
while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
}

return 0;
}

void insert_at_f() {
new_node = (struct node *)malloc(sizeof(struct node));
printf("Enter the data: ");
scanf("%d", &new_node->data);
new_node->pre = NULL;
new_node->next = head;

if (head != NULL) {
    head->pre = new_node;
}

head = new_node;

if (tail == NULL) {
    tail = head; // If list was empty, head and tail point to the same node
}
}

void insert_at_l() {
new_node = (struct node *)malloc(sizeof(struct node));
printf("Enter the data: ");
scanf("%d", &new_node->data);
new_node->pre = tail;
new_node->next = NULL;

if (tail != NULL) {
    tail->next = new_node;
}

tail = new_node;

if (head == NULL) {
    head = tail; // If list was empty, head and tail point to the same node
}
}

void insert_at_i() {
new_node = (struct node *)malloc(sizeof(struct node));
printf("Enter the data: ");
scanf("%d", &new_node->data);

int i, pos;
printf("Enter the position: ");
scanf("%d", &pos);

if (pos <= 0) {
    printf("Invalid position.\n");
    return;
}

if (pos == 1) {
    new_node->pre = NULL;
    new_node->next = head;

    if (head != NULL) {
        head->pre = new_node;
    }

    head = new_node;

    if (tail == NULL) {
        tail = head; // If list was empty, head and tail point to the same node
    }

    return;
}

temp = head;
for (i = 0; i < (pos - 2) && temp != NULL; i++) {
    temp = temp->next;
}

if (temp == NULL) {
    printf("Invalid position.\n");
    return;
}

new_node->pre = temp;
new_node->next = temp->next;

if (temp->next != NULL) {
    temp->next->pre = new_node;
}

temp->next = new_node;
}

void display() {
temp = head;
if (temp == NULL) {
    printf("The DLL is empty.\n");
} else {
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
}
