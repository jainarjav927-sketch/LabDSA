#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtEnd(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if (head == NULL) {
        head = newNode;
        head->next = head;
        return;
    }
    struct Node* temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

void deleteNode(int val) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *curr, *prev;

    // agar head hi delete karna hai
    if (head->data == val) {
        if (head->next == head) {
            free(head);
            head = NULL;
            printf("%d deleted\n", val);
            return;
        }
        struct Node* last = head;
        while (last->next != head) last = last->next;
        struct Node* temp = head;
        head = head->next;
        last->next = head;
        free(temp);
        printf("%d deleted\n", val);
        return;
    }

    curr = head;
    do {
        prev = curr;
        curr = curr->next;
        if (curr->data == val) {
            prev->next = curr->next;
            free(curr);
            printf("%d deleted\n", val);
            return;
        }
    } while (curr != head);

    printf("%d not found in list\n", val);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertAtEnd(val);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteNode(val);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice, try again\n");
        }
    }

    return 0;
}
