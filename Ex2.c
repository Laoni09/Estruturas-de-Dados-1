#include <stdlib.h>
#include <stdio.h>

typedef struct Nodo {
    int info;
    struct Nodo *prox;
} nodo;

void imprime(nodo *lista) {
    nodo *aux = lista;
    while(1){
        printf("%d ", aux->info);
        aux = aux->prox;
        if(aux == NULL) break;
    }
}

void imprime_contrario(nodo *lista) {
    if (lista == NULL) return;
    imprime_contrario(lista->prox);
    printf("%d ",lista->info);
}

void libera(nodo *lista){
    if(lista == NULL) return;
    libera(lista->prox);
    free(lista);
}

nodo *inserefinal(nodo *lista, int x){
    nodo *cabeca = lista;
    if(lista == NULL){
        nodo *novo = (nodo*)malloc(sizeof(nodo));
        novo->prox = NULL;
        novo->info = x;
        lista = novo;
        return lista;
    }
    lista->prox = inserefinal(lista->prox, x);
}

int main(){
    int n = 0;
    nodo *lista = NULL;
    while(1){
        scanf("%d", &n);
        if(n == -1)break;
        lista = inserefinal(lista, n);
    }
    imprime(lista);
    printf("\n");
    imprime_contrario(lista);
    libera(lista);
}
