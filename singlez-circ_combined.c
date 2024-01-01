#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head, *tail, *new_node;

// Function declarations
void insert_at_first();
void insert_at_end();
void insert_at_specific();
void display();
void delete_at_first();
void delete_at_end();
void delete_at_specific();

int main() {
    head = tail = NULL;
    int c, ch;

    do {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->next = NULL;
        
        printf("Enter the data: ");
        scanf("%d", &new_node->data);
        
        if (head == NULL) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        
        tail->next = head;
        printf("Do you want to add a new node? (0/1): ");
        scanf("%d", &c);
    } while (c == 1);

    printf("\nThe choices are:\n1. insert_at_first\n2. insert_at_end\n3. insert_at_specific\n4. display\n5. delete_at_first\n6. delete_at_end\n7. delete_at_specific\n");

    do {
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1: {
                insert_at_first();
                break;
            }
            case 2: {
                insert_at_end();
                break;
            }
            case 3: {
                insert_at_specific();
                break;
            }
            case 4: {
                display();
                break;
            }
            case 5: {
                delete_at_first();
                break;
            }
            case 6: {
                delete_at_end();
                break;
            }
            case 7: {
                delete_at_specific();
                break;
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    } while (ch != 0);

    return 0;
}

void insert_at_first() {
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &new_node->data);

    if (head == NULL) {
        head = tail = new_node;
        new_node->next = head;
    } else {
        new_node->next = head;
        head = new_node;
        tail->next = head;
    }
}

void insert_at_end() {
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &new_node->data);

    if (head == NULL) {
        head = tail = new_node;
        new_node->next = head;
    } else {
        tail->next = new_node;
        new_node->next = head;
        tail = new_node;
    }
}

void insert_at_specific() {
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &new_node->data);
    
    int pos, i;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        new_node->next = head;
        head = new_node;
        tail->next = head;
        return;
    }

    struct node *temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;

    if (new_node->next == head) {
        tail = new_node;
    }
}

void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("List elements: ");
    do {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

void delete_at_first() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node *temp = head;

    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        tail->next = head;
    }

    free(temp);
}

void delete_at_end() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node *temp = head, *prev = NULL;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        head = tail = NULL;
    } else {
        prev->next = head;
        tail = prev;
    }

    free(temp);
}

void delete_at_specific() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    int pos, i;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        struct node *temp = head;
        head = head->next;
        tail->next = head;
        free(temp);
        return;
    }

    struct node *curr = head, *prev = NULL;
    for (i = 1; i < pos && curr != NULL; i++) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    prev->next = curr->next;

    if (curr == tail) {
        tail = prev;
    }

    free(curr);
}
