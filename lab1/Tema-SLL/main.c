#include <stdio.h>
#include "SLL.h"

int main() {
    SLL list;
    INIT(&list);  // Initialize the list

    // Test INSERT at the beginning (NULL means inserting at head)
    printf("Inserting elements at the head:\n");
    INSERT(&list, 10, NULL); // Insert 10 at the beginning
    INSERT(&list, 20, NULL); // Insert 20 at the beginning
    INSERT(&list, 30, NULL); // Insert 30 at the beginning
    PRINTLIST(&list);

    // Test INSERT after a specific node
    printf("Inserting 15 after node with value 10:\n");
    Node* position = LOCATE(&list, 10);  // Locate node with value 10
    INSERT(&list, 15, position);  // Insert 15 after node with value 10
    PRINTLIST(&list);

    // Test LOCATE
    printf("Locating node with value 20:\n");
    Node* found = LOCATE(&list, 20);
    if (found) {
        printf("Node with value 20 found.\n");
    } else {
        printf("Node with value 20 not found.\n");
    }

    // Test RETRIEVE
    printf("Retrieve value from located node: %d\n", RETRIEVE(&list, found));

    // Test DELETE
    printf("Deleting node with value 20:\n");
    DELETE(&list, found);
    PRINTLIST(&list);

    // Test NEXT and PREVIOUS
    Node* first = FIRST(&list);
    printf("First node value: %d\n", RETRIEVE(&list, first));
    printf("Next to first node: %d\n", RETRIEVE(&list, NEXT(&list, first)));

    Node* second = NEXT(&list, first);
    printf("Previous to second node: %d\n", RETRIEVE(&list, PREVIOUS(&list, second)));

    // Free all nodes and clean up
    MAKENULL(&list);
    printf("After MAKENULL, the list is:\n");
    PRINTLIST(&list);

    return 0;
}
