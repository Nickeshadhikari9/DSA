#include <stdio.h>
int list[100];
int length = 0;
void create();
void insert();
void delete();
void update();
void traverse();
void search();
void merge();
int main() {
    int choice;
     printf("\nMenu:\n1. Create\n2. Insert\n3. Delete\n4. Update\n5. Traverse\n6. Search\n7. Merging\n8. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                insert();
                break;
            case 3:
                delete();
                break;
            case 4:
                update();
                break;
            case 5:
                traverse();
                break;
            case 6:
                search();
                break;
            case 7:
                merge();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 8);
    
    return 0;
}

void create() {
    int size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }
    length = size;
    printf("List created successfully.\n");
}
void insert() {
    int position, item;
    if (length == 0) {
        printf("List is empty. Create a list first.\n");
        return;
    }
    printf("Enter position to insert: ");
    scanf("%d", &position);
    if (position < 1 || position > length+1) {
        printf("Invalid position.\n");
        return;
    }
    printf("Enter item to insert: ");
    scanf("%d", &item);
    position--; 
    for (int i = length; i >= position; i--){ 
        list[i] = list[i - 1];
    }
    list[position] = item;
    length++;
    printf("Item inserted successfully.\n");
}
void delete() {
    if (length == 0) {
        printf("List is empty.\n");
        return;
    }
    int position;
    printf("Enter position to delete: ");
    scanf("%d", &position);
    position--; 
    for (int i = position; i < length - 1; i++) {
        list[i] = list[i + 1];
    }
    length--;
    printf("Item deleted successfully.\n");
}
void update() {
    int position, newItem;
    if (length == 0) {
        printf("List is empty.\n");
        return;
    }
    printf("Enter position to update: ");
    scanf("%d", &position);
    printf("Enter new item: ");
    scanf("%d", &newItem);
    list[position - 1] = newItem;
    printf("Item updated successfully.\n");
}
void merge() {
    int newSize;
    printf("Enter the size of the new list: ");
    scanf("%d", &newSize);
    int newlist[newSize];
    printf("Enter %d elements for the new list:\n", newSize);
    for (int i = 0; i < newSize; i++) {
        scanf("%d", &newlist[i]);
        list[length]=newlist[i];
        length=length+1;
    }
    length += newSize;
    printf("List merged successfully.\n");
}
void search() {
    if (length == 0) {
        printf("List is empty.\n");
        return;
    }
    int item, found = 0;
    printf("Enter item to search: ");
    scanf("%d", &item);
    for (int i = 0; i < length; i++) {
        if (list[i] == item) {
            printf("%d found at position %d.\n", item, i + 1);
            found = 1;
        }
    }
    if (!found) {
        printf("%d not found in the list.\n", item);
    }
}
void traverse() {
    if (length == 0) {
        printf("List is empty.\n");
        return;
    }
    printf("Items in list:\n");
    for (int i = 0; i < length; i++) {
        printf("%d\t", list[i]);
    }
    printf("\n");
}

