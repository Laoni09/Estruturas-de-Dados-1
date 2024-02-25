#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int info;
    struct Nodo *prox;
}nodo;

nodo *novaLista(){
    nodo *lista = NULL;
    return lista;
}

nodo *criaNodo(int x){
    nodo *novo = (nodo*)malloc(sizeof(nodo));
    novo->info = x;
    novo->prox = NULL;
    return novo;
}

nodo *insere(nodo *lista, int x){
    nodo *novo = criaNodo(x);
    if(lista == NULL){
        lista = novo;
        novo->prox = lista;
        return lista;
    }
    novo->prox = lista->prox;
    lista->prox = novo;
    return lista;
}

nodo *criaSeq(int n){
    nodo *lista = novaLista();
    nodo *novo = criaNodo(0);
    lista = novo;
    novo->prox = lista;
    int i;
    for(i = 1; i <= n; i++){
        novo = criaNodo(i);
        novo->prox = lista->prox;
        lista->prox = novo;
    }
    return lista;
}
void imprime(nodo *lista){
    nodo *aux = lista->prox;
    printf("%d ", lista->info);
    while(aux != lista){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
}

int main(){
    int x;
    nodo *lista = novaLista();
    while(1){
        scanf("%d", &x);
        if(x == -1) break;
        lista = insere(lista, x);
    }
    imprime(lista);
    nodo *seq = novaLista();
    seq = criaSeq(7);
    imprime(seq);
}