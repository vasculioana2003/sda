#include <stdio.h>
#include <stdlib.h>
#include "DLL.h"

int main() {
    Lista listaMea = {NULL};
    makeNull(&listaMea);
    int s = -1;
    while (s != 0) {
        printf("\n1 - addNode\n2 - listSearch\n
        3-deleteNode\n4 - listPrint\nAlege actiune:");
        scanf("%d", &s);
        switch (s) {
            int key;
            case 1: {
                printf("Cheie:");
                scanf("%d", &key);
                Nod_lista* x = 
                    (Nod_lista*)malloc(sizeof(Nod_lista));
                if (x == NULL) {
                    printf("Memory allocation failed.\n");
                    break;
                }
                x->cheie = key;
                addNode(&listaMea, x);
                break;
            }
            case 2: {
                printf("Cheie:");
                scanf("%d", &key);
                Nod_lista* x = listSearch(listaMea, key);
                if (x != NULL) {
                    printf("%d %p\n", key, x); //afisam cheia key si adresa nodului x
                } else {
                    printf("Cheie negasita\n");
                }
                break;
            }
            case 3: {
                printf("Cheie:");
                scanf("%d", &key);
                Nod_lista* x = listSearch(listaMea, key);
                if (x != NULL) {
                    deleteNode(&listaMea, x);
                } else {
                    printf("Cheie negasita\n");
                }
                break;
            }
            case 4: {
                listPrint(listaMea);
                break;
            }
        }
    }
    listFree(&listaMea);
    return 0;
}









int main(){
    Lista listaMea = {NULL};
    makeNull(&listaMea);
    s=-1;
    while (s!=0){
        printf ("\n1 - addNode\n2 - listSearch\n
        3-deleteNode\n4 - listPrint\nAlege actiune:");
        scanf("%d", &s);
        switch(s){
            int key;
            //adaugare nod
            case 1:{
                printf("cheie:");
                scanf("%d", &key);
                Nod_lista* x=malloc(sizeof(Nod_lista));
                if(x==NULL){
                    printf("memory allocation failed"\n);
                    break;
                }
                x->cheie=key;
                addNode(&listaMea, x);
                break;
            }
            //cautare nod
            case 2:{
                printf("cheie:");
                scanf("%d", &s);
                Nod_lista *x= listSearch(listaMea, key);
                if (x != NULL){
                    printf ("%d %p", key, x);
                }else{
                    printf("Cheie negasita\n");
                }
                break;
            }
            //stergere nod
            case 3:{
                printf("cheie:");
                scanf("%d", &key);
                Nod_lista* x = listSearch (listaMea, key);
                if (x != NULL){
                    deleteNode(&listaMea, x)
                } else {
                    printf ("Cheie negasita\n");
                }
                break
            }
            case 4: {
                listPrint(listaMea);
                break;
            }
        }
    }
    listFree(&listaMea);
    return 0;
}