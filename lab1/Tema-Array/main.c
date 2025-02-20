#include <stdio.h>
#include "ArrayList.h"

int main() {
    ArrayList list;
    MAKENULL(&list);  // Initialize the list to be empty

    int choice, data, position;

    while (1) {
        printf("\n1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Locate Element\n");
        printf("4. Retrieve Element\n");
        printf("5. Print List\n");
        printf("6. Make List Null\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert element at a specific position
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                INSERT(&list, data, position);
                break;

            case 2:
                // Delete element at a specific position
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                DELETE(&list, position);
                printf("After deletion: ");
                PRINTLIST(list);
                break;

            case 3:
                // Locate element
                printf("Enter the data to locate: ");
                scanf("%d", &data);
                position = LOCATE(list, data);
                if (position != -1) {
                    printf("Element %d found at position: %d\n", data, position);
                } else {
                    printf("Element %d not found.\n", data);
                }
                break;

            case 4:
                // Retrieve element
                printf("Enter the position to retrieve: ");
                scanf("%d", &position);
                data = RETRIEVE(list, position);
                if (data != -1) {
                    printf("Element at position %d is: %d\n", position, data);
                } else {
                    printf("Invalid position.\n");
                }
                break;

            case 5:
                // Print the list
                PRINTLIST(list);
                break;

            case 6:
                // Make the list null (empty)
                MAKENULL(&list);
                printf("List has been made null (empty).\n");
                break;

            case 7:
                // Exit the program
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
