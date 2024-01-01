#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *next;
struct node *pre;
};

struct node *new_node, *head = NULL, *tail = NULL, *temp = NULL;

void insert_at_f() {
new_node = (struct node *)malloc(sizeof(struct node));
printf("Enter the data:");
scanf("%d", &new_node->data);
new_node->pre = NULL;
new_node->next = head;

if (head != NULL) {
    head->pre = new_node;
} else {
    tail = new_node;
}

head = new_node;
}

void insert_at_l() {
new_node = (struct node *)malloc(sizeof(struct node));
printf("Enter the data:");
scanf("%d", &new_node->data);
new_node->next = NULL;
new_node->pre = tail;

if (tail != NULL) {
    tail->next = new_node;
} else {
    head = new_node;
}

tail = new_node;
}

void insert_at_i() {
int pos, i;
printf("Enter the position to insert:");
scanf("%d", &pos);

if (pos <= 0) {
    printf("Invalid position.\n");
    return;
}

if (pos == 1) {
    insert_at_f();
    return;
}

temp = head;
for (i = 1; i < pos - 1 && temp != NULL; i++) {
    temp = temp->next;
}

if (temp == NULL) {
    printf("Invalid position.\n");
    return;
}

new_node = (struct node *)malloc(sizeof(struct node));
printf("Enter the data:");
scanf("%d", &new_node->data);
new_node->pre = temp;
new_node->next = temp->next;

if (temp->next != NULL) {
    temp->next->pre = new_node;
} else {
    tail = new_node;
}

temp->next = new_node;
}

void deletion_at_s() {
if (head == NULL) {
    printf("List is empty.\n");
    return;
}

temp = head;
head = head->next;

if (head != NULL) {
    head->pre = NULL;
} else {
    tail = NULL;
}

free(temp);
printf("Node deleted from the start.\n");
}

void deletion_at_e() {
if (tail == NULL) {
    printf("List is empty.\n");
    return;
}

temp = tail;
tail = tail->pre;

if (tail != NULL) {
    tail->next = NULL;
} else {
    head = NULL;
}

free(temp);
printf("Node deleted from the end.\n");
}

void deletion_at_i() {
int pos, i;
printf("Enter the position to delete:");
scanf("%d", &pos);

if (pos <= 0) {
    printf("Invalid position.\n");
    return;
}

if (pos == 1) {
    deletion_at_s();
    return;
}

temp = head;
for (i = 1; i < pos && temp != NULL; i++) {
    temp = temp->next;
}

if (temp == NULL) {
    printf("Invalid position.\n");
    return;
}

if (temp->next != NULL) {
    temp->next->pre = temp->pre;
} else {
    tail = temp->pre;
}

if (temp->pre != NULL) {
    temp->pre->next = temp->next;
} else {
    head = temp->next;
}

free(temp);
printf("Node deleted from position %d.\n", pos);
}

void display() {
if (head == NULL) {
    printf("List is empty.\n");
    return;
}

temp = head;
printf("The linked list is:\n");
while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
}
printf("NULL\n");
}

void create_node() {
int c;

do {
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->pre = NULL;
    new_node->next = NULL;

    printf("Enter the data:");
    scanf("%d", &new_node->data);

    if (head == NULL) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        new_node->pre = tail;
        tail = new_node;
    }

    printf("Do you want to add a node? (0-1)");
    scanf("%d", &c);
} while (c == 1);
}

int main() {
int c, ch = 0;

create_node();

printf("The choices are:\n1.create_node \n2.insert_at_f \n3.insert_at_l \n4.insert_at_i \n5.deletion_at_s \n6.deletion_at_e \n7.deletion_at_i \n8.display");

do {
    printf("\nEnter the choice:");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
            create_node();
            break;
        case 2:
            insert_at_f();
            break;
        case 3:
            insert_at_l();
            break;
        case 4:
            insert_at_i();
            break;
        case 5:
            deletion_at_s();
            break;
        case 6:
            deletion_at_e();
            break;
        case 7:
            deletion_at_i();
            break;
        case 8:
            display();
            break;
        default:
            printf("Do you want to continue? Enter 9 for exit.");
            scanf("%d", &ch);
    }
} while (ch != 9);

return 0;
}
