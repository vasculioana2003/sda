#include <stdio.h>
#include <stdlib.h>
#include "graf.h"
#include "limits.h"

void makenull(t_lista *L){
    L->head=(t_nod_lista*)malloc(sizeof(t_nod_lista));
    L->head->next=NULL;
    L->head->prev=NULL;
}

void init_lista(t_lista *g, int n){
    for(int i=1; i<=n; i++){
        makenull(&g[i]);
    }
}

// list_insert insereaza un nod in lista de adiacenta
void list_insert(t_lista *L, t_nod_lista *x){
    if(x==NULL) return;
    x->next = L->head->next; //inserarea se face la inceputul listei 
    if(L->head->next!=NULL){
        L->head->next->prev=x;
    }
    L->head->next=x;
    x->prev=L->head;
}
// functia de inserare a vecinilor unui nod
void insert_vecini(t_lista *g, int n, int ns){ // ns este nodul sursa, n este numarul de noduri
    t_nod_lista *nod; 
    printf("--nod sursa: %d", ns);
    g[ns].head->cheie = ns; // setam cheia nodului sursa
    printf("\nApasati 0 pentru a opri inserarea vecinilor.");
    printf("\nDati vecinii nodului sursa: ");
    int nv; // nv este nodul vecin
    do{
        printf("vecin cu %d: \n", ns);
        scanf("%d", &nv);
        if((nv>0)&&(nv<=n)&&(nv!=ns))
        {
            nod=(t_nod_lista*)malloc(sizeof(t_nod_lista)); 
            nod->cheie=nv;
            list_insert(&g[ns], nod);
        }
    }while(nv>0);
}

// functia de cautare a unui nod in lista prin cheie
t_nod_lista *list_search(t_lista L, int key){
    t_nod_lista *x;
    x=L.head;
    while(x!=NULL && x->cheie!=key){
        x=x->next;
    }
    return x;
}

