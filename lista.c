#include "lista.h"
#include <stdlib.h>

Lista* criaL(){
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    Bucket *primeiro = (Bucket*)malloc(sizeof(Bucket));
    primeiro->buck = NULL;
    primeiro->tam = 0;
    primeiro->prox = NULL;
    lista->primeiro = primeiro;
    lista->ultimo = primeiro;
    return lista;
}

int vazia(Lista *lista){
    if(lista->primeiro == lista->ultimo) return 1;
    return 0;
}

void insere(Lista *lista, int n, int v[]){
    Bucket *b = (Bucket*)malloc(sizeof(Bucket));
    if (n > 0){
        b->buck = (int*)malloc(n*sizeof(int));
        for (int i = 0; i < n; i++){
            b->buck[i] = v[i];
        }
        b->tam = n;
    }else{
        b->buck = NULL;
        b->tam = n;
    }
    lista->ultimo->prox = b;
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->prox = NULL;
    if(vazia(lista)) lista->ultimo = b;
}

void desfazer(Lista *lista){
    if(vazia(lista)){
        free(lista->primeiro);
        free(lista);
        return;
    }
    Bucket *item_corrente = lista->primeiro->prox;
    Bucket *item_anterior = lista->primeiro;
    while(item_corrente != NULL){
        if (item_anterior->buck != NULL){
            free(item_anterior->buck);
        }        
        free(item_anterior);
        item_anterior = item_corrente;
        item_corrente = item_corrente->prox;
    }
    if (item_anterior->buck != NULL){
        free(item_anterior->buck);
    }
    free(item_anterior);
    free(lista);
}