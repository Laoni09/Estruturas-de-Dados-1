#include <stdio.h>
#include <stdlib.h>
typedef struct Nodo
{
    int info;
    struct Nodo *ant;
    struct Nodo *prox;
}nodo;

nodo *criaLista(){
    nodo *lista = NULL;
    return lista;
}

nodo *criaNodo(int x){
    nodo *novo = (nodo*)malloc(sizeof(nodo));
    novo->info = x;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

nodo *insereInicio(nodo *lista, int x){
    nodo *novo = criaNodo(x);
    novo->prox = lista;
    novo->ant = NULL;
    if(lista != NULL){
        lista->ant = novo;
    }
    return novo;
}

nodo *insereFinal(nodo *lista, int x){
    nodo *novo = criaNodo(x);
    if(lista == NULL){
        lista = novo;
        return lista;
    }
    nodo *aux = lista;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    novo->ant = aux;
    aux->prox = novo;
    return lista;
}

nodo *insereFinalRecursiva(nodo *lista, int x){
    if(lista == NULL) {
        nodo *novo = criaNodo(x);
        lista = novo;
        return lista;
    }
    lista->prox = insereFinal(lista->prox, x);
    return lista;
}

void swap(nodo *A, nodo *B) {
    A->ant->prox = B;
    B->prox->ant = A;
    A->prox = B->prox;
    B->ant = A->ant;
    B->prox = A;
    A->ant = B;
}

nodo *bubble(nodo *lista){
    nodo *temp1 = lista;
    nodo *aux = criaNodo(0);
    while(temp1->prox != NULL){
        nodo *temp2 = lista;
        while(temp2->prox != NULL){
            if(temp1->info > temp2->info){
                //perguntar pro professor
            }
            temp2 = temp2->prox;
        }
        temp1 = temp1->prox;
    }
    return lista;
}

void imprime(nodo *lista){
    if(lista == NULL) return;
    printf("%d", lista->info);
    imprime(lista->prox);
}

int main(){
    nodo *lista = criaLista();
    while(1)
    {
        int x;
        scanf("%d", &x);
        if (x == -1) break;
        lista = insereFinalRecursiva(lista, x);
    }
    lista = bubble(lista);
    imprime(lista);
}