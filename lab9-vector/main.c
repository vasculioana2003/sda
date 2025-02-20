#include <stdio.h>
#include <stdlib.h>
#include "graf.h"

int main(){
    t_lista g[100], topology;
    int i, n, n1, n2;
    printf("nr noduri= ");
    scanf("%d", &n);
    init_lista(g ,n);

    for(i=1; i<=n; i++){
        insert_vecini(g, n, i);
    }
    
    printf("lista de adiacenta: ");
    print_lista(g, n);
    printf("\nparcurgere in latime:\n nod start: ");
    scanf("%d", &n1);
    bfs(g, n1, n);
    printf("\ncalea cea mai scurta: ");
    printf("nod start: ");
    scanf("%d", &n1);
    printf("nod final: ");
    scanf("%d", &n2);
    print_path(g, g[n1].head, g[n2].head);
    printf("\nparcurgere in adancime: ");
    dfs(g, n);
    printf("\n sortare topologica\n");
    topology=top_sort(g, n);
    list_print(topology);

    return 0;
}

