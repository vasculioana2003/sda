#include <stdio.h>
#include "ArrayList.h"

int main() {
    ArrayList list;
    MAKENULL(&list);  // Initialize the list to be empty

    // Insert elements into the list
    INSERT(&list, 10, 0);  // Insert 10 at position 0
    INSERT(&list, 20, 1);  // Insert 20 at position 1
    INSERT(&list, 30, 2);  // Insert 30 at position 2

    // Print the list
    printf("Initial List: ");
    PRINTLIST(&list);

    // Locate element
    int pos = LOCATE(&list, 20);
    if (pos != -1) {
        printf("Element 20 found at position: %d\n", pos);
    } else {
        printf("Element 20 not found.\n");
    }

    // Insert at a specific position
    INSERT(&list, 40, 3);  // Insert 40 at the end (position 3)
    printf("After inserting 40 at the end: ");
    PRINTLIST(&list);

    // Delete element
    DELETE(&list, LOCATE(&list, 20)); // Delete the element 20
    printf("After deleting 20: ");
    PRINTLIST(&list);

    // Get first element
    pos = FIRST(&list);
    if (pos != -1) {
        printf("First element: %d\n", RETRIEVE(&list, pos));
    }

    // Make the list null (empty it)
    MAKENULL(&list);
    printf("After MAKENULL: ");
    PRINTLIST(&list);

    return 0;
}
