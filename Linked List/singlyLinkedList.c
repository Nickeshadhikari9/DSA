#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the first position in the linked list
void insertFirst(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;

    printf("Node inserted at the first position successfully.\n");
}

// Function to insert a new node at a given position in the linked list
void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        printf("Node inserted at position %d successfully.\n", position);
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position. Node not inserted.\n");
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node inserted at position %d successfully.\n", position);
    }
}

// Function to insert a new node at the last position in the linked list
void insertLast(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Node inserted at the last position successfully.\n");
}

// Function to delete the last node in the linked list
void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Last node deleted successfully.\n");
        return;
    }

    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    printf("Last node deleted successfully.\n");
}

// Function to delete the nth node in the linked list
void deleteNth(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (position == 1) {
        struct Node* temp = *head;
        *head = temp->next;
        free(temp);
        printf("Node at position %d deleted successfully.\n", position);
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position. Node not deleted.\n");
    } else {
        struct Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
        printf("Node at position %d deleted successfully.\n", position);
    }
}

// Function to calculate the sum of all nodes in the linked list
int calculateSum(struct Node* head) {
    int sum = 0;
    while (head != NULL) {
        sum += head->data;
        head = head->next;
    }
    return sum;
}

// Function to count the number of nodes in the linked list
int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to display the linked list
void displayList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at First\n");
        printf("2. Insert at Given Position\n");
        printf("3. Insert at Last\n");
        printf("4. Delete Last Node\n");
        printf("5. Delete Nth Node\n");
        printf("6. Calculate Sum\n");
        printf("7. Count Nodes\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at first: ");
                scanf("%d", &value);
                insertFirst(&head, value);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertAtPosition(&head, value, position);
                break;
            case 3:
                printf("Enter the value to insert at last: ");
                scanf("%d", &value);
                insertLast(&head, value);
                break;
            case 4:
                deleteLast(&head);
                break;
            case 5:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteNth(&head, position);
                break;
            case 6:
                printf("Sum of all nodes: %d\n", calculateSum(head));
                break;
            case 7:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
            case 8:
                displayList(head);
                break;
            case 9:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 9);

    return 0;
}
