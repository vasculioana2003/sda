#include <stdio.h>
#include <stdlib.h>

// R = 123 bani  => 25*4 + 10*2 + 1*3
int main() {
    int rest, index = 3;
    int MONEDE[4] = {1, 5, 10, 25};
    int nr_monede_folosite = 0;

    printf("Rest = ");
    scanf("%d", &rest);

    while(rest > 1){
        nr_monede_folosite = rest / MONEDE[index];
        if (nr_monede_folosite > 0){
            printf(
                "%d monede de %d\n", 
                nr_monede_folosite, MONEDE[index]
            );
        }
        rest = rest - nr_monede_folosite * MONEDE[index]; 
        index--;
    }
    return 0;
}



programare
 dinamica