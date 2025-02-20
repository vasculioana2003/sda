#include <stdio.h>
#include <stdlib.h>
#include "graf.h"
#include "limits.h"

void makenull(t_lista *L){
    L->head=(t_nod_lista*)malloc(sizeof(t_nod_lista));
    L->head->next=NULL;
    L->head->prev=NULL;
}
t_nod_lista *list_search(t_lista L, int key){
    t_nod_lista *x;
    x=L.head;
    while(x!=NULL && x->cheie!=key){
        x=x->next;
    }
    return (x);
}
void mark_visited(t_lista g[], int n, int key){
    int i;
    t_nod_lista *nod;
    for(i=1; i<=n; i++){
        nod=g[i].head;
        while(nod!=NULL){
            if(key==nod->cheie){ 
                nod->color=gray; 
            }
            nod=nod->next;
        }
    }
}
void list_delete(t_lista *L, t_nod_lista *x){
    if(x->prev!=NULL) { x->prev->next=x->next; }
    else{ L->head->next=x->next; }
    if(x->next!=NULL){
        x->next->prev=x->prev;
    }

}
void print_path(t_lista g[], t_nod_lista *s, t_nod_lista *v){
    if(v==s){ printf("%d ", s->cheie); }
    else{
        if(v->prev==NULL){
            printf("nu exista cale.\n");
        }
        else{
            print_path(g, s, v->prev);
            printf("%d ", v->cheie);
        }
    }
}

void init_lista(t_lista g[], int n)
{
    int i;
    for(i=1; i<=n; i++)
    {
        makenull(&g[i]);
    }
}

void insert_vecini(t_lista g[], int n, int ns)
{
    t_nod_lista *nod;
    int nv;
    printf("--nod sursa: %d", ns);
    g[ns].head->cheie=ns;
    printf("\nApasati 0 pentru a opri inserarea vecinilor.");
    printf("\nDati vecinii nodului sursa: ");
    do
    {
        printf("vecin cu %d \n", ns);
        scanf("%d", &nv);
        if((nv>0)&&(nv<=n)&&(nv!=ns))
        {
            nod=(t_nod_lista*)malloc(sizeof(t_nod_lista));
            nod->cheie=nv;
            list_insert(&g[ns], nod);
        }
    }while(nv>0);
}

void print_lista(t_lista g[], int n){
    t_nod_lista *nod;
    int i;
    for(i=1; i<=n; i++){
        nod=g[i].head->next;
        printf("%d:", i);
        while(nod!=NULL){
            printf("%d ", nod->cheie);
            nod=nod->next;
        }
    printf("\n");
    }
}

void bfs(t_lista g[], int s, int n){
    t_nod_lista* q[100], *u, *v, *ns;
    int k=-1, i;
    for(i=1; i<=n; i++){
        u=g[i].head;
        while(u!=NULL){
            if(u->cheie!=s) {
                u->color=white;
                u->d=INT_MAX;
                u->prev=NULL;
            }
        u=u->next;
        }
    }
    ns=g[s].head;
    ns->color=gray;
    ns->d=0;
    ns->prev=NULL;
    printf("%d ", ns->cheie);
    mark_visited(g, n, ns->cheie);
    k++;
    q[k]=ns;
    while(k>-1){
        u=q[0];
        for(i=1; i<=k; i++){
            q[i-1]=q[i];
        }
    k--;
    v=g[u->cheie].head;
       while(v!=NULL){
           if(v->color==white){
               v->color=gray;
               printf("%d ", v->cheie);
               v->d=u->d+1;
               v->prev=u;
               g[v->cheie].head->prev=u;
               g[v->cheie].head->d=u->d+1;
               mark_visited(g, n, v->cheie);
               k++;
               q[k]=v;
           }
        v=v->next;
       }
    u->color=black;
    }

}
void list_print(t_lista L){
    t_nod_lista *x;
    x=L.head->next;
    if(x==NULL){
        printf("lista vida");
    }
    else {
        printf("lista este: ");
        while(x!=NULL){
            printf("%d ", x->cheie);
            x=x->next;
        }
    }
}

void list_insert(t_lista *L, t_nod_lista *x){
    if(x==NULL) return;
    x->next=L->head->next;
    if(L->head->next!=NULL){
        L->head->next->prev=x;
    }
    L->head->next=x;
    x->prev=L->head;
}
void dfs_visit(t_lista g[], t_nod_lista *u, int n, int time){
    t_nod_lista *v;
    time=time+1;
    u->d=time;
    u->color=gray;
    printf("%d ", u->cheie);
    mark_visited(g, n, u->cheie);
    v=g[u->cheie].head->next;
    while(v!=NULL){
        if(v->color==white){
            v->prev=u;
            dfs_visit(g, v, n, time);
        }
        v=v->next;
    }
    u->color=black;
    time=time+1;
    u->f=time;
}

void dfs(t_lista g[], int n){
    int time;
    t_nod_lista *u;
    int i;
    for(i=1; i<=n; i++){
        u=g[i].head;
        while(u!=NULL){
            u->color=white;
            u->prev=NULL;
            u=u->next;
        }
    }
    time=0;
    for(i=1; i<=n; i++){
        u=g[i].head;
        if(u->color==white){ dfs_visit(g, u, n, time); }
    }

}
void dfs_visit_top(t_lista g[], t_nod_lista *u, int time, t_lista topo, int n){
    t_nod_lista *v;
    time=time+1;
    u->d=time;
    u->color=gray;
    mark_visited(g, n, u->cheie);
    v=g[u->cheie].head->next;
    while(v!=NULL){
        if(v->color==white){
            v->prev=u;
            dfs_visit_top(g, v, time, topo, n);
        }
        v=v->next;
    }
    u->color=black;
    time=time+1;
    u->f=time;
    list_insert(&topo, u);
}

t_lista top_sort(t_lista g[], int n){
    int i, time;
    t_lista topo;
    makenull(&topo);
    t_nod_lista *u;
    for(i=1; i<=n; i++){
        u=g[i].head;
        while(u!=NULL){
            u->color=white;
            u->prev=NULL;
            u=u->next;

        }
    }
    time=0;
    for(i=1; i<=n; i++){
        u=g[i].head;
        if(u->color==white){
            dfs_visit_top(g, u, time, topo, n);
        }

    }
    return topo;
}