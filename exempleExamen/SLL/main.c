#include <stdio.h>
#include "SLL.h"

int main() {
    SLL list;
    INIT(&list); 

    printf("scrie o propozitie:\n");
    char c;
    while ((c = getchar()) != '\n') {
        INSERT(&list, c, NULL);
    }

    PRINTLIST(&list);
    return 0;
}



    SLL
propozitie