void list_delete(t_lista *L, t_nod_lista *x){
    if(x->prev!=NULL) {
        x->prev->next=x->next; 
    } else L->head->next=x->next;

    if(x->next!=NULL){
        x->next->prev=x->prev;
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

void print_graf(t_lista *g, int n){ //punem *-pt ca g e vector
    t_nod_lista *nod;
    for(int i=1; i<=n; i++){//parcurgem toate listele de adiacenta
        printf("%d:", i);
        nod=g[i].head->next;
        while(nod!=NULL){
            printf("%d ", nod->cheie);
            nod=nod->next;
        }
        printf("\n");
    }
}

//il facem gri
void mark_visited(t_lista *g, int n, int key){
    t_nod_lista *nod;
    for(int i=1; i<=n; i++){//parcurgem toate listele de adiacenta
        nod=g[i].head;
        while(nod!=NULL){//parcurgem toate nodurile din lista de adiacenta
            if(key==nod->cheie){ 
                nod->color=gray; 
            }
            nod=nod->next;
        }
    }
}

//parcurgerea in latime
// void bfs(t_lista *g, int s, int n){ //s este nodul de start, n este numarul de noduri
//     t_nod_lista* q[100], *u, *v, *ns; // q este coada, u este nodul curent, v este vecinul nodului curent, ns este nodul de start
//     int k=-1;
//     for(int i=1; i<=n; i++){ //parcurgem toate listele de adiacenta
//         u=g[i].head;
//         while(u!=NULL){
//             if(u->cheie!=s) {
//                 u->color=white; // white inseamna nod nevizitat
//                 u->d=INT_MAX; //distanta de la nodul de start la nodul curent
//                 u->prev=NULL; 
//             }
//             u=u->next;
//         }
//     }
//     ns=g[s].head;
//     ns->color=gray;
//     ns->d=0;
//     ns->prev=NULL;
//     printf("%d ", ns->cheie);
//     mark_visited(g, n, ns->cheie);
//     k++;
//     q[k]=ns;
//     while(k>-1){
//         u=q[0];
//         for(int i=1; i<=k; i++){
//             q[i-1]=q[i];
//         }
//     k--;
//     v=g[u->cheie].head;
//        while(v!=NULL){
//            if(v->color==white){
//                v->color=gray;
//                printf("%d ", v->cheie);
//                v->d=u->d+1;
//                v->prev=u;
//                g[v->cheie].head->prev=u;
//                g[v->cheie].head->d=u->d+1;
//                mark_visited(g, n, v->cheie);
//                k++;
//                q[k]=v;
//            }
//         v=v->next;
//        }
//     u->color=black;
//     }

// }

void bfs(t_lista *g, int s, int n) { 
    t_nod_lista *q[100], *u, *v; // Coada, nodul curent, vecinul nodului curent
    int front = 0, tail = 0;

    // Inițializare nod de start
    g[s].head->color = gray; //il face gri in lista lui de adiacenta
    g[s].head->d = 0; // distanța de la nodul de start la nodul curent
    g[s].head->prev = NULL;
    printf("%d ", g[s].head->cheie);
    mark_visited(g, n, s); //il face gri in toate listele de adiacenta
    
    q[tail] = g[s].head; // Adăugăm nodul în coadă si incrementăm tail dupa adaugare
    tail++;

    while (front < tail) { // Cat timp coada nu este goală
        u = q[front]; // Luăm nodul din fața cozii
        front++; // Scoatem nodul din coadă

        v = g[u->cheie].head->next; // g[u->cheie] arata catre lista de adiacenta a nodului u, iar g[u->cheie].head arata catre nodul u
        while (v != NULL) {
            if (v->color == white) { 
                v->color = gray;// il facem gri in lista lui de adiacenta
                v->d = u->d + 1; // distanța de la nodul de start la nodul curent
                v->prev = u;
                printf("%d ", v->cheie);
                mark_visited(g, n, v->cheie);//il face gri in toate listele de adiacenta
                q[tail] = v; // Adăugăm vecinul în coadă
                tail++;
            }
            v = v->next; // Trecem la următorul vecin al nodului u
        }
        u->color = black; 
    }
}



//printarea caii de la nodul s la nodul v
void print_path(t_lista *g, t_nod_lista *s, t_nod_lista *v){
    if(v==s){ //cazul de baza(cand s a ajuns aici se opreste recursivitatea)
        printf("%d ", s->cheie); 
    }else{
        if(v->prev==NULL){ //dacă nodul curent (v) nu are un părinte
            printf("nu exista cale.\n");
        }
        else{
            print_path(g, s, v->prev);
            printf("%d ", v->cheie);
        }
    }
}


void dfs_visit(t_lista *g, t_nod_lista *u, int n, int time){ // u este nodul curent, n este numarul de noduri, time este timpul
    t_nod_lista *v;// v este vecinul nodului curent
    time=time+1;// time reprezintă timpul curent, iar la începutul funcției incrementăm acest timp pentru a marca timpul de descoperire al nodului u
    u->d=time;
    u->color=gray;// il facem gri in lista lui de adiacenta
    printf("%d ", u->cheie);//le dam print in ordinea in care sunt descoperite
    mark_visited(g, n, u->cheie);//il face gri in toate listele de adiacenta
    v=g[u->cheie].head->next;// v este primul vecin al nodului u
    while(v!=NULL){
        if(v->color==white){
            v->prev=u;
            dfs_visit(g, v, n, time); //apelăm recursiv funcția pentru a explora vecinii nodului u
        }
        v=v->next;
    }
    u->color=black;//le facem negre in ordinea in care sunt resolvate
    time=time+1;
    u->f=time;
}


void dfs(t_lista *g, int n){
    int time;
    t_nod_lista *u;
    for(int i=1; i<=n; i++){ //parcurgem toate listele de adiacenta
        u=g[i].head;
        while(u!=NULL){ //parcurgem toate nodurile din lista de adiacenta
            u->color=white;
            u->prev=NULL; 
            u=u->next;
        }
    }
    time=0;
    for(int i=1; i<=n; i++){
        u=g[i].head;
        if(u->color==white) dfs_visit(g, u, n, time); 
    }
}

void dfs_visit_top(t_lista *g, t_nod_lista *u, int time, t_lista topo, int n){
    t_nod_lista *v;
    time=time+1;
    u->d=time;
    u->color=gray; //il facem gri in lista lui de adiacenta
    mark_visited(g, n, u->cheie);//il face gri in toate listele de adiacenta
    v=g[u->cheie].head->next;// v este primul vecin al nodului u
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

t_lista top_sort(t_lista *g, int n){
    int i, time;
    t_lista topo;
    makenull(&topo);
    t_nod_lista *u;
    for(i=1; i<=n; i++){//parcurgem toate listele de adiacenta
        u=g[i].head;
        while(u!=NULL){
            u->color=white;
            u->prev=NULL;
            u=u->next;

        }
    }
    time=0;
    //for este important in cazul in care avem un nod izolat(daca este graf orientat for se face o data practic ca nu o sa mai fie valabila conditi DIN IF)
    for(i=1; i<=n; i++){ //parcurgem toate listele de adiacenta si apelam dfs_visit_top pentru fiecare nod
        u=g[i].head;
        if(u->color==white){
            dfs_visit_top(g, u, time, topo, n);
        }

    }
    return topo;
}
